#include <vector>
#include <sstream>

#include "calc.h"



void calc::button_minus()
{
    if (isEnteredNumber())
    {
        buf += lineEdit->text() + '-';
        textBrowser->setText(buf);
        lineEdit->clear();
    }    
}


void calc::button_plus()
{
    if (isEnteredNumber())
    {
        buf += lineEdit->text() + '+';
        textBrowser->setText(buf);
        lineEdit->clear();
    }
}



void calc::button_multiply()
{
    if (isEnteredNumber())
    {
        buf += lineEdit->text() + '*';
        textBrowser->setText(buf);
        lineEdit->clear();
    }
}



void calc::button_divide()
{
    if (isEnteredNumber())
    {
        buf += lineEdit->text() + '/';
        textBrowser->setText(buf);
        lineEdit->clear();
    }
}



void calc::button_erase_symbol()
{
    QString tmp = lineEdit->text();
    tmp.chop(1);
    lineEdit->setText(tmp);
}



void calc::button_result()
{
    if (isEnteredNumber())
    {
        buf += lineEdit->text() + '=';
        textBrowser->setText(buf);

        std::vector <char>   operators;
        std::vector <double> numbers;
        
        auto parsing = [&]()
        {
            std::stringstream data;
            data << buf.toStdString();
            double num;
            char   op;
            while (data >> num >> op)
            {
                operators.push_back(op);
                numbers.push_back(num);
            }
        };    

        
        auto calc = [&](const std::string action)
        {
            auto itf = std::begin(operators);
            while (itf != std::end(operators))
            {
                itf = std::find_if(itf, std::end(operators), [&action](char ch)
                { 
                    for (const auto &op : action)
                        if (ch == op) return true;

                    return false;
                });
                
                if (itf != std::end(operators))
                {
                    auto opPos = itf - std::begin(operators);
                    double res = calculate(numbers[opPos], numbers[opPos + 1], operators[opPos]);
                    numbers[opPos] = res;
                    numbers.erase(std::begin(numbers) + opPos + 1);
                    operators.erase(itf);
                    itf = std::begin(operators);
                }
            }
        };
        
        parsing();
        try
        {
            calc("*/");
            calc("+-");

            textBrowser->setText(buf + QString::number(numbers[0]));
            buf = "";
            lineEdit->setText("");
        }
        catch (...)
        {
            textBrowser->setText("Divide by zero");
        }    
    }    
}



void calc::button_clear()
{
    textBrowser->clear();
    lineEdit->clear();
    buf = "";
}



double calc::calculate(double num1, double num2, char action)
{
    switch (action)
    {
    case '+': return (num1 + num2);
    case '-': return (num1 - num2);
    case '*': return (num1 * num2);
    case '/': 
        if (num2 != 0) return (num1 / num2);
        else
        {
            buf = "";
            lineEdit->setText("");
            throw std::overflow_error("Divide by zero");
        };
    }

    return 0;
}



void calc::button_0()
{
    lineEdit->setText(lineEdit->text() + "0");
}



void calc::button_1()
{
    lineEdit->setText(lineEdit->text() + "1");
}



void calc::button_2()
{
    lineEdit->setText(lineEdit->text() + "2");
}



void calc::button_3()
{
    lineEdit->setText(lineEdit->text() + "3");
}



void calc::button_4()
{
    lineEdit->setText(lineEdit->text() + "4");
}



void calc::button_5()
{
    lineEdit->setText(lineEdit->text() + "5");
}



void calc::button_6()
{
    lineEdit->setText(lineEdit->text() + "6");
}



void calc::button_7()
{
    lineEdit->setText(lineEdit->text() + "7");
}



void calc::button_8()
{
    lineEdit->setText(lineEdit->text() + "8");
}



void calc::button_9()
{
    lineEdit->setText(lineEdit->text() + "9");
}



bool calc::isEnteredNumber()
{
    return (lineEdit->text() != "");
}