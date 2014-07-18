// Class Calculator

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "LongNumber.h"

class Calculator

{
public:
	Calculator();
	~Calculator();

	static LongNumber add(LongNumber a, LongNumber b);
	static LongNumber subtract(LongNumber a, LongNumber b);
	static LongNumber multiply(LongNumber a, LongNumber b);
	static LongNumber divide(LongNumber a, LongNumber b);
private:


private:

};

#endif // CALCULATOR_H