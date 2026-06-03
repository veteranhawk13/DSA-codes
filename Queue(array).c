#include <stdio.h>
int front = -1, rear = -1;
int queue[100]; 
void Enqueue(int item, int n) {
    if (rear == n - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = item;
    printf("Enqueued: %d\n", item);
}

void Dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void Display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of queue: ");
    scanf("%d", &n);

    Enqueue(15, n);
    Enqueue(23, n);
    Enqueue(17, n);
    Enqueue(45,n);
    Enqueue(19,n);
    Enqueue(71,n);
    Enqueue(20,n);
    Enqueue(23,n);

    Display();

    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();  

    Display();

    return 0;
}
