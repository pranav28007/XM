#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

int isEmpty() {
    return top == NULL;
}

void push(int data) {
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = top;
    top = temp;
}

int pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return -1;
    }
    struct node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int peek() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return -1;
    }
    return top->data;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    struct node* temp = top;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("1.Push 2.Pop 3.Peek 4.Display 5.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) printf("%d popped\n", value);
                break;
            case 3:
                value = peek();
                if (value != -1) printf("Top: %d\n", value);
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

