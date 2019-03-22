#pragma once

typedef struct {
	char* name;
	char* continent;
	double population;
}Country;

Country* createCountry(char* name, char* continent, double population);
Country* copyCountry(Country* c);
void destroyCountry(Country* country);
char* getName(Country* country);
char* getContinent(Country* country);
double getPopulation(Country* country);
void modifyPopulation(Country* country, double np);
void modifyName(Country* country, char* name);
void toString(Country* country, char str[]);
int compareCountry(Country*, Country*);