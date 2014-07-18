#include <iostream>
#include <string>

#include "LongNumber.h"
#include "Calculator.h"

int main ()
{
	std::cout << "Testing LongNumber algorithm" << std::endl;

	std::string strNumber1 = "2784923";
	std::string strNumberWithError1 = "278492asd3";
	std::string strNumberWithPoint1 = "87435.298347";
	std::string strNumberWithComma1 = "4621,83475";
	std::string strNumberWithSign1 = "-418347209";
			
	//int i = 11 222 223 719 287 382 923;
	int x = 10000;
	int y = 10000;

	int i = x * y;

	LongNumber longNumber1 = LongNumber(strNumber1);
	LongNumber longNumberWithError1 = LongNumber(strNumberWithError1);
	LongNumber longNumberWithPoint1 = LongNumber(strNumberWithPoint1);
	LongNumber longNumberWithComma1 = LongNumber(strNumberWithComma1);
	LongNumber longNumberWithSign1 = LongNumber(strNumberWithSign1);

	std::cout << "Test 1: Create LongNumber from figure without point." << std::endl;
	std::cout << "std::string: " << strNumber1 << " LongNumber: " << longNumber1.print() << std::endl;
	
	std::cout << "Test 2: Create LongNumber from figure with char." << std::endl;
	std::cout << "std::string: " << strNumberWithError1 << " LongNumber: " << longNumberWithError1.print() << std::endl;
	
	std::cout << "Test 3: Create LongNumber from figure with point: " << std::endl;
	std::cout << "std::string: " << strNumberWithPoint1 << " LongNumber: " << longNumberWithPoint1.print() << std::endl;
	
	std::cout << "Test 4: Create LongNumber from figure with comma: " << std::endl;
	std::cout << "std::string: " << strNumberWithComma1 << " LongNumber: " << longNumberWithComma1.print() << std::endl;

	std::cout << "Test 1: Create LongNumber from negative figure without point." << std::endl;
	std::cout << "std::string: " << strNumberWithSign1 << " LongNumber: " << longNumberWithSign1.print() << std::endl;

	LongNumber additionRes = Calculator::add(longNumber1, longNumber1);


	return 0;
}
