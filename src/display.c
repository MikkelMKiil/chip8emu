#include"display.h"
#include<stdio.h>
void draw(Chip8 *c){
    printf("\x1b[2J\x1b[H");
    
    for (int i = 0; i < DISPLAY_HEIGHT; i++) {
        for (int j = 0; j < DISPLAY_WIDTH; j++) {
            if(c->display[i][j] != 0){
                putchar('#');
            }
            else{
                putchar(' ');
            }
        }
        printf("\n");
    }
    fflush(stdout);
}