#pragma once
#include "Analysis.h"
class BMI: public Analysis
{
private:
	double value;
public:
	BMI(const std::string& date, double value);

	bool isResultOK() override;
	std::string toString() override;
	double getValue() { return this->value; }
	std::string getDate() override;
};

