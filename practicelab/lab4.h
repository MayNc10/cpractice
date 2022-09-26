#include <stdlib.h>

int four(char* n) {
    int max = 1;
    while (n[0]) {
        if (n[0] > max) {
            max = (int)n[0];
        }
        n++;
    }
    // This could be better
    if (max > 64) {
        if (max < 100) max -= 55;
        else max -= 87;
    }  
    else {
        max -= 48;
    }
    return max + 1;
} 