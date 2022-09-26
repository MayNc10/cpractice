#include <stdbool.h>
#include <stdlib.h>

int two(int n) {
    int numtimes = 0;
    int first;
    int nextguess;
    int i;

    srand((unsigned) 42);
    while (true) {
        first = rand() % 6;
        for (i = 1; i < n; i++) {
            nextguess = rand() % 6;
            if (nextguess != first) {
                break;
            }
        }
        numtimes++;
        if (i == n) {
            return numtimes;
        }
    }
    return numtimes;
}