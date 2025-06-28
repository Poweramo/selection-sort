#include <stdio.h>

int find_smallest_num_index(int arr[], int arrSize, int startIndex);
int *selection_sort(int unsortedArr[], int unsortedArrSize, int *sortedArr);

int main(void) {
	int unsortedArr[] = { 6, 8, 7, 0, 1, 5, 9, 11, 10, 3, 12, 2, 4 };
	int unsortedArrSize = sizeof(unsortedArr) / sizeof(unsortedArr[0]);
	int sortedArrSize = unsortedArrSize;
	int emptySortedArr[sortedArrSize];
	int *sortedArr = selection_sort(unsortedArr, unsortedArrSize, emptySortedArr);

	for (int i = 0; i < sortedArrSize; i++) {
		int number = sortedArr[i];
		printf("Element %d: %d\n", i + 1, number);
	}

	return 0;
}

// Time complexity: O(N)
int find_smallest_num_index(int arr[], int arrSize, int startIndex) {
	int smallestNumIndex = startIndex;

	for (int i = startIndex + 1; i < arrSize; i++) {
		int number = arr[i];
		int smallestNum = arr[smallestNumIndex];

		if (number < smallestNum) smallestNumIndex = i;
	}

	return smallestNumIndex;
}

// Enter as argument sortedArr pointer to an array as a buffer 
// to populate it and return it afterwards
// Time complexity: O(N²)
int *selection_sort(int unsortedArr[], int unsortedArrSize, int *sortedArr) {
	for (int i = 0; i < unsortedArrSize; i++) {
		int smallestNumIndex = find_smallest_num_index(unsortedArr, unsortedArrSize, i);
		int smallestNum = unsortedArr[smallestNumIndex];
		int numAtIndexI = unsortedArr[i];

		if (smallestNumIndex != i) {
			unsortedArr[smallestNumIndex] = numAtIndexI;
			unsortedArr[i] = smallestNum;
		}
	}

	int sortedArrSize = unsortedArrSize;
	for (int i = 0; i < sortedArrSize; i++) {
		sortedArr[i] = unsortedArr[i];
	}

	return sortedArr;
}
