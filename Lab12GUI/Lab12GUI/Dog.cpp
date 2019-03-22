#include "Dog.h"
#include "Utils.h"
#include <iostream>
#include <Windows.h>
#include <shellapi.h>

using namespace std;

Dog::Dog() : name(""), breed(""), age(), photograph("") {}

Dog::Dog(const std::string& name, const std::string& breed, const int age, const std::string& photograph)
{
	this->name = name;
	this->breed = breed;
	this->age = age;
	this->photograph = photograph;
}


Dog& Dog::operator=(const Dog & d)
{
	this->name = d.getName();
	this->breed = d.getBreed();
	this->age = d.getAge();
	this->photograph = d.getPhotograph();

	return *this;
}

int Dog::operator==(Dog & d)
{
	if (this->name == d.getName() && this->breed == d.getBreed())
		return 1;
	return 0;
}

void Dog::watch()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getPhotograph().c_str(), NULL, SW_SHOWMAXIMIZED);
}

istream & operator>>(istream & is, Dog & s)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 4) // make sure all the song data was valid
		return is;

	s.name = tokens[0];
	s.breed = tokens[1];
	s.age = atoi(tokens[2].c_str());
	s.photograph = tokens[3];

	return is;

}

ostream & operator<<(ostream & os, const Dog & s)
{
	os << s.name << "," << s.breed << "," << s.age << "," << s.photograph << "\n";
	return os;
}
