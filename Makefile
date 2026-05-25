CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2 -g

BUILD_DIR = build
TARGET = $(BUILD_DIR)/chip8
SOURCES = src/main.c src/chip8.c src/display.c src/input.c src/opcode.c

$(TARGET): $(SOURCES) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean