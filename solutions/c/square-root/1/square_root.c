#include "square_root.h"
#include <stdio.h>
int square_root(int input){
    if (input <= 0){
        printf("The input number has to be a positive whole number (a natural)");
        return -1;
    }
    if (input < 4){
        return 1;
    }
    if (input == 4){
        return 2;
    }
    int small_cand=2*square_root(input/4);
    int large_cand=small_cand+1;
    if ((large_cand * large_cand) > input){
        return small_cand;
    } else {
        return large_cand;
    }
}
    