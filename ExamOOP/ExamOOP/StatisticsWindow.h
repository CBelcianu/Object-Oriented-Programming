#pragma once
#include "Observer.h"
#include "Controller.h"
#include <qwidget.h>
#include <qpainter.h>
#include <qlabel.h>
#include <qlayout.h>

class StatisticsWindow:public QWidget, public Observer
{
private:
	QLabel* lion;
	QLabel* lmaria;
	QLabel* lmarcel;
	Programmer ii;
	Programmer mm;
	Programmer ma;
	Controller& c;
public:
	StatisticsWindow(Controller& c,Programmer& ii, Programmer& mm, Programmer& ma);
	void initStatistisc();
	//void paintEvent(QPaintEnvent* ev) override;
	void update() override;
	~StatisticsWindow() {}
};

