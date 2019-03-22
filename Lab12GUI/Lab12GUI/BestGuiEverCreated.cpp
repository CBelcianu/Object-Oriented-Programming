#include "BestGuiEverCreated.h"

BestGuiEverCreated::BestGuiEverCreated(Repository r) : r(r)
{
	this->initGUI();
	QObject::connect(this->HTML, &QPushButton::clicked, this, &BestGuiEverCreated::HTMLclick);
	QObject::connect(this->CSV, &QPushButton::clicked, this, &BestGuiEverCreated::CSVclick);
}

void BestGuiEverCreated::initGUI()
{
	QHBoxLayout* mly = new QHBoxLayout(this);
	this->CSV = new QPushButton("CSV");
	this->HTML = new QPushButton("HTML");
	mly->addWidget(CSV);
	mly->addWidget(HTML);
}

void BestGuiEverCreated::HTMLclick()
{
	BestGuiEverCreated::choiceMenu();
	this->fa = new HTMLadoption("Adoption.html");
	this->c = new Controller(this->r, this->fa);

	this->close();
}

void BestGuiEverCreated::CSVclick()
{
	BestGuiEverCreated::choiceMenu();
	this->fa = new CSVadoption("Adoption.csv");
	this->c = new Controller(this->r, this->fa);
	//this->c(this->r, this->fa);
	this->close();
}

void BestGuiEverCreated::choiceMenu()
{
	QWidget* cm = new QWidget;
	QHBoxLayout* mly = new QHBoxLayout(cm);
	this->admin = new QPushButton("ADMIN");
	this->user = new QPushButton("USER");
	mly->addWidget(admin);
	mly->addWidget(user);
	QObject::connect(this->admin, &QPushButton::clicked, this, &BestGuiEverCreated::adminClick);
	QObject::connect(this->user, &QPushButton::clicked, this, &BestGuiEverCreated::userClick);
	cm->show();
}

void BestGuiEverCreated::adminClick()
{
	BestGuiEverCreated::adminWindow();
}

void BestGuiEverCreated::adminWindow()
{
	QWidget* aw = new QWidget;
	QHBoxLayout* orizontal = new QHBoxLayout(aw);
	QVBoxLayout* stanga = new QVBoxLayout();
	QVBoxLayout* dreapta = new QVBoxLayout();
	QHBoxLayout* josStanga = new QHBoxLayout();
	this->display = new QPushButton("Show All");
	this->namesort = new QPushButton("Sort by name");
	this->agesort = new QPushButton("Sort by age");
	josStanga->addWidget(this->display);
	josStanga->addWidget(this->namesort);
	josStanga->addWidget(this->agesort);
	QHBoxLayout* dreaptaS = new QHBoxLayout();
	QVBoxLayout* dreapta1 = new QVBoxLayout();
	QLabel* lbname = new QLabel("Name:");
	QLabel* lbbreed = new QLabel("Breed:");
	QLabel* lbage = new QLabel("Age:");
	QLabel* lbphotograph = new QLabel("Photograph:");
	dreapta1->addWidget(lbname);
	dreapta1->addWidget(lbbreed);
	dreapta1->addWidget(lbage);
	dreapta1->addWidget(lbphotograph);
	QVBoxLayout* dreapta2 = new QVBoxLayout();
	this->name = new QLineEdit();
	this->breed = new QLineEdit();
	this->age = new QLineEdit();
	this->photograph = new QLineEdit();
	dreapta2->addWidget(this->name);
	dreapta2->addWidget(this->breed);
	dreapta2->addWidget(this->age);
	dreapta2->addWidget(this->photograph);
	QVBoxLayout* dreapta3 = new QVBoxLayout();
	this->name1 = new QLineEdit();
	this->breed1 = new QLineEdit();
	this->age1 = new QLineEdit();
	this->photograph1 = new QLineEdit();
	dreapta3->addWidget(this->name1);
	dreapta3->addWidget(this->breed1);
	dreapta3->addWidget(this->age1);
	dreapta3->addWidget(this->photograph1);
	QHBoxLayout* dreaptaJos = new QHBoxLayout();
	this->add = new QPushButton("ADD");
	this->del = new QPushButton("DEL");
	this->upd = new QPushButton("UPD");
	dreaptaJos->addWidget(this->add);
	dreaptaJos->addWidget(this->del);
	dreaptaJos->addWidget(this->upd);
	dreaptaS->addLayout(dreapta1);
	dreaptaS->addLayout(dreapta2);
	dreaptaS->addLayout(dreapta3);
	dreapta->addLayout(dreaptaS);
	dreapta->addLayout(dreaptaJos);
	this->list = new QListWidget();
	QHBoxLayout* susStanga = new QHBoxLayout();
	this->combo = new QComboBox();
	this->combo->addItem("Detailed");
	this->combo->addItem("Short");
	susStanga->addWidget(combo);
	stanga->addLayout(susStanga);
	stanga->addWidget(list);
	stanga->addLayout(josStanga);
	orizontal->addLayout(stanga);
	orizontal->addLayout(dreapta);

	//QObject::connect(this->display, &QPushButton::clicked, this, &BestGuiEverCreated::displayAllAdmin);
	QObject::connect(this->display, &QPushButton::clicked, this, &BestGuiEverCreated::comboDisplay);
	QObject::connect(this->add, &QPushButton::clicked, this, &BestGuiEverCreated::addDogAdmin);
	QObject::connect(this->del, &QPushButton::clicked, this, &BestGuiEverCreated::removeDogAdmin);
	QObject::connect(this->upd, &QPushButton::clicked, this, &BestGuiEverCreated::updateDogAdmin);
	QObject::connect(this->namesort, &QPushButton::clicked, this, &BestGuiEverCreated::nameSortAdmin);
	QObject::connect(this->agesort, &QPushButton::clicked, this, &BestGuiEverCreated::ageSortAdmin);
	QObject::connect(this->combo, &QComboBox::currentTextChanged, this, &BestGuiEverCreated::comboDisplay);

	aw->show();
}

void BestGuiEverCreated::userClick()
{
	BestGuiEverCreated::userWindow();
}

void BestGuiEverCreated::userWindow()
{
	QWidget* uw = new QWidget;
	QHBoxLayout* mly = new QHBoxLayout(uw);
	QVBoxLayout* stanga = new QVBoxLayout();
	QVBoxLayout* dreapta = new QVBoxLayout();
	QHBoxLayout* josStanga = new QHBoxLayout();
	this->displayU = new QPushButton("Show All");
	josStanga->addWidget(displayU);
	this->listU = new QListWidget();
	stanga->addWidget(listU);
	stanga->addLayout(josStanga);
	this->browseAll = new QPushButton("Browse all dogs");
	this->browseFiltered = new QPushButton("Browse filtered");
	dreapta->addWidget(browseAll);
	dreapta->addWidget(browseFiltered);
	mly->addLayout(stanga);
	mly->addLayout(dreapta);

	QObject::connect(this->browseAll, &QPushButton::clicked, this, &BestGuiEverCreated::browseMenu);
	QObject::connect(this->browseFiltered, &QPushButton::clicked, this, &BestGuiEverCreated::browseFiltrMenu);
	QObject::connect(this->displayU, &QPushButton::clicked, this, &BestGuiEverCreated::displayAdoptedUser);

	uw->show();
}

void BestGuiEverCreated::browseMenu()
{
	QWidget* bm = new QWidget;
	QVBoxLayout* mly = new QVBoxLayout(bm);
	QHBoxLayout* sus = new QHBoxLayout();
	QHBoxLayout* jos = new QHBoxLayout();
	QVBoxLayout* susstanga = new QVBoxLayout();
	QVBoxLayout* susdreapta = new QVBoxLayout();
	QLabel* lbN = new QLabel("name:");
	QLabel* lbB = new QLabel("breed:");
	QLabel* lbA = new QLabel("age:");
	QLabel* lbP = new QLabel("photograph:");
	susstanga->addWidget(lbN);
	susstanga->addWidget(lbB);
	susstanga->addWidget(lbA);
	susstanga->addWidget(lbP);
	this->nameA = new QLineEdit();
	this->breedA = new QLineEdit();
	this->ageA = new QLineEdit();
	this->photographA = new QLineEdit();
	susdreapta->addWidget(nameA);
	susdreapta->addWidget(breedA);
	susdreapta->addWidget(ageA);
	susdreapta->addWidget(photographA);
	this->adoptA = new QPushButton("ADOPT");
	this->nextA = new QPushButton("NEXT");
	this->saveA = new QPushButton("SAVE");
	this->openA = new QPushButton("OPEN");
	sus->addLayout(susstanga);
	sus->addLayout(susdreapta);
	jos->addWidget(adoptA);
	jos->addWidget(nextA);
	jos->addWidget(saveA);
	jos->addWidget(openA);
	mly->addLayout(sus);
	mly->addLayout(jos);

	std::vector<Dog> aux = this->c->getRepo().getDogs();
	if (aux.size() == 0) {
		QMessageBox::warning(this, "Warning", QString::fromStdString("out of dogs"));
		return;
	}
	this->nameA->setText(QString::fromStdString(aux[0].getName()));
	this->breedA->setText(QString::fromStdString(aux[0].getBreed()));
	this->ageA->setText(QString::fromStdString(std::to_string(aux[0].getAge())));
	this->photographA->setText(QString::fromStdString(aux[0].getPhotograph()));
	aux[0].watch();
	//Dog dx{ this->nameA->text().toStdString(),this->breedA->text().toStdString(),this->ageA->text().toInt(),this->photographA->text().toStdString() };
	QObject::connect(this->nextA, &QPushButton::clicked, this, &BestGuiEverCreated::nextNormal);
	QObject::connect(this->adoptA, &QPushButton::clicked, this, &BestGuiEverCreated::adoptNormal);
	QObject::connect(this->saveA, &QPushButton::clicked, this, &BestGuiEverCreated::saveAdoptionUser);
	QObject::connect(this->openA, &QPushButton::clicked, this, &BestGuiEverCreated::openAdoptionUser);

	bm->show();
}

void BestGuiEverCreated::browseFiltrMenu()
{
	QWidget* bfm = new QWidget;
	QHBoxLayout* mly = new QHBoxLayout(bfm);
	QVBoxLayout* mlyS = new QVBoxLayout();
	QHBoxLayout* mlySsus = new QHBoxLayout();
	QHBoxLayout* mlySjos = new QHBoxLayout();
	QVBoxLayout* Sstanga = new QVBoxLayout();
	QVBoxLayout* Sdreapta = new QVBoxLayout();
	QVBoxLayout* mlyD = new QVBoxLayout();
	QHBoxLayout* sus = new QHBoxLayout();
	QHBoxLayout* jos = new QHBoxLayout();
	QVBoxLayout* susstanga = new QVBoxLayout();
	QVBoxLayout* susdreapta = new QVBoxLayout();
	QLabel* lbN = new QLabel("name:");
	QLabel* lbB = new QLabel("breed:");
	QLabel* lbA = new QLabel("age:");
	QLabel* lbP = new QLabel("photograph:");
	susstanga->addWidget(lbN);
	susstanga->addWidget(lbB);
	susstanga->addWidget(lbA);
	susstanga->addWidget(lbP);
	this->nameF = new QLineEdit();
	this->breedF = new QLineEdit();
	this->ageF = new QLineEdit();
	this->photographF = new QLineEdit();
	susdreapta->addWidget(nameF);
	susdreapta->addWidget(breedF);
	susdreapta->addWidget(ageF);
	susdreapta->addWidget(photographF);
	this->adoptF = new QPushButton("ADOPT");
	this->nextF = new QPushButton("NEXT");
	this->saveF = new QPushButton("SAVE");
	this->openF = new QPushButton("OPEN");
	sus->addLayout(susstanga);
	sus->addLayout(susdreapta);
	jos->addWidget(adoptF);
	jos->addWidget(nextF);
	jos->addWidget(saveF);
	jos->addWidget(openF);
	mlyD->addLayout(sus);
	mlyD->addLayout(jos);
	QLabel* lbBF = new QLabel("breed:");
	QLabel* lbAF = new QLabel("age:");
	Sstanga->addWidget(lbBF);
	Sstanga->addWidget(lbAF);
	this->breedFF = new QLineEdit();
	this->ageFF = new QLineEdit();
	Sdreapta->addWidget(breedFF);
	Sdreapta->addWidget(ageFF);
	mlySsus->addLayout(Sstanga);
	mlySsus->addLayout(Sdreapta);
	this->fil = new QPushButton("FILTER");
	mlySjos->addWidget(fil);
	mlyS->addLayout(mlySsus);
	mlyS->addLayout(mlySjos);
	mly->addLayout(mlyS);
	mly->addLayout(mlyD);

	QObject::connect(this->fil, &QPushButton::clicked, this, &BestGuiEverCreated::getFiltr);
	QObject::connect(this->nextF, &QPushButton::clicked, this, &BestGuiEverCreated::nextFilter);
	QObject::connect(this->adoptF, &QPushButton::clicked, this, &BestGuiEverCreated::adoptFilter);
	QObject::connect(this->saveF, &QPushButton::clicked, this, &BestGuiEverCreated::saveAdoptionUser);
	QObject::connect(this->openF, &QPushButton::clicked, this, &BestGuiEverCreated::openAdoptionUser);

	bfm->show();
}

void BestGuiEverCreated::displayAllAdmin()
{
	this->list->clear();
	std::vector<Dog> all = this->c->getRepo().getDogs();
	for (auto f : all)
	{
		char age[5];
		itoa(f.getAge(), age, 10);
		this->list->addItem(QString::fromStdString(f.getName() + " the " + f.getBreed() + " - " + age + " years old - " + f.getPhotograph()));

	}
}

void BestGuiEverCreated::addDogAdmin()
{
	std::string name = this->name->text().toStdString();
	std::string breed = this->breed->text().toStdString();
	int age = this->age->text().toInt();
	std::string photograph = this->photograph->text().toStdString();

	//Dog d{ name,breed,age,photograph };
	try
	{
		this->c->addDogToRepository(name, breed, age, photograph);
	}
	catch (RepositoryException& eroare)
	{
		//eroare.what();
		QMessageBox::warning(this, "Warning", QString::fromStdString(eroare.what()));
	}
	catch (DogException& eroare)
	{
		std::string erori = "";
		for (auto err : eroare.getErrors())
			erori = erori + err + "\n";
		QMessageBox::warning(this, "Warning", QString::fromStdString(erori));
	}
	this->name->clear();
	this->breed->clear();
	this->age->clear();
	this->photograph->clear();
	//this->displayAllAdmin();
	this->comboDisplay();
}

void BestGuiEverCreated::removeDogAdmin()
{
	std::string name = this->name->text().toStdString();
	std::string breed = this->breed->text().toStdString();

	try
	{
		this->c->removeDogFromRepository(name, breed);
	}
	catch (RepositoryException& eroare)
	{
		//eroare.what();
		QMessageBox::warning(this, "Warning", QString::fromStdString(eroare.what()));
	}
	catch (DogException& eroare)
	{
		std::string erori = "";
		for (auto err : eroare.getErrors())
			erori = erori + err + "\n";
		QMessageBox::warning(this, "Warning", QString::fromStdString(erori));
	}

	this->name->clear();
	this->breed->clear();
	this->age->clear();
	this->photograph->clear();
	//this->displayAllAdmin();
	this->comboDisplay();
}

void BestGuiEverCreated::updateDogAdmin()
{
	std::string name, breed, photograph, name1, breed1, photograph1;
	int age, age1;
	name = this->name->text().toStdString();
	breed = this->breed->text().toStdString();
	age = this->age->text().toInt();
	photograph = this->photograph->text().toStdString();
	name1 = this->name1->text().toStdString();
	breed1 = this->breed1->text().toStdString();
	age1 = this->age1->text().toInt();
	photograph1 = this->photograph1->text().toStdString();
	try 
	{
		this->c->updateDogCtrl(name, breed, age, photograph, name1, breed1, age1, photograph1);
	}
	catch (RepositoryException& eroare)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString(eroare.what()));
	}
	catch (DogException& eroare)
	{
		std::string erori = "";
		for (auto err : eroare.getErrors())
			erori = erori + err + "\n";
		QMessageBox::warning(this, "Warning", QString::fromStdString(erori));
	}
	//this->displayAllAdmin();
	this->name->clear();
	this->breed->clear();
	this->age->clear();
	this->photograph->clear();
	this->name1->clear();
	this->breed1->clear();
	this->age1->clear();
	this->photograph1->clear();
	this->comboDisplay();
}

void BestGuiEverCreated::nameSortAdmin()
{
	this->list->clear();
	ComparatorAscendingName comp;
	std::vector<Dog> rep = this->c->getRepo().getDogs();
	std::vector<Dog> all = this->c->getRepo().genericSort(comp, rep);
	if (this->combo->currentText() == "Detailed")
	{
		for (auto f : all)
		{
			char age[5];
			itoa(f.getAge(), age, 10);
			this->list->addItem(QString::fromStdString(f.getName() + " the " + f.getBreed() + " - " + age + " years old - " + f.getPhotograph()));

		}
	}
	else
	{
		for (auto f : all)
		{
			char age[5];
			itoa(f.getAge(), age, 10);
			this->list->addItem(QString::fromStdString(f.getName() + " the " + f.getBreed()));

		}
	}
}

void BestGuiEverCreated::ageSortAdmin()
{
	this->list->clear();
	ComparatorAscendingAge comp;
	std::vector<Dog> rep = this->c->getRepo().getDogs();
	std::vector<Dog> all = this->c->getRepo().genericSort(comp, rep);
	for (auto f : all)
	{
		char age[5];
		itoa(f.getAge(), age, 10);
		this->list->addItem(QString::fromStdString(f.getName() + " the " + f.getBreed() + " - " + age + " years old - " + f.getPhotograph()));

	}
}

void BestGuiEverCreated::displayAdoptedUser()
{
	this->listU->clear();
	std::vector<Dog> all = this->c->getAdo()->getAdoptedDogs();
	for (auto f : all)
	{
		char age[5];
		itoa(f.getAge(), age, 10);
		this->listU->addItem(QString::fromStdString(f.getName() + " the " + f.getBreed() + " - " + age + " years old - " + f.getPhotograph()));

	}
}

void BestGuiEverCreated::nextNormal()
{
	Dog dx{ this->nameA->text().toStdString(),this->breedA->text().toStdString(),this->ageA->text().toInt(),this->photographA->text().toStdString() };
	BestGuiEverCreated::util4nextNormal(dx);
}

void BestGuiEverCreated::util4nextNormal(Dog & d)
{
	std::vector<Dog> doggos = this->c->getRepo().getDogs();
	if (doggos.size() == 0) 
	{
		this->nameA->clear();
		this->breedA->clear();
		this->ageA->clear();
		this->photographA->clear();
		QMessageBox::warning(this, "Warning", QString::fromStdString("out of dogs"));
		return;
	}
	for(int i=0;i<doggos.size();i++)
		if(doggos[i]==d)
			if (i < doggos.size() - 1)
			{
				this->nameA->setText(QString::fromStdString(doggos[i+1].getName()));
				this->breedA->setText(QString::fromStdString(doggos[i+1].getBreed()));
				this->ageA->setText(QString::fromStdString(std::to_string(doggos[i+1].getAge())));
				this->photographA->setText(QString::fromStdString(doggos[i+1].getPhotograph()));
				Dog dx{ this->nameA->text().toStdString(),this->breedA->text().toStdString(),this->ageA->text().toInt(),this->photographA->text().toStdString() };
				dx.watch();
			}
			else 
			{
				this->nameA->setText(QString::fromStdString(doggos[0].getName()));
				this->breedA->setText(QString::fromStdString(doggos[0].getBreed()));
				this->ageA->setText(QString::fromStdString(std::to_string(doggos[0].getAge())));
				this->photographA->setText(QString::fromStdString(doggos[0].getPhotograph()));
				Dog dx{ this->nameA->text().toStdString(),this->breedA->text().toStdString(),this->ageA->text().toInt(),this->photographA->text().toStdString() };
				dx.watch();
			}
}

void BestGuiEverCreated::adoptNormal()
{
	Dog dx{ this->nameA->text().toStdString(),this->breedA->text().toStdString(),this->ageA->text().toInt(),this->photographA->text().toStdString() };
	BestGuiEverCreated::util4nextNormal(dx);
	if (this->nameA->text() == "") {
		return;
	}
	this->c->addDogToAdoptionList(dx);
	std::vector<Dog> dgs = this->c->getRepo().getDogs();
	if (dgs.size() == 0)
	{
		this->nameA->clear();
		this->breedA->clear();
		this->ageA->clear();
		this->photographA->clear();
		QMessageBox::warning(this, "Warning", QString::fromStdString("out of dogs"));
		return;
	}
}

void BestGuiEverCreated::saveAdoptionUser()
{
	this->c->saveAdoption();
}

void BestGuiEverCreated::openAdoptionUser()
{
	this->c->openAdoption();
}

void BestGuiEverCreated::getFiltr()
{
	std::vector<Dog> dgs = this->c->getRepo().getFilter(this->breedFF->text().toStdString(), this->ageFF->text().toInt());
	if (dgs.size() == 0)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString("no such dogs"));
		this->breedFF->clear();
		this->ageFF->clear();
		return;
	}
	this->nameF->setText(QString::fromStdString(dgs[0].getName()));
	this->breedF->setText(QString::fromStdString(dgs[0].getBreed()));
	this->ageF->setText(QString::fromStdString(std::to_string(dgs[0].getAge())));
	this->photographF->setText(QString::fromStdString(dgs[0].getPhotograph()));
	dgs[0].watch();
}

void BestGuiEverCreated::nextFilter()
{
	Dog dx{ this->nameF->text().toStdString(),this->breedF->text().toStdString(),this->ageF->text().toInt(),this->photographF->text().toStdString() };
	BestGuiEverCreated::util4nextFilter(dx);
}

void BestGuiEverCreated::util4nextFilter(Dog & d)
{
	std::vector<Dog> doggos = this->c->getRepo().getFilter(this->breedFF->text().toStdString(), this->ageFF->text().toInt());
	if (doggos.size() == 0)
	{
		this->nameF->clear();
		this->breedF->clear();
		this->ageF->clear();
		this->photographF->clear();
		QMessageBox::warning(this, "Warning", QString::fromStdString("out of dogs"));
		return;
	}
	for (int i = 0; i<doggos.size(); i++)
		if (doggos[i] == d)
			if (i < doggos.size() - 1)
			{
				this->nameF->setText(QString::fromStdString(doggos[i + 1].getName()));
				this->breedF->setText(QString::fromStdString(doggos[i + 1].getBreed()));
				this->ageF->setText(QString::fromStdString(std::to_string(doggos[i + 1].getAge())));
				this->photographF->setText(QString::fromStdString(doggos[i + 1].getPhotograph()));
				Dog dx{ this->nameF->text().toStdString(),this->breedF->text().toStdString(),this->ageF->text().toInt(),this->photographF->text().toStdString() };
				dx.watch();
			}
			else
			{
				this->nameF->setText(QString::fromStdString(doggos[0].getName()));
				this->breedF->setText(QString::fromStdString(doggos[0].getBreed()));
				this->ageF->setText(QString::fromStdString(std::to_string(doggos[0].getAge())));
				this->photographF->setText(QString::fromStdString(doggos[0].getPhotograph()));
				Dog dx{ this->nameF->text().toStdString(),this->breedF->text().toStdString(),this->ageF->text().toInt(),this->photographF->text().toStdString() };
				dx.watch();
			}
}

void BestGuiEverCreated::adoptFilter()
{
	Dog dx{ this->nameF->text().toStdString(),this->breedF->text().toStdString(),this->ageF->text().toInt(),this->photographF->text().toStdString() };
	BestGuiEverCreated::util4nextFilter(dx);
	if (this->nameF->text() == "") {
		return;
	}
	this->c->addDogToAdoptionList(dx);
	std::vector<Dog> dgs = this->c->getRepo().getFilter(this->breedFF->text().toStdString(), this->ageFF->text().toInt());
	if (dgs.size() == 0)
	{
		this->nameF->clear();
		this->breedF->clear();
		this->ageF->clear();
		this->photographF->clear();
		QMessageBox::warning(this, "Warning", QString::fromStdString("out of dogs"));
		return;
	}
}

void BestGuiEverCreated::comboDisplay()
{
	if (this->combo->currentText() == "Detailed")
	{
		BestGuiEverCreated::displayAllAdmin();
	}
	else
	{
		this->list->clear();
		std::vector<Dog> all = this->c->getRepo().getDogs();
		for (auto f : all)
		{
			char age[5];
			itoa(f.getAge(), age, 10);
			this->list->addItem(QString::fromStdString(f.getName() + " the " + f.getBreed()));

		}
	}
}
