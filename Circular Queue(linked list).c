#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=0;
struct node *rear=0;
void Enqueue(int x){
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=x;
    newNode->next=0;
    if(rear==0){
        front=rear=newNode;
        rear->next=front;   
    }
    else{
        rear->next=newNode;
        rear=newNode;
        rear->next=newNode;
        rear=newNode;
        rear->next=front;
    }
}

void Dequeue(){
    struct node *temp=front;
    if(front==0 && rear==0){
        printf("Queue empty");
    }
    else if(front==rear){
        front=rear=0;
        free(temp);
    }
    else{
        front=front->next;
        rear->next=front;
        free(temp);
    }
}

void Print(){
    printf("Queue: ");
    struct node *p=front;
    do{
        printf("%d->",p->data);
        p=p->next;
    }
    while(p!=front);
}
int main(){
    Enqueue(5);
    Enqueue(10);
    Enqueue(13);
    Enqueue(17);
    Print();
    Dequeue();
    Dequeue();
    Dequeue();
    Print();
}