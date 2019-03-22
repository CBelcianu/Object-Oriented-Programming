#pragma once
#include <string>

typedef Dog TElement;

class Comparator
{
public:
	virtual bool compare(TElement& e1, TElement& e2) = 0;
};


class ComparatorAscendingAge :public Comparator
{
public:
	ComparatorAscendingAge() {}
	bool compare(TElement& e1, TElement& e2) {
		if (e1.getAge() < e2.getAge())
			return true;
		else return false;
	};
};

class ComparatorAscendingName :public Comparator
{
public:
	ComparatorAscendingName() {}
	bool compare(TElement& e1, TElement& e2) {
		if (e1.getName() < e2.getName())
			return true;
		else return false;
	};
};
