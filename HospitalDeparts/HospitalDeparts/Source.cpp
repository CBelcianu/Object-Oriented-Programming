#include "UI.h"

int main()
{
	Repository repo{"repo.txt"};
	Controller ctrl{ repo };
	UI ui{ ctrl };

	ui.run();
}