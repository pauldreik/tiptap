# tiptap - Linear Feedback Shift Register (LFSR) in C++ 20

This is a constexpr C++ 20 header only library for implementing [LFSR](https://en.wikipedia.org/wiki/Linear-feedback_shift_register) of varying size.

The performance is on par with hand coded C.

Sizes between N=3 and N=168 are supported, plus some additional values N=512, 768, 1024, 2048,4096.

License: Boost software license 1.0

## Quick example
```cpp
#include <iostream>
#include <tiptap/lfsr.h>

int
main()
{
  constexpr std::size_t N = 4;
  BigLFSR<N> lfsr;

  const auto initial_state = lfsr.state();
  do {
    std::cout << +lfsr.state().m_data[0] << ' ';
    lfsr.next();
  } while (lfsr.state() != initial_state);
  std::cout << '\n';
}
```
The above example will output:
> 1 8 4 2 9 12 6 11 5 10 13 14 15 7 3 

This is 15 elements, which is the longest possible cycle using N=4 taps.

There are no external dependencies.

## Longer example with N=4096

This example shows a very big shift register. It deliberately uses a second optional template argument to specify the state to be built from std::uint8_t.

```cpp
#include <iostream>
#include <tiptap/lfsr.h>

int
main()
{
  constexpr std::size_t N = 4096;
  BigLFSR<N, std::uint8_t> lfsr;

  const auto initial_state = lfsr.state();
  do {
    std::cout << +lfsr.state().m_data[0] << '\n';
    lfsr.next();
  } while (lfsr.state() != initial_state);
}

```
This program takes very long to finish, the first 100 M lines took 47 seconds on my machine. It is expected to wrap around at `2**N`, which is about 1e1219 years.

## Why? What is the purpose?

I made this for fun. I had in mind to make a counter+block cipher based pseudo random number generator (see it in action at [examples/encryptedcounter.cpp](examples/encryptedcounter.cpp)), to see how many rounds of AES would be needed to pass statistical randomness tests. 

It may be useful to prototype stuff - I have FPGA implementations in mind, where an LFSR should be very cheap compared to a counter. Being able to prototype in C++ is nice.

## How it is implemented

BigLFSR uses a custom bignum class, with minimal functionality needed for this purpose. Despite it's name, it also handles smaller sizes, down to a single std::uint8_t.

There is no limit on size, if the taps are known for larger N (the best I could find is [this pdf linked from wikipedia](https://web.archive.org/web/20161007061934/http://courses.cse.tamu.edu/csce680/walker/lfsr_table.pdf)), there is no problem augmenting the code by adding to the coefficients in [include/tiptap/lfsr_coefficients.h](include/tiptap/lfsr_coefficients.h).

Trying to use a size which is unsupported results in a compile time error, there is no risk of misusing the class.

## The SmallLFSR class, alternative implementation for (3<=N<=64)

> Note: there is no performance or size benefit of SmallLFSR over BigLFSR - will maybe deprecate it in favor of BigLFSR.

The class SmallLFSR implements smaller LFSRs using the builtin std::uint8_t, std::uint16_t etc. up to std::uint64_t. There is no bignum functionality. The resulting machine code is slightly different. It may be easier to understand due to having less abstractions than the BigLFSR class.

The class is templated on the size, all steps between N=3 and N=64 are supported. By default, the smallest underlying type that is large enough is used.

Trying to use an excessive size or below 3 results in a compile time error.

## Performance ##

The abstraction provided mostly melts away in the optimizer, and the performance is on par with hand coded C. There are however knobs to tweak, since the best performance depends on N (and obviously the compiler settings, cpu etc). The classes have template parameters for the underlying storage and how the topmost bit is set during the LFSR update step.

Benchmarks are included in the benchmark folder. Looking at the case of N=16:
 - The [code snippet on wikipedia](https://en.wikipedia.org/wiki/Linear-feedback_shift_register), written in C: 1642 µs/1M iterations 
 - The BigLFSR class: 1393-2024 µs/1M iterations depending on the template parameters 
 - The SmallLFSR class: 1668-2022 µs/1M iterations depending on the template parameters

It is recommended to run the benchmark on the target system to find the optimal settings, if performance is important. See [benchmark results](benchmark/benchmark_results_N_up_to_64.ods) for performance measured with gcc 12 on a i7-10710U CPU.
   
