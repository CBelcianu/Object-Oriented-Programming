#include "Subject.h"



Subject::Subject()
{
}


Subject::~Subject()
{
}

void Subject::registerObserver(Observer* obs)
{
	this->observers.push_back(obs);
}

void Subject::unregisterObserver(Observer* obs)
{
	int p, i = 0;
	for (auto o : this->observers) {
		if (o == obs)
			p = i;
		i++;
	}
	this->observers.erase(this->observers.begin() + p);
}
