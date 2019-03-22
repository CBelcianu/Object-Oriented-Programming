#pragma once
class Obsevator
{
public:
	Obsevator();
	virtual void update() = 0;
	virtual ~Obsevator();
};

