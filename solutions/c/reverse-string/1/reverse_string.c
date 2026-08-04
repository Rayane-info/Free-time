#include "reverse_string.h"
#include <string.h>
#include <stdlib.h>   

char *reverse(const char *value) {
    if (value == NULL) {
        return NULL;
    }

    size_t length = strlen(value);

    // Allocate memory for a copy (room for the characters + null terminator)
    char *copy = malloc(length + 1);
    if (copy == NULL) {
        return NULL; 
    }

    strcpy(copy, value);

    char *left = copy;               
    char *right = copy + length - 1; // Starts at the last character
    char temp;                       // Holds a single character

    while (left < right) {           // Stop when arrows meet or cross
        temp = *left;
        *left = *right;
        *right = temp;

        left++;   
        right--;  
    }

    return copy; 
}