#pragma once
#include "AdoptionList.h"

class FileAdoption : public AdoptionList
{
protected:
	std::string filename;

public:
	FileAdoption(const std::string& filename);
	virtual ~FileAdoption() {}

	virtual void writeToFile() = 0;
	virtual void displayPlaylist() const = 0;
};