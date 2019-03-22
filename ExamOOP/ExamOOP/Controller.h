#pragma once
#include "Repository.h"
#include "Observer.h"
class Controller:public Subject
{
private:
	Repository r;
public:
	Controller(Repository& r) :r(r) {}

	/*
	function that adds a new SourceFile to the repository and notifies all the observers about the modification that occured
	input: SourceFile& s - the source file that we want to add;
	output: void
	*/
	void addSourceFileC(SourceFile& s) { this->r.addSourceFile(s); this->notify(); }

	/*
	function that "revises" a SourceFile;
	it updates the status of a SourceFile tu "revised" if its status is "not_revised" and it updates its reviser with the name of the Programmer wich revised it
	input: SourceFile& s - the source file that we want to revise
		   std::string& name - the name of the reviser
	*/
	void reviseSourceFileC(SourceFile& s, std::string& rn) { this->r.reviseSourceFile(s, rn); this->notify(); }
	Repository getRepo() { return r; }
	int getSize() { return this->r.getSourceFiles().size(); }
	~Controller() {}
};

