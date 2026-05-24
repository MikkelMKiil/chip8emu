#include<chip8.h>


int main(int argc, char *argv[]){
    if(argc < 2){
        return 2;
    }
    else{
        Chip8 chip;
        chip8_init(&chip);
    }
}