#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];    // visited array
int queue[MAX];      // queue for BFS
int front = -1, rear = -1;
int n;               // number of vertices

void enqueue(int v) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

void BFS(int start) {
    int v, i;
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while ((v = dequeue()) != -1) {
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(start);

    return 0;
}
