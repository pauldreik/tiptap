#pragma once

#include <algorithm>

#include "bignum.h"
#include "lfsr_coefficients.h"

// the size of the shift register
/**
 * LFSR for sizes N>=3
 * The data is stored in one or more limbs, this affects performance so you
 * might want to benchmark how it affects the performance for you choice of N
 * with the particular system and compiler you have. use_direct_top_bit controls
 * how the implementation sets the top bit after shift, it affects performance
 * but not functionality.
 */
template<std::size_t N,
         typename Limb = unsigned int,
         bool use_direct_top_bit = true>
class BigLFSR
{
  using State = BigNum<N, Limb>;

public:
  constexpr void next()
  {
    constexpr auto taps = getTaps<N>();
    if constexpr (use_direct_top_bit) {
      const auto topbit = m_state.parity_into_topbit(taps_to_bits(taps));
      // do the equivalent of  m_state = (m_state >> 1) | (bit << (N - 1));
      m_state.shr_one_bit(topbit);
    } else {
      const bool bit = m_state.parity(taps_to_bits(taps));
      // do the equivalent of  m_state = (m_state >> 1) | (bit << (N - 1));
      m_state.shr_one_bit(bit);
    }
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
