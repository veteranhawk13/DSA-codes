#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
}; 
struct node *top=NULL;

void Push(){
    int data;
    printf("Enter the data:");
    scanf("%d",&data);
    if(top==NULL){
        top = (struct node*)malloc(sizeof(struct node));
        top->info=data;
        top->next=NULL;
    }
    else
    {
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->next=top;
        temp->info=data;
        top=temp;
    }
}

void Pop(){
    struct node *temp=top;
    if(top==NULL){
        printf("Error");
    }
    else
    {   
        printf("Deleted value:%d\n",top->info);
        top=top->next;
        free(temp);
    }
}

void Peek(){
    struct node *temp=top;
    if(temp==NULL){
        printf("Stack underflow");
    }
    else{
        printf("Last element:%d\n",temp->info);
    }
}
void Display(){
    struct node *temp=top;
    if(temp==NULL){
        printf("Stack underflow");
        return;
    }
    else{
        while(temp!=NULL){
            printf("%d ->",temp->info);
            temp=temp->next;
        }
        printf("\n");
    }
}


int main(){
    int choice;
    while(1){
        printf("1.Push 2.Pop 3.Peek 4.Display\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:Push(); break;
            case 2:Pop(); break;
            case 3:Peek(); break;
            case 4:Display(); break;
        }
    }
    return 0;
    
}
