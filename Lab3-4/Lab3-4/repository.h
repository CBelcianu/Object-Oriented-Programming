#pragma once
#include "domain.h"
#include "DynamicVector.h"

typedef struct {
	//Country* vect[100];
	DynamicVector* vd;
	int length;
}Repository;

Repository* createRepository();
void destroyRepository(Repository* repo);
Country* find(Repository* repo, char name[]);
int addCountry(Repository* repo, Country* country);
Country* getCountryOnPos(Repository* repo, int pos);
int removeCountry(Repository* repo, Country* country);
int updateCountry(Repository* repo, Country* oldCountry, Country* newCountry);
int migration(Repository* repo, Country* oldCountry, Country* newCountry, Country* mOldCountry, Country* mNewCountry);
int getLength(Repository* repo);



