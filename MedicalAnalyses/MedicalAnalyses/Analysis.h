#pragma once
#include <string>
#include <iostream>
class Analysis
{
protected:
	std::string date;
public:
	Analysis() {}
	Analysis(std::string& date);

	virtual bool isResultOK() = 0;
	virtual std::string toString() = 0;
	virtual std::string getDate() = 0;

	virtual ~Analysis() {}
};

