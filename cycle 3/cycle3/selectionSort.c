#include <stdio.h>
#include <stdlib.h>
void swap(int * a,int * b);
void selectionSort(int * arr,int n);
void display(int * arr,int n);
void swap(int * a,int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int * arr,int n){
    for(int i =0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(&arr[i],&arr[j]);
            }
        }
    }
}
void display(int * arr,int n){
    printf("Sorted array: ");
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int * arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selectionSort(arr,n);
    display(arr,n);
    
  
}