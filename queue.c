
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

int isEmpty() {
    return front == NULL;
}

void enqueue(int data) {
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return -1;
    }
    struct node* temp = front;
    int val = temp->data;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return val;
}

int peek() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return -1;
    }
    return front->data;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    struct node* temp = front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1) printf("%d dequeued\n", value);
                break;
            case 3:
                value = peek();
                if (value != -1) printf("Front: %d\n", value);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}

