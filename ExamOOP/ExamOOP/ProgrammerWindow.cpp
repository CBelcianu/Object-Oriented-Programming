#include "ProgrammerWindow.h"

ProgrammerWindow::ProgrammerWindow(Controller & c, Programmer& p) :c(c), p(p)
{
	this->initW();
	this->populate();
	this->setWindowTitle(QString::fromStdString(p.getName()));
	this->c.registerObserver(this);
	QObject::connect(this->btnAdd, &QPushButton::clicked, this, &ProgrammerWindow::addSW);
	QObject::connect(this->btnRev, &QPushButton::clicked, this, &ProgrammerWindow::reviseSW);
}

void ProgrammerWindow::initW()
{
	QVBoxLayout* main = new QVBoxLayout(this);
	QHBoxLayout* jos = new QHBoxLayout();
	this->list = new QListWidget();
	this->le = new QLineEdit();
	this->btnAdd = new QPushButton("ADD");
	this->btnRev = new QPushButton("REV");
	this->lrev = new QLabel(QString::fromStdString("Revised: "+std::to_string(p.getRev())));
	int x = this->p.getTotal() - p.getRev();
	this->lrem = new QLabel(QString::fromStdString("Remaining: "+std::to_string(x)));
	jos->addWidget(le);
	jos->addWidget(lrev);
	jos->addWidget(lrem);
	jos->addWidget(btnAdd);
	jos->addWidget(btnRev);
	main->addWidget(list);
	main->addLayout(jos);
}

void ProgrammerWindow::update()
{
	this->populate();
}

void ProgrammerWindow::populate()
{
	int i = 0;
	this->list->clear();
	for (auto x : this->c.getRepo().getSourceFiles())
	{
		if(x.getStatus()=="revised")
			this->list->addItem(QString::fromStdString(x.getName() + " [status]: " + x.getStatus() + " [crator]: " + x.getCreator() + " [reviser]: " + x.getReviser()));
		else this->list->addItem(QString::fromStdString(x.getName() + " [status]: " + x.getStatus() + " [crator]: " + x.getCreator() + " [reviser]: NONE"));
	}
	for (auto x : this->c.getRepo().getSourceFiles())
	{
		if (x.getStatus() == "not_revised")
		{
			QFont f;
			f.setBold(true);
			this->list->item(i)->setFont(f);
		}
		else if (x.getStatus() == "revised")
		{
			QColor clr;
			clr.setGreen(120);
			this->list->item(i)->setBackgroundColor(clr);
		}
		i++;
	}
}

void ProgrammerWindow::addSW()
{
	std::string n = this->le->text().toStdString();
	if (n == "")
	{
		QMessageBox::warning(this, "warning", "invalid name!");
		return;
	}
	for (auto y : this->c.getRepo().getSourceFiles())
		if (y.getName() == n)
		{
			QMessageBox::warning(this, "warning", "there is already a file with the same name");
			return;
		}
	SourceFile s(n, "not_revised", this->p.getName(), " ");
	this->c.addSourceFileC(s);
}

void ProgrammerWindow::reviseSW()
{
	if (this->p.getRev() == this->p.getTotal()) {
		QMessageBox::warning(this, "no worries", "the job is already done");
		return;
	}
	int pos = this->list->currentRow();
	std::vector<SourceFile> all = this->c.getRepo().getSourceFiles();
	if (all[pos].getStatus() == "revised" || all[pos].getCreator() == this->p.getName())
	{
		QMessageBox::warning(this, "warning", "you can't do that");
		return;
	}
	int rv = this->p.getRev();
	rv = rv + 1;
	int rm = this->p.getTotal() - rv;
	this->c.reviseSourceFileC(all[pos], this->p.getName());
	this->lrev->setText(QString::fromStdString("Revised: " + std::to_string(rv)));
	this->lrem->setText(QString::fromStdString("Remaining: " + std::to_string(rm)));
	if (rm == 0)
	{
		QMessageBox::warning(this, "congrats!", "Job Done");
	}
	this->p.Up();
}
