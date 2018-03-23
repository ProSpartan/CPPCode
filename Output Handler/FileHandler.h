#pragma once
#pragma comment(lib, "shell32.lib")

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <Windows.h>
#include <iostream>
#include <ShlObj.h>
#include <fstream>
#include <string>
#include <iomanip>

#include "OutputHandler.h"

class FileHandler : public OutputHandler
{
public:
	OutputHandler* open(unsigned int, std::string);
	OutputHandler* close();
	OutputHandler* setOutputPrecision(int);
	OutputHandler* setOutputFixed();
	OutputHandler* setOutputScientific();
	OutputHandler* setw(int);
	OutputHandler* output(std::string);
	OutputHandler* output(int);
	OutputHandler* output(float);
	OutputHandler* outputEndLine();
	OutputHandler* setFilePath(std::string);
	bool isOpen();
	std::string getFilePath();
	static FileHandler* getInstance();
private:
	std::string filePath;
	static std::fstream fileStream;
};

#endif
