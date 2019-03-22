#pragma once
#include "Analysis.h"
class BP: public Analysis
{
private:
	int systolic;
	int diastolic;
public:
	BP(const std::string data, int systolic, int diastolic);
	bool isResultOK() override;
	std::string toString() override;
	int getSystolic() { return this->systolic; }
	int getDiastolic() { return this->diastolic; }
	std::string getDate() override;
	
};

