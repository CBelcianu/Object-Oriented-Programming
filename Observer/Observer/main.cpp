#include "Observer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Observer w;
	w.show();
	return a.exec();
}
