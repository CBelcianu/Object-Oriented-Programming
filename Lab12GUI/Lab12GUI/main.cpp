#include "Lab12GUI.h"
#include <QtWidgets/QApplication>
#include "BestGuiEverCreated.h"
#include "Controller.h"
#include "Tests.h"

int main(int argc, char *argv[])
{
	Tests::testAll();
	QApplication a(argc, argv);
	//Lab12GUI w;
	Repository repo("Repos.txt");
	BestGuiEverCreated w(repo);
	w.show();
	return a.exec();
}
