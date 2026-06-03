#include<stdio.h>
#include<stdlib.h>

int** Sparse(int **array,int num,int r,int c);
void Transpose(int **sparse,int num);

int main(){
    int i,j,r,c,num=0;
    printf("Enter no of rows and columns:");
    scanf("%d%d",&r,&c);

    int **array=(int**)malloc(r*sizeof(int*));
    for(i=0;i<r;i++){
        array[i]=(int*)malloc(c*sizeof(int));
    }

    printf("Enter the elements:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&array[i][j]);
            if(array[i][j]!=0) num++;
        }
    }

    int **sparse = Sparse(array,num,r,c);
    Transpose(sparse,num);

    for(i=0;i<r;i++) free(array[i]);
    free(array);
    for(i=0;i<=num;i++) free(sparse[i]);
    free(sparse);

    return 0;
}

int** Sparse(int **array,int num,int r,int c){
    int **sparse=(int **)malloc((num+1)*sizeof(int*));
    for(int i=0;i<=num;i++){
        sparse[i]=(int *)malloc(3*sizeof(int));
    }

    sparse[0][0]=r;
    sparse[0][1]=c;
    sparse[0][2]=num;

    int k=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(array[i][j]!=0){
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=array[i][j];
                k++;
            }
        }
    }

    printf("\nSparse matrix (3-tuple):\n");
    for(int i=0;i<=num;i++){
        printf("%d %d %d\n",sparse[i][0],sparse[i][1],sparse[i][2]);
    }
    return sparse;
}

void Transpose(int **sparse,int num){
    int **transpose=(int **)malloc((num+1)*sizeof(int*));
    for(int i=0;i<=num;i++){
        transpose[i]=(int *)malloc(3*sizeof(int));
    }

    transpose[0][0]=sparse[0][1];
    transpose[0][1]=sparse[0][0];
    transpose[0][2]=sparse[0][2];

    for(int i=1;i<=num;i++){
        transpose[i][0]=sparse[i][1];  // swap row, col
        transpose[i][1]=sparse[i][0];
        transpose[i][2]=sparse[i][2];
    }

    printf("\nTranspose of Sparse Matrix:\n");
    for(int i=0;i<=num;i++){
        printf("%d %d %d\n",transpose[i][0],transpose[i][1],transpose[i][2]);
    }

    for(int i=0;i<=num;i++) free(transpose[i]);
    free(transpose);
}
