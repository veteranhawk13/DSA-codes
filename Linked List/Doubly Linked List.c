#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;


// Insert node at end
void insert(int value){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;


    if(head == NULL){

        newNode->prev = NULL;
        head = newNode;
    }
    else{

        struct Node *temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }
}


// Delete a node
void delete(int key){

    struct Node *temp = head;


    while(temp != NULL){

        if(temp->data == key){

            // Delete first node
            if(temp->prev == NULL){

                head = temp->next;

                if(head != NULL)
                    head->prev = NULL;
            }

            // Delete middle or last node
            else{

                temp->prev->next = temp->next;

                if(temp->next != NULL)
                    temp->next->prev = temp->prev;
            }

            free(temp);
            printf("%d deleted\n", key);
            return;
        }

        temp = temp->next;
    }

    printf("Element not found\n");
}


// Display list
void display(){

    struct Node *temp = head;

    while(temp != NULL){

        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}


int main(){

    // Inserting elements
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    printf("Doubly Linked List: ");
    display();


    // Deleting element
    delete(20);

    printf("After deletion: ");
    display();


    return 0;
}
