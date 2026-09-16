#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;

void insert(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;

    if (last == NULL) {
        last = newNode;
        newNode->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void display() {
    struct Node *temp;

    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = last->next;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    printf("Circular Linked List: ");
    display();

    return 0;
}