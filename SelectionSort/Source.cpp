#include <iostream>

void printArray(int arr[], int size)
{
	std::cout << "Array:";
	for (int i = 0; i < size; i++) {
		std::cout << " " << arr[i];
	}
	std::cout << std::endl;
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	int arr[] = {6, 3, 5, 8, 1, 0};
	int size = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, size);
	for (int i = 0; i < size - 1; i++) {
		int min_index = i;
		for (int j = i; j < size; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		swap(&arr[i], &arr[min_index]);
	}
	printArray(arr, size);
	return 0;
}
