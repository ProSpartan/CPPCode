#include "ConsoleHandler.h"

OutputHandler* ConsoleHandler::setOutputPrecision(int precision)
{
	std::cout.precision(precision);
	return this;
}

OutputHandler* ConsoleHandler::setOutputFixed()
{
	std::cout << std::fixed;
	return this;
}

OutputHandler* ConsoleHandler::setOutputScientific()
{
	std::cout << std::scientific;
	return this;
}

OutputHandler* ConsoleHandler::setw(int value)
{
	std::cout << std::setw(value);
	return this;
}

OutputHandler* ConsoleHandler::output(std::string output)
{
	std::cout << output;
	return this;
}

OutputHandler* ConsoleHandler::output(int output)
{
	std::cout << output;
	return this;
}

OutputHandler* ConsoleHandler::output(float output)
{
	std::cout << output;
	return this;
}

OutputHandler* ConsoleHandler::outputEndLine()
{
	std::cout << std::endl;
	return this;
}

OutputHandler* ConsoleHandler::setPrompt(std::string prompt)
{
	ConsoleHandler::prompt = prompt;
	return this;
}

OutputHandler* ConsoleHandler::output(std::vector<std::string> output, std::string separator)
{
	const int stackSize = output.size();

	for (int i = 0; i < stackSize; i++)
	{
		if (i == stackSize - 1)
		{
			separator = " ";
		}

		std::cout << output[i] << separator;
	}

	return this;
}

std::string ConsoleHandler::inputString()
{
	std::string input;
	std::cin >> input;
	return input;
}

std::string ConsoleHandler::inputLongString()
{
	std::string input;
	std::getline(std::cin, input);
	return input;
}

std::vector<std::string> ConsoleHandler::inputMultipleStrings(const int count)
{
	std::vector<std::string> inputs(count);

	for (int i = 0; i < count; i++)
	{
		ConsoleHandler::output(ConsoleHandler::prompt);
		inputs[i] = ConsoleHandler::inputString();
	}

	return inputs;
}

int ConsoleHandler::inputInteger()
{
	int input;
	std::cin >> input;
	return input;
}

std::vector<int> ConsoleHandler::inputMultipleIntegers(const int count)
{
	std::vector<int> inputs(count);

	for (int i = 0; i < count; i++)
	{
		ConsoleHandler::output(ConsoleHandler::prompt);
		inputs[i] = ConsoleHandler::inputInteger();
	}

	return inputs;
}

float ConsoleHandler::inputFloat()
{
	float input;
	std::cin >> input;
	return input;
}

std::vector<float> ConsoleHandler::inputMultipleFloats(const int count)
{
	std::vector<float> inputs(count);

	for (int i = 0; i < count; i++)
	{
		ConsoleHandler::output(ConsoleHandler::prompt);
		inputs[i] = ConsoleHandler::inputFloat();
	}

	return inputs;
}

char ConsoleHandler::inputChar()
{
	char input;
	std::cin >> input;
	return input;
}

ConsoleHandler* ConsoleHandler::getInstance()
{
	static ConsoleHandler *consoleHandler;
	consoleHandler = new ConsoleHandler();
	return consoleHandler;
}