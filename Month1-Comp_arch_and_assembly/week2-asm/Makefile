UNAME_S := $(shell uname -s)
CC      ?= gcc
ASM     ?= nasm

ifeq ($(UNAME_S),Darwin)
  NASM_FORMAT = macho64
  CC          = clang
  DFLAGS      = -DDARWIN
else
  NASM_FORMAT = elf64
  DFLAGS      =
endif

CFLAGS  ?= -Wall -Wextra -O2 -g -fno-omit-frame-pointer
ASFLAGS ?= -f $(NASM_FORMAT) $(DFLAGS)

all: libasm.a demo

add.o: add.asm
	$(ASM) $(ASFLAGS) -o $@ $<

strlen.o: strlen.asm
	$(ASM) $(ASFLAGS) -o $@ $<

dot_product.o: dot_product.asm
	$(ASM) $(ASFLAGS) -o $@ $<

libasm.a: add.o strlen.o dot_product.o
	ar rcs $@ $^

demo: main.c libasm.a
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o *.a demo
