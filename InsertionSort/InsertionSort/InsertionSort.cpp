#include <iostream>

void printArray(int arr[], int size)
{
	std::cout << "arra:";
	for (int i = 0; i < size; i++)
		std::cout << " " << arr[i];
	std::cout << std::endl;
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void insertionSort(int arr[], int size)
{
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (key < arr[j])
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = key;
	}
}

int main()
{
	int arr[] = {5, 2, 7, 9, 3};
	int size = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, size);
	insertionSort(arr, size);
	printArray(arr, size);
	return 0;
}
