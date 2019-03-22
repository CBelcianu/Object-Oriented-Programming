#pragma once
#include "Controller.h"
class UI
{
private:
	Controller ctrl;
public:
	UI(Controller& c) : ctrl(c) {}
	void run();
private:
	int addDepartUI();
	void displayAllDeparts();
	void displayAllEfficient();
	void saveToFile();
	void printMenu();
};

