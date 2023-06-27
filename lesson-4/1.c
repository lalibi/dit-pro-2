#include <stdio.h>

int main() {
    int i;  /* [-2^31, 2^31-1] */
    char j; /* unsigned int - 1 byte -> 8 bits -> [0, 255] */
    char *name;

    /* Bitwise operators */

    printf("%c\n", 65);      /* ASCII code for 'A' */
    printf("%c\n", 65 + 32); /* ASCII code for 'a' */
    printf("%c\n", 66 | 32); /* ASCII code for 'b' */

    /* 65 -> 0100 0001 */
    /* 97 -> 0110 0001 */

    printf("%d\n", 2 ^ 3); /*  XOR */

    /* 2     -> 0010 */
    /* 3     -> 0011 */
    /* 2 ^ 3 -> 0001 */

    /*
      0100 0001
    & 1001 1011
    -----------
      0000 0001

      0100 0001
    | 1001 1011
    -----------
      1101 1011

      0100 0001
    | 0010 0000
    -----------
      0110 0001
    */

    for (i = 60; i < 70; i++) {
        printf(" %d|%c", i, i);
    }

    printf("\n");

    for (j = 60; j < 70; j++) {
        printf(" %d|%c", j, j);
    }

    printf("\n");

    name = "Marios";

    /* 8 is the Backspace char */

    printf("%s%c%c%c%c\n", name, 8, 8, 'O', 'S');

    return 0;
}
