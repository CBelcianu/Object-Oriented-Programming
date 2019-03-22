#pragma once
#include "FileAdoption.h"
#include <string>

class HTMLadoption :public FileAdoption
{
public:
	HTMLadoption(const std::string& filename) : FileAdoption{ filename } {}

	void writeToFile() override;

	void displayPlaylist() const override;
};

