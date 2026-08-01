#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

// Simple hash functionS
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert key into hash table using linear probing
void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 0;

    while (hashTable[index] != -1) { // slot already taken
        i++;
        index = (originalIndex + (i*i)) % TABLE_SIZE;
        if (i == TABLE_SIZE) {
            printf("Hash table is full, cannot insert key %d\n", key);
            return;
        }
    }

    hashTable[index] = key;
    printf("Inserted key %d at index %d\n", key, index);
}

// Search for a key in hash table
int search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 0;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return index;

        index = (originalIndex + ++i) % TABLE_SIZE;
        if (i == TABLE_SIZE)
            return -1;
    }
    return -1;
}

// Display the hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d -> %d\n", i, hashTable[i]);
        else
            printf("Index %d -> (empty)\n", i);
    }
}

int main() {
    // Initialize hash table with -1 (empty)
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;

    // Insert some keys
    insert(5);
    insert(25);
    insert(15);
    insert(35);
    insert(95);

    display();

    // Search keys
    int key = 25;
    int result = search(key);
    if (result != -1)
        printf("\nKey %d found at index %d\n", key, result);
    else
        printf("\nKey %d not found\n", key);

    return 0;
}
