# Copyright 2023 Echipa PCLP1
# Am imprumutat si eu exemplul:)

# compiler setup
CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -O3

# define targets
TARGETS = backpack

build: $(TARGETS)

backpack: backpack.c utils.c backtracking.c high-value.c
	$(CC) $(CFLAGS) backpack.c utils.c backtracking.c backtracking-thread.c high-value.c -o backpack

clean:
	rm -f $(TARGETS)

.PHONY: pack clean
