#include <stdlib.h>
#include <string.h>

char* five(char* word, int shift) {
    int base = 0;
    char* newword = (char*) malloc(strlen(word));

    while(word[base]) { 
        newword[base] = (word[base] - 97 + shift) % 26 + 65;
        base++;
    }
    return newword;
} 