#pragma once
#include "Person.h"
class Repository
{
private:
	std::vector<Person> prs;
public:
	Repository() {}
	int addPerson(Person& p);
	int addAnalysisRep(Analysis* a, Person& p);
	std::vector<Analysis*> getAll();
	std::vector<Person> ill(int month);
	std::vector<Person> getPers() { return prs; }
};

