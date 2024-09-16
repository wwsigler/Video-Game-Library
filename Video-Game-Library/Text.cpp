/*
Walker Sigler
2/15/2022
Text.cpp
stores text data efficiently
*/

#include "Text.h"
#include <cstring>
#include <iomanip>
#include <cstring>
using namespace std;

Text::Text(const char* text)
{	
	textLength = strlen(text);

	//dynamic allocation
	char* tempTextArray = new char[(textLength)+1];

	strcpy(tempTextArray, text); 
	this->textArray = tempTextArray;	
}


Text::~Text()
{
	delete [] textArray;
}


void Text::displayText() const
{
	cout << textArray;
}


const char* Text::getText() const
{
	return textArray;
}


int Text::getLength() const
{
	return textLength;
}