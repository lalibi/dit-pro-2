#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS    5
#define MAX_NAME_LENGTH 20

struct student {
    int id;
    char name[MAX_NAME_LENGTH];
    int grade;
};

int main() {
    int i, sum, max, pos;
    /* char max_name[MAX_NAME_LENGTH]; */
    struct student students[MAX_STUDENTS]; /* magic numbers */

    for (i = 0; i < MAX_STUDENTS; i++) {
        students[i].id = i + 1;

        printf("Enter student %d name: ", students[i].id);
        scanf("%s", students[i].name);

        printf("Enter student %d grade: ", students[i].id);
        scanf("%d", &students[i].grade);
    }

    sum = 0;
    for (i = 0; i < MAX_STUDENTS; i++) {
        sum += students[i].grade;
    }
    printf("Average grade: %.2f\n", (float) sum / MAX_STUDENTS);

    max = -1;
    for (i = 0; i < MAX_STUDENTS; i++) {
        if (max < students[i].grade) {
            max = students[i].grade;
            pos = i;
            /* strcpy(max_name, students[i].name); */
        }
    }
    printf("Best student is %s with grade %d\n", students[pos].name, max);
    /* printf("Best student is %s with grade %d\n", max_name, max); */

    return 0;
}
