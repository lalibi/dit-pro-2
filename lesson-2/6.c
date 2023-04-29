#include <stdio.h>
#include <stdlib.h>

#define N 10

int main() {
    /* char names[2][N];
    char *names[2] = { "Marios", "Nikos" }; */

    int i, x, y;
    char **names;

    names = (char **) malloc(2 * sizeof(char *));

    for (i = 0; i < 2; i++) {
        names[i] = (char *) malloc(N * sizeof(char));
    }

    for (i = 0; i < 2; i++) {
        printf("Enter name %d: ", i + 1);
        scanf("%s", names[i]);
    }

    for (i = 0; i < 2; i++) {
        printf("%s\n", names[i]);
    }

    printf("Select which name and which character: ");
    scanf("%d %d", &x, &y);

    x--;
    y--;

    printf("%c\n", names[x][y]);
    printf("%c\n", *(*(names + x) + y));

    for (i = 0; i < 2; i++) {
        free(names[i]);
    }

    free(names);

    return EXIT_SUCCESS;
}
