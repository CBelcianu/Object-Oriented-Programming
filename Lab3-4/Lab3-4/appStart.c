#include "repository.h"
#include "UI.h"
#include <crtdbg.h>

int main()
{
	//create repository
	Repository* repo = createRepository();
	//create controller
	Controller* ctrl = createController(repo);

	//initialize the repository
	addCountryC(ctrl, "USA", "America", 320.20);
	addCountryC(ctrl, "Romania", "Europe", 18.80);
	addCountryC(ctrl, "South-Korea", "Asia", 50.00);
	addCountryC(ctrl, "Japan", "Asia", 220.20);
	addCountryC(ctrl, "Germany", "Europe", 88.80);
	addCountryC(ctrl, "North-Korea", "Asia", 25.00);
	addCountryC(ctrl, "Canada", "America", 60.50);
	addCountryC(ctrl, "France", "Europe", 60.80);
	addCountryC(ctrl, "China", "Asia", 1436.30);

	//create UI
	UI* ui = createUI(ctrl);

	//run the main programm
	startUI(ui);

	//clean the space allocated for the ui
	destroyUI(ui);

	//search for memory leaks
	_CrtDumpMemoryLeaks();

	return 0;
}