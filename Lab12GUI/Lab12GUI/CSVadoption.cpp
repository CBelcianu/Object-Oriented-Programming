#include "CSVadoption.h"
#include <fstream>
#include <Windows.h>

using namespace std;

void CSVadoption::writeToFile()
{
	ofstream f(this->filename);

	for (auto s : this->dogs)
		f << s;

	f.close();
}

void CSVadoption::displayPlaylist() const
{
	string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
											   //ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	ShellExecuteA(NULL, NULL, "C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
