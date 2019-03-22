#include "DogValidator.h"

using namespace std;

DogException::DogException(std::vector<std::string> _errors) : errors{ _errors }
{
}

std::vector<std::string> DogException::getErrors() const
{
	return this->errors;
}

void DogValidator::validate(const Dog & s)
{
	vector<string> errors;
	if (!isupper(s.getName()[0]))
		errors.push_back(string("The name of the dog must start with a capital letter!\n"));
	if (!isupper(s.getBreed()[0]))
		errors.push_back(string("The breed of the dog must start with a capital letter!\n"));
	if (s.getAge() == 0)
		errors.push_back(string("The age can not be 0!\n"));

	size_t posHttp = s.getPhotograph().find("http");
	if (posHttp != 0)
		errors.push_back("The link to the photograph must start with: \"http\"\n");

	if (errors.size() > 0)
		throw DogException(errors);
}
