 #include<stdio.h>
 #include<stdlib.h>
 int quicksort(int * arr, int low, int high);
 int  partition(int * arr, int low, int high);
 void swap(int * a, int * b);
 void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
 }
 int quicksort(int * arr, int low, int high){
     if(low<high){
         int j = partition(arr,low,high);
         quicksort(arr,low,j-1);
         quicksort(arr,j+1,high);
     }
 }
 int  partition(int * arr, int low, int high){
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
 void display(int * arr,int n){
     printf("Sorted array: ");
     for(int i = 0;i<n;i++){
         printf("%d ",arr[i]);
     }
     printf("\n");
 }
 void main(){
    printf("Enter the number of elements: ");
    int n;
    scanf("%d",&n);
    printf("enter elements");
    int * arr = (int *)malloc(n * sizeof(int));
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    display(arr,n);
    quicksort(arr,0,n-1);
    display(arr,n);
 }