#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char a[] = "Hello";
    char b[] = "2023";
    char c[] = "2023!";
    char d[] = "!2023";
    char e[] = "3.14";
    char *str, *r;
    long num;

    printf("atoi: %d\n", atoi(a)); /* 0 */
    printf("atoi: %d\n", atoi(b)); /* 2023 */
    printf("atoi: %d\n", atoi(c)); /* 2023 */
    printf("atoi: %d\n", atoi(d)); /* 0 */

    printf("atof: %f\n", atof(b)); /* 2023.000000 */
    printf("atof: %f\n", atof(e)); /* 3.140000 */

    str = "60kg";
    num = strtol(str, &r, 0);                             /* r points at k, num is 60 */

    printf("strtol: %ld\n", num);                         /* 60 */
    printf("strtol: %s\n", r);                            /* kg */
    printf("strtol: %s\n", r);                            /* kg */

    printf("strtol: %ld\n", strtol("10", NULL, 16));      /* 16 */
    printf("strtol: %ld\n", strtol("0x10", NULL, 16));    /* 16 */
    printf("strtol: %ld\n", strtol("010", NULL, 8));      /* 8 */
    printf("strtol: %ld\n", strtol("10", NULL, 8));       /* 8 */
    printf("strtol: %ld\n", strtol("01010011", NULL, 2)); /* 83 */

    return 0;
}
