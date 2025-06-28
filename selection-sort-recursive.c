#include <stdio.h>

int find_smallest_num_index(int arr[], int arrSize, int smallestNumIndex, int index);
int *selection_sort(int unsortedArr[], int unsortedArrSize, int *sortedArr, int index);

int main(void) {
	int unsortedArr[] = { 6, 8, 7, 0, 1, 5, 9, 11, 10, 3, 12, 2, 4 };
	int unsortedArrSize = sizeof(unsortedArr) / sizeof(unsortedArr[0]);
	int sortedArrSize = unsortedArrSize;
	// buf to give to this function as an argument and then return its pointer
	int emptySortedArr[sortedArrSize];
	int startIndex = 0;
	int *sortedArr = selection_sort(unsortedArr, unsortedArrSize, emptySortedArr, startIndex);

	for (int i = 0; i < sortedArrSize; i++) {
		int number = sortedArr[i];
		printf("Element at index %d: %d\n", i + 1, number);
	}

	return 0;
}

// Time complexity : O(N)
int find_smallest_num_index(int arr[], int arrSize, int smallestNumIndex, int index) {
	if (index >= arrSize) return smallestNumIndex;

	if (arr[index] < arr[smallestNumIndex]) smallestNumIndex = index;
	return find_smallest_num_index(arr, arrSize, smallestNumIndex, index + 1);
}

// Time complexity : O(N²)
int *selection_sort(int unsortedArr[], int unsortedArrSize, int *sortedArr, int index) {
	if (index >= unsortedArrSize) {
		for (int i = 0; i < unsortedArrSize; i++) {
			sortedArr[i] = unsortedArr[i];
		}

		return sortedArr;
	}

	int smallestNumIndex = find_smallest_num_index(unsortedArr, unsortedArrSize, index, index + 1);
	int currNum = unsortedArr[index];
	int smallestNum = unsortedArr[smallestNumIndex];

	if (smallestNumIndex != index) {
		unsortedArr[index] = smallestNum;
		unsortedArr[smallestNumIndex] = currNum;
	}

	return selection_sort(unsortedArr, unsortedArrSize, sortedArr, index + 1);
}
