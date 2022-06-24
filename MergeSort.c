#include <stdio.h>
#include <stdlib.h>



void merge(int arr[], int l, int mid, int h)
{
	int i, j, k;
	int n1 = mid - l + 1;
	int n2 = h - mid;


	int L[n1], H[n2];


	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		H[j] = arr[mid + 1 + j];


	i = 0; 
	j = 0;
	k = l;
	
	while (i < n1 && j < n2) {
		if (L[i] <= H[j]) {
			arr[k] = L[i];
			k++;
			i++;
		}
		else {
			arr[k] = H[j];
			k++;
			j++;
		}
		
	}


	while (i < n1) {
		arr[k] = L[i];
		k++;
		i++;
		
	}


	while (j < n2) {
		arr[k] = H[j];
		k++;
		j++;

	}
}


void mergeSort(int arr[], int l, int h)
{
	if (l < h) {

		int mid = l + (h - l) / 2;

		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, h);

		merge(arr, l, mid, h);
	}
}


void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}


int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}
