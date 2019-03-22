#pragma once
#include "Analysis.h"
#include <vector>
#include <string>
class Person
{
private:
	std::string name;
	std::vector<Analysis*> analyses;
public:
	Person() {}
	Person(const std::string& name);
	
	std::string getName() { return this->name; }
	int addAnalysis(Analysis* a);
	std::vector<Analysis*> getAnalyses() { return analyses; }
	std::vector<Analysis*> getAnalysesByMounth(int m);
	bool isIll();
	std::vector<Analysis*> getAnalysesBetweenDates(std::string d1, std::string d2);
};

