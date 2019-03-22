#include "BMI.h"



BMI::BMI(const std::string& date, double value)
{
	this->date = date;
	this->value = value;
}

bool BMI::isResultOK()
{
	if (this->value >= 18.5 && this->value <= 25) return true;
	else return false;
}

std::string BMI::toString()
{
	std::string bun = "BMI analysis ";
	bun = bun + this->date;
	bun = bun + " ";
	bun = bun + std::to_string(this->value);
	return bun;
}

std::string BMI::getDate()
{
	return this->date;
}



