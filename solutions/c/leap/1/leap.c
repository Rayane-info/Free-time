#include "leap.h"
#include "stdio.h"

bool leap_year(int year){ 
    if (year % 4 != 0){
        printf("%d, was not a leap year as it's not divisible by 4",year);
        return false;
    }
    if (year % 100 == 0){
        if(year % 400 != 0){
        printf("%d, was not a leap year as it's not divisible by 400",year);
        return false;
        }
    }
    printf("%d, was a leap year!",year);
    return true;
}