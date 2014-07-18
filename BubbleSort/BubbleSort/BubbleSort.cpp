#include <iostream>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void printArray(int arr[], int size)
{
	std::cout << "Array:";
	for (int i = 0; i < size; i++) {
		std::cout << " " << arr[i];
	}
	std::cout << std::endl;
}


void bubbleSort(int arr[], int size)
{
	int it = 0;
	for (int i = 0; i < size - 1; i++) {
		it++;
		for (int j = 0; j < size - i - 1; j++) {
			it++;
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void bubbleSortOptimized(int arr[], int size)
{
	int it = 0;
	for (int i = 0; i < size - 1; i++) {
		it++;
		bool isSwapped = false;
		for (int j = 0; j < size - i - 1; j++) {
			it++;
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				isSwapped = true;
			}
		}
		if (!isSwapped) {
			return;
		}
	}
}

int main()
{
	int arr[] = {5, 2, 7, 3, 6, 1};
	int size = sizeof(arr) / sizeof(arr[0]);
	int arr2[] = {5, 2, 7, 3, 6, 1};
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	std::cout << "not optimized" << std::endl;
	printArray(arr, size);
	bubbleSort(arr, size);
	printArray(arr, size);
	std::cout << "optimized" << std::endl;
	printArray(arr2, size2);
	bubbleSortOptimized(arr2, size2);
	printArray(arr2, size2);
	return 0;
}
