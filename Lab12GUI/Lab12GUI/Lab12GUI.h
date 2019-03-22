#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab12GUI.h"

class Lab12GUI : public QMainWindow
{
	Q_OBJECT

public:
	Lab12GUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::Lab12GUIClass ui;
};
