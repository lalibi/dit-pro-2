#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Declaration */
int random(int, int);

int main() {
    int i, r;
    int c[6] = {0};

    printf("\n%s %d", "In this computer, RAND_MAX=", RAND_MAX);

    srand(time(NULL));

    for (i = 0; i < 100000; i++) {
        r = random(1, 6);
        /* printf("%d\n", r); */
        c[r - 1]++;
    }

    /* For each number between 1 and 6 show the percentage */
    for (i = 0; i < 6; i++) {
        printf("\n%d: %.2f%%", i + 1, (float) c[i] / 1000);
    }

    return EXIT_SUCCESS;
}

/* Definition */
int random(int min, int max) {
    // % might not be the best solution
    return rand() % (max - min + 1) + min;
}
