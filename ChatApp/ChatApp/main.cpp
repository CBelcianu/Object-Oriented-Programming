#include "ChatApp.h"
#include <QtWidgets/QApplication>
#include "ChatWindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//ChatApp w;
	ChatWindow w;
	w.show();
	return a.exec();
}
