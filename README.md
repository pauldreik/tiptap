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

## Why? What is the purpose?

I made this for fun. I had in mind to make a counter+block cipher based pseudo random number generator, to see how many rounds of AES would be needed to pass statistical randomness tests. 

It may be useful to prototype stuff - I have FPGA implementations in mind, where an LSFR should be very cheap compared to a counter. Being able to prototype in C++ is nice.

## Smaller sizes (3<=N<=64)

The class SmallLFSR implements smaller LFSRs using the builtin std::uint8_t, std::uint16_t etc. up to std::uint64_t.

The class is templated on the size, all steps between N=3 and N=64 are supported. By default, the smallest underlying type that is large enough is used.

Trying to use an excessive size or below 3 results in a compile time error.

## Larger sizes (up to N=168)

Larger LFSR is implemented in BigLFSR using a custom bignum class, adapted for this purpose. That should in theory make it faster, since the bignum class only needs to support what is needed for LFSRs, not arbitrary operations.

There is no limit on size, if the taps are known for larger N (the best I could find is [this pdf linked from wikipedia](https://web.archive.org/web/20161007061934/http://courses.cse.tamu.edu/csce680/walker/lfsr_table.pdf)), there is no problem augmenting the code.

Trying to use a size which is unsupported results in a compile time error.

## Performance ##

Benchmarks are included in the benchmark folder. Looking at a N=16 bit example using std::uint16_t, the performance is equal between the following:
 - The code snippet on wikipedia, written in C
 - The SmallLFSR class (using std::uint16_t)
 - The BigLFSR class, using C++ abstractions: a std::array and fold expressions.

The abstraction luckily melts away in the optimizer.
   
