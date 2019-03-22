#include "ExamOOP.h"
#include <QtWidgets/QApplication>
#include "ProgrammerWindow.h"
#include "Tests.h"
#include "StatisticsWindow.h"

int main(int argc, char *argv[])
{
	Tests ts;
	ts.testAll();
	QApplication a(argc, argv);
	Repository r{ "programmers.txt","sourcefiles.txt" };
	Controller c{ r };
	for (auto x : r.getProgrammers())
	{
		ProgrammerWindow* pw = new ProgrammerWindow(c, x);
		pw->show();
	}
	StatisticsWindow* sw = new StatisticsWindow(c,r.getProgrammers()[0],r.getProgrammers()[1],r.getProgrammers()[2]);
	sw->show();
	return a.exec();
}
