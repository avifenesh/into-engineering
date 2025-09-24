UNAME_S := $(shell uname -s)
CC ?= gcc
ifeq ($(UNAME_S),Darwin)
CC = clang
endif
CFLAGS ?= -O2 -g -fno-omit-frame-pointer -Wall -Wextra
all: bench_cache

bench_cache: bench_cache.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f bench_cache
