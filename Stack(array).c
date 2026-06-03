#include <stdio.h>

#define MAX 100

void Push(int stack[], int *top, int n, int item) {
    if (*top == n - 1) {
        printf("Stack overflow\n");
    } else {
        (*top)++;
        stack[*top] = item;
    }
}

int Pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        int item = stack[*top];
        (*top)--;
        return item;
    }
}

int Peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top];
    }
}

void Print(int stack[], int top) {
    printf("Stack implementation: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int stack[MAX];
    int top = -1;
    int n = 5;
    int item = 0;
    int choice;

    do {
        printf("\n1.Push  2.Pop  3.Peek  4.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item: ");
                scanf("%d", &item);
                Push(stack, &top, n, item);
                break;

            case 2:
                item = Pop(stack, &top);
                if (item != -1)
                    printf("%d removed\n", item);
                break;

            case 3:
                item = Peek(stack, top);
                if (item != -1)
                    printf("Last element: %d\n", item);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    Print(stack, top);
    return 0;
}