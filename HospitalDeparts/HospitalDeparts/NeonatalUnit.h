#pragma once
#include "Departament.h"
#include <iostream>
#include <fstream>
class NeonatalUnit:public Departament
{
private:
	int nrmds;
	int nrnb;
	double avggrade;
public:
	NeonatalUnit() {}
	NeonatalUnit(const std::string& hospitalname, int nrdrs, int nrmds, int nrnb, double avggrade);

	std::string toString() override;
	bool isEfficient() override;
	std::string getHospital() override;
	int getNoDrs() override;
	int getNoMth() { return this->nrmds; }
	int getNoNb() { return this->nrnb; }
	double getAvg() { return this->avggrade; }
	friend std::ostream& operator<<(std::ostream& os, NeonatalUnit& ne);
	std::ostream& writeIt(std::ostream& os) override;
};

