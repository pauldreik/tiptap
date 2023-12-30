#include <catch2/catch_test_macros.hpp>

#include "tiptap/integerselect.h"

TEST_CASE("the correct integer is selected")
{
  // will fail to compile
  // static_assert(std::is_same_v<SelectInteger_t<-1>, std::uint8_t>);

  static_assert(std::is_same_v<SelectInteger_t<0>, std::uint8_t>);
  static_assert(std::is_same_v<SelectInteger_t<1>, std::uint8_t>);
  static_assert(std::is_same_v<SelectInteger_t<8>, std::uint8_t>);
  static_assert(std::is_same_v<SelectInteger_t<9>, std::uint16_t>);
  static_assert(std::is_same_v<SelectInteger_t<16>, std::uint16_t>);
  static_assert(std::is_same_v<SelectInteger_t<17>, std::uint32_t>);
  static_assert(std::is_same_v<SelectInteger_t<32>, std::uint32_t>);
  static_assert(std::is_same_v<SelectInteger_t<31>, std::uint32_t>);
  static_assert(std::is_same_v<SelectInteger_t<32>, std::uint32_t>);
  static_assert(std::is_same_v<SelectInteger_t<33>, std::uint64_t>);
  static_assert(std::is_same_v<SelectInteger_t<45>, std::uint64_t>);
  static_assert(std::is_same_v<SelectInteger_t<64>, std::uint64_t>);
#ifdef __SIZEOF_INT128__
  static_assert(std::is_same_v<SelectInteger_t<65>, unsigned __int128>);
  static_assert(std::is_same_v<SelectInteger_t<73>, unsigned __int128>);
  static_assert(std::is_same_v<SelectInteger_t<128>, unsigned __int128>);
#else
  // will fail to compile
  using Fail = SelectInteger_t<65>;
#endif
  // will fail to compile
  // using Fail = SelectInteger_t<129>;
}
