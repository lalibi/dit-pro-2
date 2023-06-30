#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point *points;
    int n;
} polyline;

int main() {
    int i;
    float length;
    point p1, p2;
    polyline pl;

    printf("Enter number of points: ");
    scanf("%d", &pl.n);

    pl.points = (point *) malloc(sizeof(point) * pl.n);

    for (i = 0; i < pl.n; i++) {
        printf("Enter point %d x, y: ", i + 1);
        scanf("%d %d", &pl.points[i].x, &pl.points[i].y);
    }

    length = 0;
    for (i = 1; i < pl.n; i++) {
        p1 = pl.points[i - 1];
        p2 = pl.points[i];

        length += sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    }

    printf("Length of polyline: %.2f\n", length);

    free(pl.points);

    return 0;
}
