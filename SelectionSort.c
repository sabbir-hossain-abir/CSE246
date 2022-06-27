#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n){
    
    int i,j,min_index;

    for (i = 0; i < n-1; i++)
    {
        min_index=i;
        for (j = i+1; j < n; j++){
        
            if (arr[j]<arr[min_index])
            
            min_index=j;         
        }
    swap(&arr[min_index], &arr[i]);
        
    }
    
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
  

int main()
{
    int arr[] = {341, 255, 12, 242, 121};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}