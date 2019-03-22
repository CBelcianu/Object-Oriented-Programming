#pragma once
#include <iostream>
#include <fstream>
#include "Utils.h"
class SourceFile
{
private:
	std::string name;
	std::string status;
	std::string creator;
	std::string reviser;
public:
	SourceFile() {}
	SourceFile(const std::string& name, const std::string& status, const std::string& creator, const std::string& reviser) :name(name), status(status), creator(creator), reviser(reviser) {}
	std::string getName() { return name; }
	std::string getStatus() { return status; }
	std::string getCreator() { return creator; }
	std::string getReviser() { return reviser; }
	void revise(std::string& rn) { status = "revised"; reviser = rn; }
	SourceFile& operator=(SourceFile& s) { this->name = s.name; this->status = s.status; this->creator = s.creator; this->reviser = s.reviser; return *this; }
	friend std::istream& operator>>(std::istream& is, SourceFile& p);
	friend std::ostream& operator<<(std::ostream& os, SourceFile& p);
	~SourceFile() {}
};

