/*
Walker Sigler
2/15/2022
VideoGameLibrary.h
Header file for VideoGameLibrary.cpp
*/

#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H
#include "VideoGame.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class VideoGameLibrary
{
	private:
		VideoGame** videogamesArray; 
		int maxGames; 
		int numGames; 
		
		/*
			Function name:  resizeVideoGameArray 
			Parameters:  none
			Returns:  none (void)
			Purpose:  This function is called by addVideoGameToArray when the array size
			is not big enough to hold a new video game that needs to be added.  The function
			makes the array twice as big as it currently is and then moves all the video 
			game pointers to this new array.
		*/
		void resizeVideoGameArray();
		
	public:
		/*
			Function name:  VideoGameLibrary constructor 
			Parameters:  An integer containing the maximum size of the video game library 
			Purpose:  This function is automatically called when a VideoGameLibrary object
			is created and it creates a library of video games.  
		*/
		VideoGameLibrary(int);
		
	
		/*
			Function name:  ~VideoGameLibrary destructor 
			Purpose:  This function is automatically called when the VideoGame object is destroyed.
			This releases the dynamically created individual video games and then deletes the array.
		*/
		~VideoGameLibrary();
		
		
		/*
			Function name:  addVideoGameToArray 
			Parameters:  none
			Returns:  none (void)
			Purpose:  This function should be called when you need to add a single
			video game to the video game library.  
		*/
		void addVideoGameToArray();  

		
		/*
			Function name:  displayVideoGames 
			Parameters:  none
			Returns:   none (void)
			Purpose:  This function should be called when the user wants to
			have all the video games in the library printed to the screen.  
		*/
		void displayVideoGames();

		
		/*
			Function name:  displayVideoGameTitles 
			Parameters:  none 
			Returns:   none (void)
			Purpose:  This function should be called when you want to print only the video
			game titles out of the video game library (when a user wants to remove a video game from library).  
		*/
		void displayVideoGameTitles();

		
		/*
			Function name:  loadVideoGamesFromFile 
			Parameters:  A pointer to a character (c-string or string literal argument) containing the filename
			Returns:   none (void)
			Purpose:  This function should be called when the user wants to read video game data from a file and add the video games to the video game library.  The file must have data in the following order: title, developer, publisher, year.  
		*/
		void loadVideoGamesFromFile(char* filename);
		
		
		/*
			Function name:  removeVideoGameFromArray 
			Parameters:  none
			Returns: none (void)
			Purpose:  This function should be called when the user wants to remove one single video game from the video game library.  The video game to be removed must is identified by the user and then removed.
		*/
		void removeVideoGameFromArray();
		
		
		/*
			Function name:  saveToFile 
			Parameters:  A pointer to a character (c-string or string literal argument) containing the filename
			Returns:  none (void)
			Purpose:   This function should be called when the user wants to print all the video game data from the video game library to a file.  The data is printed in the following order (one piece of data per line):  title, developer, publisher, year.
		*/
		void saveToFile(char *filename);
};

#endif