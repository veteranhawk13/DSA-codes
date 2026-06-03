#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;

void Enqueue(int item){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->info=item;
    newNode->next=NULL;
    if(front==NULL){
        front=newNode;
        rear=newNode;
        printf("%d element enqueued",newNode->info);
    }
    else{
        rear->next=newNode;
        rear=newNode;
        printf("%d element enqueued",newNode->info);
    }
    printf("\n");
}

void Dequeue(){
    if(front==NULL){
        printf("Queue Underflow");
    }
    else{
        struct node *temp=front;
        front=front->next;
        printf("%d element dequeued",temp->info);
        free(temp);
        printf("\n");
    }
}

void Display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node *t1 = front;
    printf("Queue elements: ");
    while (t1 != NULL) {
        printf("%d->", t1->info);
        t1 = t1->next;
    }
    printf("\n");
}


int main(){
    Enqueue(3);
    Enqueue(6);
    Enqueue(7);
    Enqueue(9);
    Enqueue(11);
    Display();
    Dequeue();
    Dequeue();
    Dequeue();
    Display();
    return 0;
}