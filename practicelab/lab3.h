#include <stdbool.h>

bool three(char* word, int length) {
    if (length == 1) return true;
    else if(word[0] == word[length - 1]) return three(word + 1, length - 2);
    else return false;
} 