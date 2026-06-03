#include <stdio.h>

#define N 4   // Queue can store 3 elements

int queue[N];
int front = -1;
int rear = -1;

void Enqueue(int x) {
    // Check if queue is full
    if ((rear + 1) % N == front) {
        printf("Queue overflow\n");
    }
    // First element
    else if (front == -1) {
        front = rear = 0;
        queue[rear] = x;
    }
    else {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void Dequeue() {
    // Queue empty
    if (front == -1) {
        printf("Queue underflow\n");
    }
    // Only one element
    else if (front == rear) {
        printf("Dequeued element: %d\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("Dequeued element: %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void Display() {
    if (front == -1) {
        printf("Queue is empty\n");
    }
    else {
        int i = front;

        printf("Queue: ");

        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }

        printf("%d\n", queue[rear]);
    }
}

int main() {
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);

    Enqueue(40); // Overflow

    Display();

    Dequeue();
    Dequeue();

    Display();

    Enqueue(50);
    Enqueue(60);

    Display();

    return 0;
}