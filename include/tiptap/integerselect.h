#pragma once

#include <cstdint>

namespace detail {
template<int N>
concept fitsin128 = (N >= 0 && N <= 128);

template<int N>
requires fitsin128<N>
constexpr int
bitwidth()
{
  if constexpr (N <= 8)
    return 8;
  if constexpr (N <= 16)
    return 16;
  if constexpr (N <= 32)
    return 32;
  if constexpr (N <= 64)
    return 64;
  if constexpr (N <= 128)
    return 128;
}

template<int N>
struct SelectImpl
{
};
template<>
struct SelectImpl<8>
{
  using type = std::uint8_t;
};
template<>
struct SelectImpl<16>
{
  using type = std::uint16_t;
};
template<>
struct SelectImpl<32>
{
  using type = std::uint32_t;
};
template<>
struct SelectImpl<64>
{
  using type = std::uint64_t;
};
template<>
struct SelectImpl<128>
{
#ifdef __SIZEOF_INT128__
  using type = unsigned __int128;
#else
#error "sorry, no 128 bit support"
#endif
};

template<int N>
struct SelectInteger : SelectImpl<bitwidth<N>()>
{
};
} // namespace detail

/**
 * selects the smallest builtin integer type that can hold N bits
 */
template<int N>
using SelectInteger_t = typename detail::SelectInteger<N>::type;
