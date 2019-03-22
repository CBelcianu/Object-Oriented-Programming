#pragma once
#include <string>
#include "Dog.h"
#include <vector>

class DogException
{
private:
	std::vector<std::string> errors;

public:
	DogException(std::vector<std::string> _errors);
	/*
	constructor for the DogException class
	*/

	std::vector<std::string> getErrors() const;
	/*
	function that returns the field errors;
	input: -
	output: errors
	*/
};

class DogValidator
{
public:
	DogValidator() {} //default constructor for the dog class
	static void validate(const Dog& s);
	/*
	function that checks if a given dog is valid
	input: dog
	output: nothhing or, if the dog is not valid throws the errors
	*/
};