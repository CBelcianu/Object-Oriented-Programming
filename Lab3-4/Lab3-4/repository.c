#include "repository.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

Repository* createRepository()
{
	/*
		Function that creates a repository-type object
		input: void
		output: repo, repository-type object
	*/
	Repository* repo= (Repository*)malloc(sizeof(Repository));
	repo->vd = createDynamicVector(2, compareCountry, destroyCountry);
	//Repository* repo = (Repository*)malloc(sizeof(Repository));
	repo->length = 0;
	return repo;
}

void destroyRepository(Repository * repo)
{
	/*
		Function that destorys the space allocated foar a repository-type object
		input: repo, repository-type object
		output: void
	*/
	for (int i = 0; i < repo->length; i++)
		destroyCountry(repo->vd->elems[i]);
	free(repo);
}

Country* find(Repository* repo, char name[])
{
	/*
		Function that verifies if a given country exists in the repository
		input: repo, char name[]
		output: the country if it exists or NULL otherwise
	*/
	for (int i = 0; i < repo->length; i++)
	{
		if (strcmp(getName(repo->vd->elems[i]), name) == 0)
			return repo->vd->elems[i];
	}
	return NULL;
}

int addCountry(Repository * repo, Country * country)
{
	/*
		Function that adds a country in the repository
		input: repo, country
		output: 0 if the country was not added, 1 otherwise
	*/
	if (find(repo, country->name) != NULL)
		return 0;

	Country* copy = copyCountry(country);
	addV(repo->vd, copy);

	return 1;
}

Country* getCountryOnPos(Repository* repo, int pos)
{
	/*
		Function that returns the country on a given position in the repository
		input: repo, pos
		output: NULL if the position given is outside of the repository, the country of position pos otherwise
	*/
	if (pos < 0 || pos >= repo->length)
		return NULL;
	return repo->vd->elems[pos];
}

int removeCountry(Repository* repo, Country* country)
{
	/*
		Function that removes a country from the repository
		input: repo, country
		output: 0 if the country was not removed, 1 otherwise
	*/
	if (find(repo, country->name) == NULL)
		return 0;

	int position;

	for (int i = 0; i < repo->length; i++)
	{
		if (strcmp(getName(repo->vd->elems[i]), country->name) == 0)
		{
			position = i;
			break;
		}
	}

	for (int i = position; i < repo->length-1; i++) 
	{
		repo->vd->elems[i] = repo->vd->elems[i + 1];
	}
	repo->length--;

	return 1;
}

int updateCountry(Repository* repo, Country* oldCountry, Country* newCountry)
{
	/*
		Function that updates a country from the repository
		input: repo, oldCountry, newCountry
		output: 0 if the country was not updated, 1 otherwise
	*/
	if (find(repo, oldCountry->name) == NULL)
		return 0;

	int position=-1;

	for (int i = 0; i < repo->length; i++)
	{
		if (strcmp(getName(repo->vd->elems[i]), oldCountry->name) == 0 && strcmp(getContinent(repo->vd->elems[i]), oldCountry->continent) == 0)
		{
			position = i;
			break;
		}
	}

	if (position == -1) return 0;

	repo->vd->elems[position] = newCountry;

	return 1;
}

int migration(Repository* repo, Country* oldCountry, Country* newCountry, Country* mOldCountry, Country* mNewCountry)
{
	/*
		Function that updates the populations of two given countries from the repository
		input: repo, oldCountry, newCountry, mOldCountry, mNewCountry
		output: 0 if the countries were not updated, 1 otherwise
	*/
	if (find(repo, oldCountry->name) == NULL)
		return 0;

	if (find(repo, mOldCountry->name) == NULL)
		return 0;

	int position1 = -1, position2 = -1;

	for (int i = 0; i < repo->length; i++)
	{
		if (strcmp(getName(repo->vd->elems[i]), oldCountry->name) == 0 && strcmp(getContinent(repo->vd->elems[i]), oldCountry->continent) == 0 && getPopulation(repo->vd->elems[i])==oldCountry->population)
		{
			position1 = i;
			break;
		}
	}
	
	if (position1 == -1) return 0;

	for (int i = 0; i < repo->length; i++)
	{
		if (strcmp(getName(repo->vd->elems[i]), mOldCountry->name) == 0 && strcmp(getContinent(repo->vd->elems[i]), mOldCountry->continent) == 0 && getPopulation(repo->vd->elems[i]) == mOldCountry->population)
		{
			position2 = i;
			break;
		}
	}

	if (position2 == -1) return 0;

	repo->vd->elems[position1] = newCountry;
	repo->vd->elems[position2] = mNewCountry;

	return 1;
}

int getLength(Repository * repo)
{
	/*
		Function that returns the length of the repository as int
		input: repo
		output: repo->length
	*/
	return repo->length;
}

//TESTS

void testAdd()
{
	/*
		Function that tests the addCountry function
		input: void
	*/
	Repository* tst = createRepository();
	Country* tc = createCountry("Spain", "Europe", 59.35);
	addCountry(tst, tc);
	assert(getLength(tst) == 1);
	Country* tc2 = createCountry("Argentina", "America", 44.20);
	assert(addCountry(tst, tc2) == 1);
	assert(getLength(tst) == 2);
	assert(addCountry(tst, tc2) == 0);

	destroyRepository(tst);
}

void testDelete()
{
	/*
		Function that tests the removeCountry function
		input: void
	*/
	Repository* tst = createRepository();
	Country* tc = createCountry("Spain", "Europe", 59.35);
	addCountry(tst, tc);
	Country* tc2 = createCountry("Argentina", "America", 44.20);
	addCountry(tst, tc2);
	assert(removeCountry(tst, tc2) == 1);
	assert(getLength(tst) == 1);
	assert(removeCountry(tst, tc2) == 0);

	destroyRepository(tst);
}

void testUpdate()
{
	/*
		Function that tests the migration function
		input: void
	*/
	Repository* tst = createRepository();
	Country* tc = createCountry("Spain", "Europe", 59.35);
	addCountry(tst, tc);
	Country* tc2 = createCountry("Argentina", "America", 44.20);
	addCountry(tst, tc2);
	Country* tc3 = createCountry("Brazil", "America", 184.20);
	assert(updateCountry(tst, tc2, tc3) == 1);
	assert(updateCountry(tst, tc2, tc3) == 0);

	destroyRepository(tst);
}

void tests4Repo()
{
	/*
		Function that runs all the repository tests
		input: void
	*/
	testAdd();
	testDelete();
	testUpdate();
}