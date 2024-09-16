/*
Walker Sigler
2/15/2022
VideoGame.h
Header file for VideoGame.cpp
*/

#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include "Text.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;

class VideoGame
{
	private: 
		Text* videogameTitle;  
		Text* videogameDeveloper;
		Text* videogamePublisher;
        int videogameYear; 
		
	public:
		/*
			Function name:  VideoGame constructor
			Parameters:  
			1. A pointer to a Text variable, containing the title of the video game
			2. A pointer to a Text variable, containing the developer of the video game
			3. A pointer to a Text variable, containing the publisher of the video game
			4. An integer containing the year the video game was released 
			Purpose:  This function should be called when all video game information is
			known and it will create a new video game with this information.
		*/
		VideoGame(Text*, Text*, Text*, int); 

		
		/*
			Purpose: This function is automatically called when a Video game object is
			destroyed. This function releases the dynamically allocated text arrays in the Video game.
		*/
		~VideoGame();
		

		/*
			Function name:  printVideoGameDetails 
			Parameters:  none
			Returns: none (void)
			Purpose:  This function should be called when the user wants to print ALL the video game information to the screen.
		*/
		void printVideoGameDetails();

		
		/*
			Function name:  printVideoGameDetailsToFile 
			Parameters:  a file stream object (sent by reference)
			Returns: none (void)
			Purpose:  This function should be called when the user wants to print ALL the video game information to the file.
		*/
		void printVideoGameDetailsToFile(ofstream &outFile);

		
		/*
			Function name: getVideoGameTitle (accessor function)
			Parameters: none
			Returns: a pointer to the Text object containing the video game title
		*/
		Text* getVideoGameTitle() const;
};

#endif