#include <stdio.h>
#include <stdlib.h>

int factorial(int);

int main() {
    int n, p, i;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("%d! = %d\n", n, factorial(n));

    return EXIT_SUCCESS;
}

/* Calculate factorial recursively */
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
