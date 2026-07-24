#include "grains.h"
#include "stdio.h"
#define CHESSBOARD_SIZE 64

uint64_t square(uint8_t index){
    if ((index < 1) || (index > CHESSBOARD_SIZE)){
        printf("Values not in the right interval, they have to be between 1 and %d\n",CHESSBOARD_SIZE);
        return 0;
    }
    return (uint64_t)1 << (index-1);
}

uint64_t total(void){
    uint64_t sum = 0;
    for (int i = 1; i <= CHESSBOARD_SIZE ; i++){
        sum+=square((uint64_t)i);
    }
    return sum;
}