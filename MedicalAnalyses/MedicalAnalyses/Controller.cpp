#include "Controller.h"



Controller::Controller(Repository& r) :repo{ r } {}

int Controller::addAnalysisCtrl(Analysis * a, Person & p)
{
	this->repo.addAnalysisRep(a, p);
	return 1;
}

std::vector<Analysis*> Controller::getAllCtrl()
{
	std::vector<Analysis*> res;
	res = this->repo.getAll();
	return res;
}

std::vector<Person> Controller::getIllCtrl(int month)
{
	std::vector<Person> il = this->repo.ill(month);
	return il;
}

