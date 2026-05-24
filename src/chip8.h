#ifndef CHIP8_H
#define CHIP8_H

#include <stdint.h>

#define MEMORY_SIZE 4096
#define NUM_REGISTERS 16
#define STACK_SIZE 16
#define DISPLAY_WIDTH 64
#define DISPLAY_HEIGHT 32
#define NUM_KEYS 16
#define PROGRAM_START 0x200
#define FONT_START 0x050

typedef struct {
    uint8_t  memory[MEMORY_SIZE];
    uint8_t  V[NUM_REGISTERS];
    uint16_t I;
    uint16_t PC;
    uint16_t stack[STACK_SIZE];
    uint8_t  SP;
    uint8_t  delay_timer;
    uint8_t  sound_timer;
    uint8_t  display[DISPLAY_HEIGHT][DISPLAY_WIDTH];
    uint8_t  keys[NUM_KEYS];
    int      draw_flag;
} Chip8;

// Function prototypes — implemented in chip8.c
void chip8_init(Chip8 *c);
int  chip8_load_rom(Chip8 *c, const char *path);
void chip8_emulate_cycle(Chip8 *c);
void chip8_update_timers(Chip8 *c);

#endif