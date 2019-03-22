#include "Repository.h"
#include <iostream>

int Repository::addPerson(Person& p)
{
	this->prs.push_back(p);
	return 1;
}

int Repository::addAnalysisRep(Analysis * a, Person& p)
{
	for (int i=0;i<this->prs.size();i++)
	{
		if (this->prs[i].getName() == p.getName())
			prs[i].addAnalysis(a);
	}
	return 1;
}

std::vector<Analysis*> Repository::getAll()
{
	std::vector<Analysis*> res;
	std::vector<Person> pp = this->getPers();
	for (auto x : pp)
	{
		//std::cout << 'a';
		std::vector<Analysis*> tst = x.getAnalyses();
		for (auto d : tst) {
			//std::cout << 'b';
			//std::cout << d->getDate();
			res.push_back(d);
		}
	}
	return res;
}

std::vector<Person> Repository::ill(int month)
{
	std::vector<Analysis*> res;
	std::vector<Person> il;
	int ok = 0;
	for (auto p : this->prs)
	{
		res = p.getAnalysesByMounth(month);
		for (auto d : res)
		{
			//std::cout << d->getDate();
			if (d->isResultOK() == false)
				ok = 1;
		}
		if (ok == 1)
		{
			il.push_back(p);
		}
		ok = 0;
	}

	return il;
}
