#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char data[50];
    int priority;
    struct node *next;
};
struct node *head=NULL;

void Enqueue(){
    char value[50];
    int prior;
    printf("Enter value and priority number:");
    scanf("%s %d",value,&prior);
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    strcpy(newNode->data,value);
    newNode->priority=prior;
    if(head==NULL || head->priority >= prior){
        newNode->next=head;
        head=newNode;
    }
    else{
        struct node *temp=head;
        while(temp->next!=NULL && temp->next->priority < prior){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    printf("%s element enqueued\n",newNode->data);
    printf("\n");
}

void Dequeue(){
    printf("%s element dequeued\n",head->data);
    struct node *temp=head;
    head=head->next;
    free(temp);
    printf("\n");
}

void Traverse(){
    printf("Elements traversed:");
    struct node *temp=head;
    while(temp!=NULL){
        printf("%s|%d ->",temp->data,temp->priority);
        temp=temp->next;
    }
    printf("\n");
}


int main(){
    int ch;
    printf("1.Enqueue 2.Dequeue 3.Traverse 4.Exit\n");
    while(1){
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
            Enqueue();
            break;
            case 2:
            Dequeue();
            break;
            case 3:
            Traverse();
            break;
            case 4:
            exit(0);  
            default:
            printf("Invalid choice\n");
        }
    }
}