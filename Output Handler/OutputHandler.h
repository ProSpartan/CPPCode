#pragma once

#ifndef OUTPUTHANDLER_H
#define OUTPUTHANDLER_H

#include <iostream>

class OutputHandler
{
public:
	virtual OutputHandler* setOutputPrecision(int) = 0;
	virtual OutputHandler* setOutputFixed() = 0;
	virtual OutputHandler* setOutputScientific() = 0;
	virtual OutputHandler* setw(int) = 0;
	virtual OutputHandler* output(std::string) = 0;
	virtual OutputHandler* output(int) = 0;
	virtual OutputHandler* output(float) = 0;
	virtual OutputHandler* outputEndLine() = 0;
	template<class T> T* cast(OutputHandler* castObject) { return dynamic_cast<T*>(castObject); };
};

#endif
