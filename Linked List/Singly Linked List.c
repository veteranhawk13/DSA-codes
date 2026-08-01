#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at end
void Insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Delete by value
void Delete(int value) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // If head node holds the value
    if (head != NULL && head->data == value) {
        head = head->next;
        free(temp);
        return;
    }

    // Search for the node
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // Value not found
    if (temp == NULL) return;

    // Unlink and free
    prev->next = temp->next;
    free(temp);
}

// Display list
void PrintList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Search for a value
int Search(int value) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) return 1;
        temp = temp->next;
    }
    return 0;
}

int main() {
    Insert(4);
    Insert(5);
    Insert(1);
    Insert(3);
    Insert(7);

    printf("List after insertion:\n");
    PrintList();

    printf("Deleting 3...\n");
    Delete(3);
    PrintList();

    printf("Searching for 5: %s\n", Search(5) ? "Found" : "Not Found");
    printf("Searching for 10: %s\n", Search(10) ? "Found" : "Not Found");

    return 0;
}
