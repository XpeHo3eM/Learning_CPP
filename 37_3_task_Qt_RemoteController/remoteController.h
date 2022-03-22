#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextBrowser>


class remoteController : public QMainWindow
{
    Q_OBJECT

public:
    remoteController(QWidget *parent = nullptr) : QMainWindow(parent) {};
    QTextBrowser *textBrowser = nullptr;

public slots:
    void button_1 ();
    void button_2 ();
    void button_3 ();
    void button_4 ();
    void button_5 ();
    void button_6 ();
    void button_7 ();
    void button_8 ();
    void button_9 ();
    void button_0 ();
    void button_volume_inc ();
    void button_volume_dec ();
    void button_channel_inc (); 
    void button_channel_dec ();

    void showParameters();

private:
    int currentVolume  = 0;
    int currentChannel = 0;
};