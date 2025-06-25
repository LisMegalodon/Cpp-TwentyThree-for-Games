#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <algorithm>

using std::string;

//FUNCTION
bool isNumber(const string& input) {
	if (input.empty())
		return false;

	for (char ch : input) {
		if (std::isdigit(static_cast<unsigned char>(ch))) {
			return true;
		}
	}
	return false;
}

int main()
{
	string name;
	int age;
	int messageOption;

	std::cout << "What is your name ?" << std::endl;
	std::cin >> name;

	//ERROR Handling-> STRING
	while (isNumber(name)) {
		std::cout << "That looks like a number. Please enter a valid name: ";
		std::cin >> name;
	}

	std::cout << "What is your age ?" << std::endl;
	std::cin >> age;

	//ERROR Handling-> INTEGER
	while (std::cin.fail())
	{
		std::cout << "ERROR: I expected a number." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Provide your age as a number." << std::endl;
		std::cin >> age;
	}

	//MESSAGE Option
	if (age > 0 && age < 25)
		messageOption = 1;
	else if (age >= 25 && age <= 50)
		messageOption = 2;
	else
		messageOption = 3;

	//ADVANCED
	switch (messageOption) {
	case 1:
		std::cout << "\nHello " << name
			<< ", you are only " << age
			<< " years old." << std::endl;
		break;
	case 2:
		std::cout << "\nHello " << name
			<< ", you are already " << age
			<< " years old." << std::endl;
		break;
	case 3:
		std::cout << "\nHello " << name
			<< ".You are very wise for your age" << std::endl;
		break;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	//MESSAGE prior to exiting
	std::cout << "Press Enter to exit...";
	std::cin.get();
	return 0;	//No errors
}