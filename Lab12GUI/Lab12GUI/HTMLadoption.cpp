#include "HTMLadoption.h"
#include <fstream>
#include <Windows.h>

using namespace std;


void HTMLadoption::writeToFile()
{
	ofstream f(this->filename);

	f << "<!DOCTYPE html>\n<html>\n<head>\n<title>AdoptionList</title>\n</head>\n<body>\n<table border = \"1\">\n<tr>\n<td>Name</td>\n<td>Breed</td>\n<td>Age</td>\n<td>Photograph</td>\n";
	for (auto s : this->dogs)
		f << "</tr>\n<tr>\n<td>" << s.getName() << "</td>" << endl << "<td>" << s.getBreed() << "</td>" << endl << "<td>" << s.getAge() << "</td>" << endl << "<td><a href=\"" << s.getPhotograph() << "\">Link</a></td>" << endl;
	f << " </tr>\n</table>\n</body>\n</html>";
	f.close();
}

void HTMLadoption::displayPlaylist() const
{
	string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
											   //ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
