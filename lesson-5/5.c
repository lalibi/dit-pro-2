#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_node {
    int id;
    char name[20];
    struct list_node *next;
} node;

/* Declarations */
void append(int, char[], node **);
void prepend(int, char[], node **);
void print(node *);
node *search(int, node *);
void free_list(node *);

int main() {
    node *head = NULL, *s;

    append(1, "Nikos", &head);
    append(2, "Dimitris", &head);
    append(3, "Stefanos", &head);
    prepend(4, "Marios", &head);

    print(head);

    s = search(3, head);
    if (s != NULL) {
        printf("Found: %d %s\n", s->id, s->name);
    } else {
        printf("Not found\n");
    }

    free_list(head);

    return 0;
}

void prepend(int id, char name[], node **phead) {
    node *new = (node *) malloc(sizeof(node));

    new->id = id; /* (*new).id */
    strcpy(new->name, name);

    if (*phead == NULL) {
        new->next = NULL;
        *phead = new;
    } else {
        new->next = *phead;
        *phead = new;
    }
}

void append(int id, char name[], node **phead) {
    node *new = (node *) malloc(sizeof(node));

    new->id = id; /* (*new).id */
    strcpy(new->name, name);
    new->next = NULL;

    if (*phead == NULL) {
        *phead = new;
    } else {
        node *cur = *phead;

        while (cur->next != NULL) {
            cur = cur->next;
        }

        cur->next = new;
    }
}

void print(node *head) {
    node *cur = head;

    while (cur != NULL) {
        printf("%d %s\n", cur->id, cur->name);

        cur = cur->next;
    }
}

node *search(int id, node *head) {
    node *cur = head;

    while (cur != NULL) {
        if (cur->id == id) break;

        cur = cur->next;
    }

    return cur;
}

void free_list(node *head) {
    node *cur = head;

    while (cur != NULL) {
        node *tmp = cur;
        cur = cur->next;

        free(tmp);
    }
}
