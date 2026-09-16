#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *deleteNode(struct Node *head, int key) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
        return head;

    // If deleting first node
    if (temp->prev == NULL) {
        head = temp->next;

        if (head != NULL)
            head->prev = NULL;
    }
    else {
        temp->prev->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
    return head;
}

void display(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

    // Create nodes
    struct Node *a = malloc(sizeof(struct Node));
    struct Node *b = malloc(sizeof(struct Node));
    struct Node *c = malloc(sizeof(struct Node));

    a->data = 10;
    b->data = 20;
    c->data = 30;

    a->prev = NULL;
    a->next = b;

    b->prev = a;
    b->next = c;

    c->prev = b;
    c->next = NULL;

    head = a;

    printf("Before deletion:\n");
    display(head);

    head = deleteNode(head, 20);

    printf("After deletion:\n");
    display(head);

    return 0;
}