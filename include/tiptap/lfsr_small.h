#pragma once

#include <algorithm>

#include "integerselect.h"
#include "lfsr_coefficients.h"

/**
 * SmallLFSR is a linear feedback shift register
 * for smaller types. Small is defined as being able
 * to fit within the largest native integer the platform supports.
 */
template<std::size_t N>
class SmallLFSR
{

  using State = SelectInteger_t<N>;

  static_assert(
    std::numeric_limits<State>::digits >= N,
    "the state must be able to represent the size of the shift register");

  template<std::size_t... ints>
  constexpr int parity_impl(std::index_sequence<ints...>)
  {
    return 0x1 & ((m_state >> (N - ints)) ^ ...);
  }

public:
  constexpr void next()
  {
    // taps numbered according to LFSR convention
    const unsigned bit = parity_impl(getTaps<N>());
    using Tmp = std::common_type_t<State, unsigned>;
    m_state = (m_state >> 1) | (Tmp{ bit } << (N - 1));
  }

  /// observe the state
  constexpr State state() const { return m_state; }

private:
  State m_state = 1;
};
