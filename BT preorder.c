#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *Leftchild;
    int data;
    struct node *Rightchild;
}; struct node *root=NULL;

struct node * CreateNode(int value){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->Leftchild=NULL;
    newNode->Rightchild=NULL;
    return newNode;
}

void Preorder(struct node *curr){
    if(curr==NULL){
        return;
    }
    printf("%d ",curr->data);
    Preorder(curr->Leftchild);
    Preorder(curr->Rightchild);
}

int main(){
    root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    printf("PreOrder Traversal of Binary tree:");
    Preorder(root);
    return 0;
}