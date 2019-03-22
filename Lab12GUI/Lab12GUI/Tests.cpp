#include "Tests.h"
#include <assert.h>
#include <vector>
#include "Repository.h"
#include "Controller.h"
#include "AdoptionList.h"
#include "CSVadoption.h"
#include "RepositoryExceptions.h"
#include "DogValidator.h"

void Tests::testDog()
{

	Dog s{ "A", "B", 5,"https://www.google.com" };
	Dog s1{ "C","B",5,"https://www.google.com" };
	assert(s.getName() == "A");
	assert(s.getBreed() == "B");
	assert(s.getPhotograph() == "https://www.google.com");
	assert(s.getAge() == 5);
	s = s1;
	assert(s.getName() == "C");
	Dog s2{ "C","B",5,"https://www.google/com" };
	assert(s1 == s2);
	Dog s3{ "S","Z",5,"https://www.google.com" };
	int z = (s1 == s3);
	assert(z == 0);

	//s.watch();
}
/*
void Tests::testDynamicVector()
{

Dog s1{ "A", "B", 5,"https://www.google.com" };
Dog s2{ "C", "D", 5,"https://www.google.com" };
DynamicVector<Dog> v1;
v1.add(s1);
v1.add(s2);
assert(v1.getSize() == 2);

DynamicVector<Dog> v2 = v1;
assert(v2.getSize() == 2);

v1.remove(s2);
assert(v1.getSize() == 1);

Dog s3{ "1", "2", 5,"https://www.google.com" };
Dog s4{ "3", "4", 5,"https://www.google.com" };

v1.update(s1, s2);
v1.add(s1);
v1.add(s3);
v1.add(s2);
assert(v1[0].getName() == s2.getName());
v1 = v1 - s1;
v1 = v1 - s2;
v1.add(s1);
v1.add(s2);

Dog s5{ "5", "6", 5,"https://www.google.com" };
Dog s6{ "7", "8", 5,"https://www.google.com" };
Dog s7{ "9", "10", 5,"https://www.google.com" };
Dog s8{ "f", "j", 5,"https://www.google.com" };
Dog s9{ "x", "x", 5,"https://www.google.com" };
Dog s10{ "y", "y", 5,"https://www.google.com" };
Dog s11{ "w", "w", 5,"https://www.google.com" };
Dog s12{ "z", "z", 5,"https://www.google.com" };
Dog s13{ "g", "g", 5,"https://www.google.com" };
Dog s14{ "88", "88", 5,"https://www.google.com" };

v1.add(s3);
v1.add(s4);
v1.add(s5);
v1.add(s6);
v1.add(s7);
v1.add(s8);
v1.add(s9);
v1.add(s10);
v1.add(s11);
v1.add(s12);
v1.add(s13);

assert(v1.getSize() == 13);

Dog* dg = v1.getAllElems();

assert(v1.update(s14, s13) == 0);
assert(v1.update(s14, s12) == 0);
assert(v1.remove(s14) == 0);
}
*/
void Tests::testRepository()
{

	Repository repo{ "test.txt" };
	Dog s1{ "A", "B", 5,"https://www.google.com" };
	Dog s2{ "C", "D", 6,"https://www.google.com" };
	Dog s3{ "E", "F", 5,"https://www.google.com" };
	repo.addDog(s1);
	repo.addDog(s2);
	repo.addDog(s3);
	assert("A" == s1.getName() && "B" == s1.getBreed());

	std::vector<Dog> dogs = repo.getDogs();
	assert(dogs.size() == 3);
	repo.removeDog(s3);
	dogs = repo.getDogs();
	assert(dogs.size() == 2);
	repo.updateDog(s2, s3);
	dogs = repo.getDogs();
	assert(dogs[1].getName() == s3.getName());

	std::vector<Dog> f = repo.getFilter("B", 6);
	assert(f.size() == 1);
	ComparatorAscendingAge c;
	assert(c.compare(s1, s2) == 1);
	std::vector<Dog> tst = repo.genericSort(c, repo.getDogs());
	ComparatorAscendingName d;
	assert(d.compare(s2, s1) == 0);
	std::vector<Dog> tst1 = repo.genericSort(d, repo.getDogs());
	try
	{
		repo.addDog(s1);
	}
	catch (DuplicateDogException& exc)
	{
		exc;
	}
	try
	{
		repo.removeDog(s2);
	}
	catch (RepositoryException& rex)
	{
		rex;
	}
	try
	{
		repo.updateDog(s2, s1);
	}
	catch (RepositoryException& rex)
	{
		rex;
	}
	repo.removeDog(s1);
	repo.removeDog(s3);

}

void Tests::testController()
{

	Repository repo{ "testC.txt" };
	FileAdoption* al = new CSVadoption("test1.txt");
	Controller ctrl{ repo, al };
	ctrl.addDogToRepository("Aa", "Bb", 5, "https://www.google.com");
	ctrl.addDogToRepository("Cc", "Dd", 5, "https://www.google.com");
	ctrl.addDogToRepository("Ee", "Ff", 5, "https://www.google.com");

	assert(ctrl.getRepo().getDogs().size() == 3);
	ctrl.removeDogFromRepository("Cc", "Dd");
	assert(ctrl.getRepo().getDogs().size() == 2);
	ctrl.updateDogCtrl("Aa", "Bb", 5, "https://www.google.com", "Cc", "Dd", 5, "https://www.google.com");
	std::vector<Dog> v1 = ctrl.getRepo().getDogs();
	assert(v1[0].getName() == "Cc");
	Dog d{ "Cc","Dd",5,"https://www.google.com" };
	ctrl.addDogToAdoptionList(d);
	std::vector<Dog> v2 = ctrl.getAdo()->getAdoptedDogs();
	assert(v2[0].getName() == "Cc");
	ComparatorAscendingAge c;
	ctrl.removeDogFromRepository("Ee", "Ff");
	ctrl.saveAdoption();


}

void Tests::testAll()
{

	testDog();
	//testDynamicVector();
	testRepository();
	testController();
}
