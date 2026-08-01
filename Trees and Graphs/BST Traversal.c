#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *left;
    int data;
    struct node *right;
};


// Create Node
struct node* createNode(int value){

    struct node *newNode = malloc(sizeof(struct node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


// Preorder Traversal (Root -> Left -> Right)
void Preorder(struct node *root){

    if(root == NULL)
        return;

    printf("%d ", root->data);

    Preorder(root->left);

    Preorder(root->right);
}


// Inorder Traversal (Left -> Root -> Right)
void Inorder(struct node *root){

    if(root == NULL)
        return;

    Inorder(root->left);

    printf("%d ", root->data);

    Inorder(root->right);
}


// Postorder Traversal (Left -> Right -> Root)
void Postorder(struct node *root){

    if(root == NULL)
        return;

    Postorder(root->left);

    Postorder(root->right);

    printf("%d ", root->data);
}


int main(){

    struct node *root = NULL;

    // Creating Binary Tree
    root = createNode(7);

    root->left = createNode(2);
    root->right = createNode(9);

    root->left->left = createNode(1);
    root->left->right = createNode(5);


    printf("Preorder: ");
    Preorder(root);

    printf("\nInorder: ");
    Inorder(root);

    printf("\nPostorder: ");
    Postorder(root);


    return 0;
}
