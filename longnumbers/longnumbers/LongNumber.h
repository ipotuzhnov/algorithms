// Class LongNumber

#ifndef LONGNUMBER_H
#define LONGNUMBER_H

#define BASE 10000;

#include <vector>
#include <string>

class LongNumber

{
public:
	LongNumber(std::vector<int> left, std::vector<int> right);
	LongNumber(std::string strNumber);
	
	~LongNumber();

	std::string print();

	std::string getSign();
	std::vector<int> getLeft();
	std::vector<int> getRight();
private:
	LongNumber convertStringToNumber_(std::string strNumber);
	std::string convertNumberToString_(LongNumber number);

	void checkForSign_(std::string &strNumber);
	void checkForIncorrectSymbols_(std::string strNumber);

	void addToLeft_(std::string strNumber);
	void addToRight_(std::string strNumber);

private:
	std::string error_;
	bool noerr_;

	std::vector<int> left_;
	std::vector<int> right_;

	std::string sign_;
	int point_;
};

#endif // LONGNUMBER_H