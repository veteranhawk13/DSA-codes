#include<stdio.h>
#include<stdlib.h>
struct node{                          
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;

void Insertfront(int val){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=head;
    head->prev=newNode;
    newNode->prev=tail;
    tail->next=newNode;
    head=newNode;
}

void Insertback(int val){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    tail->next=newNode;
    newNode->prev=tail;
    newNode->next=head;
    head->prev=newNode;
    tail=newNode;
}

void Deletefront(){
    struct node *temp=head;
    head=head->next;
    tail->next=head;
    head->prev=tail;
    free(temp);    
}

void Deleteback(){
    struct node *temp=tail;
    tail=tail->prev;
    tail->next=head;
    head->prev=tail;
    free(temp);
}
void Display(){
    struct node *temp=head;
    do{
        printf("%d->",temp->data);
        temp=temp->next;
    }
    while(temp!=head);
}

void ReverseDisplay(){
    struct node *temp=tail;
    do{
        printf("%d->",temp->data);
        temp=temp->prev;
    }
    while(temp!=tail);
}
int main(){
    int n,val;
    printf("Enter no of elements:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("Enter node %d:",i);
        scanf("%d",&val);
        struct node *newNode=(struct node*)malloc(sizeof(struct node));
        newNode->data=val;

        if(head==NULL){
            head=tail=newNode;
            newNode->next=head;
            newNode->prev=tail;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            newNode->next=head;
            head->prev=newNode;
            tail=newNode;
        }
    }
    Insertfront(7);
    Insertback(10);
    Display();
    Deletefront();
    printf("\n");
    Display();
    printf("\n");
    Deleteback();
    Display();
    printf("\n");
    ReverseDisplay();
    return 0;
}