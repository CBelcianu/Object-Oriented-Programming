#pragma once
#include "Repository.h"
class Controller
{
private:
	Repository repo;
public:
	Controller(Repository& r);
	int addAnalysisCtrl(Analysis* a, Person& p);
	std::vector<Analysis*> getAllCtrl();
	std::vector<Person> getIllCtrl(int month);
};

