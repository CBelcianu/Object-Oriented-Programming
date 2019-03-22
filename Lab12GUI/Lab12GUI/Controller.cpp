#include "Controller.h"
#include "DogValidator.h"

int Controller::addDogToRepository(const std::string& name, const std::string& breed, int age, const std::string& photograph)
{
	Dog d{ name, breed, age, photograph };
	DogValidator vd;
	vd.validate(d);
	return this->repo.addDog(d);
}

int Controller::removeDogFromRepository(const std::string & name, const std::string & breed)
{
	Dog d{ name, breed, 1, "https://photograph" };
	DogValidator vd;
	vd.validate(d);
	return this->repo.removeDog(d);
}

int Controller::updateDogCtrl(const std::string& name, const std::string& breed, int age, const std::string& photograph, const std::string& nname, const std::string& nbreed, int nage, const std::string& nphotograph)
{
	Dog d1{ name,breed,age,photograph };
	Dog d2{ nname,nbreed,nage,nphotograph };
	DogValidator vd;
	vd.validate(d1);
	vd.validate(d2);
	return this->repo.updateDog(d1, d2);
}

/*int Controller::addDogToAdoptionList(const std::string & name, const std::string & breed, int age, const std::string & photograph)
{
Dog d{ name, breed, age, photograph };
this->repo.removeDog(d);
return this->lst.adoptDog(d);

}
*/

int Controller::addDogToAdoptionList(Dog& d)
{
	this->repo.removeDog(d);
	return this->lst->adoptDog(d);
}

void Controller::saveAdoption()
{
	if (this->lst == nullptr)
		return;

	this->lst->writeToFile();
}

void Controller::openAdoption() const
{
	if (this->lst == nullptr)
		return;

	this->lst->displayPlaylist();
}
