#pragma once
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qwidget.h>
#include <qmessagebox.h>
#include "Observer.h"
#include "Controller.h"
class ProgrammerWindow :public QWidget, public Observer
{
private:
	QListWidget * list;
	QLineEdit* le;
	QPushButton* btnAdd;
	QPushButton* btnRev;
	QLabel* lrev;
	QLabel* lrem;
	Programmer p;
	Controller& c;
public:
	ProgrammerWindow(Controller& c, Programmer& p);
	void initW();
	void update() override;
	void populate();
	void addSW();
	void reviseSW();
	~ProgrammerWindow() {}
};

