#include "UI.h"

void UI::printMenu()
{
	cout << "1.Add analysis\n";
	cout << "2.Show all analyses\n";
	cout << "3.Show if a person is ill\n";
	cout << "0.Quit\n";
}

void UI::isPersonIll()
{
	std::string name;
	cout << "name: ";
	getline(cin, name);
	int m;
	cout << "month: ";
	cin >> m;
	cin.ignore();
	std::vector<Person> il = this->ctrl.getIllCtrl(m);
	for (auto ps : il)
		if (ps.getName() == name)
		{
			cout << "the person is ill\n";
			return;
		}
	cout << "the person isn't ill\n";
}

int UI::addAnalysisUI()
{
	int cm{ -1 };
	cout << "1.BMI\n";
	cout << "2.BP\n";
	cin >> cm;
	cin.ignore();
	if (cm == 1) {
		std::string date;
		cout << "date (yyyy.mm.dd): ";
		getline(cin, date);
		double value;
		cout << "value: ";
		cin >> value;
		cin.ignore();
		std::string name;
		cout << "person (name): ";
		getline(cin, name);
		Person p{ name };
		Analysis* a = new BMI{ date,value };
		this->ctrl.addAnalysisCtrl(a, p);
	}
	else {
		std::string date;
		cout << "date (yyyy.mm.dd): ";
		getline(cin, date);
		int s;
		cout << "systolic: ";
		cin >> s;
		cin.ignore();
		int d;
		cout << "diastolic: ";
		cin >> d;
		cin.ignore();
		std::string name;
		cout << "person (name): ";
		getline(cin, name);
		Person p{ name };
		Analysis* a = new BP{ date,s,d };
		this->ctrl.addAnalysisCtrl(a, p);
	}
	return 1;
}

void UI::displayAll()
{
	std::vector<Analysis*> res;
	res = this->ctrl.getAllCtrl();
	for (auto d : res)
		cout << d->toString() << endl;
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
		if (command == 0)
			break;
		if (command == 1)
		{
			int x = UI::addAnalysisUI();
			cout << x << endl;
		}
		if (command == 2)
		{
			UI::displayAll();
		}
		if (command == 3)
		{
			UI::isPersonIll();
		}
	}
}
