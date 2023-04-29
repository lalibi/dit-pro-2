#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, *grades, sum;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    grades = (int *) malloc(n * sizeof(int)); /* (int *) calloc(n, sizeof(int)); */

    if (grades == NULL) {
        printf("Error allocating memory\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++) {
        printf("Enter the grade of student %d: ", i + 1);
        scanf("%d", &grades[i]);
    }

    for (i = 0; i < n; i++) {
        printf("Grade of student %d: %d\n", i + 1, *(grades + i)); /* grades[i] */
    }

    free(grades);

    return EXIT_SUCCESS;
}
