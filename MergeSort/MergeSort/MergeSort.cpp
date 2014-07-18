#include <iostream>

void printArray(int arr[], int size)
{
	std::cout << "array:";
	for (int i = 0; i < size; i++)
		std::cout << " " << arr[i];
	std::cout << std::endl;
}

void merge(int arr[], int l, int m, int r)
{
	int sizel = m - l + 1, sizer = r - m;
	int *arrl = new int[sizel];
	for (int i = 0; i < sizel; i++)
		arrl[i] = arr[l + i];
	int *arrr = new int[sizer];
	for (int i = 0; i < sizer; i++)
		arrr[i] = arr[m + 1 + i];
	int i = 0, j = 0;
	while (i < sizel && j < sizer)
	{
		if (arrl[i] < arrr[j]) {
			arr[l + i + j] = arrl[i];
			i++;
		} else {
			arr[l + i + j] = arrr[j];
			j++;
		}
	}
	while (i < sizel) {
		arr[l + i + j] = arrl[i];
		i++;
	}
	while (j < sizer) {
		arr[l + i + j] = arrr[j];
		j++;
	}
	delete [] arrl, arrr;
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = (l + r) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

int main()
{
	int arr[] = {17, 2, 97, 53, 92, 13, 43, 20, 85, 23};
	int size = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, size);
	mergeSort(arr, 0, size - 1);
	printArray(arr, size);
	return 0;
}
