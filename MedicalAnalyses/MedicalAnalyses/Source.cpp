#include "UI.h"

int main()
{
	Repository repo{};
	Person p1{ "Ion" };
	Person p2{ "Ana" };
	Person p3{ "Stefan" };
	Person p4{ "Je" };
	Person p5{ "Maria" };

	repo.addPerson(p1);
	repo.addPerson(p2);
	repo.addPerson(p3);
	repo.addPerson(p4);
	repo.addPerson(p5);

	Analysis* a = new BMI{ "2017.11.15",18 };
	repo.addAnalysisRep(a, p1);
	Analysis* a1 = new BP{ "2018.01.12",199,166 };
	repo.addAnalysisRep(a1, p2);

	Controller ctr{ repo };
	UI ui{ ctr };

	ui.run();
}