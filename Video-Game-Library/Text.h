/*
Walker Sigler
2/15/2022
Text.h
Header File for Text.cpp
*/

#ifndef TEXT_H
#define TEXT_H
#include <iostream>
using namespace std;

class Text
{
	private:
		const char* textArray;
		int textLength;
	public:
		
		/*
			Function Name:  Text (constructor)
			Parameters:  Send a pointer to a constant character array or a string literal to this function
			Purpose:  called automatically when Text object is created, dynamically allocates a character array which
			contains the character array passed to the function.
		*/
		Text(const char*);


		/*
			Function Name:  ~Text (destructor)
			Purpose: release dynamically allocated memory for the c-string in the Text object 
		*/
		~Text();
		

		/*
			Function Name:  displayText
			Parameters:  none
			Returns:  none (void)
			Purpose: print the c-string (textArray) to the screen. (c++ will let you just cout a char array)
		*/
		void displayText() const;	
		

		/*
			Function Name:  getText() (accessor function)
			Parameters:  none
			Returns:  pointer to a constant character array
		*/
		const char* getText() const;


		/*
			Function Name:  getLength() (accessor function)
			Parameters:  none
			Returns:  the length of the string 
		*/
		int getLength() const;
};

#endif