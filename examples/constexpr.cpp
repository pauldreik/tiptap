#include <iostream>
#include <tiptap/lfsr.h>

template<std::size_t N>
constexpr auto
thirdState()
{
  SmallLFSR<N> lfsr;
  for (int i = 0; i < 3; ++i) {
    lfsr.next();
  }
  return lfsr.state();
}

int
main()
{
  // somewhat contrived example to demonstrate use in constexpr context: make an
  // array with the size equal to the third state of a size 19 LFSR
  constexpr auto M = thirdState<19>();
  [[maybe_unused]] const int data[M]{};
}
