#include <array>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <span>
#include <sstream>

#include <tiptap/lfsr.h>

#include <wmmintrin.h> //for intrinsics for AES-NI

template<typename Object>
std::string
hexdump(const Object& obj)
{
  std::stringstream oss;

  auto ptr = reinterpret_cast<const unsigned char*>(&obj);
  const std::span data(ptr, ptr + sizeof(obj));
  for (const auto d : data) {
    oss << std::setfill('0') << std::setw(2) << std::hex
        << static_cast<unsigned>(d);
  }
  return oss.str();
}

constexpr std::array<std::uint8_t, 16> operator""_128bithex(const char* str,
                                                            std::size_t length)
{
  assert(length == 32);
  std::array<std::uint8_t, 16> parsed;
  auto get_nibble = [](const char c) {
    if (c >= 'a' && c <= 'f') {
      return (c - 'a') + 0xA;
    }
    if (c >= 'A' && c <= 'F') {
      return (c - 'A') + 0xA;
    }
    if (c >= '0' && c <= '9') {
      return (c - '0');
    }
    throw "not a hex char";
  };
  for (int i = 0; i < 16; ++i) {
    parsed[i] = (get_nibble(str[2 * i]) << 4) | get_nibble(str[2 * i + 1]);
  }
  return parsed;
}

__m128i
to_128bit_register(const std::array<std::uint8_t, 16>& x)
{
  __m128i ret = _mm_loadu_si128((const __m128i*)x.data());
  return ret;
}

struct EncryptedCounter
{
  static constexpr std::size_t N = 128;
  BigLFSR<N> lfsr;

  static constexpr std::size_t Nrounds = 9; // 9,11,13
  static constexpr std::size_t NroundsTotal = Nrounds + 1;
  static constexpr std::size_t Nkeys = NroundsTotal + 1;
  std::array<__m128i, Nkeys> expanded_keys{};
  using SixteenByte = std::array<std::uint8_t, 16>;

  EncryptedCounter()
  {
    // from the AES-128 example in
    // https://csrc.nist.gov/files/pubs/fips/197/final/docs/fips-197.pdf
    expanded_keys[0] =
      to_128bit_register("000102030405060708090a0b0c0d0e0f"_128bithex);
    expanded_keys[1] =
      to_128bit_register("d6aa74fdd2af72fadaa678f1d6ab76fe"_128bithex);
    expanded_keys[2] =
      to_128bit_register("b692cf0b643dbdf1be9bc5006830b3fe"_128bithex);
    expanded_keys[3] =
      to_128bit_register("b6ff744ed2c2c9bf6c590cbf0469bf41"_128bithex);
    expanded_keys[4] =
      to_128bit_register("47f7f7bc95353e03f96c32bcfd058dfd"_128bithex);
    expanded_keys[5] =
      to_128bit_register("3caaa3e8a99f9deb50f3af57adf622aa"_128bithex);
    expanded_keys[6] =
      to_128bit_register("5e390f7df7a69296a7553dc10aa31f6b"_128bithex);
    expanded_keys[7] =
      to_128bit_register("14f9701ae35fe28c440adf4d4ea9c026"_128bithex);
    expanded_keys[8] =
      to_128bit_register("47438735a41c65b9e016baf4aebf7ad2"_128bithex);
    expanded_keys[9] =
      to_128bit_register("549932d1f08557681093ed9cbe2c974e"_128bithex);
    expanded_keys[10] =
      to_128bit_register("13111d7fe3944a17f307a78b4d2b30c5"_128bithex);
  }

  __m128i encrypt(__m128i m) const
  {
    // initial round
    m = _mm_xor_si128(m, expanded_keys[0]);

    // intermediate rounds (use one-based indexing)
    for (std::size_t round = 1; round <= Nrounds; ++round) {
      m = _mm_aesenc_si128(m, expanded_keys[round]);
    }
    // last round
    m = _mm_aesenclast_si128(m, expanded_keys[NroundsTotal]);
    return m;
  }

  SixteenByte encrypt(const SixteenByte& x) const
  {
    SixteenByte ret;
    const auto m = encrypt(to_128bit_register(x));
    _mm_storeu_si128((__m128i*)ret.data(), m);
    return ret;
  }

  SixteenByte generate_unencrypted()
  {
    lfsr.next();
    static_assert(sizeof(lfsr) == sizeof(SixteenByte));
    SixteenByte ret;
    std::memcpy(&ret, &lfsr, sizeof(lfsr));
    return ret;
  }

  SixteenByte generate_encrypted()
  {
    lfsr.next();
    static_assert(sizeof(lfsr) == 16);
    __m128i encrypted = encrypt(_mm_loadu_si128((const __m128i*)&lfsr));
    SixteenByte ret;
    _mm_storeu_si128((__m128i*)&ret, encrypted);
    return ret;
  }
};

void
runEncrypted()
{
  EncryptedCounter counter;

  // check that the encryption works
  constexpr auto plaintext = "00112233445566778899aabbccddeeff"_128bithex;
  constexpr auto expected = "69c4e0d86a7b0430d8cdb78070b4c55a"_128bithex;
  assert(counter.encrypt(plaintext) == expected);

  const std::uint32_t maxreps = 10;
  for (std::uint32_t i = 0; i < maxreps; ++i) {
    auto out = counter.generate_encrypted();
    std::cout << hexdump(out) << '\n';
  }
}

int
main()
{
  runEncrypted();
}
