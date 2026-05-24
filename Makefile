CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2 -g

chip8: src/main.c src/chip8.c src/display.c src/input.c
	$(CC) $(CFLAGS) -o chip8 src/main.c src/chip8.c src/display.c src/input.c

clean:
	rm -f chip8

.PHONY: clean