#include "BP.h"

BP::BP(const std::string data, int systolic, int diastolic)
{
	this->date = data;
	this->systolic = systolic;
	this->diastolic = diastolic;
}

bool BP::isResultOK()
{
	if (this->systolic >= 90 && this->systolic <= 119 && this->diastolic >= 60 && this->diastolic <= 79)
		return true;
	else return false;
}

std::string BP::toString()
{
	std::string bun = "BP analysis ";
	bun = bun + this->date;
	bun = bun + " ";
	bun = bun + std::to_string(this->systolic);
	bun = bun + " ";
	bun = bun + std::to_string(this->diastolic);
	return bun;
}

std::string BP::getDate()
{
	return this->date;
}
