#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
};

struct node *root = NULL;

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* Insert(struct node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    } else if (value < root->data) {
        root->left = Insert(root->left, value);
    } else if (value > root->data) {
        root->right = Insert(root->right, value);
    }
    return root;
}

struct node* Search(struct node *root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    } else if (key < root->data) {
        return Search(root->left, key);
    } else {
        return Search(root->right, key);
    }
}

struct node* findMin(struct node *node) {
    while (node != NULL && node->left != NULL) {
        node = node->left;
    }
    return node;
}

struct node* Delete(struct node *root, int key) {
    if (root == NULL) {
        return root;
    } else if (key < root->data) {
        root->left = Delete(root->left, key);
    } else if (key > root->data) {
        root->right = Delete(root->right, key);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left != NULL && root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        } else if (root->left == NULL && root->right != NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else {
            struct node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
            return root;
        }
    }
    return root;
}

void Preorder(struct node *curr){
    if(curr==NULL){
        return;
    }
    printf("%d ",curr->data);
    Preorder(curr->left);
    Preorder(curr->right);
}

int main() {
    root = Insert(root, 7);
    root = Insert(root, 3);
    root = Insert(root, 9);
    root = Insert(root, 1);
    root = Insert(root, 5);
    Preorder(root);
    printf("\n");
    root = Delete(root, 1);
    root = Delete(root, 9);
    Preorder(root);
    printf("\n");
    struct node* found = Search(root, 5);
    if (found != NULL)
        printf("Found: %d\n", found->data);
    else
        printf("Not found\n");

    root = Delete(root, 3);
    return 0;
}