import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15


Window
{
    minimumHeight: 150
    minimumWidth:  250
    maximumHeight: 150
    maximumWidth:  250
    visible:       true
    title:         qsTr("37_2_task_Qt_QML_Mediaplayer")


    Rectangle
    {
        anchors.horizontalCenter: parent.horizontalCenter

        Text
        {
            id:             mainMenu
            width:          parent.width
            height:         50
            font.pointSize: 20
            font.bold:      true
            text:           "0"
        }
    }


    Button
    {
        id:                     rewind
        width:                  50
        height:                 50
        anchors.verticalCenter: parent.verticalCenter
        anchors.right:          playPause.left
        anchors.rightMargin:    5

        Image
        {
            anchors.centerIn: parent
            width:            parent.width - 20
            height:           parent.height - 20
            source:           "icons/rewind.png"
        }

        onPressed:
        {
            playTimer.stop()
            playTimer.changeParam(250, -1)
            playTimer.start()
            playPauseIcon.updateStatus(false)
        }
    }


    Button
    {
        property bool played:   false
        id:                     playPause
        width:                  50
        height:                 50
        anchors.verticalCenter: parent.verticalCenter
        anchors.right:          stop.left
        anchors.rightMargin:    5

        Image
        {
            id:               playPauseIcon
            anchors.centerIn: parent
            width:            parent.width - 20
            height:           parent.height - 20
            source:           "icons/play.png"

            function updateStatus(isPlay)
            {
                playPause.played = isPlay
                source = playPause.played ? "icons/pause.png" : "icons/play.png"
            }
        }

        onClicked:
        {
            playPauseIcon.updateStatus(!played)

            if (played)
            {
                playTimer.changeParam(1000, 1)
                playTimer.start()
            }
            else
                playTimer.stop()
        }
    }


    Button
    {
        id:                     stop
        width:                  50
        height:                 50
        anchors.verticalCenter: parent.verticalCenter
        anchors.left:           parent.horizontalCenter

        Image
        {
            anchors.centerIn: parent
            width:            parent.width - 20
            height:           parent.height - 20
            source:           "icons/stop.png"
        }

        onClicked:
        {
            playPauseIcon.updateStatus(false)
            playTimer.stop()
            progress.value = 0
            mainMenu.text  = 0
        }
    }


    Button
    {
        id:                     forward
        width:                  50
        height:                 50
        anchors.verticalCenter: parent.verticalCenter
        anchors.left:           stop.right
        anchors.leftMargin:     5

        Image
        {
            anchors.centerIn: parent
            width:            parent.width - 20
            height:           parent.height - 20
            source:           "icons/forward.png"
        }

        onPressed:
        {
            playTimer.stop()
            playTimer.changeParam(250, 1)
            playTimer.start()
            playPauseIcon.updateStatus(false)
        }
    }


    ProgressBar
    {
        id:                progress
        anchors.top:       stop.bottom
        anchors.topMargin: 10
        anchors.left:      rewind.left
        anchors.right:     forward.right
        height:            10
        width:             parent.width
        from:              0
        to:                100
        value:             0

        function changeProgress(delta)
        {
            value = value + delta
            mainMenu.text = value.toString()

            if (value == 0)
                playPauseIcon.updateStatus(false)
        }

        Timer
        {
            id:                 playTimer
            repeat:             true
            running:            false
            property int delta: 1

            function changeParam (newInterval, newDelta)
            {
                interval = newInterval
                delta    = newDelta
            }

            onTriggered:
            {
                progress.changeProgress(delta)
            }
        }
    }
}
