#pragma once
#include <iostream>

class Dog
{
private:
	std::string name;
	std::string breed;
	int age;
	std::string photograph;

public:
	Dog(); //default constructor

	Dog(const std::string& name, const std::string& breed, const int age, const std::string& photograph); //copy constructor

	Dog& operator=(const Dog& d);

	//void copy(Dog& d);

	int operator==(Dog& d);
	/*
	function that overloads the == operator for the class Dog
	input: dog
	output: 1 if this==dog, 0 if this!=dog
	*/

	std::string getName() const { return name; }
	/*
	function that returns the name of a dog
	input: -
	output: name
	*/

	std::string getBreed() const { return breed; }
	/*
	function that returns the breed of a dog
	input: -
	output: breed
	*/

	int getAge() const { return age; }
	/*
	function that returns the age of a dog
	input: -
	output: age
	*/

	std::string getPhotograph() const { return photograph; }
	/*
	function that returns the link to the photograph of a dog
	input: -
	output: link
	*/

	void watch();
	/*
	function that exectues a shell command to open the link to the photograph of a dog
	*/

	friend std::istream& operator>>(std::istream& is, Dog& s);
	friend std::ostream& operator<<(std::ostream& os, const Dog& s);
};

