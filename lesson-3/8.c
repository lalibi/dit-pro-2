#include <stdio.h>
#include <stdlib.h>

int binarySearch(int[], int, int, int);

int main() {
    /* array of 20 random numbers in ascending order */
    int key,
        a[20] = {15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53};

    printf("Enter a number: ");
    scanf("%d", &key);

    printf("The number %d is in position %d\n", key, binarySearch(a, key, 0, 19));

    return EXIT_SUCCESS;
}

int binarySearch(int p[], int key, int low, int high) {
    int middle = (low + high) / 2;

    if (high < low) return -1;

    if (key == p[middle]) {
        return middle;
    } else if (key < p[middle]) {
        return binarySearch(p, key, low, middle - 1);
    } else {
        return binarySearch(p, key, middle + 1, high);
    }

    return -1;
}
