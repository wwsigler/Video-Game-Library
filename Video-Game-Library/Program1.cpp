/*
Walker Sigler
2/15/2022
Program1.cpp
This program keeps tracks of a library of video games. It allows a user to load a list of
video game data from a file, save video game data to a file, add a video game, remove a video game,
display all video games in the library, and remove all video games.
*/

#include "VideoGameLibrary.h"
#include "VideoGame.h"
#include "Text.h"
#include <iostream>
using namespace std;

int main()
{
	int userInput;
	int maxGames;
	char filename[25];
	
	cout << "\n\nHow many video games can your library hold?" << endl;
	cin >> maxGames;
	while(maxGames <= 0)
	{
		cout << "\n\nYou have to have at least one game in your library." << endl;
		cout << "How many video games can your library hold?" << endl;
		cin >> maxGames;
	}
	VideoGameLibrary* videogameLibrary = new VideoGameLibrary(maxGames);
	
	do
	{
		cout << "What would you like to do?" << endl;
		cout << "1.  Load video games from file." << endl;
		cout << "2.  Save video games to a file." << endl;
		cout << "3.  Add a video game." << endl;
		cout << "4.  Remove a video game." << endl;
		cout << "5.  Display all video games." << endl;
		cout << "6.  Remove ALL video games from this library and end program." << endl;
		cout << "CHOOSE 1-6:  ";

		//validates use input
		cin >> userInput;
		while(userInput <=0 || userInput > 6)
		{
			cout << "That is not a valid choice.\n";
			cout << "CHOOSE 1-6:  ";
			cin >> userInput;
		}
		
		switch(userInput)
		{
			case 1:	cout << "\nWhat is the name of the file? (example.txt):  ";
					cin >> filename;
					videogameLibrary->loadVideoGamesFromFile(filename);
					break;
					
			case 2: cout << "\nWhat do you want to name the file? (example.txt):  ";
					cin >> filename;
					videogameLibrary->saveToFile(filename); 
					break;
					
			case 3: videogameLibrary->addVideoGameToArray();
					break;
					
				
			case 4:	videogameLibrary->removeVideoGameFromArray();
					break;
					
			
			case 5: videogameLibrary->displayVideoGames();
					break;
					
			case 6: delete videogameLibrary;
					break;
					
		}
		
	}while(userInput != 6);
	
	cout << endl << "\nGOODBYE!";
	
	return 0;
}
