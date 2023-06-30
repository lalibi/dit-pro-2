#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

typedef struct {
    pixel **pixels;
    int width;
    int height;
} image;

typedef struct {
    image *frames;
    int length;
} video;

int main() {
    int i, j, w, h;
    image img;

    printf("Enter image width and height: ");
    scanf("%d %d", &w, &h);

    img.width = w;
    img.height = h;
    img.pixels = (pixel **) malloc(sizeof(pixel *) * img.height);

    for (i = 0; i < img.height; i++) {
        img.pixels[i] = (pixel *) malloc(sizeof(pixel) * img.width);
    }

    for (i = 0; i < img.height; i++) {
        for (j = 0; j < img.width; j++) {
            printf("Enter pixel %d %d r, g, b: ", i + 1, j + 1);
            scanf("%hhu %hhu %hhu", &img.pixels[i][j].r, &img.pixels[i][j].g, &img.pixels[i][j].b);
        }
    }

    for (i = 0; i < img.height; i++) {
        free(img.pixels[i]);
    }

    free(img.pixels);

    video v;
    v.length = 240;
    v.frames = (image *) malloc(sizeof(image) * v.length);

    /* Do something with the video */

    free(v.frames);

    return 0;
}
