#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

struct recordSheet
{
    std::string firstName;
    std::string secondName;
    std::string date;
    int cash;
};

// Проверка корректности ввода даты в формате ДД.ММ.ГГГГ
bool isCorrectDate(std::string& date);

// Преобразование введенного ответа к нижнему регистру
void lowerTransform(std::string& answer);

// Запись в ведомость
void writeRecordSheet();

// Просмотр ведомости
void readRecordSheet();

// Пауза до ввода
void wait();


int main()
{
    std::string action;
    do
    {
        system("cls");
        std::cout << "Welcome to recordsheet. Choose your action:" << std::endl;
        std::cout << "1. Enter \"add\" to add new record;" << std::endl;
        std::cout << "2. Enter \"read\" to view recordsheet;" << std::endl;
        std::cout << "3. Enter \"exit\" to close program." << std::endl << std::endl;
        std::cin >> action;
        lowerTransform(action);

        if (action == "add") writeRecordSheet();
        else if (action == "read") readRecordSheet();

    } while (action != "exit");
}


void wait()
{
    std::cout << std::endl << std::endl << "Enter 0 to continue: ";
    std::string answer;
    do
        std::cin >> answer;
    while (answer != "0");
}


bool isCorrectDate(std::string& date)
{
    // Проверяем корректность установленных точек и длины введенной даты
    if ((date.length() != 10) || (date[2] != '.') || (date[5] != '.'))
        return false;

    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));
    int year = std::stoi(date.substr(6, 4));

    if ((day <= 0) || (month <= 0) || (month > 12) || (year <= 0))
        return false;

    // Проверяем принадлежность даты к месяцам с 30 днями
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return (day <= 30);
    else
        // Проверяем високосность и 28/29 дней в феврале
        if (month == 2)
            return (((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))) ? (day <= 29) : (day <= 28));

        // Проверяем оставшиеся месяцы с 31 днем
        else
            return (day <= 31);
}


void lowerTransform(std::string& answer)
{
    for (int i = 0; i < answer.length(); ++i)
        answer[i] = std::tolower(answer[i]);
}


void writeRecordSheet()
{
    system("cls");
    std::cin.ignore();
    recordSheet person;
    std::cout << "Enter first and second name: ";
    std::cin >> person.firstName;
    std::cin >> person.secondName;

    do 
    {
        std::cout << "Enter date of withdraw on format DD.MM.YYYY: ";
        std::cin >> person.date;
    } while (!isCorrectDate(person.date));
    
    std::cout << "Enter withdraw cash: ";
    std::cin >> person.cash;

    std::ofstream file("recordsheet.txt", std::ios::app);
    file.width(20);
    file << person.firstName + ' ' + person.secondName;
    file.width(13);
    file << person.date;
    file.width(10);
    file << person.cash;
    file << '\n';
    file.close();

    system("cls");
    std::cout << "~ New record was added ~";
    wait();
}


void readRecordSheet()
{
    system("cls");
    std::ifstream file("recordsheet.txt");

    bool isEmpty = true;
    // Если файла не существовало - создаем пустой файл
    if (!file)
    {
        std::ofstream file("recordsheet.txt");
        file.close();
    }
    else
    {  
        recordSheet person;
        while (file >> person.firstName >> person.secondName >> person.date >> person.cash)
        {
            std::cout.width(20);
            std::cout << person.firstName + ' ' + person.secondName;
            std::cout.width(13);
            std::cout << person.date;
            std::cout.width(10);
            std::cout << person.cash;
            std::cout << std::endl;
            isEmpty = false;
        }
    }

    if (isEmpty) 
        std::cout << "Recordsheet is empty";

    wait();
}