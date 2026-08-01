#include <stdio.h>

#define SIZE 10

// Hash table
int hashTable[SIZE];

// Initialize all positions with -1 (empty)
void initialize() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}

// First hash function
int hash1(int key) {
    return key % SIZE;
}

// Second hash function
// Step size should never be 0
int hash2(int key) {
    return 7 - (key % 7);
}

// Insert a key using double hashing
void insert(int key) {

    int index = hash1(key);   // Initial index
    int step = hash2(key);    // Step size
    int i = 0;

    // Continue until an empty position is found
    while (hashTable[index] != -1) {

        i++;

        // New index using double hashing formula
        index = (hash1(key) + i * step) % SIZE;
    }

    // Insert the key
    hashTable[index] = key;
}

// Display the hash table
void display() {

    printf("\nHash Table:\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d --> %d\n", i, hashTable[i]);
    }
}

int main() {

    initialize();

    insert(15);
    insert(25);
    insert(35);
    insert(45);
    insert(55);

    display();

    return 0;
}
