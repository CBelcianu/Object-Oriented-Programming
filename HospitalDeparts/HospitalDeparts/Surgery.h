#pragma once
#include "Departament.h"
#include <fstream>
#include <iostream>
class Surgery: public Departament
{
private:
	int nrpts;
public:
	Surgery() {}
	Surgery(const std::string& hospitalname, int nrdrs, int nrpts);

	std::string toString() override;
	bool isEfficient() override;
	std::string getHospital() override;
	int getNoDrs() override;
	int getNoPts() { return this->nrpts; }
	friend std::ostream& operator<<(std::ostream& os, Surgery& s);
	std::ostream& writeIt(std::ostream& os) override;
};

