#include <stdio.h>
#define MAX 100

int data[MAX];        
int left[MAX];        
int right[MAX];       
int nodeCount = 0;    


int createNode(int value) {
    if (nodeCount >= MAX) {
        printf("Tree is full!\n");
        return -1;
    }
    data[nodeCount] = value;
    left[nodeCount] = -1;  
    right[nodeCount] = -1;
    return nodeCount++;
}


void setChildren(int parent, int leftChild, int rightChild) {
    left[parent] = leftChild;
    right[parent] = rightChild;
}


void inorder(int root) {
    if (root == -1) return;
    inorder(left[root]);
    printf("%d ", data[root]);
    inorder(right[root]);
}

void preorder(int root) {
    if (root == -1) return;
    printf("%d ", data[root]);
    preorder(left[root]);
    preorder(right[root]);
}

void postorder(int root) {
    if (root == -1) return;
    postorder(left[root]);
    postorder(right[root]);
    printf("%d ", data[root]);
}

int main() {
    int root = createNode(1);
    int n2 = createNode(2);
    int n3 = createNode(3);
    int n4 = createNode(4);
    int n5 = createNode(5);

    // Build tree manually:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    setChildren(root, n2, n3);
    setChildren(n2, n4, n5);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
