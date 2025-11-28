
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node* insertEnd(struct node* head, int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    if (head == NULL) {
        newnode->next = newnode;
        newnode->prev = newnode;
        return newnode;
    }
    struct node* last = head->prev;
    newnode->next = head;
    head->prev = newnode;
    newnode->prev = last;
    last->next = newnode;
    return head;
}

void display(struct node* head) {
    if (head == NULL)
        return;
    struct node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    struct node* head = NULL;
    int n, data;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = insertEnd(head, data);
    }
    display(head);
    return 0;
}

