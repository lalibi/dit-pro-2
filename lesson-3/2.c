#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, r;
    int c[6] = {0};

    printf("\n%s %d", "In this computer, RAND_MAX=", RAND_MAX);

    for (i = 0; i < 100000; i++) {
        r = rand() * 6 / RAND_MAX + 1;
        /* printf("%d\n", r); */
        c[r - 1]++;
    }

    /* For each number between 1 and 6 show the percentage */
    for (i = 0; i < 6; i++) {
        printf("\n%d: %.2f%%", i + 1, (float) c[i] / 1000);
    }

    return EXIT_SUCCESS;
}
