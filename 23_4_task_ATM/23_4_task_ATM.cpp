#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>


// Количество купюр в банкомате
const int gCountBill = 1000;

// Путь к файлу банкомата
const char* gPath = "atm.bin";


// Возможные номиналы купюр
enum CashVariables
{
    ONE_HUNDRED = 100,
    TWO_HUNDRED = 200,
    FIVE_HUNDRED = 500,
    ONE_THOUSAND = 1000,
    TWO_THOUSAND = 2000,
    FIVE_THOUSAND = 5000,
    CASH_VARIABLES_COUNT = 6,
    CASH_NOT_ENOUGHT = -1
};


// Ожидание нажатия клавиши для продолжения
void pressKey()
{
    using namespace std;
    cout << endl << "Enter 0 to continue" << endl;
    int action;
    do
        cin >> action;
    while (action != 0);
}


// Генерация случайных купюр
int randomizeBill()
{
    int rnd = rand() % CASH_VARIABLES_COUNT;
    switch (rnd)
    {
    case 0: return ONE_HUNDRED;
    case 1: return TWO_HUNDRED;
    case 2: return FIVE_HUNDRED;
    case 3: return ONE_THOUSAND;
    case 4: return TWO_THOUSAND;
    case 5: return FIVE_THOUSAND;
    }
}


// Пополнение банкомата деньгами
void fillATM()
{
    std::ifstream atmIn(gPath, std::ios::binary);
    int money;
    int count = 0;

    // Считаем количество купюр в банкомате
    while (atmIn.read((char*)&money, sizeof(money)))
        ++count;
    atmIn.close();

    // Пополняем недоставющим количеством купюр
    std::ofstream atmOut(gPath, std::ios::app, std::ios::binary);
    while (count < gCountBill)
    {
        money = randomizeBill();
        atmOut.write((char*)&money, sizeof(money));
        ++count;
    }
    atmOut.close();
}


// Проверка или создание файла atm.txt
void isATMExists()
{
    std::ifstream atm(gPath, std::ios::binary);
    if (!atm.is_open())
    {
        std::ofstream atm(gPath);
        atm.close();
        fillATM();
    }
    atm.close();
}


// Подсчет количества купюр по каждому номиналу
void checkCountBill(int *arr)
{
    std::ifstream atm(gPath, std::ios::binary);

    int money;
    while (atm.read((char*)&money, sizeof(money)))
    {
        switch (money)
        {
        case ONE_HUNDRED:
            ++arr[0];
            break;
        case TWO_HUNDRED:
            ++arr[1];
            break;
        case FIVE_HUNDRED:
            ++arr[2];
            break;
        case ONE_THOUSAND:
            ++arr[3];
            break;
        case TWO_THOUSAND:
            ++arr[4];
            break;
        case FIVE_THOUSAND:
            ++arr[5];
            break;
        }
    }
    atm.close();
}


// Подсчет максимальной суммы для снятия (сколько находится в банкомате)
int totalCash(int *arr)
{
    return  (ONE_HUNDRED * arr[0] + TWO_HUNDRED * arr[1] + FIVE_HUNDRED * arr[2] +
             ONE_THOUSAND * arr[3] + TWO_THOUSAND * arr[4] + FIVE_THOUSAND * arr[5]);
}


// Принятие корректного ввода для снятия средств
int requiredAmount (int maxCash)
{
    int cash;
    do
    {
        system("cls");
        std::cout << "~~ Max sum to withdraw is " << maxCash << " ~~" << std::endl;
        std::cout << "Enter the amount of money to withdraw in multiples of 100: ";
        std::cin >> cash;

        system("cls");
        if ((cash % 100 != 0) || (cash <= 0))
        {
            std::cout << "!! Incorret amount of money. Try again !!" << std::endl << std::endl;
            pressKey();
        }
            
        if (cash > maxCash)
        {
            std::cout << "!! Requested amount of money is more than ATM can issue !!" << std::endl << std::endl;
            return CASH_NOT_ENOUGHT;
        }
    } 
    while ((cash % 100 != 0) || (cash > maxCash) || (cash <= 0));

    return cash;
}


// Определение количества выданных купюр
int isEnoughtBill(int *arr, int i, int& requiredCash, int denomination)
{
    int requiredBill = requiredCash / denomination;
    if (arr[i] >= requiredBill)
    {
        // Забираем необходимое количество купюр
        arr[i] -= requiredBill;
        requiredCash %= denomination;
    }
    else
    {
        requiredCash -= arr[i] * denomination;

        // Запоминаем количество выданных купюр
        requiredBill = arr[i];

        // Выдали все имеющиеся купюры определенного номинала
        arr[i] = 0;
    }

    return requiredBill;
}


// Вывод на печать количества выданных купюр
void withdrawPrint(int count, int denomination)
{
    if (count)
        std::cout << "You received " << denomination << " bills in quantity: " << count << std::endl;
}


// Выдача срадств
void withdraw(int *arr, int arrSize, int requiredCash)
{
    system("cls");
    withdrawPrint(isEnoughtBill(arr, 5, requiredCash, FIVE_THOUSAND), FIVE_THOUSAND);
    withdrawPrint(isEnoughtBill(arr, 4, requiredCash, TWO_THOUSAND), TWO_THOUSAND);
    withdrawPrint(isEnoughtBill(arr, 3, requiredCash, ONE_THOUSAND), ONE_THOUSAND);
    withdrawPrint(isEnoughtBill(arr, 2, requiredCash, FIVE_HUNDRED), FIVE_HUNDRED);
    withdrawPrint(isEnoughtBill(arr, 1, requiredCash, TWO_HUNDRED), TWO_HUNDRED);
    withdrawPrint(isEnoughtBill(arr, 0, requiredCash, ONE_HUNDRED), ONE_HUNDRED);
}


// Удаление из файла выданных купюр
void leftCashATM(int *arr)
{
    const char* pathTemp = "atmTemp.bin";

    // Переносим остатки купюр во временный файл
    std::ofstream atm(pathTemp, std::ios::binary);
    for (int i = 0; i < CASH_VARIABLES_COUNT; ++i)
    {
        int money;
        for (int j = 0; j < arr[i]; ++j)
        {
            switch (i)
            {
            case 0: 
                money = ONE_HUNDRED; 
                break;
            case 1:
                money = TWO_HUNDRED;
                break;
            case 2:
                money = FIVE_HUNDRED;
                break;
            case 3:
                money = ONE_THOUSAND;
                break;
            case 4:
                money = TWO_THOUSAND;
                break;
            case 5:
                money = FIVE_THOUSAND;
                break;
            }
            atm.write((char*)&money, sizeof(money));
        }
    }
    atm.close();

    // Удаляем старый файл банкомата
    remove(gPath);

    // Переименовываем наш временный файл после выдачи средств
    rename(pathTemp, gPath);
}



int main()
{
    std::srand(std::time(nullptr));

    bool exit = false;
    while (!exit)
    {
        char action;
        do
        {
            system("cls");
            std::cout << "~~ Welcome to ATM ~~" << std::endl;
            std::cout << "Choose your action:" << std::endl;
            std::cout << "Press '-' to withdraw" << std::endl;
            std::cout << "Press '+' to fill ATM" << std::endl;
            std::cout << "Press '0' to exit" << std::endl;

            std::cin >> action;
        } while (action != '-' && action != '+' && action != '0');

        isATMExists();

        // Количество купюр по номиналам 100, 200, 500, 1000, 2000, 5000
        int countBill[] = { 0, 0, 0, 0, 0, 0 };
        int countBillSize = sizeof(countBill) / sizeof(countBill[0]);

        int cash, maxCash;
        switch (action)
        {
        case '+':
            fillATM();
           
            system("cls");
            std::cout << "~~ ATM was filled ~~" << std::endl; 
            
            pressKey();
            break;
        case '-':
            checkCountBill(countBill);

            maxCash = totalCash(countBill);
            cash = requiredAmount(maxCash);
            if (cash != CASH_NOT_ENOUGHT)
            {
                withdraw(countBill, countBillSize, cash);
                leftCashATM(countBill);
            }

            pressKey();
            break;
        case '0':
            exit = true;
            break;
        }
    }
}