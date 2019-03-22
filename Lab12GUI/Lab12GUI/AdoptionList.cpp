#include "AdoptionList.h"

AdoptionList::AdoptionList()
{
	//this->filename = filename;
	this->current = 0;
}

int AdoptionList::adoptDog(Dog& dog)
{
	this->dogs.push_back(dog);
	return 1;
}
