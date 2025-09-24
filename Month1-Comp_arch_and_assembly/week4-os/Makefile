UNAME_S := $(shell uname -s)
CC ?= gcc
ASM ?= nasm
ifeq ($(UNAME_S),Darwin)
  CC = clang
  NASM_FORMAT = macho64
  DFLAGS = -DDARWIN
else
  NASM_FORMAT = elf64
  DFLAGS =
endif
CFLAGS ?= -O2 -g -fno-omit-frame-pointer -Wall -Wextra
ASFLAGS ?= -f $(NASM_FORMAT) $(DFLAGS)

# Targets differ by OS
ifeq ($(UNAME_S),Linux)
  all: write_demo grep_lite
else
  all: write_demo_libc grep_lite
endif

# Linux raw syscalls
sys_write.o: sys_write.asm
	$(ASM) $(ASFLAGS) -o $@ $<

sys_exit.o: sys_exit.asm
	$(ASM) $(ASFLAGS) -o $@ $<

write_demo: sys_write.o sys_exit.o write_demo.c
	$(CC) $(CFLAGS) -o $@ $^

# macOS libc fallback
write_demo_libc: write_demo_libc.c
	$(CC) $(CFLAGS) -o $@ $<

hotloop.o: hotloop.asm
	$(ASM) $(ASFLAGS) -o $@ $<

grep_lite: grep_lite.c hotloop.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o write_demo write_demo_libc grep_lite
