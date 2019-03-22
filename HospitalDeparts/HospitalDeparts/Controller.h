#pragma once
#include "Repository.h"
#include <fstream>
class Controller
{
private:
	Repository repo;
public:
	Controller(Repository& r) : repo{ r } {}

	int addDepartCtrl(Departament* d);
	std::vector<Departament*> getAllDepartsCtrl() { return this->repo.getAllDeparts(); }
	std::vector<Departament*> getAllEfficientCtrl() { return this->repo.getAllEfficient(); }
	Repository getRepo() { return repo; }

};

