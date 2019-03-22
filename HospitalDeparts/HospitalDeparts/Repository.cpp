#include "Repository.h"

using namespace std;

Repository::Repository(const std::string & filename)
{
	this->filename = filename;
}

int Repository::addDepart(Departament * d)
{
	this->departs.push_back(d);
	return 1;
}

std::vector<Departament*> Repository::getAllDeparts()
{
	return this->departs;
}

std::vector<Departament*> Repository::getAllEfficient()
{
	std::vector<Departament*> res;
	for (auto d : this->departs)
		if (d->isEfficient() == true)
			res.push_back(d);
	return res;
}

void Repository::writeToFile()
{
	ofstream file(this->filename);
	for (auto d : this->getAllDeparts())
		d->writeIt(file);
	file.close();
}
