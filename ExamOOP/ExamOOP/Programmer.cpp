#include "Programmer.h"

std::istream & operator>>(std::istream & is, Programmer & p)
{
	std::string line;
	std::getline(is, line);
	std::vector<std::string> tokens = tokenize(line, ',');
	if (tokens.size() != 3)
		return is;
	p.name = tokens[0];
	p.rev = atoi(tokens[1].c_str());
	p.total = atoi(tokens[2].c_str());
	return is;
}

std::ostream & operator<<(std::ostream & os, Programmer & p)
{
	os << p.name << ',' << std::to_string(p.rev) << ',' << std::to_string(p.total) << '\n';
	return os;
}
