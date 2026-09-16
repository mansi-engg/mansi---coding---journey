#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int priority;
    struct Node *next;
};

struct Node *front = NULL;

void enqueue(int value, int priority)
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->priority = priority;
    newNode->next = NULL;

    /* Insert at beginning if it has higher priority */
    if (front == NULL || priority < front->priority)
    {
        newNode->next = front;
        front = newNode;
    }
    else
    {
        temp = front;

        while (temp->next != NULL &&
               temp->next->priority <= priority)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("%d inserted with priority %d\n", value, priority);
}

void dequeue()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Priority Queue Underflow\n");
        return;
    }

    temp = front;

    printf("%d deleted (Priority %d)\n",
           temp->data, temp->priority);

    front = front->next;
    free(temp);
}

void display()
{
    struct Node *temp = front;

    if (front == NULL)
    {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue:\n");

    while (temp != NULL)
    {
        printf("Data = %d, Priority = %d\n",
               temp->data, temp->priority);

        temp = temp->next;
    }
}

int main()
{
    enqueue(10, 3);
    enqueue(20, 1);
    enqueue(30, 2);
    enqueue(40, 1);

    display();

    dequeue();
    display();

    return 0;
}