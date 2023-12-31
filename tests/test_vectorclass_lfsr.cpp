#include <type_traits>
#include <vector>

#include <catch2/catch_test_macros.hpp>

#include "tiptap/lfsr_small.h"
#include "tiptap/lfsr_vectorclass.h"

template<std::size_t N>
void
differential_test()
{
  SmallLFSR<N> reference_lfsr;
  REQUIRE(reference_lfsr.state() == 1);

  VectorLFSR<N> vector_lfsr;
  REQUIRE(vector_lfsr.state()[0] == 1);
  REQUIRE(vector_lfsr.state()[1] == 1);
  REQUIRE(vector_lfsr.state()[2] == 1);
  REQUIRE(vector_lfsr.state()[3] == 1);

  // verify that the vectorized implementation wraps around in the same way as
  // the reference, by looping for the entire period, plus one.
  const std::size_t period = (1ULL << N) - 1;

  for (std::size_t i = 0; i < period + 10; ++i) {
    REQUIRE(horizontal_and(vector_lfsr.state() == reference_lfsr.state()));
    vector_lfsr.next();
    reference_lfsr.next();
  }
}

TEST_CASE("test small sizes")
{
  differential_test<3>();
  differential_test<4>();
  differential_test<5>();
  differential_test<6>();
  differential_test<7>();
  differential_test<8>();
  differential_test<9>();
}
