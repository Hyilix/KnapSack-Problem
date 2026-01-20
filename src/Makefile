# Compiler setup
CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -O3

# Define targets
TARGETS = backpack

build: $(TARGETS)

backpack: backpack.c utils.c backtracking.c high-value.c
	$(CC) $(CFLAGS) backpack.c utils.c backtracking.c backtracking-thread.c high-value.c -o backpack

clean:
	rm -f $(TARGETS)

.PHONY: pack clean
