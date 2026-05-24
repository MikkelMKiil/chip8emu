#include<chip8.h>


int main(int argc, char *argv[]){
    int run = 1;
    if(argc < 2){
        return 2;
    }
    else{
        Chip8 chip;
        chip8_init(&chip);
        chip8_load_rom(&chip, argv[1]);
        while(run == 1){
            chip8_emulate_cycle(&chip);
            
        }
    }
}