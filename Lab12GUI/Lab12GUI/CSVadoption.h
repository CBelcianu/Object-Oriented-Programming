#pragma once
#include "FileAdoption.h"
#include <string>

class CSVadoption : public FileAdoption
{
public:
	CSVadoption(const std::string& filename) : FileAdoption{ filename } {}

	/*
	Writes the playlist to file.
	Throws: FileException - if it cannot write.
	*/
	void writeToFile() override;

	/*
	Displays the playlist using Microsof Excel.
	*/
	void displayPlaylist() const override;
};

