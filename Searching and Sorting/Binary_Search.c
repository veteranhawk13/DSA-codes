#include<stdio.h>

// Function declaration for Binary Search
void Binary_Search(int arr[], int n, int k);

int main(){

        int n, k;

        // Taking size of array from user
        printf("Enter n:");
        scanf("%d",&n);

        // Declaring array of size n
        int arr[n];

        // Taking array elements from user
        for(int i=0;i<n;i++){
                scanf("%d",&arr[i]);
        }

        // Taking the element to search
        printf("Enter k:");
        scanf("%d",&k);

        // Calling Binary Search function
        Binary_Search(arr,n,k);

        return 0;
}


// Function to perform Binary Search
void Binary_Search(int arr[],int n,int k){

        // Initializing starting and ending indexes
        int low=0;
        int high=n-1;

        // Variable to check whether element is found or not
        int flag=0;

        // Repeat search until low crosses high
        while(low<=high){

                // Finding middle index
                int mid=(low+high)/2;

                // Checking if middle element is the required element
                if(arr[mid]==k){
                        flag=1;
                        break;
                }

                // If key is smaller, search in left half
                else if(arr[mid]>k){
                        high=mid-1;
                }

                // If key is greater, search in right half
                else{
                        low=mid+1;
                }
        }

        // Display result
        if(flag==1){
                printf("%d number found at index %d",k,mid);
        }
        else{
                printf("Number not found");
        }
}
