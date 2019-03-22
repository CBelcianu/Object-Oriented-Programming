#include "Repository.h"
#include "DogValidator.h"
#include "RepositoryExceptions.h"
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

Repository::Repository(const std::string & filename)
{
	this->filename = filename;
	this->readFromFile();
}

int Repository::addDog(Dog& d)
{
	if (this->findNameBreed(d.getName(), d.getBreed()) != -1)
		throw DuplicateDogException();
	this->dogs.push_back(d);
	this->writeToFile();
	return 1;
}

int Repository::findNameBreed(const std::string & name, const std::string & breed)
{
	int i = 0;
	for (auto d : this->dogs)
	{
		if (d.getName() == name && d.getBreed() == breed)
			return i;
		i++;
	}

	return -1;
}

int Repository::removeDog(Dog& d)
{
	if (this->findNameBreed(d.getName(), d.getBreed()) == -1)
		throw RepositoryException("No such dog!\n");
	else this->dogs.erase(this->dogs.begin() + findNameBreed(d.getName(), d.getBreed()));
	this->writeToFile();
	return 1;
}

int Repository::updateDog(Dog & d1, Dog & d2)
{
	if (this->findNameBreed(d1.getName(), d1.getBreed()) == -1)
		throw RepositoryException("No such dog!\n");
	else {
		this->dogs.at(findNameBreed(d1.getName(), d1.getBreed())) = d2;
		this->writeToFile();
		return 1;
	}
}

std::vector<Dog> Repository::getFilter(const std::string & breed, int age)
{
	std::vector<Dog> v = this->getDogs();
	std::vector<Dog> v1;
	for (auto d : v)
		if (d.getBreed() == breed && d.getAge() <= age)
		{
			v1.push_back(d);
		}
	return v1;
}

std::vector<Dog> Repository::genericSort(Comparator& c, std::vector<Dog> d)
{
	unsigned int i, j;
	std::vector<Dog> v = d;
	Dog aux;
	for (i = 0; i < v.size(); i++)
		for (j = i + 1; j < v.size(); j++)
		{
			if (!(c.compare(v[i], v[j])))
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	return v;
}

void Repository::readFromFile()
{
	ifstream file(this->filename);

	Dog d;
	while (file >> d)
		this->dogs.push_back(d);

	file.close();
}

void Repository::writeToFile()
{
	ofstream file(this->filename);

	for (auto s : this->dogs)
	{
		file << s;
	}

	file.close();
}
