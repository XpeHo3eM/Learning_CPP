#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>


// Проверка корректности символов в ФИО
bool checkName(std::string &name)
{
	for (int i = 0; i < name.length(); ++i)
		if (!(((name[i] >= 'a') && (name[i] <= 'z')) || ((name[i] >= 'A') && (name[i] <= 'Z'))))
			return false;
	return true;
}


// Проверка корректности введенной даты
bool checkDate(std::string& date)
{
	if (date.length() != 10)
		return false;

	int day = std::stoi(date.substr(0, 2));
	int month = std::stoi(date.substr(3, 2));

	if ((date[2] == '.') && (date[5] == '.') && (day > 0) && (month > 0) && (month <= 12))
	{
		
		if (month != 2)
		{
			if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				if (day > 30)
					return false;
			}
			else
				if (day > 31)
					return false;
		}
		else
		{
			int year = std::stoi(date.substr(6, 4));
			if (year < 1)
				return false;

			// Проверка високосного года
			if ((year % 4 != 0) || ((year % 100 == 0) && (year % 400 != 0)))
			{
				if (day > 28)
					return false;
			}
			else
				if (day > 29)
					return false;	
		}
	}
	else
		return false;

	return true;
}


// Проверка корректности введенных данных
bool isCorrectData(std::string &firstName, std::string &secondName, std::string &date, int cash)
{
	system("cls");
	if (checkName(firstName) && checkName(secondName) && checkDate(date) && (cash > 0))
	{
		std::cout << "~~~ Data was added ~~~" << std::endl << std::endl;
		return true;
	}
	else
	{
		std::cout << "~~~ Incorrect input. Data wasn't added ~~~" << std::endl << std::endl;
		return false;
	}
}


void inputDatabase()
{
	std::string firstName, secondName;
	std::string date;
	int cash;
	do
	{
		std::cout << "Input First and Second name: ";
		std::cin >> firstName >> secondName;
		std::cout << "Input date on format DD.MM.YYYY: ";
		std::cin >> date;
		std::cout << "Input cash: ";
		std::cin >> cash;
	} 
	while (!isCorrectData(firstName, secondName, date, cash));

	std::ofstream database("database.txt", std::ios::app);
	database.width(20);
	database << firstName + ' ' + secondName;
	database.width(12);
	database << date;
	database.width(10);
	database << cash << std::endl;
	database.close();
}


int main()
{
	int action;
	do
	{
		std::cout << "Press 1 to add data" << std::endl;
		std::cout << "Press 9 to erase data" << std::endl;
		std::cout << "Press 0 to exit" << std::endl;
		std::cin >> action;

		// Очистка экрана
		system("cls");

		if (action == 1)
			inputDatabase();
		else
			if (action == 9)
			{
				std::ofstream database("database.txt");
				database.close();
				std::cout << "!!! Database was cleared !!!" << std::endl << std::endl;
			}
	} while (action != 0);
}