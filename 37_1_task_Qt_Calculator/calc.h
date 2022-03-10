#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_calc.h"

class calc : public QMainWindow
{
    Q_OBJECT

public:
    calc(QWidget *parent = nullptr);
    QLineEdit *lineEdit = nullptr;
    QTextBrowser *textBrowser = nullptr;

public slots:
    void button_minus();
    void button_plus();
    void button_multiply();
    void button_divide();
    void button_erase_symbol();
    void button_result();
    void button_clear();
    void button_0();
    void button_1();
    void button_2();
    void button_3();
    void button_4();
    void button_5();
    void button_6();
    void button_7();
    void button_8();
    void button_9();

private:
    Ui::calcClass ui;
    QString buf = "";

    bool isEnteredNumber();
    double calculate(double num1, double num2, char action);
};