#include "Tests.h"

Tests::Tests()
{
}


Tests::~Tests()
{
}

void Tests::testController()
{
	Repository tr{ "testp.txt","tests.txt" };
	Controller tc{ tr };
	int k = tc.getSize();
	SourceFile s{ "name","not_revised","Ion"," " };
	tc.addSourceFileC(s);
	assert(tc.getSize() == k+1);
	SourceFile s1{ "cc","not_reivsed","Maria"," " };
	Programmer prg{ "Ion",2,3 };
	s1.revise(prg.getName());
	assert(s1.getReviser() == prg.getName());
}

void Tests::testAll()
{
	this->testController();
}
