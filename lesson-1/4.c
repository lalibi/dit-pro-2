#include <stdio.h>

int main() {
    int a[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    int *p = &a[0];

    char s[] = "Hi, there!";
    char *q = &s[0];

    printf("The value of a[0] is: %d\n", a[0]);
    printf("The value of a[0] is: %d\n", *p);

    printf("The value of a[1] is: %d\n", a[1]);
    printf("The value of a[1] is: %d\n", *(p + 1));

    printf("The 3rd char in s is: %c\n", s[2]);
    printf("The 3rd char in s is: %c\n", *(q + 2));

    return 0;
}
