/*
Walker Sigler
2/15/2022
VideoGameLibrary.cpp
deals with storing/editing video game data
*/

#include "VideoGameLibrary.h"
#include "VideoGame.h"

void VideoGameLibrary::resizeVideoGameArray()
{
	int max = maxGames * 2;
	cout << "\nResizing videogamesArray from " << maxGames << " to " << max << ".";
	
	VideoGame ** newVideoGamesArray = new VideoGame*[max];
	for(int x = 0; x < numGames; x++)
	{
		newVideoGamesArray[x] = videogamesArray[x];
	}
	delete [] videogamesArray;
	videogamesArray = newVideoGamesArray;
	maxGames = max;
}


VideoGameLibrary::VideoGameLibrary(int max)
{
	maxGames = max;
	numGames = 0;
	
	//dynamically allocated array
	videogamesArray = new VideoGame*[max];
}


VideoGameLibrary::~VideoGameLibrary()
{
	for(int x=0; x<numGames; x++)
	{
		delete videogamesArray[x];
	}
	delete [] videogamesArray;
}


//adds game to array 
void VideoGameLibrary::addVideoGameToArray() 
{
	Text* title;
	Text* developer;
	Text* publisher;
	int year;
	char arr[100];
	
	cin.ignore();
	cout << "\nVideo Game TITLE: ";
	cin.getline(arr, 100);
	title = new Text(arr);
	cout << "\nVideo Game DEVELOPER: ";
	cin.getline(arr, 100);
	developer = new Text(arr);
	cout << "\nVideo Game PUBLISHER: ";
	cin.getline(arr, 100);
	publisher = new Text(arr);
	cout << "\nVideo Game YEAR: ";
	cin >> year;
	cin.ignore();
	cout << endl << endl;
	
	//makes the game
	VideoGame* oneGame = new VideoGame(title, developer, publisher, year);
	
	//adds game to the library
	if(numGames == maxGames)
		resizeVideoGameArray();

	videogamesArray[numGames] = oneGame;
	(numGames)++;
}


void VideoGameLibrary::displayVideoGames()
{
	if(numGames >= 1)
	{
		for(int i=0; i < numGames; i++)
		{
			cout << endl << right << setw(50) << "----------VIDEO GAME " << (i+1) << "----------";
			videogamesArray[i]->printVideoGameDetails();
		}
	}
	else	
		cout << "\nThere are no video games in your library yet." << endl;
}


void VideoGameLibrary::displayVideoGameTitles()
{
	Text* videogameTitle;
	
	for(int i = 0; i < numGames; i++)
	{
		cout << "\nVIDEO GAME " << (i+1) << ": ";
		videogameTitle = videogamesArray[i]->getVideoGameTitle();
		videogameTitle->displayText();
	}
}


void VideoGameLibrary::loadVideoGamesFromFile(char * filename)
{
	ifstream inFile;
	VideoGame* oneGame;
	Text* title;
	Text* developer;
	Text* publisher;
	int year;
	int gamesFromFile = 0;
	char arr[100];

	
	inFile.open(filename);
	if(inFile.good())
	{
		inFile.getline(arr, 100);
		while(!inFile.eof()) //stops looping at end of file
		{	
			title = new Text(arr);

			inFile.getline(arr, 100);
			developer = new Text(arr);

			inFile.getline(arr, 100);
			publisher = new Text(arr);

			inFile >> year;
			inFile.ignore();
			
			oneGame = new VideoGame(title, developer, publisher, year);
			
			if(numGames == maxGames)
			{
				resizeVideoGameArray();
			}

			videogamesArray[numGames] = oneGame;
			numGames++;
			
			//tells user game was added
			cout << endl;
			title->displayText();
			cout << " was added to the video game library!";
			inFile.getline(arr, 100);
			
			gamesFromFile++;
		}
		
		cout << endl << gamesFromFile << " video games were read from the file and added to your library.\n" << endl;
	}
	else
	{
		cout << "Failed to open file." << endl;
	}
}


void VideoGameLibrary::removeVideoGameFromArray()
{
	int videogameChoice;
	int videogameDelete = videogameChoice - 1;
	Text* videogameTitle;
	
	if(numGames <= 1)
	{
	   cout << endl << "There must always be at least one video game in your library.  You can't";
	   cout << " remove any games right now or you will have no video games in your library." << endl;
	}
	else
	{
		cout << "\n\nChoose from the following video games to remove:" << endl;

		displayVideoGameTitles();

		cout << "\nChoose a video game to remove between 1 & " << numGames << ":  ";
		cin >> videogameChoice;
		
		while(videogameChoice <= 0 || videogameChoice > numGames)
		{
			cout << "\nOops!  You must enter a number between 1 & " << numGames << ":  ";
			cin >> videogameChoice;
		}

	videogameTitle = videogamesArray[videogameDelete]->getVideoGameTitle();
		
	cout << "\n\nThe video game ";
	videogameTitle->displayText();
	cout << " has been successfully deleted." << endl;	
	
	int minusElement = (numGames) - 1;

	delete videogamesArray[videogameDelete];
		
	for(int i = videogameDelete; i < minusElement; i++)
	{
		videogamesArray[i] = videogamesArray[i+1];
	}
		
	videogamesArray[minusElement] = NULL;
		
	(numGames)--;
		
	}
}


void VideoGameLibrary::saveToFile(char *filename)
{
	ofstream outFile;
	outFile.open(filename);
	
	for(int i=0; i<numGames; i++)
	{
		videogamesArray[i]->printVideoGameDetailsToFile(outFile);
	}

	outFile.close();
	
	cout << "\n\nAll video games in your library have been printed to " << filename << endl;
}



