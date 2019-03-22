#include "Controller.h"

//using namespace std;

int Controller::addDepartCtrl(Departament * d)
{
	return this->repo.addDepart(d);
}
