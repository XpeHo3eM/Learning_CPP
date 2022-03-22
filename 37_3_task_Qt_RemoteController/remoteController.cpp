#include <QString>

#include "remoteController.h"



void remoteController::button_1()
{
    currentChannel = 1;
    showParameters();
}



void remoteController::button_2()
{
    currentChannel = 2;
    showParameters();
}



void remoteController::button_3()
{
    currentChannel = 3;
    showParameters();
}



void remoteController::button_4()
{
    currentChannel = 4;
    showParameters();
}



void remoteController::button_5()
{
    currentChannel = 5;
    showParameters();
}


void remoteController::button_6()
{
    currentChannel = 6;
    showParameters();
}


void remoteController::button_7()
{
    currentChannel = 7;
    showParameters();
}


void remoteController::button_8()
{
    currentChannel = 8;
    showParameters();
}


void remoteController::button_9()
{
    currentChannel = 9;
    showParameters();
}


void remoteController::button_0()
{
    currentChannel = 0;
    showParameters();
}


void remoteController::button_volume_inc()
{
    if (currentVolume < 100)
        currentVolume += 10;
    
    showParameters();
}



void remoteController::button_volume_dec()
{
    if (currentVolume > 0)
        currentVolume -= 10;

    showParameters();
}



void remoteController::button_channel_inc()
{
    ++currentChannel;
    if (currentChannel > 9)
        currentChannel = 0;

    showParameters();
}



void remoteController::button_channel_dec()
{
    --currentChannel;
    if (currentChannel < 0)
        currentChannel = 9;

    showParameters();
}



void remoteController::showParameters()
{
    QString str = "Current volume  is " + QString::number(currentVolume) + '\n';
    str        += "Current channel is " + QString::number(currentChannel);
    textBrowser->setText(str);
}
