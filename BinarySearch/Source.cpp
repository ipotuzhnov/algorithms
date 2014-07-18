#include <iostream>

/* Input
int arr - array 
int l - begin of array
int r - end of array
int n - number to search
 */
int binartSearch(int arr[], int l, int r, int n)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == n)
			return mid;
		if (n > arr[mid])
			return binartSearch(arr, mid + 1, r, n);
		else
			return binartSearch(arr, l, mid - 1, n);
	}
	return -1;
}

int main()
{
	int arr[] = {1, 3, 6, 7, 8, 9};
	int size = sizeof(arr) / sizeof(arr[0]);
	std::cout << binartSearch(arr, 0, size, 1) << std::endl;
	std::cout << binartSearch(arr, 0, size, 3) << std::endl;
	std::cout << binartSearch(arr, 0, size, 6) << std::endl;
	std::cout << binartSearch(arr, 0, size, 7) << std::endl;
	std::cout << binartSearch(arr, 0, size, 8) << std::endl;
	std::cout << binartSearch(arr, 0, size, 9) << std::endl;
	std::cout << binartSearch(arr, 0, size, 0) << std::endl;
	return 0;
}
