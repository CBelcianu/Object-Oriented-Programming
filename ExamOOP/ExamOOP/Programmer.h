#pragma once
#include <iostream>
#include <fstream>
#include "Utils.h"
class Programmer
{
private:
	std::string name;
	int rev;
	int total;
public:
	Programmer() {}
	Programmer(const std::string& name, int rev, int total) :name(name), rev(rev), total(total) {}
	std::string getName() { return name; }
	int getRev() { return rev; }
	int getTotal() { return total; }
	void Up() { rev = rev + 1; }
	friend std::istream& operator>>(std::istream& is, Programmer& p);
	friend std::ostream& operator<<(std::ostream& os, Programmer& p);
	~Programmer() {}
};

