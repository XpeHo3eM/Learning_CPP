#include "calc.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    calc window (nullptr);
    Ui::calcClass calc;
    calc.setupUi(&window);
    window.lineEdit = calc.lineEdit;
    window.textBrowser = calc.textBrowser;
    window.show();
    return app.exec();
}
