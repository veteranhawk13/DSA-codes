#include<stdio.h>

int main(){

    int n;

    // Taking size of array
    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];

    // Taking array elements
    printf("Enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    // Bubble Sort
    for(int i=0;i<n-1;i++){

        for(int j=0;j<n-i-1;j++){

            // Swap if current element is greater than next element
            if(arr[j]>arr[j+1]){

                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    // Printing sorted array
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
