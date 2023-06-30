#include <stdio.h>

int main() {
    int c, grade;
    float sum;

    FILE *in, *out;

    in = fopen("1.in", "r");

    c = 0;
    sum = 0;
    while (fscanf(in, "%d", &grade) != EOF) {
        c += 1;
        sum += grade;
    }

    fclose(in);

    out = fopen("1.out", "w");

    fprintf(out, "%.2f", sum / c);

    return 0;
}
