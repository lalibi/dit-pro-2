#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, p, i;
    /* Calculate factorial proceduraly */

    printf("Enter a number: ");
    scanf("%d", &n);

    p = 1;
    for (i = 1; i <= n; i++) {
        p *= i; /* p = p * i; */
    }

    printf("%d! = %d\n", n, p);

    return EXIT_SUCCESS;
}
