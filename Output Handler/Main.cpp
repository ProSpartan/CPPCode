#include "ConsoleHandler.h"
#include "FileHandler.h"
#include <cctype>

int main()
{
	OutputHandler *console;
	console = ConsoleHandler::getInstance();
	OutputHandler *file;
	file = FileHandler::getInstance();

	std::string name;
	int age;
	std::string job;
	char married;

	name = console
		->output("What is your name> ")
		->cast<ConsoleHandler>(console)
		->inputString();
	age = console
		->output("What is your age> ")
		->cast<ConsoleHandler>(console)
		->inputInteger();
	job = console
		->output("What is your job> ")
		->cast<ConsoleHandler>(console)
		->inputString();
	married = std::tolower(console
		->output("Are you married(y/n)> ")
		->cast<ConsoleHandler>(console)
		->inputChar());


	file
		->cast<FileHandler>(file)
		->setFilePath("C:\\Users\\Isaac\\Documents\\GitHub\\CPPCode\\Output Handler\\")
		->cast<FileHandler>(file)
		->open(std::fstream::out | std::fstream::trunc, "example_output.txt");

	file->output("Name: ")->output(name)->outputEndLine()
		->output("Age: ")->output(age)->outputEndLine()
		->output("Job: ")->output(job)->outputEndLine();
	if (married == 'n')
	{
		file->output("Marriage Status: Single")->outputEndLine();
	}
	else
	{
		file->output("Marriage Status: Married")->outputEndLine();
	}

	file->cast<FileHandler>(file)->close();

    return 0;
}
