# into-engineering

Hands-on study notes and code for low-level systems engineering. x86-64, Intel syntax, NASM with C, on Linux and macOS.

## Month 1: Computer Architecture & Assembly

[`Month1-Comp_arch_and_assembly/`](Month1-Comp_arch_and_assembly/) follows a 24-day plan ([`24_day_plan_resources_structure.md`](Month1-Comp_arch_and_assembly/24_day_plan_resources_structure.md)).

- `week2-asm/`: `add`, `my_strlen` and `dot_product` in NASM, called from C.
- `week3-cache/`: `bench_cache`, row-major vs column-major traversal timing.
- `week4-os/`: raw `write`/`exit` syscalls on Linux, a libc fallback on macOS, and `grep_lite`.

Each week builds with `make` in its folder. Requires GCC or Clang, NASM and Binutils.
