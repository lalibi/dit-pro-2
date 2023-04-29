#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, *grades, sum;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    grades = (int *) malloc(n * sizeof(int)); /* (int *) calloc(n, sizeof(int)); */

    if (grades == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter the grade of student %d: ", i + 1);
        scanf("%d", &grades[i]);
    }

    sum = 0;
    for (i = 0; i < n; i++) {
        sum += grades[i];
    }

    free(grades);

    printf("Average grade: %.2f\n", (float) sum / n);

    return 0;
}
