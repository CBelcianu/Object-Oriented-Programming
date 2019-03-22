#pragma once
#include "Repository.h"
#include "AdoptionList.h"
#include "FileAdoption.h"

class Controller
{
private:
	Repository repo;
	FileAdoption* lst;

public:
	Controller(const Repository& r, FileAdoption* l) : repo{ r }, lst{ l } {} //default constructor

	//Controller() {}

	Repository getRepo() const { return repo; }
	/*
	function that returns the repository
	input: -
	output: repo
	*/

	FileAdoption* getAdo() { return lst; }
	/*
	function that returns the adoption list
	input: -
	output: adoption list
	*/

	int addDogToRepository(const std::string& name, const std::string& breed, int age, const std::string& photograph);
	/*
	function that adds a dog to the repo
	input: name, breed, age, photograph
	*/

	int removeDogFromRepository(const std::string& name, const std::string& breed);
	/*
	function that removes a dog from the repo
	input: name, breed, age, photograph
	*/

	int updateDogCtrl(const std::string& name, const std::string& breed, int age, const std::string& photograph, const std::string& nname, const std::string& nbreed, int nage, const std::string& nphotograph);
	/*
	function that updates a dog from the repository
	input: name, breed, age, photograph, newName, newBreed, newAge, newPhotograph
	*/

	//int addDogToAdoptionList(const std::string& name, const std::string& breed, int age, const std::string& photograph);
	int addDogToAdoptionList(Dog& d);
	/*
	function that adds a dog to the adoption list
	input: name, breed, age, photograph
	*/
	void saveAdoption();

	/*
	Opens the playlist, with an appropriate application.
	Throws: FileException - if the given file cannot be opened.
	*/
	void openAdoption() const;
};

