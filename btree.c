
#include <stdio.h>
#include <stdlib.h>

#define t 2

typedef struct BTreeNode {
    int keys[2*t-1];
    struct BTreeNode* child[2*t];
    int n;
    int leaf;
} BTreeNode;

BTreeNode* createNode(int leaf) {
    BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->leaf = leaf;
    newNode->n = 0;
    for(int i = 0; i < 2*t; i++)
        newNode->child[i] = NULL;
    return newNode;
}

void traverse(BTreeNode* root) {
    if(root == NULL) return;
    int i;
    for(i = 0; i < root->n; i++) {
        if(!root->leaf) traverse(root->child[i]);
        printf("%d ", root->keys[i]);
    }
    if(!root->leaf) traverse(root->child[i]);
}

BTreeNode* search(BTreeNode* root, int key) {
    int i = 0;
    while(i < root->n && key > root->keys[i])
        i++;

    if(i < root->n && root->keys[i] == key)
        return root;

    if(root->leaf)
        return NULL;

    return search(root->child[i], key);
}

void splitChild(BTreeNode* parent, int i, BTreeNode* y) {
    BTreeNode* z = createNode(y->leaf);
    z->n = t - 1;

    for(int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if(!y->leaf) {
        for(int j = 0; j < t; j++)
            z->child[j] = y->child[j + t];
    }

    y->n = t - 1;

    for(int j = parent->n; j >= i+1; j--)
        parent->child[j+1] = parent->child[j];

    parent->child[i+1] = z;

    for(int j = parent->n - 1; j >= i; j--)
        parent->keys[j+1] = parent->keys[j];

    parent->keys[i] = y->keys[t-1];
    parent->n++;
}

void insertNonFull(BTreeNode* root, int key) {
    int i = root->n - 1;

    if(root->leaf) {
        while(i >= 0 && root->keys[i] > key) {
            root->keys[i+1] = root->keys[i];
            i--;
        }
        root->keys[i+1] = key;
        root->n++;
    } else {
        while(i >= 0 && root->keys[i] > key)
            i--;

        if(root->child[i+1]->n == 2*t-1) {
            splitChild(root, i+1, root->child[i+1]);
            if(root->keys[i+1] < key)
                i++;
        }
        insertNonFull(root->child[i+1], key);
    }
}

void insert(BTreeNode** rootRef, int key) {
    BTreeNode* root = *rootRef;
    if(root->n == 2*t - 1) {
        BTreeNode* newRoot = createNode(0);
        newRoot->child[0] = root;
        splitChild(newRoot, 0, root);
        insertNonFull(newRoot, key);
        *rootRef = newRoot;
    } else {
        insertNonFull(root, key);
    }
}

int main() {
    BTreeNode* root = createNode(1);
    int choice, key;

    while(1) {
        printf("\n1.Insert  2.Search  3.Display  4.Exit\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter key: ");
            scanf("%d", &key);
            insert(&root, key);
        }
        else if(choice == 2) {
            printf("Enter key to search: ");
            scanf("%d", &key);
            if(search(root, key) != NULL)
                printf("Key Found!\n");
            else
                printf("Key Not Found!\n");
        }
        else if(choice == 3) {
            printf("B-Tree: ");
            traverse(root);
            printf("\n");
        }
        else
            break;
    }
    return 0;
}

