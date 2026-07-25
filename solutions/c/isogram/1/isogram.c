#include "isogram.h"
#include "string.h"
#include "ctype.h"
bool is_isogram(const char phrase[]){
    if (!phrase){
        return false;
    }
    
    bool seen[26]= {false};
    int len = strlen(phrase);
    
    for (int i = 0; i < len; i++){
        if (isalpha(phrase[i]) != 0){
            char letter= tolower(phrase[i]);
            int index = letter - 'a';
            if (seen[index] == true){
                return false;
            }
            seen[index]= true;
        }
    }
    return true;
}