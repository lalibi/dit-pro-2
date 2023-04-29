#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 10, *stack, top = 0, choice, x;

    stack = (int *) malloc(n * sizeof(int));

    if (stack == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    do {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (top == n) {
                n *= 2;

                stack = (int *) realloc(stack, n * sizeof(int));

                if (stack == NULL) {
                    printf("Error allocating memory\n");
                    return 1;
                }
            }

            printf("Enter a number: ");
            scanf("%d", &x);

            stack[top++] = x;
            break;
        case 2:
            if (top == 0) {
                printf("Stack is empty\n");
            } else {
                printf("Popped %d\n", stack[--top]);
            }
            break;
        }

    } while (choice != 0);

    free(stack);

    return 0;
}
