#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Node for linked list
struct Node {
    int data;
    struct Node *next;
};

// Hash table containing linked lists
struct Node *table[SIZE];

// Insert a key into the hash table
void insert(int key) {

    int index = key % SIZE;

    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = key;
    newNode->next = NULL;

    // If bucket is empty
    if (table[index] == NULL) {
        table[index] = newNode;
    }

    // Otherwise insert at the beginning
    else {
        newNode->next = table[index];
        table[index] = newNode;
    }
}

// Display the hash table
void display() {

    printf("\nHash Table:\n");

    for (int i = 0; i < SIZE; i++) {

        printf("%d --> ", i);

        struct Node *temp = table[i];

        // Traverse linked list
        while (temp != NULL) {

            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main() {

    // Initialize every bucket to NULL
    for (int i = 0; i < SIZE; i++) {
        table[i] = NULL;
    }

    insert(10);
    insert(20);
    insert(30);
    insert(15);
    insert(25);
    insert(35);

    display();

    return 0;
}
