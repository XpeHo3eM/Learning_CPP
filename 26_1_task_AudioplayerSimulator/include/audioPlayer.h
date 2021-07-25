#pragma once

#include <string>
#include <map>
#include "track.h"


class AudioPlayer
{
public:
    AudioPlayer ();
    void addTrack ();
    void play (std::string name);
    void pause ();
    void next ();
    void stop ();

private:
    std::map <std::string, Track> tracks;
    std::string lastTrackPlay;
    bool isPlay;
};