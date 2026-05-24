#ifndef OPCODE_H
#define OPCODE_H

// Exact opcodes
#define OP_CLS 0x00E0
#define OP_RET 0x00EE

// Family mask and IDs
#define OP_FAMILY_MASK 0xF000
#define OP_JP   0x1000
#define OP_CALL 0x2000
#define OP_SE   0x3000
#define OP_SNE  0x4000
#define OP_LD   0x6000
#define OP_ADD  0x7000
#define OP_LDI  0xA000
#define OP_DRW  0xD000

// Common field masks
#define OP_ADDR_MASK 0x0FFF
#define OP_X_MASK    0x0F00
#define OP_Y_MASK    0x00F0
#define OP_KK_MASK   0x00FF
#define OP_N_MASK    0x000F

int op_cls(Chip8 *c);
int op_call(Chip8 *c, uint16_t opcode);
int op_ret(Chip8 *c);
int op_jp(Chip8 *c, uint16_t opcode);
int op_ld(Chip8 *c, uint16_t opcode);
int op_ldi(Chip8 *c, uint16_t opcode);
int op_add_nc(Chip8 *c, uint16_t opcode);
int op_add(Chip8 *c);
int op_drw(Chip8 *c, uint16_t opcode);
int op_se(Chip8 *c, uint16_t opcode);
int op_sne(Chip8 *c, uint16_t opcode);

#endif