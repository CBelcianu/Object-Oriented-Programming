#include "Surgery.h"

using namespace std;

Surgery::Surgery(const std::string & hospitalname, int nrdrs, int nrpts)
{
	this->hospitalname = hospitalname;
	this->nrdrs = nrdrs;
	this->nrpts = nrpts;
}

std::string Surgery::toString()
{
	std::string res = "Surgery depart. Hospital: ";
	res = res + this->hospitalname + " no. of doctors: ";
	res = res + std::to_string(this->nrdrs) + " no. of parients: ";
	res = res + std::to_string(this->nrpts);
	return res;
}

bool Surgery::isEfficient()
{
	if (this->nrpts / this->nrdrs >= 2)
		return true;
	return false;
}

std::string Surgery::getHospital()
{
	return this->hospitalname;
}

int Surgery::getNoDrs()
{
	return this->nrdrs;
}

std::ostream& Surgery::writeIt(std::ostream & os)
{
	os << this->getHospital() << endl;
	return os;
}

std::ostream & operator<<(std::ostream & os, Surgery & s)
{
	os << s.getHospital() << "," << s.getNoDrs() << "," << s.getNoPts() << endl;
	return os;
}
