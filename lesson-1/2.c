#include <stdio.h>

/* Declarations */
int fun1(long);
int fun2(long *);

int main() {
    long num = 256;
    long *ptr = &num;

    printf("The value of num is: %ld and its address is: %p\n", num, ptr);

    *ptr = 0;

    /* *(&num) == num */
    /* &(*prt) == ptr */

    printf("The value of num is: %ld and its address is: %p\n", num, ptr);

    fun1(num); /* Call by value */
    fun2(ptr); /* Call by reference */

    printf("The value of num is: %ld and its address is: %p\n", num, ptr);
}

/* Definitions */
int fun1(long x) {
    x += 1;
    return x;
}

int fun2(long *p) {
    *p += 1;
    return *p;
}

void minmax(int a[10], int *min, int *max) {
    int i;
    *min = *max = a[0];
    for (i = 1; i < 10; i++) {
        if (a[i] < *min) {
            *min = a[i];
        }
        if (a[i] > *max) {
            *max = a[i];
        }
    }
}
