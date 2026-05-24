#include"chip8.h"
#include<time.h>

int main(int argc, char *argv[]){
    int run = 1;
    if(argc < 2){
        return 2;
    }
    else{
        const long long frame_ns = 1000000000L / 60;
        Chip8 chip;
        chip8_init(&chip);
        chip8_load_rom(&chip, argv[1]);
        while(run == 1){
            struct timespec start;
            clock_gettime(CLOCK_MONOTONIC, &start);
            chip8_emulate_cycle(&chip);
            struct timespec end;
            clock_gettime(CLOCK_MONOTONIC, &end);
            long long elapsed = (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec - start.tv_nsec);
            long long sleep_ns = frame_ns - elapsed;
            if(sleep_ns > 0){
                struct timespec req;
                req.tv_sec = 0;
                req.tv_nsec = sleep_ns;
                nanosleep(&req, NULL);
            }
        }
    }
}