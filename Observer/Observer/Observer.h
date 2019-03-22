#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Observer.h"

class Observer : public QMainWindow
{
	Q_OBJECT

public:
	Observer(QWidget *parent = Q_NULLPTR);

private:
	Ui::ObserverClass ui;
};
