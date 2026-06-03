#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *Left;
    int data;
    struct node *Right;
};

struct node *root = NULL;

struct node *CreateNode(int value) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->Left = NULL;
    newNode->Right = NULL;
    return newNode;
}

void Preorder(struct node *curr) {
    if (curr == NULL) {
        return;
    }
    printf("%d ",curr->data);
    Preorder(curr->Left);
    Preorder(curr->Right);
}

void Inorder(struct node *curr){
    if(curr==NULL){
        return;
    }
    Inorder(curr->Left);
    printf("%d ",curr->data);
    Inorder(curr->Right);
}

void Postorder(struct node *curr){
    if(curr==NULL){
        return;
    }
    Postorder(curr->Left);
    Postorder(curr->Right);
    printf("%d ",curr->data);
}

int main() {
    root = CreateNode(1);
    root->Left = CreateNode(2);
    root->Right = CreateNode(3);
    root->Left->Left = CreateNode(4);
    root->Left->Right = CreateNode(5);

    printf("PreOrder Traversal of Binary tree: ");
    Preorder(root);
    printf("\n");
    printf("Inorder Traversal of Binary tree:");
    Inorder(root);
    printf("\n");
    printf("Postorder Traversal of Binary tree: ");
    Postorder(root);
    printf("\n");

    return 0;
}
