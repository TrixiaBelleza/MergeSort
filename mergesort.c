#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[], int arr_size) {
	int i;
	for(i = 0; i < arr_size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int merge(int arr[], int left_index, int middle_index, int right_index) {
	//Initialize left and right arrays based on the number of elements that were passed on.
	int left_size = middle_index - left_index + 1;

	int right_size = right_index - middle_index;

	int L[left_size], R[right_size];

	//Copy the left elements to L from arr
	int i;
	for(i = 0; i < left_size; i++) {
		L[i] = arr[left_index + i];
	}
	//Copy the right elements to R from arr
	for(i = 0; i < right_size; i++) {
		R[i] = arr[middle_index + 1 + i];
	}

	int L_ptr = 0, R_ptr = 0, arr_ptr = left_index; 

	while((L_ptr < left_size) && (R_ptr < right_size)) {

		if(L[L_ptr] > R[R_ptr]) {

			arr[arr_ptr] = R[R_ptr];
			R_ptr++; 
		}

		else {
			arr[arr_ptr] = L[L_ptr];
			L_ptr++;
		}
		arr_ptr++;
	}

	//Copy the remaining left elements
	for(i = L_ptr; i < left_size; i++) {
		arr[arr_ptr] = L[i];
		arr_ptr++;
	}

	//Copy the remaining right elements
	for(i = R_ptr; i < right_size; i++) {
		arr[arr_ptr] = R[i];
		arr_ptr++;
	}
	return 1; 
}

int mergeSort(int arr[], int left_index, int right_index) {
	if(left_index < right_index) {
		//Find the middle point to divide the array into half
		int middle_index = (left_index + right_index) / 2;

		//Call merge sort for first half
		mergeSort(arr, left_index, middle_index);

		//Call merge sort for second half
		mergeSort(arr, middle_index+1, right_index);

		//Call the two halves to merge:
		merge(arr, left_index, middle_index, right_index);
	}
}


int main() {
	int size;
	printf("Enter size of array: ");
	scanf("%d", &size);

	int *arr;
	arr = (int *)malloc(size*sizeof(int));
	int i;
	for(i=0; i < size; i++) {
		printf("Enter number: ");
		scanf("%d", &arr[i]);
	}
	// int arr[] = {8,7,6,5,4,2,1,3};
	// int arr_size = sizeof(arr) / sizeof(arr[0]); 
	printArray(arr, size);

	mergeSort(arr, 0, size-1);

	printf("Final:\n");
	printArray(arr, size);
}