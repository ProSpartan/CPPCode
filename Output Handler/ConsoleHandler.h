#pragma once

#ifndef CONSOLEHANDLER_H
#define CONSOLEHANDLER_H

#include <string>
#include <vector>
#include <iomanip>

#include "OutputHandler.h"

class ConsoleHandler : public OutputHandler
{
public:
	OutputHandler* setOutputPrecision(int);
	OutputHandler* setOutputFixed();
	OutputHandler* setOutputScientific();
	OutputHandler* setw(int);
	OutputHandler* output(std::string);
	OutputHandler* output(int);
	OutputHandler* output(float);
	OutputHandler* outputEndLine();
	OutputHandler* setPrompt(std::string);
	OutputHandler* output(std::vector<std::string>, std::string);
	std::string inputString();
	std::string inputLongString();
	std::vector<std::string> inputMultipleStrings(const int);
	int inputInteger();
	std::vector<int> inputMultipleIntegers(const int);
	float inputFloat();
	std::vector<float> inputMultipleFloats(const int);
	char inputChar();
	static ConsoleHandler* getInstance();
private:
	std::string prompt;
};

#endif