#include <stdio.h>

int main() {

    int arr[100];
    int n, choice;
    int element, position;

    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {

        printf("\n----- MENU -----\n");
        printf("1. Traverse Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            // Traversal
            case 1:

                printf("\nArray Elements are:\n");

                for(int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }

                printf("\n");
                break;

            // Insertion
            case 2:

                printf("Enter the element to insert: ");
                scanf("%d", &element);

                printf("Enter the position (1 to %d): ", n + 1);
                scanf("%d", &position);

                if(position < 1 || position > n + 1) {
                    printf("Invalid Position!\n");
                    break;
                }

                // Shift elements to the right
                for(int i = n; i >= position; i--) {
                    arr[i] = arr[i - 1];
                }

                arr[position - 1] = element;
                n++;

                printf("Element inserted successfully.\n");
                break;

            // Deletion
            case 3:

                printf("Enter the position to delete (1 to %d): ", n);
                scanf("%d", &position);

                if(position < 1 || position > n) {
                    printf("Invalid Position!\n");
                    break;
                }

                // Shift elements to the left
                for(int i = position - 1; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }

                n--;

                printf("Element deleted successfully.\n");
                break;

            case 4:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 4);

    return 0;
}
