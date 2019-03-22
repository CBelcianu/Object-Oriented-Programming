#include "controller.h"
#include <stdlib.h>
#include <string.h>

Controller* createController(Repository* r)
{
	/*
		Function that creates a controller-type object
		input: repository
		output: controller
	*/
	Controller* c = (Controller*)malloc(sizeof(Controller));
	c->repos = r;

	return c;
}

void destroyController(Controller * c)
{
	/*
		Function that destorys the space allocated foar a controller-type object
		input: controller
		output: void
	*/
	destroyRepository(c->repos);
	free(c);
}

int addCountryC(Controller* c, char* name, char* continent, double population)
{
	/*
		Function that adds a country in the repository
		input: controller, char name, char continent, double population
		output: res
	*/
	Country* country = createCountry(name, continent, population);

	int res = addCountry(c->repos, country);
	if (res == 0)
		destroyCountry(country);
	//else
	//{
		//Operation* o = createOperation(country, "add");
		//push(c->uStack, o);
		// once added, the operation can be destroyed (a copy of the operation was added)
		//destroyOperation(o);
	//}

	return res;
}

int removeCountryC(Controller* c, char* name, char* continent, double population)
{
	/*
		Function that removes a country from the repository
		input: controller, char name, char continent, double population
		output: res
	*/
	Country* country = createCountry(name, continent, population);

	int res = removeCountry(c->repos, country);
	if (res == 0)
		destroyCountry(country);

	return res;
}

int updateCountryC(Controller* c, char* oldName, char* oldContinent, double oldPopulation, char* newName, char* newContinent, double newPopulation)
{
	/*
		Function that updates a country from the repository
		input: controller, char oldName, char oldContinent, double oldPopulation, char* newName, char* newContinent, double newPopulation
		output: res
	*/
	Country* oldCountry = createCountry(oldName, oldContinent, oldPopulation);
	Country* newCountry = createCountry(newName, newContinent, newPopulation);

	int res = updateCountry(c->repos, oldCountry, newCountry);
	if (res == 0)
	{
		destroyCountry(oldCountry);
		destroyCountry(newCountry);
	}

	return res;
}

int migrationC(Controller* c, char* oldName, char* oldContinent, double oldPopulation, char* newName, char* newContinent, double newPopulation, char* mOldName, char* mOldContinent, double mOldPopulation, char* mNewName, char* mNewContinent, double mNewPopulation)
{
	/*
		Function that updates the populations of two given countries from the repository
		input: controller, char* oldName, char* oldContinent, double oldPopulation, char* newName, char* newContinent, double newPopulation, char* mOldName, char* mOldContinent, double mOldPopulation, char* mNewName, char* mNewContinent, double mNewPopulation
		output: res
	*/
	Country* oldCountry = createCountry(oldName, oldContinent, oldPopulation);
	Country* newCountry = createCountry(newName, newContinent, newPopulation);
	Country* mOldCountry = createCountry(mOldName, mOldContinent, mOldPopulation);
	Country* mNewCountry = createCountry(mNewName, mNewContinent, mNewPopulation);

	int res = migration(c->repos, oldCountry, newCountry, mOldCountry, mNewCountry);
	if (res == 0)
	{
		destroyCountry(oldCountry);
		destroyCountry(newCountry);
		destroyCountry(mOldCountry);
		destroyCountry(mNewCountry);
	}

	return res;
}

Repository* getRepo(Controller* c)
{
	/*
		Function that returns the list of all contries
		intput: controller
		output: repository
	*/
	return c->repos;
}

int undo(Controller* c)
{
	if (isEmpty(c->uStack))
	{
		return 0;
	}

	Operation* operation = pop(c->uStack);

	if (strcmp(getOperationType(operation), "add") == 0)
	{
		Country* country = getCountryS(operation);
		char name[50];
		removeCountry(c->repos, getName(country), getContinent(country), getPopulation(country));
	}
	else if (strcmp(getOperationType(operation), "remove") == 0)
	{
		// TO DO!!!
	}

	// the operation must be destroyed
	destroyOperation(operation);

	return 1;

}