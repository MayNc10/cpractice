#include <stdlib.h>

int one(int n) {
    int numzeros = 0;
    
    srand((unsigned) 42);
    for (int i = 0; i < n; i++) {
        if (!(rand() % 2)) {
            numzeros++;            
        } 
    }
    return numzeros;
} 