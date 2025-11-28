
#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node *next;
};


struct node* createNode(int c, int e) {
    struct node* temp = malloc(sizeof(struct node));
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;
    return temp;
}


void insertEnd(struct node **head, int c, int e) {
    struct node *temp = createNode(c, e);
    if (*head == NULL) {
        *head = temp;
    } else {
        struct node *p = *head;
        while (p->next)
            p = p->next;
        p->next = temp;
    }
}


void display(struct node *head) {
    while (head) {
        printf("%dx^%d", head->coeff, head->exp);
        if (head->next) printf(" + ");
        head = head->next;
    }
    printf("\n");
}


struct node* addPoly(struct node *p1, struct node *p2) {
    struct node *result = NULL;
    while (p1 && p2) {
        if (p1->exp > p2->exp) {
            insertEnd(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            insertEnd(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            insertEnd(&result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1) {
        insertEnd(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2) {
        insertEnd(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
}

int main() {
    struct node *poly1 = NULL, *poly2 = NULL, *sum;


    insertEnd(&poly1, 5, 3);
    insertEnd(&poly1, 4, 2);
    insertEnd(&poly1, 2, 0);


    insertEnd(&poly2, 3, 3);
    insertEnd(&poly2, 2, 1);
    insertEnd(&poly2, 6, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    sum = addPoly(poly1, poly2);

    printf("Sum: ");
    display(sum);

    return 0;
}

