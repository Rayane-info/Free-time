#include "collatz_conjecture.h"


int steps(int start){
    if (start <= 0){
        return -1;
    }
    int steps = 0;
    while (start != 1 && steps < 500){
        if (start % 2 == 0){
            start= start/ 2;
            steps++;
        }
        else{
            start= start * 3 + 1;
            steps++;
        }
    }
    return steps;
}