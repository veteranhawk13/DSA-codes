#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *left;
    int data;
    struct node *right;
};


// Create a new node
struct node* createNode(int value){

    struct node *newNode = malloc(sizeof(struct node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


// Insert a node into BST
struct node* Insert(struct node *root, int value){

    if(root == NULL){
        return createNode(value);
    }

    if(value < root->data){
        root->left = Insert(root->left, value);
    }
    else if(value > root->data){
        root->right = Insert(root->right, value);
    }

    return root;
}


// Search a node in BST
struct node* Search(struct node *root, int key){

    if(root == NULL || root->data == key){
        return root;
    }

    if(key < root->data){
        return Search(root->left, key);
    }
    else{
        return Search(root->right, key);
    }
}


// Find minimum value node
struct node* findMin(struct node *root){

    while(root->left != NULL){
        root = root->left;
    }

    return root;
}


// Delete a node from BST
struct node* Delete(struct node *root, int key){

    if(root == NULL){
        return NULL;
    }


    if(key < root->data){
        root->left = Delete(root->left, key);
    }

    else if(key > root->data){
        root->right = Delete(root->right, key);
    }

    else{

        // No child
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }

        // Only right child
        else if(root->left == NULL){

            struct node *temp = root->right;
            free(root);
            return temp;
        }

        // Only left child
        else if(root->right == NULL){

            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Two children
        else{

            struct node *temp = findMin(root->right);

            root->data = temp->data;

            root->right = Delete(root->right, temp->data);
        }
    }

    return root;
}


int main(){

    struct node *root = NULL;

    // Inserting elements
    root = Insert(root, 7);
    Insert(root, 2);
    Insert(root, 9);
    Insert(root, 1);
    Insert(root, 5);


    // Searching
    if(Search(root,5)!=NULL)
        printf("Element found\n");
    else
        printf("Element not found\n");


    // Deleting
    root = Delete(root,2);

    printf("Deletion successful\n");


    return 0;
}
