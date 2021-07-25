#include <iostream>
#include "audioPlayer.h"
#include "commands.h"


int main()
{
	AudioPlayer myAudioPlayer;
	bool exit = false;
	std::string name;

	do
	{
		int command = chosenCommand ();

		switch (command)
		{
		case 0 : 
			std::cout << "Enter track's name: ";
			std::getline (std::cin, name);
			myAudioPlayer.play (name);
			break;
		case 1 :
			myAudioPlayer.pause ();
			break;
		case 2 : 
			myAudioPlayer.stop ();
			break;
		case 3 :
			myAudioPlayer.next ();
			break;
		case 4 :
			myAudioPlayer.addTrack ();
			break;
		case 5 :
			exit = true;
			break;
		default:
			std::cout << "! Incorrect command. Try again !";
			break;
		}
	}
	while (!exit);	
}
