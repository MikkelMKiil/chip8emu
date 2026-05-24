#include<chip8.h>
#include<opcode.h>

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
    uint8_t i = (opcode & OP_X_MASK) >> 8;
    c->V[i] = data;
    return 0;
}
//TODO, also needs bounds check like the others, op_ldi.
int op_ldi(Chip8 *c, uint16_t opcode){
    uint16_t addr = opcode & OP_ADDR_MASK;
    c->I = addr; 
    return 0;
}
int op_add(Chip8 *c){
    return 0;
}
int op_drw(Chip8 *c){
    return 0;
}
int op_se(Chip8 *c){
    return 0;
}
int op_sne(Chip8 *c){
    return 0;
}
