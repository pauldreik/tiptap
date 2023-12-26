#include <type_traits>
#include <vector>

#include <catch2/catch_test_macros.hpp>

#include "tiptap/lfsr_big.h"

template<std::size_t N, typename Limb>
void
test_lfsr_impl()
{
  BigLFSR<N, Limb> lfsr;

  // ensure a default initialized object is not zero
  CHECK(to_uint64(lfsr.state()) == 1);

  // the expected number of entries is 2**N-1
  const std::size_t expected_size = (1ULL << N) - 1;

  std::vector<std::uint64_t> states;
  states.reserve(expected_size);

  const auto initial_state = to_uint64(lfsr.state());
  do {
    states.push_back(to_uint64(lfsr.state()));
    lfsr.next();
    // zero must not be included
    REQUIRE(to_uint64(lfsr.state()) > 0);
    // all values must be within (0,2**N)
    constexpr std::uint64_t max = (1ULL << N);
    REQUIRE(to_uint64(lfsr.state()) < max);
  } while (to_uint64(lfsr.state()) != initial_state);

  // correct size
  REQUIRE(states.size() == expected_size);
}

template<std::size_t N>
void
test_lfsr()
{
  test_lfsr_impl<N, std::uint8_t>();
  test_lfsr_impl<N, std::uint16_t>();
  test_lfsr_impl<N, std::uint32_t>();
  test_lfsr_impl<N, std::uint64_t>();
}
TEST_CASE("test big LSFR (fits in 8 bits) with brute force")
{
  test_lfsr<3>();
  test_lfsr<4>();
  test_lfsr<5>();
  test_lfsr<6>();
  test_lfsr<7>();
  test_lfsr<8>();
}

TEST_CASE("test big LSFR (fits in 16 bits) with brute force")
{
  test_lfsr<9>();
  test_lfsr<10>();
  test_lfsr<11>();
  test_lfsr<12>();
  test_lfsr<13>();
  test_lfsr<14>();
  test_lfsr<15>();
  test_lfsr<16>();
}

TEST_CASE("test big LSFR (fits in 32 bits) with brute force")
{
  test_lfsr<17>();
  test_lfsr<18>();
}

namespace {
template<std::size_t N, std::size_t Msteps>
constexpr auto
proceed()
{
  BigLFSR<N> lfsr;
  for (std::size_t i = 0; i < Msteps; ++i) {
    lfsr.next();
  }
  return to_uint64(lfsr.state());
}
}

TEST_CASE("ensure big LSFR is usable in constexpr context")
{
  constexpr auto third = proceed<12, 3>();
  constexpr auto fourth = proceed<12, 4>();
  static_assert(third != fourth);
}

TEST_CASE("a newly constructed bif LSFR has nonzero start")
{
  CHECK(to_uint64(BigLFSR<12, std::uint8_t>{}.state()) != 0);
  CHECK(to_uint64(BigLFSR<4, std::uint8_t>{}.state()) != 0);
  CHECK(to_uint64(BigLFSR<17, std::uint64_t>{}.state()) != 0);
  CHECK(to_uint64(BigLFSR<12, std::uint32_t>{}.state()) != 0);
  CHECK(to_uint64(BigLFSR<33, std::uint32_t>{}.state()) != 0);
}
