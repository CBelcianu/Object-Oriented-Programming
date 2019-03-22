#include "Person.h"


Person::Person(const std::string & name)
{
	this->name = name;
}

int Person::addAnalysis(Analysis * a)
{
	this->analyses.push_back(a);
	return 1;
}

std::vector<Analysis*> Person::getAnalysesByMounth(int m)
{
	std::vector<Analysis*> res;
	for (auto d : this->analyses)
	{
		int month = stoi(d->getDate().substr(5, 2));
		if (month == m)
			res.push_back(d);	
	}
	return res;
}

bool Person::isIll()
{
	for (auto d : this->analyses)
		if (d->isResultOK() == 0)
			return true;
	return false;
}

std::vector<Analysis*> Person::getAnalysesBetweenDates(std::string d1, std::string d2)
{
	std::vector<Analysis*> res;
	for (auto d : this->analyses)
		if (d->getDate() >= d1 && d->getDate() <= d2)
			res.push_back(d);
	return res;
}
