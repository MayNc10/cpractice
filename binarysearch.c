#include <stdio.h>

size_t binarySearch(int arr[], size_t length, int key);

int main(void) {
    int arr[4] = {0, 2, 4, 10};

    printf("%d\n", binarySearch(arr, 4, 9));
    return 0;
}

size_t binarySearch(int arr[], size_t length, int key) {
    int mid;
    int res;

    if (length == 1) return arr[0] == key ? 0 : -1;
    else if (length == 2) {
        if (arr[0] == key) {
            return 0;
        }
        else if (arr[1] == key) {
            return 1;
        }
        return -1;
    }
     
    mid = length / 2;
    if (key > arr[mid - 1]) {
        res = binarySearch(arr + mid, length - mid, key);
        if (res == -1) return -1;
        return mid + res;
    }
    return binarySearch(arr, length - mid, key);
}

