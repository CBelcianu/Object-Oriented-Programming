#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ChatApp.h"

class ChatApp : public QMainWindow
{
	Q_OBJECT

public:
	ChatApp(QWidget *parent = Q_NULLPTR);

private:
	Ui::ChatAppClass ui;
};
