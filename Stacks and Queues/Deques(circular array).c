#include <stdio.h>
#define N 5
int deque[N];
int front = -1, rear = -1;

void Enqueue_front(int x) {
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) {
        printf("Queue Overflow\n");
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        deque[front] = x;
    }
    else if (front == 0) {
        front = N - 1;
        deque[front] = x;
    }
    else {
        front--;
        deque[front] = x;
    }
}

void Enqueue_rear(int x) {
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) {
        printf("Queue Overflow\n");
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        deque[rear] = x;
    }
    else if (rear == N - 1) {
        rear = 0;
        deque[rear] = x;
    }
    else {
        rear++;
        deque[rear] = x;
    }
}

void Dequeue_front() {
    if (front == -1 && rear == -1) {
        printf("Queue Underflow\n");
    }
    else if (front == rear) {
        printf("Deleted: %d\n", deque[front]);
        front = rear = -1;
    }
    else if (front == N - 1) {
        printf("Deleted: %d\n", deque[front]);
        front = 0;
    }
    else {
        printf("Deleted: %d\n", deque[front]);
        front++;
    }
}

void Dequeue_rear() {
    if (front == -1 && rear == -1) {
        printf("Queue Underflow\n");
    }
    else if (front == rear) {
        printf("Deleted: %d\n", deque[rear]);
        front = rear = -1;
    }
    else if (rear == 0) {
        printf("Deleted: %d\n", deque[rear]);
        rear = N - 1;
    }
    else {
        printf("Deleted: %d\n", deque[rear]);
        rear--;
    }
}

void Display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue is: ");
    int i = front;
    while (i != rear) {
        printf("%d ", deque[i]);
        i = (i + 1) % N;
    }
    printf("%d\n", deque[i]);
}

int main() {
    Enqueue_front(10);
    Enqueue_front(20);
    Enqueue_rear(40);
    Enqueue_rear(60);
    Display();
    Dequeue_front();
    Dequeue_front();
    Dequeue_rear();
    Dequeue_rear();
    Display();
}
