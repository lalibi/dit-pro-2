#include <stdio.h>

typedef struct _node {
    int data;
    struct _node *next;
} node;

void print_list(node *head) {
    node *cur = head;

    while (cur != NULL) {
        printf("%d ", cur->data); /* (*cur).data; */

        cur = cur->next;
    }
    printf("\n");
}

int main() {
    node *head = NULL;

    node n1, n2, n3;

    n1.data = 34;
    n1.next = NULL;

    head = &n1;

    print_list(head);

    n3.data = 12;
    n3.next = NULL;

    n1.next = &n3;

    print_list(head);

    n2.data = 56;
    n2.next = &n3; /* n1.next; */

    n1.next = &n2;

    print_list(head);

    return 0;
}
