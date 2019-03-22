#pragma once
#include <string>
#include <iostream>
class Departament
{
protected:
	std::string hospitalname;
	int nrdrs;
public:
	Departament() {}
	Departament(const std::string& haspitalname, int nrdrs);
	virtual bool isEfficient() = 0;
	virtual std::string toString() = 0;
	virtual std::string getHospital() = 0;
	virtual int getNoDrs() = 0;
	virtual ~Departament() {}
	virtual std::ostream& writeIt(std::ostream& os) = 0;
};

