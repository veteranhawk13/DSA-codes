#include<stdio.h>

#define SIZE 10

int hashTable[SIZE];


// Function to insert element
void insert(int key){

    int index = key % SIZE;

    // Linear probing if position is already occupied
    while(hashTable[index] != -1){
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}


// Function to search element
void search(int key){

    int index = key % SIZE;
    int start = index;

    while(hashTable[index] != -1){

        if(hashTable[index] == key){
            printf("%d found at index %d", key, index);
            return;
        }

        index = (index + 1) % SIZE;

        // Avoid infinite loop
        if(index == start)
            break;
    }

    printf("Number not found");
}


int main(){

    int n, key;

    // Initialize hash table
    for(int i=0;i<SIZE;i++){
        hashTable[i] = -1;
    }

    printf("Enter number of elements: ");
    scanf("%d",&n);


    // Insert elements
    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&key);
        insert(key);
    }


    // Search element
    printf("Enter element to search: ");
    scanf("%d",&key);

    search(key);

    return 0;
}
