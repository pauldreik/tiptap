#pragma once

#include <algorithm>

#include "bignum.h"
#include "lfsr_coefficients.h"

// the size of the shift register
template<std::size_t N, typename Limb = unsigned int>
class BigLFSR
{

  using State = BigNum<N, Limb>;

public:
  constexpr void next()
  {
    constexpr auto taps = getTaps<N>();
    const auto bit = m_state.parity(taps_to_bits(taps));
    // do the equivalent of  m_state = (m_state >> 1) | (bit << (N - 1));
    m_state.shr_one_bit(bit);
  }

  /// observe the state
  constexpr State state() const { return m_state; }

private:
  template<std::size_t... ints>
  static constexpr auto taps_to_bits(std::index_sequence<ints...>)
  {
    return std::index_sequence<(N - ints)...>{};
  }
  State m_state{ 1 };
};
