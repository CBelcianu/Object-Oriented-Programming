#include "SourceFile.h"

std::istream & operator>>(std::istream & is, SourceFile & p)
{
	std::string line;
	std::getline(is, line);
	std::vector<std::string> tokens = tokenize(line, ',');
	if (tokens.size() != 4)
		return is;
	p.name = tokens[0];
	p.status = tokens[1];
	p.creator = tokens[2];
	p.reviser = tokens[3];
	return is;
}

std::ostream & operator<<(std::ostream & os, SourceFile & p)
{
	os << p.name << ',' << p.status << ',' << p.creator << ',' << p.reviser << '\n';
	return os;
}
