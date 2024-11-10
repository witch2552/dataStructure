#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b);
void heapsort(int * arr, int n);
void Buildmaxheap(int*  arr, int n);
void Heapify(int *arr, int i, int n);

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;  

}
void heapsort(int *arr, int n) {
    Buildmaxheap(arr, n);
    for(int i = n-1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        Heapify(arr, 0, i);
    }
}
void Buildmaxheap(int*  arr, int n) {
    for(int i = n/2-1; i >= 0; i--) {
        Heapify(arr, i, n);
    }
}
void Heapify(int *arr, int i, int n) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if(r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if(largest != i) {
        swap(&arr[i], &arr[largest]);
        Heapify(arr, largest, n);
    }
}
void main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
   
 

   Heapify(arr, 0, n);  
   Buildmaxheap(arr, n);
   heapsort(arr,n);
   printf("Sorted array: ");
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);  // Free the memory allocated for the original array
                                  
}