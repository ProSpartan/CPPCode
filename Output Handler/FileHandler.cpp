#include "FileHandler.h"

std::fstream FileHandler::fileStream;

std::string FileHandler::getFilePath()
{
	return FileHandler::filePath;
}

OutputHandler* FileHandler::setFilePath(std::string filePath)
{
	FileHandler::filePath = filePath;
	return this;
}

OutputHandler* FileHandler::open(unsigned int _mode, std::string fileName)
{
	if (filePath == "")
	{
		CHAR my_documents[MAX_PATH];
		HRESULT result = SHGetFolderPathA(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, my_documents);
		if (result != S_OK)
		{
			std::cout << "Error occured trying to get default user path to documents: " << result << std::endl;
		}
		FileHandler::filePath = std::string(my_documents);
	}
	if (fileName == "")
	{
		FileHandler::filePath += "\\temp.txt";
	}
	else
	{
		FileHandler::filePath += fileName;
	}

	FileHandler::filePath = FileHandler::filePath;
	FileHandler::fileStream.open(FileHandler::filePath, _mode);

	if (FileHandler::fileStream.fail())
	{
		std::cout << "Failed to open file " << FileHandler::filePath << "." << std::endl;
	}

	return this;
}

OutputHandler* FileHandler::close()
{
	if (this->isOpen())
	{
		FileHandler::fileStream.close();
	}

	return this;
}

OutputHandler* FileHandler::setOutputPrecision(int precision)
{
	if (this->isOpen())
	{
		FileHandler::fileStream << std::setprecision(precision);
	}

	return this;
}

OutputHandler* FileHandler::setOutputFixed()
{
	if (this->isOpen())
	{
		FileHandler::fileStream << std::fixed;
	}

	return this;
}

OutputHandler* FileHandler::setOutputScientific()
{
	if (this->isOpen())
	{
		FileHandler::fileStream << std::scientific;
	}

	return this;
}

OutputHandler* FileHandler::setw(int value)
{
	if (this->isOpen())
	{
		FileHandler::fileStream << std::setw(value);
	}

	return this;
}

OutputHandler* FileHandler::output(int value)
{
	if (this->isOpen())
	{
		FileHandler::fileStream << value;
	}

	return this;
}

OutputHandler* FileHandler::output(float value)
{
	if (this->isOpen())
	{
		FileHandler::fileStream << value;
	}

	return this;
}

OutputHandler* FileHandler::output(std::string value)
{
	if (this->isOpen())
	{
		FileHandler::fileStream << value;
	}

	return this;
}

OutputHandler* FileHandler::outputEndLine()
{
	if (this->isOpen())
	{
		FileHandler::fileStream << std::endl;
	}

	return this;
}

bool FileHandler::isOpen()
{
	return FileHandler::fileStream.is_open();
}

FileHandler* FileHandler::getInstance()
{
	static FileHandler *fileHandler;
	fileHandler = new FileHandler();
	return fileHandler;
}