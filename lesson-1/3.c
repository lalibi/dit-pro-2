#include <stdio.h>

int main() {
    int a = 10, b = 20;
    int *p1, *p2;
    int *ptr;

    p1 = &a;
    p2 = &b;

    *p1 = *p2;
    p1 = p2;
    *p1 = *p2;

    printf("\n%s %d", "Number is: ", ptr);
    printf("\n%s %d", "Number is: ", *ptr); /* Segmentation fault */

    return 0;
}
