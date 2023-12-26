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
