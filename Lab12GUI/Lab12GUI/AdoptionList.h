#pragma once
#include "Dog.h"
#include <vector>

class AdoptionList
{
protected:
	std::vector<Dog> dogs;
	int current;

public:
	AdoptionList();

	// Adds a dog to the adoptionlist.
	int adoptDog(Dog& dog);

	std::vector<Dog> getAdoptedDogs() const { return dogs; }
	virtual ~AdoptionList() {}
};

