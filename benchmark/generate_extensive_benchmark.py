#!/usr/bin/env python3
#
# this generates the body of the benchmark, on stdout.
# don't use this directly, use combine_extensive.sh

Nmin = 3
Nmax = 64

bitwidths = [8, 16, 32, 64]


def sectionstart(name):
    print(f"\nTEST_CASE(\"{name}\") {{")


def sectionend(name):
    print(f"}}//end of {name}\n\n")


def printbench(implementation):
    print(
        f"BENCHMARK(\"{implementation}\")  {{  return run_impl<{implementation}>();  }};")


for N in range(Nmin, Nmax + 1):
    # print(N)
    name = f"N={N}"
    sectionstart(name)
    for alternative in ["true", "false"]:
        small = f"SmallLFSR<{N}, {alternative}>"
        printbench(small)
    for bitwidth in bitwidths:
        for alternative in ["true", "false"]:
            big = f"BigLFSR<{N}, std::uint{bitwidth}_t, {alternative}>"
            printbench(big)
    sectionend(name)
