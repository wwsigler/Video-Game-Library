/*
Walker Sigler
2/15/2022
VideoGame.cpp
prints data to file
*/

#include "VideoGame.h"
#include "Text.h"

VideoGame::VideoGame(Text* title, Text* developer, Text* publisher, int year)
{
	videogameTitle = title;
	videogameDeveloper = developer;
	videogamePublisher = publisher;
	videogameYear = year;
}


VideoGame::~VideoGame()
{
	delete videogameTitle;
	delete videogameDeveloper;
	delete videogamePublisher;
}


void VideoGame::printVideoGameDetails()
{
	cout << endl;
	cout << right << setw(30) << "Game Title:  " << left;
	videogameTitle->displayText();
	cout << endl;
	cout << right << setw(30) << "Developer:  " << left;
    videogameDeveloper->displayText();
    cout << endl;
	cout << right << setw(30) << "Publisher:  " << left;
	videogamePublisher->displayText();
	cout << endl;
	cout << right << setw(30) << "Year Released:  " << left << videogameYear << endl << endl;
}


void VideoGame::printVideoGameDetailsToFile(ofstream & outFile)
{
	char temp[1000];

	strncpy(temp, videogameTitle->getText(), 1000);
	outFile << temp << endl;

	strncpy(temp, videogameDeveloper->getText(), 1000);
	outFile << temp << endl;

	strncpy(temp, videogamePublisher->getText(), 1000);
	outFile << temp << endl;

	outFile << videogameYear << endl;
}


Text* VideoGame::getVideoGameTitle() const
{
	return videogameTitle;
}

