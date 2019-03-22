#pragma once
#include "repository.h"
#include "OStack.h"

typedef struct
{
	Repository* repos;
	OperationsStack* uStack;
	OperationsStack* rStack;
} Controller;

Controller* createController(Repository* r);
void destroyController(Controller* c);
int addCountryC(Controller* c, char* name, char* continent, double population);
int removeCountryC(Controller* c, char* name, char* continent, double population);
int updateCountryC(Controller* c, char* oldName, char* oldContinent, double oldPopulation, char* newName, char* newContinent, double newPopulation);
int migrationC(Controller* c, char* oldName, char* oldContinent, double oldPopulation, char* newName, char* newContinent, double newPopulation, char* mOldName, char* mOldContinent, double mOldPopulation, char* mNewName, char* mNewContinent, double mNewPopulation);
Repository* getRepo(Controller* c);
int undo(Controller* c);
//int redo(Controller* c);