#include <QtWidgets/QApplication>

#include "calc.h"
#include "ui_calc.h"



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    calc window (nullptr);
    Ui::calcClass calc;
    calc.setupUi(&window);
    window.lineEdit    = calc.lineEdit;
    window.textBrowser = calc.textBrowser;
    window.show();
    return app.exec();
}