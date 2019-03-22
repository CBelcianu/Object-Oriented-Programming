#pragma once
#include "Programmer.h"
#include "SourceFile.h"
class Repository
{
private:
	std::vector<Programmer> programmers;
	std::vector<SourceFile> sourcefiles;
	std::string fp;
	std::string fs;
public:
	Repository(const std::string fp, const std::string fs) :fp(fp), fs(fs) { this->readProgrammers(); this->readSourceFiles(); this->sortSN(); }
	void addSourceFile(SourceFile& s) { this->sourcefiles.push_back(s); this->toFile(); this->sortSN(); }
	void reviseSourceFile(SourceFile& s,std::string& rn);
	std::vector<Programmer> getProgrammers() { return programmers; }
	std::vector<SourceFile> getSourceFiles() { return sourcefiles; }
	void sortSN();
	void readProgrammers();
	void readSourceFiles();
	void toFile();
	~Repository() {}
};

