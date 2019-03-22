#pragma once
#include "Departament.h"
#include <vector>
#include <fstream>
class Repository
{
private:
	std::vector<Departament*> departs;
	std::string filename;
public:
	Repository(const std::string& filename);
	int addDepart(Departament* d);
	std::vector<Departament*> getAllDeparts();
	std::vector<Departament*> getAllEfficient();
	void writeToFile();
};

