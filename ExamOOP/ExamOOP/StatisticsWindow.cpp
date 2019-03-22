#include "StatisticsWindow.h"

StatisticsWindow::StatisticsWindow(Controller & c, Programmer& ii, Programmer& mm, Programmer& ma) :c(c), ii(ii), mm(mm), ma(ma)
{
	this->initStatistisc();
	this->setWindowTitle("Statistics");
	this->c.registerObserver(this);
}

void StatisticsWindow::initStatistisc()
{
	//this->QPaintEvent();
	QVBoxLayout* main = new QVBoxLayout(this);
	this->lion = new QLabel("Ion has 1 more to go");
	this->lmaria = new QLabel("Maria has 8 more to go");
	this->lmarcel = new QLabel("Marcel has 10 more to go");
	main->addWidget(lion);
	main->addWidget(lmaria);
	main->addWidget(lmarcel);
}
/*
void StatisticsWindow::paintEvent(QPaintEnvent* ev)
{
	QPainter p{ this };
	p.drawEllipse(50, 50, 10, 10);
}
*/

void StatisticsWindow::update()
{
	if (this->ii.getRev() == this->ii.getTotal())
		this->lion->setText("Ion finished his job");
	else
	{
		int x = this->ii.getTotal() - this->ii.getRev();
		this->lion = new QLabel(QString::fromStdString("Ion has"+std::to_string(x)+ "more to go"));
	}
	if (this->mm.getRev() == this->mm.getTotal())
		this->lmaria->setText("Maria finished her job");
	else
	{
		int x = this->mm.getTotal() - this->mm.getRev();
		this->lmaria = new QLabel(QString::fromStdString("maria has" + std::to_string(x) + "more to go"));
	}
	if (this->ma.getRev() == this->ma.getTotal())
		this->lmarcel->setText("Marcel finished his job");
	else
	{
		int x = this->ma.getTotal() - this->ma.getRev();
		this->lmarcel = new QLabel(QString::fromStdString("Marcel has" + std::to_string(x) + "more to go"));
	}

}
