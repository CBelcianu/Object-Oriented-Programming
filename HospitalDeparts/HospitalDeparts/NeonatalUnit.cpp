#include "NeonatalUnit.h"

using namespace std;

NeonatalUnit::NeonatalUnit(const std::string & hospitalname, int nrdrs, int nrmds, int nrnb, double avggrade)
{
	this->hospitalname = hospitalname;
	this->nrdrs = nrdrs;
	this->nrmds = nrmds;
	this->nrnb = nrnb;
	this->avggrade = avggrade;
}

std::string NeonatalUnit::toString()
{
	std::string res = "Neonatal Unit. Hospital: ";
	res = res + this->hospitalname + " no. of doctors: ";
	res = res + std::to_string(this->nrdrs) + " no. of mothers: ";
	res = res + std::to_string(this->nrmds) + " no. of newborns: ";
	res = res + std::to_string(this->nrnb) + " having average grade: ";
	res = res + std::to_string(this->avggrade);
	return res;
}

bool NeonatalUnit::isEfficient()
{
	if (this->avggrade >= 8.5 && this->nrnb >= this->nrmds)
		return true;
	return false;
}

std::string NeonatalUnit::getHospital()
{
	return this->hospitalname;
}

int NeonatalUnit::getNoDrs()
{
	return this->nrdrs;
}

std::ostream & NeonatalUnit::writeIt(std::ostream & os)
{
	os << this->getHospital() << endl;
	return os;
}

std::ostream & operator<<(std::ostream & os, NeonatalUnit & ne)
{
	os << ne.getHospital() << "," << ne.getNoDrs() << "," << ne.getNoMth() << "," << ne.getNoNb() << "," << ne.getAvg() << endl;
	return os;
}
