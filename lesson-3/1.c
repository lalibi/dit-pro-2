#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int num;

    printf("\n%s %d", "In this computer, RAND_MAX=", RAND_MAX);
    printf("\nWe generate 10 random coin trials.");

    for (i = 0; i < 10000; i++) {
        num = rand();
        if (num <= RAND_MAX / 2) {
            printf("\n%s", "head");
        } else {
            printf("\n%s", "tails");
        }
    }

    return EXIT_SUCCESS;
}
