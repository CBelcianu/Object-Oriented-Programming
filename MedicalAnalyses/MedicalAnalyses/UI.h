#pragma once
#include "Controller.h"
#include <iostream>
#include "BMI.h"
#include "BP.h"

using namespace std;

class UI
{
private:
	Controller ctrl;
public:
	UI(Controller& c) : ctrl(c) {}
	void run();
private:
	int addAnalysisUI();
	void displayAll();
	void printMenu();
	void isPersonIll();
};

