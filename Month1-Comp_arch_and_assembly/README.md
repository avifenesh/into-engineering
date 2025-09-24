# Month 1 — Computer Architecture & Assembly — Starter Repo (v2)
Portable scaffold for Linux and macOS. Requires: GCC/Clang, NASM, Binutils.

Folders:
- week2-asm/   → Assembly + C interop (Days 7–12)
- week3-cache/ → Cache & perf experiments (Days 13–18)
- week4-os/    → Raw syscalls (Linux) or libc fallback (macOS) + capstone (Days 19–24)

Tips:
- On macOS: `brew install llvm nasm binutils` (use `clang`, `nasm -f macho64`, `gobjdump`).
- On Linux: `sudo apt install build-essential nasm binutils`.
