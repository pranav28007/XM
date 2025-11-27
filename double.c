#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* next,*prev;
};

void insertatbeg(struct node**ptr,int data)
{
	struct node*temp=malloc(sizeof(struct node));
	temp->data=data;
	temp->prev=NULL;
	temp->next=*ptr;
	(*ptr)->prev=temp;
	*ptr=temp;

}
void insertPos(struct node **head, int data, int pos) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;

    if (pos == 1 || *head == NULL) {
        temp->prev = NULL;
        temp->next = *head;
        if (*head)
            (*head)->prev = temp;
        *head = temp;
        return;
    }

    struct node *p = *head;
    for (int i = 1; i < pos - 1 && p->next; i++)
        p = p->next;

    temp->next = p->next;
    temp->prev = p;
    if (p->next)
        p->next->prev = temp;
    p->next = temp;
}

void deletePos(struct node **head, int pos) {
    if (*head == NULL) {
        printf("List Empty\n");
        return;
    }

    struct node *p = *head;

    if (pos == 1) {
        *head = p->next;
        if (*head) (*head)->prev = NULL;
        free(p);
        return;
    }

    for (int i = 1; i < pos && p; i++)
        p = p->next;

    if (p == NULL) {
        printf("Position Out of Range\n");
        return;
    }

    if (p->next)
        p->next->prev = p->prev;
    if (p->prev)
        p->prev->next = p->next;

    free(p);
}
void insertend(struct node*ptr,int data)
{
	struct node*temp=malloc(sizeof(struct node));
	temp->next=NULL;
	struct node*p=ptr;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=temp;
	temp->prev=p;
}
void deletebeg(struct node**ptr,int data)
{

	if(*ptr==NULL)
	{
		printf("list empty");
	}
	else{
		struct node*t=*ptr;
		*ptr=(*ptr)->next;
		(*ptr)->prev=NULL;
		free(t);
	}
}

void deletend(struct node*ptr)
{
	struct node*p=ptr;
      if(ptr==NULL)
	{
		printf("list empty");
	}
	struct node*a;

		while(p->next!=NULL)
		{
			p=p->next;
		}
		a=p->prev;
		a->next=NULL;
		free(p);

	}

void print(struct node*ptr)
{
	struct node*p=ptr;
	while(p!=NULL)
	{
		printf("%d->",p->data);
		p=p->next;
	}
	printf("NULL");
}
int main()
{
    struct node *head =malloc(sizeof(struct node));
	printf("Enter data\n");
	scanf("%d",&head->data);
    int choice, data, pos;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertatbeg(&head, data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertend(head, data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertPos(&head, data, pos);
                break;

            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePos(&head, pos);
                break;

            case 5:
                print(head);
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

