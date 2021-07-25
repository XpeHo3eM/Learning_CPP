#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include "audioPlayer.h"
#include "clear.h"


AudioPlayer::AudioPlayer ()
{
    isPlay = false;
}


void AudioPlayer::addTrack ()
{
    clear ();
    
    Track newTrack;

    std::string name;
    newTrack.getName (name);

    clear ();
    if (tracks.find (name) == tracks.end ())
    {
        tracks.insert (std::pair <std::string, Track> (name, newTrack));
        std::cout << "~ " << name << " was added ~" << std::endl << std::endl;
    }
    else
        std::cout << "! " << name << " already exist !" << std::endl << std::endl;
}


void AudioPlayer::play (std::string name)
{
    clear ();

    if (!isPlay)
    {
        std::map <std::string, Track>::iterator itf = tracks.find (name);
        if (itf != tracks.end ())
        {
            std::string trackName;
            Date trackCreatedTime;
            int trackDuration;
            itf->second.getName        (trackName);
            itf->second.getCreatedTime (trackCreatedTime);
            itf->second.getDuration    (trackDuration);
            
            std::string datePrint;
            trackCreatedTime.getDateToPrint (datePrint);
            std::cout << "~ Track play ~" << std::endl;
            std::cout << "  name:     "   << trackName     << std::endl;
            std::cout << "  date:     "   << datePrint     << std::endl;
            std::cout << "  duration: "   << trackDuration << " sec" << std::endl << std::endl;

            lastTrackPlay = trackName;
            isPlay = true;
        }
        else
            std::cout << "! " << name << " not found !" << std::endl << std::endl;
    }
    else
        std::cout << "! " << lastTrackPlay << " is playing. Press stop or pause !" << std::endl << std::endl;
}


void AudioPlayer::pause ()
{
    clear ();

    if (isPlay)
    {
        std::cout << "~ " << lastTrackPlay << " paused ~" << std::endl << std::endl;
        isPlay = false;
    }
    else
        std::cout << "! No track is playing !" << std::endl << std::endl;
}
    

void AudioPlayer::next ()
{
    clear ();

    if (tracks.begin () != tracks.end ())
    {
        std::srand (std::time (nullptr));
        uint16_t randNo = std::rand () % (tracks.size ());
        std::map <std::string, Track>::iterator itn = std::next (tracks.begin (), randNo);
        std::string randTrack = itn->first;
        play (randTrack);
    }
    else
        std::cout << "! There is no tracks !" << std::endl << std::endl;
}

    
void AudioPlayer::stop ()
{
    clear ();

    if (isPlay)
    {
        std::cout << "~ " << lastTrackPlay << " was stopped ~" << std::endl << std::endl;
        isPlay = false;
    }
    else
        std::cout << "! No track is playing !" << std::endl << std::endl;
}