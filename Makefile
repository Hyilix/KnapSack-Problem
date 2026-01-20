# Compiler setup
CC=gcc
CFLAGS=-Wall -Wextra -std=c99

# Define targets
TARGETS = backpack

build: $(TARGETS)

backpack: backpack.c utils.c backtracking.c high-value.c
	$(CC) $(CFLAGS) backpack.c utils.c backtracking.c high-value.c -o backpack

clean:
	rm -f $(TARGETS)

.PHONY: pack clean
