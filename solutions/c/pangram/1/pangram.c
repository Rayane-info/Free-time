#include "pangram.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool is_pangram(const char *sentence) {
    if (!sentence) {
        return false;
    }
    
    bool seen[26] = {false};
    int len = strlen(sentence);
    
    for (int i = 0; i < len; i++) {
        if (isalpha(sentence[i])) {
            char letter = tolower(sentence[i]);
            int index = letter - 'a';
            seen[index] = true;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        if (!seen[i]) {   
            return false;
        }
    }
    return true;
}