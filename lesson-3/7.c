#include <stdio.h>
#include <stdlib.h>

int fibonacci(int);

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));

    return EXIT_SUCCESS;
}

int fibonacci(int n) {
    switch (n) {
    case 0:
        return 0;
    case 1:
        return 1;
    default:
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
