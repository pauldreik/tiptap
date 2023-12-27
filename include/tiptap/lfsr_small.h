#pragma once

#include <algorithm>

#include "integerselect.h"
#include "lfsr_coefficients.h"

/**
 * SmallLFSR is a linear feedback shift register
 * for smaller types. Small is defined as being able
 * to fit within the largest native integer the platform supports.
 *
 * N is the LSFR size.
 * use_direct_top_bit is an implementation detail, leading to slightly
 * different code gen. seems like use_direct_top_bit gives zero to 15%
 * boost depending on N.
 * State is the underlying type to use, default is to use an unsigned integer
 * the smallest size possible.
 */
template<std::size_t N,
         bool use_direct_top_bit = true,
         typename State = SelectInteger_t<N>>
class SmallLFSR
{
  /// State, after integer promotion
  using PromotedState = std::common_type_t<State, unsigned>;

  static_assert(
    std::numeric_limits<State>::digits >= N,
    "the state must be able to represent the size of the shift register");

  /// this calculates the parity of the bits at the taps position,
  /// and places the result in the bottom bit
  /// taps are numbered according to LFSR convention
  template<std::size_t... taps>
  constexpr PromotedState parity_impl(std::index_sequence<taps...>)
  {
    // this shifts everything to the bottom bit:
    return 0x1 & ((m_state >> (N - taps)) ^ ...);
  }

  /// this calculates the parity of the bits at the taps position,
  /// and places the result in the topmost bit
  /// taps are numbered according to LFSR convention
  template<std::size_t... taps>
  constexpr PromotedState put_parity_in_top_bit(std::index_sequence<taps...>)
  {
    constexpr State topbitmask = (1ULL << (N - 1));

    // the zero indexed bit is (N-taps). If we right shift it to the bottom bit
    // with (N-taps), we need it shifted left (N-1) to end up at the top bit.
    // (N-taps)-(N-1) is equal to left shift (N-1)-(N-taps) == taps-1
    return topbitmask & ((m_state << (taps - 1)) ^ ...);
  }

public:
  constexpr void next()
  {
    if constexpr (use_direct_top_bit) {
      // this leads to different codegen and is 0-15% faster
      m_state = (m_state >> 1) | put_parity_in_top_bit(getTaps<N>());
    } else {
      m_state = (m_state >> 1) | (parity_impl(getTaps<N>()) << (N - 1));
    }
  }

  /// observe the state
  constexpr State state() const { return m_state; }

private:
  State m_state = 1;
};
