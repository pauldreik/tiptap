#pragma once

#include <algorithm>

#include "integerselect.h"
#include "lfsr_coefficients.h"
#include "vectorclass.h"

template<std::size_t N, bool use_direct_top_bit = true>
class VectorLFSR
{

  using State = Vec4ui;
  using Element = decltype(std::declval<State>()[0]);

  static_assert(
    std::numeric_limits<Element>::digits >= N,
    "the state must be able to represent the size of the shift register");

  template<std::size_t... taps>
  constexpr State parity_impl(std::index_sequence<taps...>)
  {
    // this shifts everything to the bottom bit:
    return 0x1 & ((m_state >> int(N - taps)) ^ ...);
  }

  /// this calculates the parity of the bits at the taps position,
  /// and places the result in the topmost bit
  /// taps are numbered according to LFSR convention
  template<std::size_t... taps>
  constexpr State put_parity_in_top_bit(std::index_sequence<taps...>)
  {
    const State topbitmask = (1ULL << (N - 1));

    // the zero indexed bit is (N-taps). If we right shift it to the bottom bit
    // with (N-taps), we need it shifted left (N-1) to end up at the top bit.
    // (N-taps)-(N-1) is equal to left shift (N-1)-(N-taps) == taps-1
    return topbitmask & ((m_state << int(taps - 1)) ^ ...);
  }

public:
  constexpr void next()
  {
    if constexpr (use_direct_top_bit) {
      m_state = (m_state >> 1) | put_parity_in_top_bit(getTaps<N>());
    } else {
      m_state = (m_state >> 1) | (parity_impl(getTaps<N>()) << int(N - 1));
    }
  }

  /// observe the state
  constexpr State state() const { return m_state; }

private:
  State m_state = 1;
};
