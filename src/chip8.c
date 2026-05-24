#include "chip8.h"
#include "opcode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defines how to construct a char.
static const uint8_t font[80] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80, // F
};

void chip8_init(Chip8 *c) {
    memset(c, 0, sizeof(Chip8));
    memcpy(&c->memory[FONT_START], font, sizeof(font));
    c->PC = PROGRAM_START;
}
int chip8_load_rom(Chip8 *c, const char *path){
    FILE *f = fopen(path, "rb");
    long size = ftell(f);
    if(size > (MEMORY_SIZE - PROGRAM_START)){
        fclose(f);
        return 1;
    }
    size_t read = fread(&c->memory[PROGRAM_START], 1, (size_t)size, f);
    fclose(f);
    return 0;
}
void chip8_emulate_cycle(Chip8 *c){
    uint16_t opcode = (c->memory[c->PC] << 8) | c->memory[c->PC+1];
    c->PC += 2;
    switch (opcode & OP_FAMILY_MASK) {
        case 0x0000:
            if (opcode == OP_CLS) {
                op_cls(c);
            } else if (opcode == OP_RET) {
                op_ret(c);
            }
            break;
        case OP_JP:
            op_jp(c, opcode);
            break;
        case OP_CALL:
            op_call(c, opcode);
            break;
        case OP_SE:
            op_se(c, opcode);
            break;
        case OP_SNE:
            op_sne(c, opcode);
            break;
        case OP_LD:
            op_ld(c, opcode);
            break;
        case OP_ADD:
            op_add_nc(c, opcode);
            break;
        case OP_LDI:
            op_ldi(c, opcode);
            break;
        case OP_DRW:
            op_drw(c, opcode);
            break;
        default:
            break;
    }
}