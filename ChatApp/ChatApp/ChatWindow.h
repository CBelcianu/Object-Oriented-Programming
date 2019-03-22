#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include "Observer.h"
class ChatWindow:public Observer
{
private:
	QListWidget * list;
	QLineEdit* line;
	QPushButton* send;
public:
	ChatWindow();
	~ChatWindow();
	void initGUI();
	void update() override;
};

