#include "domain.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Country* createCountry(char* name, char* continent, double population)
{
	/*
		Function that creates a country-type object
		input: char* name, char* continent, double population
		output: c, country-type object
	*/
	Country* c= (Country*)malloc(sizeof(Country));
	c->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(c->name, name);
	c->continent = (char*)malloc(sizeof(char) * (strlen(continent) + 1));
	strcpy(c->continent, continent);

	c->population = population;

	return c;
}

void destroyCountry(Country * country)
{
	/*
		Function that destroys the space allocated on the heap for a country
		input: country, country-type object
		output: void
	*/
	free(country->name);
	free(country->continent);
	free(country);
}

char* getName(Country* country)
{
	/*
		Function that returns the name of a country as a char
		input: country, country-type object
		output: name
	*/
	return country->name;
}

char* getContinent(Country* country)
{
	/*
		Function that returns the continent of a country as a char
		input: country, country-type object
		output: continent
	*/
	return country->continent;
}

double getPopulation(Country * country)
{
	/*
		Function that returns the population of a country as a double
		input: country, country-type object
		output: population
	*/
	return country->population;
}

void modifyPopulation(Country* country, double np)
{
	country->population = np;
}

void modifyName(Country* country, char* name)
{
	strcpy(country->name, name);
}

int compareCountry(Country* a, Country* b)
{
	return a->population - b->population;
}

Country* copyCountry(Country* c)
{
	if (c == NULL)
		return NULL;

	Country* newC = createCountry(getName(c), getContinent(c), getPopulation(c));
	return newC;
}

void toString(Country* country, char str[])
{
	/*
		Function that prints a country on the screed
		input: country, country-type object && str[], string
		output: "Country %s from %s has a population of %.2lf million."
	*/
	sprintf(str, "Country %s from %s has a population of %.2lf million.", country->name, country->continent, country->population);
}
