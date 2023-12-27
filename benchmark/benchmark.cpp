#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <span>
#include <sstream>
#include <utility>

#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "tiptap/lfsr.h"

// list of taps
// https://datacipy.cz/lfsr_table.pdf
//
// here is a program for generating taps, it is very slow for sizes over 200:
// https://github.com/hayguen/mlpolygen

// this is from https://en.wikipedia.org/wiki/Linear-feedback_shift_register
class LFSR_wikipedia
{
public:
  LFSR_wikipedia() {}

  void next()
  {
    auto lfsr = m_state;
    /* taps: 16 14 13 11; feedback polynomial: x^16 + x^14 + x^13 + x^11 + 1 */
    auto bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1u;
    // taps:
    lfsr = (lfsr >> 1) | (bit << 15);
    m_state = lfsr;
  }

  /// observe the state
  std::uint16_t state() const { return m_state; }

private:
  std::uint16_t m_state = 1;
};

class Counter
{
public:
  Counter() {}

  void next() { ++m_state; }

  /// observe the state
  std::uint16_t state() const { return m_state; }

private:
  std::uint16_t m_state = 1;
};

/// something more complicated than a counter, to have something to compare with
class Fnv1a
{
public:
  Fnv1a() {}

  void next()
  {
    const char* ptr = reinterpret_cast<const char*>(&m_counter);
    for (int i = 0; i < 4; ++i) {
      m_state ^= *ptr++;
      m_state *= 0x01000193;
    }
    ++m_counter;
  }

  /// observe the state
  std::uint32_t state() const { return m_state; }

private:
  std::uint32_t m_counter{};
  std::uint32_t m_state = 0x811c9dc5;
};

std::uint32_t
Fnva1aHash(std::span<const char> data)
{
  std::uint32_t state = 0x811c9dc5;
  for (const auto d : data) {
    state ^= d;
    state *= 0x01000193;
  }
  return state;
}

template<typename LFSR>
unsigned
run_impl()
{
  LFSR x;
  const std::uint32_t maxreps = 1'000'000;
  for (std::uint32_t i = 0; i < maxreps; ++i) {
    x.next();
  }
  // return the hash of the state, to make it more difficult for the optimizer
  // to remove it
  const auto tmp = x.state();
  const auto* ptr = reinterpret_cast<const char*>(&tmp);
  return Fnva1aHash(std::span<const char>(ptr, ptr + sizeof(tmp)));
}

TEST_CASE("benchmark small LFSR")
{
  BENCHMARK("simple_counter")
  {
    return run_impl<Counter>();
  };
  BENCHMARK("32 bit fnv1a of counter")
  {
    return run_impl<Fnv1a>();
  };
  BENCHMARK("wikipedia 16bit LFSR")
  {
    return run_impl<LFSR_wikipedia>();
  };
  BENCHMARK("SmallLFSR<16>")
  {
    return run_impl<SmallLFSR<16>>();
  };
  BENCHMARK("SmallLFSR<32>")
  {
    return run_impl<SmallLFSR<32>>();
  };
  BENCHMARK("SmallLFSR<64>")
  {
    return run_impl<SmallLFSR<64>>();
  };
}

TEST_CASE("benchmark big 16 bit LFSR")
{
  BENCHMARK("BigLFSR<16, std::uint8_t>")
  {
    return run_impl<BigLFSR<16, std::uint8_t>>();
  };
  BENCHMARK("BigLFSR<16, std::uint16_t>")
  {
    return run_impl<BigLFSR<16, std::uint16_t>>();
  };
  BENCHMARK("BigLFSR<16, std::uint32_t>")
  {
    return run_impl<BigLFSR<16, std::uint32_t>>();
  };
  BENCHMARK("BigLFSR<16, std::uint64_t>")
  {
    return run_impl<BigLFSR<16, std::uint64_t>>();
  };
}

TEST_CASE("benchmark big 32 bit LFSR")
{
  BENCHMARK("BigLFSR<32, std::uint8_t>")
  {
    return run_impl<BigLFSR<32, std::uint8_t>>();
  };
  BENCHMARK("BigLFSR<32, std::uint16_t>")
  {
    return run_impl<BigLFSR<32, std::uint16_t>>();
  };
  BENCHMARK("BigLFSR<32, std::uint32_t>")
  {
    return run_impl<BigLFSR<32, std::uint32_t>>();
  };
  BENCHMARK("BigLFSR<32, std::uint64_t>")
  {
    return run_impl<BigLFSR<32, std::uint64_t>>();
  };
}

TEST_CASE("benchmark big 64 bit LFSR")
{
  BENCHMARK("BigLFSR<64, std::uint8_t>")
  {
    return run_impl<BigLFSR<64, std::uint8_t>>();
  };
  BENCHMARK("BigLFSR<64, std::uint16_t>")
  {
    return run_impl<BigLFSR<64, std::uint16_t>>();
  };
  BENCHMARK("BigLFSR<64, std::uint32_t>")
  {
    return run_impl<BigLFSR<64, std::uint32_t>>();
  };
  BENCHMARK("BigLFSR<64, std::uint64_t>")
  {
    return run_impl<BigLFSR<64, std::uint64_t>>();
  };
}

TEST_CASE("benchmark big 168 bit LFSR")
{
  BENCHMARK("BigLFSR<168, std::uint8_t>")
  {
    return run_impl<BigLFSR<168, std::uint8_t>>();
  };
  BENCHMARK("BigLFSR<168, std::uint16_t>")
  {
    return run_impl<BigLFSR<168, std::uint16_t>>();
  };
  BENCHMARK("BigLFSR<168, std::uint32_t>")
  {
    return run_impl<BigLFSR<168, std::uint32_t>>();
  };
  BENCHMARK("BigLFSR<168, std::uint64_t>")
  {
    return run_impl<BigLFSR<168, std::uint64_t>>();
  };
}

TEST_CASE("N=16 shootout")
{
  BENCHMARK("BigLFSR<16, std::uint8_t, false> (blah)")
  {
    return run_impl<BigLFSR<16, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<16, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<16, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<16, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<16, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<16, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<16, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<16, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<16, std::uint64_t, false>>();
  };
  BENCHMARK("BigLFSR<16, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<16, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<16, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<16, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<16, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<16, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<16, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<16, std::uint64_t, true>>();
  };
  BENCHMARK("wikipedia 16bit LFSR")
  {
    return run_impl<LFSR_wikipedia>();
  };

  BENCHMARK("SmallLFSR<16,true,std::uint16_t>")
  {
    return run_impl<SmallLFSR<16, true, std::uint16_t>>();
  };
  BENCHMARK("SmallLFSR<16,false,std::uint16_t>")
  {
    return run_impl<SmallLFSR<16, false, std::uint16_t>>();
  };

  BENCHMARK("SmallLFSR<16,true,std::uint32_t>")
  {
    return run_impl<SmallLFSR<16, true, std::uint32_t>>();
  };
  BENCHMARK("SmallLFSR<16,false,std::uint32_t>")
  {
    return run_impl<SmallLFSR<16, false, std::uint32_t>>();
  };

  BENCHMARK("SmallLFSR<16,true,std::uint64_t>")
  {
    return run_impl<SmallLFSR<16, true, std::uint64_t>>();
  };
  BENCHMARK("SmallLFSR<16,false,std::uint64_t>")
  {
    return run_impl<SmallLFSR<16, false, std::uint64_t>>();
  };
}

TEST_CASE("N=32 shootout")
{
  BENCHMARK("BigLFSR<32, std::uint8_t>")
  {
    return run_impl<BigLFSR<32, std::uint8_t>>();
  };
  BENCHMARK("BigLFSR<32, std::uint16_t>")
  {
    return run_impl<BigLFSR<32, std::uint16_t>>();
  };
  BENCHMARK("BigLFSR<32, std::uint32_t>")
  {
    return run_impl<BigLFSR<32, std::uint32_t>>();
  };
  BENCHMARK("BigLFSR<32, std::uint64_t>")
  {
    return run_impl<BigLFSR<32, std::uint64_t>>();
  };
  BENCHMARK("SmallLFSR<32>")
  {
    return run_impl<SmallLFSR<32>>();
  };
}

TEST_CASE("N=64 shootout")
{
  BENCHMARK("BigLFSR<64, std::uint8_t>")
  {
    return run_impl<BigLFSR<64, std::uint8_t>>();
  };
  BENCHMARK("BigLFSR<64, std::uint16_t>")
  {
    return run_impl<BigLFSR<64, std::uint16_t>>();
  };
  BENCHMARK("BigLFSR<64, std::uint32_t>")
  {
    return run_impl<BigLFSR<64, std::uint32_t>>();
  };
  BENCHMARK("BigLFSR<64, std::uint64_t>")
  {
    return run_impl<BigLFSR<64, std::uint64_t>>();
  };
  BENCHMARK("SmallLFSR<64>")
  {
    return run_impl<SmallLFSR<64>>();
  };
}

TEST_CASE("alternative implementation of small")
{
  BENCHMARK("SmallLFSR<64,true>")
  {
    return run_impl<SmallLFSR<64, true>>();
  };
  BENCHMARK("SmallLFSR<64,false>")
  {
    return run_impl<SmallLFSR<64, false>>();
  };
  BENCHMARK("SmallLFSR<45,true>")
  {
    return run_impl<SmallLFSR<45, true>>();
  };
  BENCHMARK("SmallLFSR<45,false>")
  {
    return run_impl<SmallLFSR<45, false>>();
  };
  BENCHMARK("SmallLFSR<13,true>")
  {
    return run_impl<SmallLFSR<13, true>>();
  };
  BENCHMARK("SmallLFSR<13,false>")
  {
    return run_impl<SmallLFSR<13, false>>();
  };
  BENCHMARK("SmallLFSR<32,true>")
  {
    return run_impl<SmallLFSR<32, true>>();
  };
  BENCHMARK("SmallLFSR<32,false>")
  {
    return run_impl<SmallLFSR<32, false>>();
  };
}
