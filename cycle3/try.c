#include <stdio.h>
#include <stdlib.h>

void swap(int * a,int * b){
    int temp = a;
    * a = * b;
    * b = temp;
}
void quicksort(int * arr,int low,int high){
    if(low<high){
        int j = partition(arr,low,high);
        quicksort(arr,low,j-1);
        quicksort(arr,j+1,high);
    }
}
void partion(int * arr ,int low,int high){
    int i = low;
    int j = high;
    int pivot = low;
    while(i<j){
        while(arr[i]<=arr[pivot]&&i<high)i++;
        while(arr[j]>arr[pivot]&&j>low) j--;
        if(i<j)
            swap(&arr[i],&arr[j]);
    }
    swap(&arr[j],&arr[pivot]);
    return j;   
}
int main(){
   
    printf("Enter the number of elements: ");
     int n;
    scanf("%d",&n);
    printf("enter the elements");
    int * arr = (int *)malloc(n* sizeof(int));
  
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    return 0;
}