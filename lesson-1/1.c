#include <stdio.h>

int main() {
    int x, i, j;
    float y;
    char ch;
    long num[10];
    long num2d[3][4];

    x = 5;
    y = 6.5;
    ch = 'A';

    printf("The values of the variables are: x = %d, y = %.2f, ch = %c", x, y, ch);

    for (i = 0; i < 10; i++) {
        scanf("%ld", &num[i]);
    }

    for (i = 0; i < 10; i++) {
        printf("\nnum[%d] = %ld", i, num[i]);
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            num2d[i][j] = i * j;
        }
    }

    return 0;
}
