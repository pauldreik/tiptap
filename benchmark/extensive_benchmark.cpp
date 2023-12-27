#include <cstdint>
#include <span>

#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "tiptap/lfsr.h"

namespace {
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

}

TEST_CASE("N=3")
{
  BENCHMARK("SmallLFSR<3, true>")
  {
    return run_impl<SmallLFSR<3, true>>();
  };
  BENCHMARK("SmallLFSR<3, false>")
  {
    return run_impl<SmallLFSR<3, false>>();
  };
  BENCHMARK("BigLFSR<3, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<3, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<3, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<3, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<3, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<3, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<3, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<3, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<3, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<3, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<3, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<3, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<3, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<3, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<3, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<3, std::uint64_t, false>>();
  };
} // end of N=3

TEST_CASE("N=4")
{
  BENCHMARK("SmallLFSR<4, true>")
  {
    return run_impl<SmallLFSR<4, true>>();
  };
  BENCHMARK("SmallLFSR<4, false>")
  {
    return run_impl<SmallLFSR<4, false>>();
  };
  BENCHMARK("BigLFSR<4, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<4, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<4, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<4, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<4, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<4, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<4, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<4, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<4, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<4, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<4, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<4, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<4, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<4, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<4, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<4, std::uint64_t, false>>();
  };
} // end of N=4

TEST_CASE("N=5")
{
  BENCHMARK("SmallLFSR<5, true>")
  {
    return run_impl<SmallLFSR<5, true>>();
  };
  BENCHMARK("SmallLFSR<5, false>")
  {
    return run_impl<SmallLFSR<5, false>>();
  };
  BENCHMARK("BigLFSR<5, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<5, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<5, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<5, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<5, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<5, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<5, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<5, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<5, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<5, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<5, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<5, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<5, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<5, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<5, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<5, std::uint64_t, false>>();
  };
} // end of N=5

TEST_CASE("N=6")
{
  BENCHMARK("SmallLFSR<6, true>")
  {
    return run_impl<SmallLFSR<6, true>>();
  };
  BENCHMARK("SmallLFSR<6, false>")
  {
    return run_impl<SmallLFSR<6, false>>();
  };
  BENCHMARK("BigLFSR<6, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<6, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<6, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<6, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<6, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<6, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<6, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<6, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<6, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<6, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<6, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<6, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<6, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<6, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<6, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<6, std::uint64_t, false>>();
  };
} // end of N=6

TEST_CASE("N=7")
{
  BENCHMARK("SmallLFSR<7, true>")
  {
    return run_impl<SmallLFSR<7, true>>();
  };
  BENCHMARK("SmallLFSR<7, false>")
  {
    return run_impl<SmallLFSR<7, false>>();
  };
  BENCHMARK("BigLFSR<7, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<7, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<7, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<7, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<7, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<7, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<7, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<7, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<7, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<7, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<7, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<7, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<7, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<7, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<7, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<7, std::uint64_t, false>>();
  };
} // end of N=7

TEST_CASE("N=8")
{
  BENCHMARK("SmallLFSR<8, true>")
  {
    return run_impl<SmallLFSR<8, true>>();
  };
  BENCHMARK("SmallLFSR<8, false>")
  {
    return run_impl<SmallLFSR<8, false>>();
  };
  BENCHMARK("BigLFSR<8, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<8, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<8, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<8, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<8, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<8, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<8, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<8, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<8, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<8, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<8, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<8, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<8, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<8, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<8, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<8, std::uint64_t, false>>();
  };
} // end of N=8

TEST_CASE("N=9")
{
  BENCHMARK("SmallLFSR<9, true>")
  {
    return run_impl<SmallLFSR<9, true>>();
  };
  BENCHMARK("SmallLFSR<9, false>")
  {
    return run_impl<SmallLFSR<9, false>>();
  };
  BENCHMARK("BigLFSR<9, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<9, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<9, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<9, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<9, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<9, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<9, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<9, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<9, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<9, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<9, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<9, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<9, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<9, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<9, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<9, std::uint64_t, false>>();
  };
} // end of N=9

TEST_CASE("N=10")
{
  BENCHMARK("SmallLFSR<10, true>")
  {
    return run_impl<SmallLFSR<10, true>>();
  };
  BENCHMARK("SmallLFSR<10, false>")
  {
    return run_impl<SmallLFSR<10, false>>();
  };
  BENCHMARK("BigLFSR<10, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<10, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<10, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<10, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<10, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<10, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<10, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<10, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<10, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<10, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<10, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<10, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<10, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<10, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<10, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<10, std::uint64_t, false>>();
  };
} // end of N=10

TEST_CASE("N=11")
{
  BENCHMARK("SmallLFSR<11, true>")
  {
    return run_impl<SmallLFSR<11, true>>();
  };
  BENCHMARK("SmallLFSR<11, false>")
  {
    return run_impl<SmallLFSR<11, false>>();
  };
  BENCHMARK("BigLFSR<11, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<11, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<11, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<11, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<11, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<11, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<11, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<11, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<11, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<11, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<11, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<11, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<11, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<11, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<11, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<11, std::uint64_t, false>>();
  };
} // end of N=11

TEST_CASE("N=12")
{
  BENCHMARK("SmallLFSR<12, true>")
  {
    return run_impl<SmallLFSR<12, true>>();
  };
  BENCHMARK("SmallLFSR<12, false>")
  {
    return run_impl<SmallLFSR<12, false>>();
  };
  BENCHMARK("BigLFSR<12, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<12, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<12, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<12, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<12, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<12, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<12, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<12, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<12, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<12, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<12, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<12, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<12, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<12, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<12, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<12, std::uint64_t, false>>();
  };
} // end of N=12

TEST_CASE("N=13")
{
  BENCHMARK("SmallLFSR<13, true>")
  {
    return run_impl<SmallLFSR<13, true>>();
  };
  BENCHMARK("SmallLFSR<13, false>")
  {
    return run_impl<SmallLFSR<13, false>>();
  };
  BENCHMARK("BigLFSR<13, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<13, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<13, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<13, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<13, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<13, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<13, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<13, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<13, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<13, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<13, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<13, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<13, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<13, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<13, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<13, std::uint64_t, false>>();
  };
} // end of N=13

TEST_CASE("N=14")
{
  BENCHMARK("SmallLFSR<14, true>")
  {
    return run_impl<SmallLFSR<14, true>>();
  };
  BENCHMARK("SmallLFSR<14, false>")
  {
    return run_impl<SmallLFSR<14, false>>();
  };
  BENCHMARK("BigLFSR<14, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<14, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<14, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<14, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<14, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<14, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<14, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<14, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<14, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<14, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<14, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<14, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<14, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<14, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<14, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<14, std::uint64_t, false>>();
  };
} // end of N=14

TEST_CASE("N=15")
{
  BENCHMARK("SmallLFSR<15, true>")
  {
    return run_impl<SmallLFSR<15, true>>();
  };
  BENCHMARK("SmallLFSR<15, false>")
  {
    return run_impl<SmallLFSR<15, false>>();
  };
  BENCHMARK("BigLFSR<15, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<15, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<15, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<15, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<15, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<15, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<15, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<15, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<15, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<15, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<15, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<15, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<15, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<15, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<15, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<15, std::uint64_t, false>>();
  };
} // end of N=15

TEST_CASE("N=16")
{
  BENCHMARK("SmallLFSR<16, true>")
  {
    return run_impl<SmallLFSR<16, true>>();
  };
  BENCHMARK("SmallLFSR<16, false>")
  {
    return run_impl<SmallLFSR<16, false>>();
  };
  BENCHMARK("BigLFSR<16, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<16, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<16, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<16, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<16, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<16, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<16, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<16, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<16, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<16, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<16, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<16, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<16, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<16, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<16, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<16, std::uint64_t, false>>();
  };
} // end of N=16

TEST_CASE("N=17")
{
  BENCHMARK("SmallLFSR<17, true>")
  {
    return run_impl<SmallLFSR<17, true>>();
  };
  BENCHMARK("SmallLFSR<17, false>")
  {
    return run_impl<SmallLFSR<17, false>>();
  };
  BENCHMARK("BigLFSR<17, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<17, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<17, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<17, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<17, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<17, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<17, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<17, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<17, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<17, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<17, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<17, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<17, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<17, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<17, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<17, std::uint64_t, false>>();
  };
} // end of N=17

TEST_CASE("N=18")
{
  BENCHMARK("SmallLFSR<18, true>")
  {
    return run_impl<SmallLFSR<18, true>>();
  };
  BENCHMARK("SmallLFSR<18, false>")
  {
    return run_impl<SmallLFSR<18, false>>();
  };
  BENCHMARK("BigLFSR<18, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<18, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<18, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<18, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<18, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<18, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<18, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<18, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<18, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<18, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<18, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<18, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<18, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<18, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<18, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<18, std::uint64_t, false>>();
  };
} // end of N=18

TEST_CASE("N=19")
{
  BENCHMARK("SmallLFSR<19, true>")
  {
    return run_impl<SmallLFSR<19, true>>();
  };
  BENCHMARK("SmallLFSR<19, false>")
  {
    return run_impl<SmallLFSR<19, false>>();
  };
  BENCHMARK("BigLFSR<19, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<19, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<19, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<19, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<19, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<19, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<19, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<19, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<19, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<19, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<19, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<19, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<19, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<19, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<19, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<19, std::uint64_t, false>>();
  };
} // end of N=19

TEST_CASE("N=20")
{
  BENCHMARK("SmallLFSR<20, true>")
  {
    return run_impl<SmallLFSR<20, true>>();
  };
  BENCHMARK("SmallLFSR<20, false>")
  {
    return run_impl<SmallLFSR<20, false>>();
  };
  BENCHMARK("BigLFSR<20, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<20, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<20, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<20, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<20, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<20, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<20, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<20, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<20, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<20, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<20, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<20, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<20, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<20, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<20, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<20, std::uint64_t, false>>();
  };
} // end of N=20

TEST_CASE("N=21")
{
  BENCHMARK("SmallLFSR<21, true>")
  {
    return run_impl<SmallLFSR<21, true>>();
  };
  BENCHMARK("SmallLFSR<21, false>")
  {
    return run_impl<SmallLFSR<21, false>>();
  };
  BENCHMARK("BigLFSR<21, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<21, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<21, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<21, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<21, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<21, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<21, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<21, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<21, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<21, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<21, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<21, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<21, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<21, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<21, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<21, std::uint64_t, false>>();
  };
} // end of N=21

TEST_CASE("N=22")
{
  BENCHMARK("SmallLFSR<22, true>")
  {
    return run_impl<SmallLFSR<22, true>>();
  };
  BENCHMARK("SmallLFSR<22, false>")
  {
    return run_impl<SmallLFSR<22, false>>();
  };
  BENCHMARK("BigLFSR<22, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<22, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<22, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<22, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<22, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<22, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<22, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<22, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<22, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<22, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<22, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<22, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<22, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<22, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<22, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<22, std::uint64_t, false>>();
  };
} // end of N=22

TEST_CASE("N=23")
{
  BENCHMARK("SmallLFSR<23, true>")
  {
    return run_impl<SmallLFSR<23, true>>();
  };
  BENCHMARK("SmallLFSR<23, false>")
  {
    return run_impl<SmallLFSR<23, false>>();
  };
  BENCHMARK("BigLFSR<23, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<23, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<23, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<23, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<23, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<23, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<23, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<23, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<23, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<23, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<23, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<23, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<23, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<23, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<23, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<23, std::uint64_t, false>>();
  };
} // end of N=23

TEST_CASE("N=24")
{
  BENCHMARK("SmallLFSR<24, true>")
  {
    return run_impl<SmallLFSR<24, true>>();
  };
  BENCHMARK("SmallLFSR<24, false>")
  {
    return run_impl<SmallLFSR<24, false>>();
  };
  BENCHMARK("BigLFSR<24, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<24, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<24, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<24, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<24, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<24, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<24, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<24, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<24, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<24, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<24, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<24, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<24, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<24, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<24, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<24, std::uint64_t, false>>();
  };
} // end of N=24

TEST_CASE("N=25")
{
  BENCHMARK("SmallLFSR<25, true>")
  {
    return run_impl<SmallLFSR<25, true>>();
  };
  BENCHMARK("SmallLFSR<25, false>")
  {
    return run_impl<SmallLFSR<25, false>>();
  };
  BENCHMARK("BigLFSR<25, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<25, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<25, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<25, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<25, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<25, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<25, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<25, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<25, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<25, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<25, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<25, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<25, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<25, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<25, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<25, std::uint64_t, false>>();
  };
} // end of N=25

TEST_CASE("N=26")
{
  BENCHMARK("SmallLFSR<26, true>")
  {
    return run_impl<SmallLFSR<26, true>>();
  };
  BENCHMARK("SmallLFSR<26, false>")
  {
    return run_impl<SmallLFSR<26, false>>();
  };
  BENCHMARK("BigLFSR<26, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<26, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<26, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<26, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<26, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<26, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<26, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<26, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<26, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<26, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<26, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<26, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<26, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<26, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<26, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<26, std::uint64_t, false>>();
  };
} // end of N=26

TEST_CASE("N=27")
{
  BENCHMARK("SmallLFSR<27, true>")
  {
    return run_impl<SmallLFSR<27, true>>();
  };
  BENCHMARK("SmallLFSR<27, false>")
  {
    return run_impl<SmallLFSR<27, false>>();
  };
  BENCHMARK("BigLFSR<27, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<27, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<27, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<27, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<27, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<27, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<27, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<27, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<27, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<27, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<27, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<27, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<27, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<27, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<27, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<27, std::uint64_t, false>>();
  };
} // end of N=27

TEST_CASE("N=28")
{
  BENCHMARK("SmallLFSR<28, true>")
  {
    return run_impl<SmallLFSR<28, true>>();
  };
  BENCHMARK("SmallLFSR<28, false>")
  {
    return run_impl<SmallLFSR<28, false>>();
  };
  BENCHMARK("BigLFSR<28, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<28, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<28, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<28, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<28, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<28, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<28, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<28, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<28, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<28, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<28, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<28, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<28, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<28, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<28, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<28, std::uint64_t, false>>();
  };
} // end of N=28

TEST_CASE("N=29")
{
  BENCHMARK("SmallLFSR<29, true>")
  {
    return run_impl<SmallLFSR<29, true>>();
  };
  BENCHMARK("SmallLFSR<29, false>")
  {
    return run_impl<SmallLFSR<29, false>>();
  };
  BENCHMARK("BigLFSR<29, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<29, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<29, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<29, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<29, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<29, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<29, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<29, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<29, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<29, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<29, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<29, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<29, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<29, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<29, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<29, std::uint64_t, false>>();
  };
} // end of N=29

TEST_CASE("N=30")
{
  BENCHMARK("SmallLFSR<30, true>")
  {
    return run_impl<SmallLFSR<30, true>>();
  };
  BENCHMARK("SmallLFSR<30, false>")
  {
    return run_impl<SmallLFSR<30, false>>();
  };
  BENCHMARK("BigLFSR<30, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<30, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<30, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<30, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<30, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<30, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<30, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<30, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<30, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<30, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<30, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<30, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<30, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<30, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<30, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<30, std::uint64_t, false>>();
  };
} // end of N=30

TEST_CASE("N=31")
{
  BENCHMARK("SmallLFSR<31, true>")
  {
    return run_impl<SmallLFSR<31, true>>();
  };
  BENCHMARK("SmallLFSR<31, false>")
  {
    return run_impl<SmallLFSR<31, false>>();
  };
  BENCHMARK("BigLFSR<31, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<31, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<31, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<31, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<31, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<31, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<31, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<31, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<31, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<31, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<31, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<31, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<31, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<31, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<31, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<31, std::uint64_t, false>>();
  };
} // end of N=31

TEST_CASE("N=32")
{
  BENCHMARK("SmallLFSR<32, true>")
  {
    return run_impl<SmallLFSR<32, true>>();
  };
  BENCHMARK("SmallLFSR<32, false>")
  {
    return run_impl<SmallLFSR<32, false>>();
  };
  BENCHMARK("BigLFSR<32, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<32, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<32, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<32, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<32, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<32, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<32, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<32, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<32, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<32, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<32, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<32, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<32, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<32, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<32, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<32, std::uint64_t, false>>();
  };
} // end of N=32

TEST_CASE("N=33")
{
  BENCHMARK("SmallLFSR<33, true>")
  {
    return run_impl<SmallLFSR<33, true>>();
  };
  BENCHMARK("SmallLFSR<33, false>")
  {
    return run_impl<SmallLFSR<33, false>>();
  };
  BENCHMARK("BigLFSR<33, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<33, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<33, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<33, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<33, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<33, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<33, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<33, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<33, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<33, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<33, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<33, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<33, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<33, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<33, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<33, std::uint64_t, false>>();
  };
} // end of N=33

TEST_CASE("N=34")
{
  BENCHMARK("SmallLFSR<34, true>")
  {
    return run_impl<SmallLFSR<34, true>>();
  };
  BENCHMARK("SmallLFSR<34, false>")
  {
    return run_impl<SmallLFSR<34, false>>();
  };
  BENCHMARK("BigLFSR<34, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<34, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<34, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<34, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<34, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<34, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<34, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<34, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<34, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<34, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<34, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<34, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<34, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<34, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<34, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<34, std::uint64_t, false>>();
  };
} // end of N=34

TEST_CASE("N=35")
{
  BENCHMARK("SmallLFSR<35, true>")
  {
    return run_impl<SmallLFSR<35, true>>();
  };
  BENCHMARK("SmallLFSR<35, false>")
  {
    return run_impl<SmallLFSR<35, false>>();
  };
  BENCHMARK("BigLFSR<35, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<35, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<35, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<35, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<35, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<35, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<35, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<35, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<35, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<35, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<35, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<35, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<35, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<35, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<35, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<35, std::uint64_t, false>>();
  };
} // end of N=35

TEST_CASE("N=36")
{
  BENCHMARK("SmallLFSR<36, true>")
  {
    return run_impl<SmallLFSR<36, true>>();
  };
  BENCHMARK("SmallLFSR<36, false>")
  {
    return run_impl<SmallLFSR<36, false>>();
  };
  BENCHMARK("BigLFSR<36, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<36, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<36, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<36, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<36, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<36, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<36, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<36, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<36, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<36, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<36, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<36, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<36, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<36, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<36, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<36, std::uint64_t, false>>();
  };
} // end of N=36

TEST_CASE("N=37")
{
  BENCHMARK("SmallLFSR<37, true>")
  {
    return run_impl<SmallLFSR<37, true>>();
  };
  BENCHMARK("SmallLFSR<37, false>")
  {
    return run_impl<SmallLFSR<37, false>>();
  };
  BENCHMARK("BigLFSR<37, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<37, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<37, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<37, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<37, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<37, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<37, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<37, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<37, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<37, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<37, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<37, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<37, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<37, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<37, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<37, std::uint64_t, false>>();
  };
} // end of N=37

TEST_CASE("N=38")
{
  BENCHMARK("SmallLFSR<38, true>")
  {
    return run_impl<SmallLFSR<38, true>>();
  };
  BENCHMARK("SmallLFSR<38, false>")
  {
    return run_impl<SmallLFSR<38, false>>();
  };
  BENCHMARK("BigLFSR<38, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<38, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<38, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<38, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<38, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<38, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<38, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<38, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<38, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<38, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<38, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<38, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<38, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<38, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<38, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<38, std::uint64_t, false>>();
  };
} // end of N=38

TEST_CASE("N=39")
{
  BENCHMARK("SmallLFSR<39, true>")
  {
    return run_impl<SmallLFSR<39, true>>();
  };
  BENCHMARK("SmallLFSR<39, false>")
  {
    return run_impl<SmallLFSR<39, false>>();
  };
  BENCHMARK("BigLFSR<39, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<39, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<39, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<39, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<39, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<39, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<39, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<39, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<39, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<39, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<39, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<39, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<39, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<39, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<39, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<39, std::uint64_t, false>>();
  };
} // end of N=39

TEST_CASE("N=40")
{
  BENCHMARK("SmallLFSR<40, true>")
  {
    return run_impl<SmallLFSR<40, true>>();
  };
  BENCHMARK("SmallLFSR<40, false>")
  {
    return run_impl<SmallLFSR<40, false>>();
  };
  BENCHMARK("BigLFSR<40, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<40, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<40, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<40, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<40, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<40, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<40, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<40, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<40, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<40, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<40, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<40, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<40, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<40, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<40, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<40, std::uint64_t, false>>();
  };
} // end of N=40

TEST_CASE("N=41")
{
  BENCHMARK("SmallLFSR<41, true>")
  {
    return run_impl<SmallLFSR<41, true>>();
  };
  BENCHMARK("SmallLFSR<41, false>")
  {
    return run_impl<SmallLFSR<41, false>>();
  };
  BENCHMARK("BigLFSR<41, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<41, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<41, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<41, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<41, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<41, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<41, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<41, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<41, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<41, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<41, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<41, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<41, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<41, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<41, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<41, std::uint64_t, false>>();
  };
} // end of N=41

TEST_CASE("N=42")
{
  BENCHMARK("SmallLFSR<42, true>")
  {
    return run_impl<SmallLFSR<42, true>>();
  };
  BENCHMARK("SmallLFSR<42, false>")
  {
    return run_impl<SmallLFSR<42, false>>();
  };
  BENCHMARK("BigLFSR<42, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<42, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<42, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<42, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<42, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<42, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<42, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<42, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<42, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<42, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<42, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<42, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<42, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<42, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<42, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<42, std::uint64_t, false>>();
  };
} // end of N=42

TEST_CASE("N=43")
{
  BENCHMARK("SmallLFSR<43, true>")
  {
    return run_impl<SmallLFSR<43, true>>();
  };
  BENCHMARK("SmallLFSR<43, false>")
  {
    return run_impl<SmallLFSR<43, false>>();
  };
  BENCHMARK("BigLFSR<43, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<43, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<43, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<43, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<43, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<43, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<43, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<43, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<43, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<43, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<43, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<43, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<43, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<43, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<43, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<43, std::uint64_t, false>>();
  };
} // end of N=43

TEST_CASE("N=44")
{
  BENCHMARK("SmallLFSR<44, true>")
  {
    return run_impl<SmallLFSR<44, true>>();
  };
  BENCHMARK("SmallLFSR<44, false>")
  {
    return run_impl<SmallLFSR<44, false>>();
  };
  BENCHMARK("BigLFSR<44, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<44, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<44, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<44, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<44, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<44, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<44, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<44, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<44, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<44, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<44, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<44, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<44, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<44, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<44, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<44, std::uint64_t, false>>();
  };
} // end of N=44

TEST_CASE("N=45")
{
  BENCHMARK("SmallLFSR<45, true>")
  {
    return run_impl<SmallLFSR<45, true>>();
  };
  BENCHMARK("SmallLFSR<45, false>")
  {
    return run_impl<SmallLFSR<45, false>>();
  };
  BENCHMARK("BigLFSR<45, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<45, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<45, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<45, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<45, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<45, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<45, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<45, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<45, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<45, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<45, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<45, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<45, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<45, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<45, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<45, std::uint64_t, false>>();
  };
} // end of N=45

TEST_CASE("N=46")
{
  BENCHMARK("SmallLFSR<46, true>")
  {
    return run_impl<SmallLFSR<46, true>>();
  };
  BENCHMARK("SmallLFSR<46, false>")
  {
    return run_impl<SmallLFSR<46, false>>();
  };
  BENCHMARK("BigLFSR<46, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<46, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<46, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<46, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<46, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<46, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<46, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<46, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<46, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<46, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<46, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<46, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<46, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<46, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<46, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<46, std::uint64_t, false>>();
  };
} // end of N=46

TEST_CASE("N=47")
{
  BENCHMARK("SmallLFSR<47, true>")
  {
    return run_impl<SmallLFSR<47, true>>();
  };
  BENCHMARK("SmallLFSR<47, false>")
  {
    return run_impl<SmallLFSR<47, false>>();
  };
  BENCHMARK("BigLFSR<47, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<47, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<47, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<47, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<47, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<47, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<47, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<47, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<47, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<47, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<47, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<47, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<47, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<47, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<47, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<47, std::uint64_t, false>>();
  };
} // end of N=47

TEST_CASE("N=48")
{
  BENCHMARK("SmallLFSR<48, true>")
  {
    return run_impl<SmallLFSR<48, true>>();
  };
  BENCHMARK("SmallLFSR<48, false>")
  {
    return run_impl<SmallLFSR<48, false>>();
  };
  BENCHMARK("BigLFSR<48, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<48, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<48, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<48, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<48, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<48, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<48, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<48, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<48, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<48, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<48, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<48, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<48, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<48, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<48, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<48, std::uint64_t, false>>();
  };
} // end of N=48

TEST_CASE("N=49")
{
  BENCHMARK("SmallLFSR<49, true>")
  {
    return run_impl<SmallLFSR<49, true>>();
  };
  BENCHMARK("SmallLFSR<49, false>")
  {
    return run_impl<SmallLFSR<49, false>>();
  };
  BENCHMARK("BigLFSR<49, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<49, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<49, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<49, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<49, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<49, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<49, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<49, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<49, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<49, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<49, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<49, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<49, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<49, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<49, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<49, std::uint64_t, false>>();
  };
} // end of N=49

TEST_CASE("N=50")
{
  BENCHMARK("SmallLFSR<50, true>")
  {
    return run_impl<SmallLFSR<50, true>>();
  };
  BENCHMARK("SmallLFSR<50, false>")
  {
    return run_impl<SmallLFSR<50, false>>();
  };
  BENCHMARK("BigLFSR<50, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<50, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<50, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<50, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<50, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<50, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<50, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<50, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<50, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<50, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<50, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<50, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<50, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<50, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<50, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<50, std::uint64_t, false>>();
  };
} // end of N=50

TEST_CASE("N=51")
{
  BENCHMARK("SmallLFSR<51, true>")
  {
    return run_impl<SmallLFSR<51, true>>();
  };
  BENCHMARK("SmallLFSR<51, false>")
  {
    return run_impl<SmallLFSR<51, false>>();
  };
  BENCHMARK("BigLFSR<51, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<51, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<51, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<51, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<51, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<51, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<51, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<51, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<51, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<51, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<51, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<51, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<51, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<51, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<51, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<51, std::uint64_t, false>>();
  };
} // end of N=51

TEST_CASE("N=52")
{
  BENCHMARK("SmallLFSR<52, true>")
  {
    return run_impl<SmallLFSR<52, true>>();
  };
  BENCHMARK("SmallLFSR<52, false>")
  {
    return run_impl<SmallLFSR<52, false>>();
  };
  BENCHMARK("BigLFSR<52, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<52, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<52, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<52, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<52, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<52, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<52, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<52, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<52, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<52, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<52, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<52, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<52, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<52, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<52, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<52, std::uint64_t, false>>();
  };
} // end of N=52

TEST_CASE("N=53")
{
  BENCHMARK("SmallLFSR<53, true>")
  {
    return run_impl<SmallLFSR<53, true>>();
  };
  BENCHMARK("SmallLFSR<53, false>")
  {
    return run_impl<SmallLFSR<53, false>>();
  };
  BENCHMARK("BigLFSR<53, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<53, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<53, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<53, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<53, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<53, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<53, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<53, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<53, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<53, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<53, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<53, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<53, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<53, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<53, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<53, std::uint64_t, false>>();
  };
} // end of N=53

TEST_CASE("N=54")
{
  BENCHMARK("SmallLFSR<54, true>")
  {
    return run_impl<SmallLFSR<54, true>>();
  };
  BENCHMARK("SmallLFSR<54, false>")
  {
    return run_impl<SmallLFSR<54, false>>();
  };
  BENCHMARK("BigLFSR<54, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<54, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<54, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<54, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<54, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<54, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<54, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<54, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<54, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<54, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<54, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<54, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<54, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<54, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<54, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<54, std::uint64_t, false>>();
  };
} // end of N=54

TEST_CASE("N=55")
{
  BENCHMARK("SmallLFSR<55, true>")
  {
    return run_impl<SmallLFSR<55, true>>();
  };
  BENCHMARK("SmallLFSR<55, false>")
  {
    return run_impl<SmallLFSR<55, false>>();
  };
  BENCHMARK("BigLFSR<55, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<55, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<55, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<55, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<55, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<55, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<55, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<55, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<55, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<55, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<55, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<55, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<55, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<55, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<55, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<55, std::uint64_t, false>>();
  };
} // end of N=55

TEST_CASE("N=56")
{
  BENCHMARK("SmallLFSR<56, true>")
  {
    return run_impl<SmallLFSR<56, true>>();
  };
  BENCHMARK("SmallLFSR<56, false>")
  {
    return run_impl<SmallLFSR<56, false>>();
  };
  BENCHMARK("BigLFSR<56, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<56, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<56, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<56, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<56, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<56, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<56, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<56, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<56, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<56, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<56, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<56, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<56, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<56, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<56, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<56, std::uint64_t, false>>();
  };
} // end of N=56

TEST_CASE("N=57")
{
  BENCHMARK("SmallLFSR<57, true>")
  {
    return run_impl<SmallLFSR<57, true>>();
  };
  BENCHMARK("SmallLFSR<57, false>")
  {
    return run_impl<SmallLFSR<57, false>>();
  };
  BENCHMARK("BigLFSR<57, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<57, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<57, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<57, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<57, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<57, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<57, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<57, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<57, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<57, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<57, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<57, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<57, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<57, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<57, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<57, std::uint64_t, false>>();
  };
} // end of N=57

TEST_CASE("N=58")
{
  BENCHMARK("SmallLFSR<58, true>")
  {
    return run_impl<SmallLFSR<58, true>>();
  };
  BENCHMARK("SmallLFSR<58, false>")
  {
    return run_impl<SmallLFSR<58, false>>();
  };
  BENCHMARK("BigLFSR<58, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<58, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<58, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<58, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<58, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<58, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<58, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<58, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<58, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<58, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<58, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<58, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<58, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<58, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<58, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<58, std::uint64_t, false>>();
  };
} // end of N=58

TEST_CASE("N=59")
{
  BENCHMARK("SmallLFSR<59, true>")
  {
    return run_impl<SmallLFSR<59, true>>();
  };
  BENCHMARK("SmallLFSR<59, false>")
  {
    return run_impl<SmallLFSR<59, false>>();
  };
  BENCHMARK("BigLFSR<59, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<59, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<59, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<59, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<59, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<59, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<59, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<59, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<59, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<59, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<59, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<59, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<59, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<59, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<59, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<59, std::uint64_t, false>>();
  };
} // end of N=59

TEST_CASE("N=60")
{
  BENCHMARK("SmallLFSR<60, true>")
  {
    return run_impl<SmallLFSR<60, true>>();
  };
  BENCHMARK("SmallLFSR<60, false>")
  {
    return run_impl<SmallLFSR<60, false>>();
  };
  BENCHMARK("BigLFSR<60, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<60, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<60, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<60, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<60, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<60, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<60, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<60, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<60, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<60, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<60, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<60, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<60, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<60, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<60, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<60, std::uint64_t, false>>();
  };
} // end of N=60

TEST_CASE("N=61")
{
  BENCHMARK("SmallLFSR<61, true>")
  {
    return run_impl<SmallLFSR<61, true>>();
  };
  BENCHMARK("SmallLFSR<61, false>")
  {
    return run_impl<SmallLFSR<61, false>>();
  };
  BENCHMARK("BigLFSR<61, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<61, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<61, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<61, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<61, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<61, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<61, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<61, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<61, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<61, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<61, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<61, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<61, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<61, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<61, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<61, std::uint64_t, false>>();
  };
} // end of N=61

TEST_CASE("N=62")
{
  BENCHMARK("SmallLFSR<62, true>")
  {
    return run_impl<SmallLFSR<62, true>>();
  };
  BENCHMARK("SmallLFSR<62, false>")
  {
    return run_impl<SmallLFSR<62, false>>();
  };
  BENCHMARK("BigLFSR<62, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<62, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<62, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<62, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<62, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<62, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<62, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<62, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<62, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<62, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<62, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<62, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<62, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<62, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<62, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<62, std::uint64_t, false>>();
  };
} // end of N=62

TEST_CASE("N=63")
{
  BENCHMARK("SmallLFSR<63, true>")
  {
    return run_impl<SmallLFSR<63, true>>();
  };
  BENCHMARK("SmallLFSR<63, false>")
  {
    return run_impl<SmallLFSR<63, false>>();
  };
  BENCHMARK("BigLFSR<63, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<63, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<63, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<63, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<63, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<63, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<63, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<63, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<63, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<63, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<63, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<63, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<63, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<63, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<63, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<63, std::uint64_t, false>>();
  };
} // end of N=63

TEST_CASE("N=64")
{
  BENCHMARK("SmallLFSR<64, true>")
  {
    return run_impl<SmallLFSR<64, true>>();
  };
  BENCHMARK("SmallLFSR<64, false>")
  {
    return run_impl<SmallLFSR<64, false>>();
  };
  BENCHMARK("BigLFSR<64, std::uint8_t, true>")
  {
    return run_impl<BigLFSR<64, std::uint8_t, true>>();
  };
  BENCHMARK("BigLFSR<64, std::uint8_t, false>")
  {
    return run_impl<BigLFSR<64, std::uint8_t, false>>();
  };
  BENCHMARK("BigLFSR<64, std::uint16_t, true>")
  {
    return run_impl<BigLFSR<64, std::uint16_t, true>>();
  };
  BENCHMARK("BigLFSR<64, std::uint16_t, false>")
  {
    return run_impl<BigLFSR<64, std::uint16_t, false>>();
  };
  BENCHMARK("BigLFSR<64, std::uint32_t, true>")
  {
    return run_impl<BigLFSR<64, std::uint32_t, true>>();
  };
  BENCHMARK("BigLFSR<64, std::uint32_t, false>")
  {
    return run_impl<BigLFSR<64, std::uint32_t, false>>();
  };
  BENCHMARK("BigLFSR<64, std::uint64_t, true>")
  {
    return run_impl<BigLFSR<64, std::uint64_t, true>>();
  };
  BENCHMARK("BigLFSR<64, std::uint64_t, false>")
  {
    return run_impl<BigLFSR<64, std::uint64_t, false>>();
  };
} // end of N=64

// end of auto generated benchmark
