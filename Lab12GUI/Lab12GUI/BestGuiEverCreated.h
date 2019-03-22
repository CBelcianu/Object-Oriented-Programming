#pragma once
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qwidget.h>
#include <qlist.h>
#include <QHBoxLayout>
#include <qmessagebox.h>
#include <qlistwidget.h>
#include <qcombobox.h>
#include "Controller.h"
#include "Repository.h"
#include "DogValidator.h"
#include "RepositoryExceptions.h"
#include "FileAdoption.h"
#include "HTMLadoption.h"
#include "CSVadoption.h"

class BestGuiEverCreated:public QWidget
{
private:
	QPushButton* HTML;
	QPushButton* CSV;
	//choice menu
	QPushButton* admin;
	QPushButton* user;
	//admin
	QListWidget* list;
	QPushButton* display;
	QPushButton* add;
	QPushButton* del;
	QPushButton* upd;
	QPushButton* namesort;
	QPushButton* agesort;
	QLineEdit* name;
	QLineEdit* breed;
	QLineEdit* age;
	QLineEdit* photograph;
	QLineEdit* name1;
	QLineEdit* breed1;
	QLineEdit* age1;
	QLineEdit* photograph1;
	QComboBox* combo;
	//user
	QListWidget* listU;
	QPushButton* displayU;
	QPushButton* browseAll;
	QPushButton* browseFiltered;
	//browseall
	QPushButton* nextA;
	QPushButton* adoptA;
	QPushButton* saveA;
	QPushButton* openA;
	QLineEdit* nameA;
	QLineEdit* breedA;
	QLineEdit* ageA;
	QLineEdit* photographA;
	//browse filtered
	QPushButton* nextF;
	QPushButton* adoptF;
	QPushButton* saveF;
	QPushButton* openF;
	QPushButton* fil;
	QLineEdit* nameF;
	QLineEdit* breedF;
	QLineEdit* ageF;
	QLineEdit* photographF;
	QLineEdit* breedFF;
	QLineEdit* ageFF;
	//idk
	Repository r;
	Controller* c;
	FileAdoption* fa;
	
public:
	BestGuiEverCreated(Repository r);
	~BestGuiEverCreated() = default;
private:
	//functions related to the graphics exclusively
	void initGUI();
	void HTMLclick();
	void CSVclick();
	void choiceMenu();
	void adminClick();
	void adminWindow();
	void userClick();
	void userWindow();
	void browseMenu();
	void browseFiltrMenu();
	//functions that actually do something besides making the application look cool
	//these are for the admin window by the way
	void displayAllAdmin();
	void addDogAdmin();
	void removeDogAdmin();
	void updateDogAdmin();
	void nameSortAdmin();
	void ageSortAdmin();
	//these are for the user window in case you were wondering
	void displayAdoptedUser();
	void nextNormal();
	void util4nextNormal(Dog& d);
	void adoptNormal();
	void saveAdoptionUser();
	void openAdoptionUser();
	void getFiltr();
	void nextFilter();
	void util4nextFilter(Dog& d);
	void adoptFilter();
	void comboDisplay();
};

