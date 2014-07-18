#include "LongNumber.h"

// Some functions

int convertStringToInt(std::string strNumber)
{
	return atoi(strNumber.c_str());
}

// Constructor 

LongNumber::LongNumber(std::vector<int> left, std::vector<int> right)
{
	error_ = "noerr";

	left_ = left;
	right_ = right;
}

LongNumber::LongNumber(std::string strNumber)
{
	error_ = "noerr";
	noerr_ = true;

	checkForSign_(strNumber);

	checkForIncorrectSymbols_(strNumber);

	if (noerr_) {

		int posPoint = strNumber.find(".");
		int posComma = strNumber.find(",");

		int pos;

		if (posPoint > 0)
			pos = posPoint;
		else if (posComma > 0)
			pos = posComma;
		else 
			pos = -1;

		std::string left, right;

		if (pos < 0) {
			left = strNumber;
		} else {
			left = strNumber.substr(0, pos);
			right = strNumber.substr(pos + 1);
		}

		if (left.length() > 0) {
			while (left.length() > 4) {
				addToLeft_(left.substr(static_cast<int>(left.length()) - 4, 4));
				left = left.substr(0, static_cast<int>(left.length()) - 4);
			}
			addToLeft_(left);
		}

		if (right.length() > 0) {
			while (right.length() > 4) {
				addToRight_(right.substr(0, 4));
				right = right.substr(4);
			}
			addToRight_(right);
		}

	}

}

// Destructor

LongNumber::~LongNumber()
{
}

// Public 

std::string LongNumber::print()
{
	if (noerr_) {
		std::string ret;

		if (!sign_.empty())
			ret += sign_;

		if (left_.empty()) {
			ret = "0";
		} else {
			for (auto it = left_.rbegin(); it != left_.rend(); it++) {
				ret += std::to_string(*it);
			}
		}

		if (!right_.empty()) {
			ret += ".";
			for (auto it = right_.begin(); it != right_.end(); it++) {
				ret += std::to_string(*it);
			}
		}

		return ret;
	} else {
		return error_;
	}
}

// Get

std::string LongNumber::getSign()
{
	return sign_;
}

std::vector<int> LongNumber::getLeft()
{
	return left_;
}

std::vector<int> LongNumber::getRight()
{
	return right_;
}

// Private

void LongNumber::checkForSign_(std::string &strNumber)
{
	if (strNumber.find("+") == 0) {
		sign_ = "+";
		strNumber = strNumber.substr(1);
	} else if (strNumber.find("-") == 0) {
		sign_ = "-";
		strNumber = strNumber.substr(1);
	}	
}

void LongNumber::checkForIncorrectSymbols_(std::string strNumber)
{
	int posPoint = strNumber.find(".");
	int posComma = strNumber.find(",");

	if (posPoint > 0)
		strNumber = strNumber.substr(0, posPoint) + strNumber.substr(posPoint + 1);
	else if (posComma > 0)
		strNumber = strNumber.substr(0, posComma) + strNumber.substr(posComma + 1);

	for (int i = 0; i < 10; i++) {
		std::string s = std::to_string(i);
		int spos = strNumber.find(s);
		while (spos >= 0) {
			strNumber = strNumber.substr(0, spos) + strNumber.substr(spos + 1);
			spos = strNumber.find(s);
		}
	}

	if (strNumber.length() > 0) {
		error_ = "incorrect symbols";
		noerr_ = false;
	}
}

void LongNumber::addToLeft_(std::string strNumber)
{
	try {
		left_.push_back(convertStringToInt(strNumber));
	} catch (...) {
		error_ = "parsing error";
		noerr_ = false;
	}
}

void LongNumber::addToRight_(std::string strNumber)
{
	try {
		right_.push_back(convertStringToInt(strNumber));
	} catch (...) {
		error_ = "parsing error";
		noerr_ = false;
	}
}
