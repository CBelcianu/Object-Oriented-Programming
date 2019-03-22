#pragma once
#include "Dog.h"
#include "Comparator.h"
#include <vector>


class Repository
{
private:
	std::vector<Dog> dogs;
	std::string filename;
	//friend class Dog;

public:

	Repository(const std::string& filename);

	//Repository() {}

	int addDog(Dog& d);
	/*
	function that adds a dog in the repo
	input: dog
	*/

	int findNameBreed(const std::string& name, const std::string& breed);

	int removeDog(Dog& d);
	/*
	function that removes a dog from the repository
	input: dog
	*/

	int updateDog(Dog& d1, Dog& d2);
	/*
	function that updates a dog from the repository
	input: dog1, dog2
	*/


	std::vector<Dog> getDogs() const { return dogs; }
	/*
	functions that returns all the dogs in the repository
	input: -
	output: all the dogs from the repo
	*/

	std::vector<Dog> getFilter(const std::string& breed, int age);
	/*
	function that returns all the dogs of a given breed and under a given age
	input: breed, age
	output: all the dogs that match a given criteria
	*/

	std::vector<Dog> genericSort(Comparator& c, std::vector<Dog> d);
	void setDogs(std::vector<Dog> dg) { this->dogs = dg; }
//private:
	void readFromFile();
	void writeToFile();
};
