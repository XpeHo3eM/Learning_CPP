#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>


struct SVector
{
    double x = 0;
    double y = 0;
};


// Прооверка на корректный ввод типа double
double enterDouble();

// Приведение к нижнему регистру
void toLower(std::string &str);

// Создание вектора
SVector newVector();

// Сложение векторов
SVector add(SVector vec1, SVector vec2);

// Вычитание векторов
SVector substract(SVector vec1, SVector vec2);

// Умножение вектора на скаляр
SVector scale(SVector vec, double scalar);

// Определение длины вектора
double length(SVector vec);

// Нормализация ветора
SVector normalize(SVector vec);


int main()
{
    const int actionVariables = 5;
    std::string action[actionVariables] = { "add", "substract", "scale", "length", "normalize" };
    
    std::cout << "Enter one of actions below:" << std::endl;
    std::cout << "\t1. Addition vectors (command - \"add\");" << std::endl;;
    std::cout << "\t2. Substraction vectors (command - \"substract\");" << std::endl;
    std::cout << "\t3. Multiplication vector-scalar (command - \"scale\");" << std::endl;
    std::cout << "\t4. Find vector's length (command - \"length\");" << std::endl;
    std::cout << "\t5. Normalize vector (command - \"normalize\")." << std::endl;

    std::string answer;
    bool correct = false;
    do
    {
        std::getline(std::cin, answer);     
        toLower(answer);  
        for (int i = 0; (i < actionVariables) && !correct; ++i)
            if (answer == action[i])
                correct = true;
    }
    while (!correct);

    for (int i = 0; i < actionVariables; ++i)
        if (answer == action[i])
            switch (i)
            {
            case 0:
            {
                std::system("cls");
                std::cout << "~ Enter first term ~" << std::endl;
                SVector vec1 = newVector();
                std::system("cls");
                std::cout << "~ Enter second term ~" << std::endl;
                SVector vec2 = newVector();

                SVector result = add(vec1, vec2);

                std::system("cls");
                std::cout << "~ Vector (" << vec1.x << ", " << vec1.y << ") plus vector (" << vec2.x << ", " << vec2.y << ") ~" << std::endl;
                std::cout << "Result: vector (" << result.x << ", " << result.y << ")" << std::endl << std::endl;
                break;
            }
            case 1: 
            {
                std::system("cls");
                std::cout << "~ Enter minuend term ~" << std::endl;
                SVector vec1 = newVector();
                std::system("cls");
                std::cout << "~ Enter subtrahend term ~" << std::endl;
                SVector vec2 = newVector();

                SVector result = substract(vec1, vec2);

                std::system("cls");
                std::cout << "~ Vector (" << vec1.x << ", " << vec1.y << ") minus vector (" << vec2.x << ", " << vec2.y << ") ~" << std::endl;
                std::cout << "Result: vector (" << result.x << ", " << result.y << ")" << std::endl << std::endl;
                break;
            }
            case 2: 
            {
                std::system("cls");
                std::cout << "~ Enter vector ~" << std::endl;
                SVector vec = newVector();
                std::system("cls");
                std::cout << "~ Enter scalar ~" << std::endl;
                double scalar = enterDouble();

                SVector result = scale(vec, scalar);

                std::system("cls");
                std::cout << "~ Vector (" << vec.x << ", " << vec.y << ") multiply scalar " << scalar << " ~" << std::endl;
                std::cout << "Result: vector (" << result.x << ", " << result.y << ")" << std::endl << std::endl;
                break;
            }
            case 3: 
            {
                std::system("cls");
                std::cout << "~ Enter vector ~" << std::endl;
                SVector vec = newVector();
                std::cout << "~ Vector's (" << vec.x << ", " << vec.y << ") length ~" << std::endl;

                double vecLength = length(vec);

                std::cout << "Result: " << vecLength << std::endl << std::endl;
                break;
            }
            case 4: 
            {
                std::system("cls");
                std::cout << "~ Enter vector ~" << std::endl;
                SVector vec = newVector();

                SVector result = normalize(vec);

                std::system("cls");
                std::cout << "~ Normalize vector (" << vec.x << ", " << vec.y << ") ~" << std::endl;
                std::cout << "Result: vector (" << result.x << ", " << result.y << ")" << std::endl << std::endl;
                break;
            }
            }
}


double enterDouble()
{
    std::string tmp;
    bool err;
    
    do
    {
        err = false;
        bool dot = false;
        std::cin >> tmp;

        for (int i = 0; (i < tmp.length()) && !err; ++i)
            if ((tmp[i] >= '0' && tmp[i] <= '9') || tmp[i] == '.' || tmp[i] == '-')
            {
                if (tmp[i] == '.')
                    (dot ? err = true : dot = true);
                else
                    if (tmp[i] == '-' && i != 0)
                        err = true;
            }
            else
                err = true;

        if (err)
            std::cout << "Incorrect coordinates. Try again" << std::endl;
    } 
    while (err);

    return (std::stod(tmp));
}


void toLower(std::string& str)
{
    for (int i = 0; i < str.length(); ++i)
        str[i] = std::tolower(str[i]);
}


SVector newVector()
{
    SVector vec;

    std::cout << "Enter vector's coordinates X, Y: ";
    vec.x = enterDouble();
    vec.y = enterDouble();

    return vec;
}


SVector add(SVector vec1, SVector vec2)
{   
    SVector result;
    result.x = vec1.x + vec2.x;
    result.y = vec1.y + vec2.y;

    return result;
}


SVector substract(SVector vec1, SVector vec2)
{
    SVector result;
    result.x = vec1.x - vec2.x;
    result.y = vec1.y - vec2.y;

    return result;
}


SVector scale(SVector vec, double scalar)
{
    SVector result;
    result.x = vec.x * scalar;
    result.y = vec.y * scalar;

    return result;
}


double length(SVector vec)
{
    return (std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2)));
}


SVector normalize(SVector vec)
{
    double vecLength = length(vec);
    
    SVector result;
    result.x = vec.x / vecLength;
    result.y = vec.y / vecLength;

    return result;
}