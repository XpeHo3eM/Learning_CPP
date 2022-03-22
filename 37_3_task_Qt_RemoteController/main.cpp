#include <QtWidgets/QApplication>

#include "remoteController.h"
#include "ui_remoteController.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    remoteController window(nullptr);
    Ui::remoteController controller;
    controller.setupUi(&window);
    window.textBrowser = controller.textBrowser;
    window.show();

    app.exec();
}
