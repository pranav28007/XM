
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *front = NULL, *rear = NULL;

void insertFront(int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = front;

    if (front == NULL)
        rear = temp;
    else
        front->prev = temp;

    front = temp;
    printf("Inserted %d at front\n", data);
}

void insertRear(int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = rear;

    if (rear == NULL)
        front = temp;
    else
        rear->next = temp;

    rear = temp;
    printf("Inserted %d at rear\n", data);
}

void deleteFront() {
    if (front == NULL) {
        printf("Queue Empty!\n");
        return;
    }

    struct node *temp = front;
    printf("Deleted %d from front\n", temp->data);

    front = front->next;

    if (front != NULL)
        front->prev = NULL;
    else
        rear = NULL;

    free(temp);
}

void deleteRear() {
    if (rear == NULL) {
        printf("Queue Empty!\n");
        return;
    }

    struct node *temp = rear;
    printf("Deleted %d from rear\n", temp->data);

    rear = rear->prev;

    if (rear != NULL)
        rear->next = NULL;
    else
        front = NULL;

    free(temp);
}

void display() {
    struct node *p = front;
    if (p == NULL) {
        printf("Queue Empty!\n");
        return;
    }

    printf("DEQueue: ");
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data;

    while (1) {

        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertFront(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertRear(data);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:

                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
}

