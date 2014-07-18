#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int linearSearch(std::vector<int> v, int n)
{
	for (auto it = v.begin(); it != v.end(); it++) {
		if (*it == n) 
			return std::distance(v.begin(), it); 
	}
	return -1;
}

void printVector(std::string s, std::vector<int> v)
{
	std::cout << s << " ";
	std::for_each(v.begin(), v.end(), [](int i) { std::cout << i << " "; });
	std::cout << std::endl;
}

void printResult(int n, int r)
{
	if (r == -1) {
		std::cout << "Vector doesn't contain: " << n << std::endl;
		return;
	}
	std::cout << "Found " << n << " at [" << r << "]" << std::endl;
}

int main ()
{
	static const int arr[] = {1, 34, 23, 10, 94, 26, 63, 23};
	std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
	printVector("Pure vector:", v);
	std::sort(v.begin(), v.end());
	printVector("Sorted vector:", v);
	int search1 = 3, search2 = 26;
	printResult(search1, linearSearch(v, search1));
	int ret2 = linearSearch(v, 26);
	printResult(search2, linearSearch(v, search2));
	return 0;
}
