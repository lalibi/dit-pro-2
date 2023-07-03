#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILENAME  "1.in"
#define OUTPUT_FILENAME "1.out"
#define MAX_NAME_LENGTH 21

typedef struct {
    float grades[4];
    char sex;
    char name[MAX_NAME_LENGTH];
} student;

void read(FILE *, int, student[]);

void print(int, student[]);

void remove_nl(char *);

float average(const student *);

float total_average(int, student[]);

int main() {
    int i, n, b;
    student *students;
    FILE *fin, *fout;

    fin = fopen(INPUT_FILENAME, "r");

    if (fin == NULL) exit(1);

    fscanf(fin, "%d %d", &n, &b);

    students = (student *) malloc(sizeof(student) * n);
    read(fin, n, students);
    fclose(fin);

    print(n, students);

    fout = fopen(OUTPUT_FILENAME, "w");
    fprintf(fout, "Students: %d\n", n);
    fprintf(fout, "Total Average: %.2f\n",
            total_average(n, students));
    fclose(fout);

    free(students);

    return 0;
}

void read(FILE *fin, int n, student s[]) {
    int i;
    char t[MAX_NAME_LENGTH];
    for (i = 0; i < n; i++) {
        fscanf(fin, "%f %f %f %f %c ", &s[i].grades[0],
               &s[i].grades[1], &s[i].grades[2],
               &s[i].grades[3], &s[i].sex);
        fgets(t, MAX_NAME_LENGTH, fin);
        remove_nl(t);
        strcpy(s[i].name, t);
    }
}

void print(int n, student s[]) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%.2f %.2f %.2f %.2f - %.2f - %c - %s\n",
               s[i].grades[0], s[i].grades[1],
               s[i].grades[2], s[i].grades[3],
               average(&s[i]), s[i].sex, s[i].name);
    }
}

void remove_nl(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') str[i] = '\0';
        i++;
    }
}

float average(const student *s) {
    int i;
    float sum = 0;
    for (i = 0; i < 4; i++) {
        sum += s->grades[i];
    }
    return sum / 4;
}

float total_average(int n, student s[]) {
    int i;
    float sum = 0;
    for (i = 0; i < n; i++) {
        sum += average(&s[i]);
    }
    return sum / n;
}
