#include "UI.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

UI* createUI(Controller* c)
{
	/*
		Function that creates a UI-type object
		input: controller
		output: UI
	*/
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->ctrl = c;

	return ui;
}

void destroyUI(UI* ui)
{
	/*
		Function that destorys the space allocated for a UI-type object
		input: ui
		output: void
	*/
	destroyController(ui->ctrl);
	free(ui);
}

void printMenu()
{
	/*
		Function that prints on the screen the menu of the application
		input: void
		output: the menu printed
	*/
	printf("\n+------------------------------------------------------------------------------------------------------+\n");
	printf("|\t1.Add a country                                                                                |\n");
	printf("|\t2.Delete a country                                                                             |\n");
	printf("|\t3.Update a country                                                                             |\n");
	printf("|\t4.List                                                                                         |\n");
	printf("|\t5.List all the countries on a continent                                                        |\n");
	printf("|\t6.List all the countries on a continent whose population are greater than a given value        |\n");
	printf("+------------------------------------------------------------------------------------------------------+\n\n");
}

int validCommand(int command)
{
	/*
		Function that verifies if a command is valid
		input: command
		output: 1 if the command is valid, 0 otherwise
	*/
	if (command >= 0 && command <= 8)
		return 1;
	return 0;
}

int validUpCommand(int command)
{
	/*
	Function that verifies if a update command is valid
	input: command
	output: 1 if the command is valid, 0 otherwise
	*/
	if (command >= 1 && command <= 2)
		return 1;
	return 0;
}

int readIntegerNumber(const char* message)
{
	/*
		Function that reads an integer number from the keyboard
		input: message
		output: res
	*/
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}

int addCountryU(UI* ui)
{
	/*
		Function that adds a country in the repository
		input: ui
		output: 0 if the contry was not added, 1 otherwise
	*/
	char name[50], continent[50];
	double population = 0;
	int ok = 0;

	printf("Please input the name: ");
	scanf("%49s", name);
	while (ok == 0)
	{
		printf("Please input the continent: ");
		scanf("%49s", continent);
		if (strcmp(continent, "Europe") == 0 || strcmp(continent, "Asia") == 0 || strcmp(continent, "Africa") == 0 || strcmp(continent, "America") == 0 || strcmp(continent, "Australia") == 0)
			ok = 1;
		else printf("Invalid continent!\n");
	}
	while (ok == 1)
	{
		printf("Please input the population of the country (in millions): ");
		scanf("%lf", &population);
		if (population > 0) ok = 0;
		else printf("Invalid population!\n");
	}

	return addCountryC(ui->ctrl, name, continent, population);
}

int removeConunrtyU(UI* ui)
{
	/*
		Function that removes a country from the repository
		input: ui
		output: 0 if the contry was not removed, 1 otherwise
	*/
	char name[50], continent[50];
	double population = 0;

	printf("Please input the name: ");
	scanf("%49s", name);
	printf("Please input the continent: ");
	scanf("%49s", continent);
	printf("Please input the population of the country (in millions): ");
	scanf("%lf", &population);

	return removeCountryC(ui->ctrl, name, continent, population);
}

int updateCountryU(UI* ui)
{
	/*
		Function that updates a country from the repository
		input: ui
		output: 0 if the contry was not updated, 1 otherwise
	*/
	char oldName[50], oldContinent[50], newName[50], newContinent[50];
	double oldPopulation = 0, newPopulation = 0;

	printf("Please input the name: ");
	scanf("%49s", oldName);
	printf("Please input the continent: ");
	scanf("%49s", oldContinent);
	printf("Please input the population of the country (in millions): ");
	scanf("%lf", &oldPopulation);

	printf("Please input the new name: ");
	scanf("%49s", newName);
	printf("Please input the new continent: ");
	scanf("%49s", newContinent);
	newPopulation = oldPopulation;

	return updateCountryC(ui->ctrl, oldName, oldContinent, oldPopulation, newName, newContinent, newPopulation);
}

int migrationU(UI* ui)
{
	/*
		Function that updates the population of two countries from the repository
		input: ui
		output: 0 if the contries were not updated, 1 otherwise
	*/
	char oldName[50], oldContinent[50], newName[50], newContinent[50], mOldName[50], mOldContinent[50], mNewName[50], mNewContinent[50];
	double oldPopulation = 0, newPopulation = 0, mOldPopulation = 0, mNewPopulation = 0;

	printf("PLEASE ENTER THE SOURECE COUNTRY'S DETAILS!!!\n");

	printf("Please input the name: ");
	scanf("%49s", oldName);
	printf("Please input the continent: ");
	scanf("%49s", oldContinent);
	printf("Please input the current population of the country (in millions): ");
	scanf("%lf", &oldPopulation);

	int ok = 0;
	while (ok == 0)
	{
		printf("Please input the new population of the country (in millions): ");
		scanf("%lf", &newPopulation);
		if (newPopulation > 0) ok = 1;
		else printf("Invlid population!\n");
	}
	strcpy(newName, oldName);
	strcpy(newContinent, oldContinent);

	printf("PLEASE ENTER THE DESTINATION COUNTRY'S DETAILS!!!\n");

	printf("Please input the name: ");
	scanf("%49s", mOldName);
	printf("Please input the continent: ");
	scanf("%49s", mOldContinent);
	printf("Please input the current population of the country (in millions): ");
	scanf("%lf", &mOldPopulation);

	strcpy(mNewName, mOldName);
	strcpy(mNewContinent, mOldContinent);
	mNewPopulation = mOldPopulation + oldPopulation - newPopulation;

	if (mNewPopulation < 0) return 0;

	return migrationC(ui->ctrl, oldName, oldContinent, oldPopulation, newName, newContinent, newPopulation, mOldName, mOldContinent, mOldPopulation, mNewName, mNewContinent, mNewPopulation);
}

void append(char* s, char c)
{
	/*
		Function that appends a string with a character
		input: string, char
		output: void
	*/
	int len = strlen(s);
	s[len] = c;
	s[len + 1] = '\0';
}

void listAllCountries(UI* ui)
{
	/*
		Function that prints all the contries that contain a given string
		input: ui
		output: the countries printed
	*/
	char ch,ch1,ss[50];
	printf("\t\tEnter a string: ");
	ch = fgetc(stdin);
	ch = fgetc(stdin);
	if (ch == 0x0A)
	{
		Repository* repo = getRepo(ui->ctrl);
		//int length = getLength(repo);

		if (repo->vd->dim == 0)
		{
			char* str = "There are no stored counties.";
			printf("%s \n", str);
		}

		for (int i = 0; i < repo->vd->dim; i++)
		{
			char str[200];
			toString(getCountryOnPos(repo, i), str);
			printf("%s\n", str);
		}
	}
	else
	{
		int i = 0;
		char* cmd[50];
		strcpy(cmd, "");
		append(cmd, ch);
		ch = getchar();
		while (ch != 0x0A)
		{
			append(cmd, ch);
			ch = getchar();
		}
		
		Repository* repo = getRepo(ui->ctrl);
		int length = getLength(repo);

		if (length == 0)
		{
			char* str = "There are no stored counties.";
			printf("%s \n", str);
		}

		for (i = 0; i < getLength(repo); i++)
		{
			if (strstr(getName(ui->ctrl->repos->vd->elems[i]), cmd) != NULL) 
			{
				char str[200];
				toString(getCountryOnPos(repo, i), str);
				printf("%s\n", str);
			}
		}	
	}
}

void countriesContinent(UI* ui)
{
	char continent[50];
	int ok = 0, i, j=0;
	Repository* repo = getRepo(ui->ctrl);
	Repository* repo2 = createRepository();
	while (ok == 0)
	{
		printf("Please input the continent: ");
		scanf("%49s", continent);
		if (strcmp(continent, "Europe") == 0 || strcmp(continent, "Asia") == 0 || strcmp(continent, "Africa") == 0 || strcmp(continent, "America") == 0 || strcmp(continent, "Australia") == 0)
			ok = 1;
		else printf("Invalid continent!\n");
	}

	for (i = 0; i < getLength(repo); i++)
	{
		if (strcmp(getContinent(getCountryOnPos(repo,i)), continent) == 0)
		{
			Country* cty = createCountry(getName(getCountryOnPos(repo, i)), getContinent(getCountryOnPos(repo, i)), getPopulation(getCountryOnPos(repo, i)));
			addCountry(repo2, cty);
		}
	}

	for (i = 0; i < getLength(repo2); i++)
	{
		if (strcmp(getContinent(getCountryOnPos(repo2, i)), continent) == 0)
		{
			for (j = i; j < getLength(repo2); j++)
				if (strcmp(getContinent(getCountryOnPos(repo2, j)), continent) == 0)
					if (strcmp(getName(getCountryOnPos(repo2, i)), getName(getCountryOnPos(repo2, j))) > 0)
					{
						char temp[50];
						strcpy(temp, getName(getCountryOnPos(repo2, i)));
						modifyName(getCountryOnPos(repo2, i), getName(getCountryOnPos(repo2, j)));
						modifyName(getCountryOnPos(repo2, j), temp);

						int aux;
						aux = getPopulation(getCountryOnPos(repo2, i));
						modifyPopulation(getCountryOnPos(repo2, i),getPopulation(getCountryOnPos(repo2, j)));
						modifyPopulation(getCountryOnPos(repo2, j),aux);
					}
		}
	}
	for (i = 0; i < getLength(repo2); i++)
	{
			char str[100];
			toString(getCountryOnPos(repo2, i), str);
			printf("%s\n", str);
	}
}

void countriesContinentPop(UI* ui)
{
	char continent[50];
	int ok = 0, i, j = 0;
	double pop;
	Repository* repo = getRepo(ui->ctrl);
	Repository* repo2 = createRepository();
	while (ok == 0)
	{
		printf("Please input the continent: ");
		scanf("%49s", continent);
		if (strcmp(continent, "Europe") == 0 || strcmp(continent, "Asia") == 0 || strcmp(continent, "Africa") == 0 || strcmp(continent, "America") == 0 || strcmp(continent, "Australia") == 0)
			ok = 1;
		else printf("Invalid continent!\n");
	}
	while (ok == 1)
	{
		printf("Please input the population (in millions): ");
		scanf("%lf", &pop);
		if (pop > 0) ok = 0;
		else printf("Invalid population!\n");
	}

	for (i = 0; i < getLength(repo); i++)
	{
		if (strcmp(getContinent(getCountryOnPos(repo, i)), continent) == 0 && getPopulation(getCountryOnPos(repo, i))>pop)
		{
			Country* cty = createCountry(getName(getCountryOnPos(repo, i)), getContinent(getCountryOnPos(repo, i)), getPopulation(getCountryOnPos(repo, i)));
			addCountry(repo2, cty);
		}
	}

	for (i = 0; i < getLength(repo2); i++)
	{
		if (strcmp(getContinent(getCountryOnPos(repo2, i)), continent) == 0)
		{
			for (j = i; j < getLength(repo2); j++)
				if (strcmp(getContinent(getCountryOnPos(repo2, j)), continent) == 0)
					if (getPopulation(getCountryOnPos(repo2, i)) > getPopulation(getCountryOnPos(repo2, j)))
					{
						char temp[50];
						strcpy(temp, getName(getCountryOnPos(repo2, i)));
						modifyName(getCountryOnPos(repo2, i), getName(getCountryOnPos(repo2, j)));
						modifyName(getCountryOnPos(repo2, j), temp);

						int aux;
						aux = getPopulation(getCountryOnPos(repo2, i));
						modifyPopulation(getCountryOnPos(repo2, i), getPopulation(getCountryOnPos(repo2, j)));
						modifyPopulation(getCountryOnPos(repo2, j), aux);
					}
		}
	}

	for (i = 0; i < getLength(repo2); i++)
	{
		char str[100];
		toString(getCountryOnPos(repo2, i), str);
		printf("%s\n", str);
	}
}

void startUI(UI* ui)
{
	//main programm
	while (1)
	{
		printMenu();
		int cmd = readIntegerNumber("Enter command: ");
		while (validCommand(cmd) == 0) 
		{
			printf("Please enter a valid command!\n");
			cmd = readIntegerNumber("Enter command: ");
		}
		if (cmd == 1)
		{
			int res = addCountryU(ui);
			if (res == 1) printf("Country succesfully added!\n");
			else printf("This country already exists!\n");
		}
		if (cmd == 2)
		{
			int res = removeConunrtyU(ui);
			if (res == 1) printf("Country succesfully deleted!\n");
			else printf("No such country exists!\n");
		}
		if (cmd == 3)
		{
			printf("\t\t1.Update a contry's name or continent\n");
			printf("\t\t2.Update a country's population\n");
			int cmdd = readIntegerNumber("Enter command: ");
			while (validUpCommand(cmdd) == 0)
			{
				printf("Please enter a valid command!\n");
				cmdd = readIntegerNumber("Enter command: ");
			}
			if (cmdd == 1)
			{
				int res = updateCountryU(ui);
				if (res == 1) printf("Country succesfully updated!\n");
				else printf("Error!");
			}
			if (cmdd == 2)
			{
				int res = migrationU(ui);
				if (res == 1) printf("Country succesfully updated!\n");
				else printf("Error!");
			}
		}
		if (cmd == 4)
		{
			listAllCountries(ui);
		}
		if (cmd == 5)
		{
			countriesContinent(ui);
		}
		if (cmd == 6)
		{
			countriesContinentPop(ui);
		}
		if (cmd == 7)
		{
			//int res = undo(ui->ctrl);
		}
	}
}