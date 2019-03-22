#include "Repository.h"

void Repository::reviseSourceFile(SourceFile & s, std::string& rn)
{
	int pos, i = 0;
	for (auto x : this->sourcefiles)
	{
		if (x.getName() == s.getName())
			pos = i;
		i++;
	}
	this->sourcefiles[pos].revise(rn);
	this->toFile();
}

void Repository::sortSN()
{
	int i, j;
	for (i = 0; i < this->sourcefiles.size(); i++) {
		for (j = 0; j < this->sourcefiles.size(); j++)
		{
			if (this->sourcefiles[i].getName() < this->sourcefiles[j].getName())
			{
				SourceFile cv = this->sourcefiles[i];
				this->sourcefiles[i] = this->sourcefiles[j];
				this->sourcefiles[j] = cv;
			}
		}
	}
}

void Repository::readProgrammers()
{
	std::ifstream f(this->fp);
	Programmer p;
	while (f >> p)
		this->programmers.push_back(p);
	f.close();
}

void Repository::readSourceFiles()
{
	std::ifstream f(this->fs);
	SourceFile s;
	while (f >> s)
		this->sourcefiles.push_back(s);
	f.close();
}

void Repository::toFile()
{
	std::ofstream f(this->fs);
	for (auto s : this->sourcefiles)
		f << s;
	f.close();
}
