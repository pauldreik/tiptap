# tiptap - Linear Feedback Shift Register (LFSR) in C++ 20

This is a constexpr C++ 20 library for implementing [LFSR](https://en.wikipedia.org/wiki/Linear-feedback_shift_register) of varying size.

## Quick example
```cpp
#include <iostream>
#include <tiptap/lfsr.h>

int
main()
{
  constexpr std::size_t N = 4;
  SmallLFSR<N> lfsr;

  const auto initial_state = lfsr.state();
  do {
    std::cout << +lfsr.state() << ' ';
    lfsr.next();
  } while (lfsr.state() != initial_state);
  std::cout << '\n';
}

```
The above example will output:
> 1 8 4 2 9 12 6 11 5 10 13 14 15 7 3 

This is 15 elements, which is the longest cycle using N=4 taps.

There are no external dependencies.

License: Boost software license 1.0

## Smaller sizes (3<=N<=64)

The class SmallLFSR implements smaller LFSRs using the builtin std::uint8_t, std::uint16_t etc. up to std::uint64_t.

The class is templated on the size, all steps between N=3 and N=64 are supported. By default, the smallest underlying type that is large enough is used.

## Larger sizes (up to N=168)

Larger LFSR is implemented with a custom bignum class, adapted for this purpose. That should in theory make it faster, since the bignum class only needs to support what is needed for LFSRs, not arbitrary operations.
