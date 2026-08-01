#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *last = NULL;


// Insert node at end
void insert(int value){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;

    if(last == NULL){

        last = newNode;
        last->next = last;
    }
    else{

        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}


// Search an element
void search(int key){

    if(last == NULL){
        printf("List is empty\n");
        return;
    }

    struct Node *temp = last->next;

    do{

        if(temp->data == key){
            printf("%d found\n", key);
            return;
        }

        temp = temp->next;

    }while(temp != last->next);

    printf("Element not found\n");
}


// Delete an element
void delete(int key){

    if(last == NULL){
        printf("List is empty\n");
        return;
    }

    struct Node *current = last->next;
    struct Node *previous = last;


    do{

        if(current->data == key){

            // Only one node
            if(current == last && current->next == last){
                last = NULL;
            }

            // Delete first node
            else if(current == last->next){
                last->next = current->next;
            }

            // Delete last node
            else if(current == last){
                previous->next = last->next;
                last = previous;
            }

            // Delete middle node
            else{
                previous->next = current->next;
            }

            free(current);
            printf("%d deleted\n", key);
            return;
        }

        previous = current;
        current = current->next;

    }while(current != last->next);


    printf("Element not found\n");
}


// Display list
void display(){

    if(last == NULL){
        printf("List is empty");
        return;
    }

    struct Node *temp = last->next;

    do{
        printf("%d ", temp->data);
        temp = temp->next;

    }while(temp != last->next);

    printf("\n");
}


int main(){

    int choice, value;

    while(1){

        printf("\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);


        switch(choice){

            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                insert(value);
                break;


            case 2:
                printf("Enter value to search: ");
                scanf("%d",&value);
                search(value);
                break;


            case 3:
                printf("Enter value to delete: ");
                scanf("%d",&value);
                delete(value);
                break;


            case 4:
                display();
                break;


            case 5:
                exit(0);


            default:
                printf("Invalid choice");
        }
    }

    return 0;
}
