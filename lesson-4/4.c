#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[] = "Hello, world!";
    char p[20], *q;

    /* Get the length of s */
    printf("strlen: %ld\n", strlen(s));

    /* Make a copy of s in p */
    strcpy(p, s); /* not p = s; */

    q = (char *) malloc(sizeof(char) * (strlen(s) + 1));

    /* Make a copy of s in q */
    strcpy(q, s);

    printf("p: %s\n", p);
    printf("q: %s\n", q);

    /* Concatenate "!!" ate the end of p */
    strcat(p, "!!");

    printf("p: %s\n", p);

    printf("strcmp: %d\n", strcmp("Nikos", "Marios"));
    printf("strcmp: %d\n", strcmp("Marios", "Nikos"));
    printf("strcmp: %d\n", strcmp("Marios", "Marios"));

    free(q);

    return 0;
}
