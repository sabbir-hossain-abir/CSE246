#include<stdio.h>
#include <stdlib.h>


void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high-1; j++)
	{
		if (arr[j]<pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high){
	if(low<high){
		int p = partition(arr, low, high);
		quickSort(arr, low, p - 1);
		quickSort(arr, p + 1, high);
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
	int arr[] = {10, 767, 86, 9, 15, 135};
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
    printf("Sorted Array: ");
    printArray(arr, n);
	return 0;
}
