#include<stdio.h>

int main(){

    int n, k;
    int flag = 0;

    // Taking size of array
    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];

    // Taking array elements
    printf("Enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    // Element to search
    printf("Enter element to search: ");
    scanf("%d",&k);

    // Linear Search
    for(int i=0;i<n;i++){

        // Checking each element
        if(arr[i]==k){
            printf("%d found at index %d", k, i);
            flag = 1;
            break;
        }
    }

    // If element is not found
    if(flag==0){
        printf("Number not found");
    }

    return 0;
}
