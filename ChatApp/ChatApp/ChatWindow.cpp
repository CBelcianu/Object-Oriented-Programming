#include "ChatWindow.h"



ChatWindow::ChatWindow()
{
	initGUI();
}


ChatWindow::~ChatWindow()
{
}

void ChatWindow::initGUI()
{
	QVBoxLayout* main = new QVBoxLayout(this);
	QHBoxLayout* jos = new QHBoxLayout();
	this->list = new QListWidget();
	this->line = new QLineEdit();
	this->send = new QPushButton("SEND");
	jos->addWidget(line);
	jos->addWidget(send);
	main->addWidget(list);
	main->addLayout(jos);
}

void ChatWindow::update()
{
}
