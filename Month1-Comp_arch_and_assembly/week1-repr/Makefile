# Simple Makefile for C projects
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wmissing-prototypes -Wstrict-prototypes -D_POSIX_C_SOURCE=200809L
OPTFLAGS = -O2 -march=native -mtune=native
DBGFLAGS = -O0 -g -fsanitize=address,undefined

SOURCES = main.c
TARGET = main

.PHONY: all build debug format asm clean run perf help

all: build

# Build targets
build: $(TARGET)

debug: CFLAGS += $(DBGFLAGS)
debug: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(OPTFLAGS) -o $@ $^

# Assembly output (clean)
asm: $(TARGET).s

$(TARGET).s: $(SOURCES)
	@echo "Generating clean assembly..."
	$(CC) $(CFLAGS) -O2 -S -masm=intel \
		-fno-asynchronous-unwind-tables -fno-dwarf2-cfi-asm \
		-fno-stack-protector -fomit-frame-pointer \
		-fno-verbose-asm -fno-ident -o $@ $<
	@sed -i '/^\s*\./d; /^\s*endbr64/d; /^\s*$$/d' $@
	@echo "Clean assembly saved as: $@"

# Format source code
format:
	@if command -v clang-format >/dev/null 2>&1; then \
		clang-format -i -style='{BasedOnStyle: LLVM, IndentWidth: 4, UseTab: Never}' $(SOURCES); \
		echo "Formatted $(SOURCES)"; \
	else \
		echo "clang-format not found"; \
	fi

# Run program
run: build
	./$(TARGET)

# Performance analysis
perf: build
	@if command -v perf >/dev/null 2>&1; then \
		perf stat -e cycles,instructions,cache-misses,branch-misses ./$(TARGET); \
	else \
		time ./$(TARGET); \
	fi

# Clean build artifacts
clean:
	rm -f $(TARGET) $(TARGET).s *.o *.d

# Help
help:
	@echo "Available targets:"
	@echo "  build    - Build optimized binary"
	@echo "  debug    - Build with debug info"
	@echo "  asm      - Generate clean assembly"
	@echo "  format   - Format source code"
	@echo "  run      - Build and run"
	@echo "  perf     - Run with performance stats"
	@echo "  clean    - Remove build artifacts"