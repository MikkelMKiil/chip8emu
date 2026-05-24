#include"chip8.h"
#include"opcode.h"

void op_cls(Chip8 *c){
    for (int i = 0; i < DISPLAY_HEIGHT; i++) {
        for (int j = 0; j < DISPLAY_WIDTH; j++) {
            c->display[i][j] = 0;    
        }
    }
    c->draw_flag = 1;
}
//TODO, implement error catching for op_call.
int op_call(Chip8 *c, uint16_t opcode){
    uint16_t addr = opcode & OP_ADDR_MASK;
    c->SP++;
    c->stack[c->SP] = c->PC;
    c->PC = addr;
    return 0;
}
//TODO, implement error catching for op_ret.
int op_ret(Chip8 *c){
    c->PC = c->stack[c->SP]; // top of stack?
    if(c->SP > 0) {
        c->SP--;
        return 0;
    }
    else return 1;
}
int op_jp(Chip8 *c, uint16_t opcode){
    uint16_t addr = opcode & OP_ADDR_MASK;
    if(addr < MEMORY_SIZE) {
        if(addr >= PROGRAM_START){
            c->PC = addr;
            return 0;
        }
        else return 1;
    }
    else return 1;
}
//TODO, implement error catching for op_ld.
int op_ld(Chip8 *c, uint16_t opcode){
    uint8_t data = opcode & OP_KK_MASK;
    uint8_t x = (opcode & OP_X_MASK) >> 8;
    c->V[x] = data;
    return 0;
}
//TODO, also needs bounds check like the others, op_ldi.
int op_ldi(Chip8 *c, uint16_t opcode){
    uint16_t addr = opcode & OP_ADDR_MASK;
    c->I = addr; 
    return 0;
}
//nc == no carry
int op_add_nc(Chip8 *c, uint16_t opcode){
    uint8_t data = opcode & OP_KK_MASK;
    uint8_t x = (opcode & OP_X_MASK) >> 8;
    c->V[x] += data;
    return 0;
}
// with carry
int op_add(Chip8 *c){
    c->delay_timer = 69;
    return 0;
}
int op_drw(Chip8 *c, uint16_t opcode){
    c->V[0xF] = 0;
    uint8_t x = (opcode & OP_X_MASK) >> 8;
    uint8_t y = (opcode & OP_Y_MASK) >> 4;
    uint8_t n = (opcode & OP_N_MASK);
    uint8_t vx = c->V[x];
    uint8_t vy = c->V[y];
    for (int row = 0; row < n; row++) {
        uint8_t t_col = vy + row;
        if(t_col >= DISPLAY_HEIGHT) continue;
        uint8_t sprite = c->memory[c->I + row];
        for (int col = 0; col < 8; col++) {
            if(((sprite >> (7 - col)) & 1) == 1) {
                uint8_t t_row = vx + col;
                if(t_row >= DISPLAY_WIDTH) continue;
                if(c->display[t_col][t_row] == 1) c->V[0xF] = 1;
                c->display[t_col][t_row] ^= 1;
            }   
        }
    }
    c->draw_flag = 1;
    return 0;
}
int op_se(Chip8 *c, uint16_t opcode){
    uint8_t data = opcode & OP_KK_MASK;
    uint8_t x = (opcode & OP_X_MASK) >> 8;
    if(c->V[x] == data) c->PC += 2;
    return 0;
}
int op_sne(Chip8 *c, uint16_t opcode){
    uint8_t data = opcode & OP_KK_MASK;
    uint8_t x = (opcode & OP_X_MASK) >> 8;
    if(c->V[x] != data) c->PC += 2;
    return 0;
}
