#pragma once
#include <qwidget.h>
class Observer : public QWidget
{
public:
	Observer();
	virtual void update()=0;
	virtual ~Observer();
};
