# Week 3 — Cache Experiments (Portable)
Build & Run:
```bash
make
./bench_cache            # n=2048, stride_col=1
./bench_cache 4096 16    # ./bench_cache [n] [stride_col]
```
It times a row-major pass and a column-major pass over an n x n int matrix.
Interpret deltas with cache line size & associativity.
