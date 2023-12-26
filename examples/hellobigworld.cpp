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
