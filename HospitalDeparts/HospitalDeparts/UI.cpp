#include "UI.h"
#include <iostream>
#include "Surgery.h"
#include "NeonatalUnit.h"

using namespace std;

void UI::printMenu()
{
	cout << "1.Add departament\n";
	cout << "2.Show all departaments\n";
	cout << "3.Show all efficient departaments\n";
	cout << "4.Save the registered departaments to a file\n";
	cout << "0.Exit\n";
}

int UI::addDepartUI()
{
	int cm{ -1 };
	cout << "1.Surgery depart.\n";
	cout << "2.Neonatal Unit.\n";
	cout << "Choose: ";
	cin >> cm;
	cin.ignore();
	if (cm == 1) {
		std::string hospitalname;
		cout << "Hospital name: ";
		getline(cin, hospitalname);
		int nrdrs;
		cout << "Number of doctors: ";
		cin >> nrdrs;
		cin.ignore();
		int nrpts;
		cout << "Number of patients: ";
		cin >> nrpts;
		cin.ignore();

		Departament* d = new Surgery{ hospitalname,nrdrs,nrpts };
		this->ctrl.addDepartCtrl(d);
	}
	else {
		std::string hospitalname;
		cout << "Hospital name: ";
		getline(cin, hospitalname);
		int nrdrs;
		cout << "Number of doctors: ";
		cin >> nrdrs;
		cin.ignore();
		int nrmds;
		cout << "Number of mothers: ";
		cin >> nrmds;
		cin.ignore();
		int nrnb;
		cout << "Number of newborns: ";
		cin >> nrnb;
		cin.ignore();
		double avggrade;
		cout << "Average grade of newbornds: ";
		cin >> avggrade;
		cin.ignore();

		Departament* d = new NeonatalUnit{ hospitalname,nrdrs,nrmds,nrnb,avggrade };
		this->ctrl.addDepartCtrl(d);
	}
	return 1;
}

void UI::displayAllDeparts()
{
	std::vector<Departament*> deps = this->ctrl.getAllDepartsCtrl();
	for (auto d : deps)
		cout << d->toString() << endl;
}

void UI::displayAllEfficient()
{
	std::vector<Departament*> deps = this->ctrl.getAllEfficientCtrl();
	for (auto d : deps)
		cout << d->toString() << endl;
}

void UI::saveToFile()
{
	this->ctrl.getRepo().writeToFile();
}

void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ -1 };
		cout << "Enter command: ";
		cin >> command;
		cin.ignore();
		if (command == 0) {
			break;
		}
		if (command == 1) {
			int res = UI::addDepartUI();
			if (res == 1) cout << "Nois\n";
			else cout << "No gud";
		}
		if (command == 2) {
			UI::displayAllDeparts();
		}
		if (command == 3) {
			UI::displayAllEfficient();
		}
		if (command == 4) {
			UI::saveToFile();
		}
	}
}