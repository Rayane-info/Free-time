#include "binary.h"
#include "stdio.h"
#include "string.h"
#include "math.h"

int convert(const char *input){
    int sum = 0;
    for (int i = 0 ; input[i] != '\0' ; i++){
        if ((input[i] != '0') && (input[i] != '1')){
            printf("Invalid input, binary numbers have either 0 or 1 as value.");
            return -1;
        }        
        int power = strlen(input)-i-1;
        int bit = input[i] - '0';
        sum += bit * pow(2,power);
    }
    return sum;
}