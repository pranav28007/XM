
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertatbeg(struct node **tail, int data) {
    struct node *p = (*tail)->next;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = p;
    (*tail)->next = temp;
}

void insertatend(struct node **tail, int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = (*tail)->next;
    (*tail)->next = temp;
    *tail = temp;
}

void insertatpos(struct node **tail, int data, int pos) {
    struct node *p = (*tail)->next;
    int i = 1;
    while (i < pos - 1) {
        p = p->next;
        i++;
    }
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = p->next;
    p->next = temp;
    if (p == *tail) {
        *tail = temp;
    }
}

void deleteatbeg(struct node **tail) {
    struct node *p = (*tail)->next;
    (*tail)->next = p->next;
    free(p);
}

void deleteatend(struct node **tail) {
    struct node *p = (*tail)->next;
    while (p->next != *tail)
        p = p->next;
    p->next = (*tail)->next;
    free(*tail);
    *tail = p;
}

void deleteatpos(struct node **tail, int pos) {
    struct node *p = (*tail)->next;
    int i = 1;
    while (i < pos - 1) {
        p = p->next;
        i++;
    }
    struct node *q = p->next;
    p->next = q->next;
    if (q == *tail)
        *tail = p;
    free(q);
}

void display(struct node *tail) {
    struct node *p = tail->next;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != tail->next);
    printf("\n");
}

int main() {
    struct node *tail = NULL, *temp;
    int ch, val, pos;

    // create first node
    temp = malloc(sizeof(struct node));
    temp->data = 10;
    tail = temp;
    tail->next = tail;

    while (1) {
        printf("\n1.InsertBeg 2.InsertEnd 3.InsertPos\n");
        printf("4.DeleteBeg 5.DeleteEnd 6.DeletePos\n");
        printf("7.Display 8.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &val);
            insertatbeg(&tail, val);
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d", &val);
            insertatend(&tail, val);
            break;

        case 3:
            printf("Enter data & pos: ");
            scanf("%d %d", &val, &pos);
            insertatpos(&tail, val, pos);
            break;

        case 4:
            deleteatbeg(&tail);
            break;

        case 5:
            deleteatend(&tail);
            break;

        case 6:
            printf("Enter pos: ");
            scanf("%d", &pos);
            deleteatpos(&tail, pos);
            break;

        case 7:
            display(tail);
            break;

        case 8:
            exit(0);
        }
    }
    return 0;
}

