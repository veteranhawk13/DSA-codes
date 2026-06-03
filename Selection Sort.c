#include<stdio.h>
void SelectionSort(int array[],int n);
int main(){
    int n=8;
    int array[]={14,33,27,10,35,19,42,44};
    SelectionSort(array,n);
    return 0;
}
void SelectionSort(int array[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if (array[min]> array[j])
                min=j;
        }
        int temp=array[i];
        array[i]=array[min];
        array[min]=temp;
    }
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
}