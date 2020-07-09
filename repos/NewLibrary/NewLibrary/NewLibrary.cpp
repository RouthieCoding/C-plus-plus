// NewLibrary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include "BookClass.cpp"
const int MAX_BOOKS_MAIN = 100;
using namespace std;

//Menu to give user options
int getMenuChoice()
{
	int menuChoice = 0;

	cout << "\nNancy's Library\n"
		<< "\nPlease select from the menu below \n\n"
		<< "1: Display all books\n"
		<< "2: Display book titles\n"
		<< "3: Find book\n"
		<< "4: Check out\n"
		<< "5: Check in\n"
		<< "6: Exit program\n\n"
		<< "Enter your choice: ";
	cin >> menuChoice;
	return menuChoice;
	cout << endl;

}

BookClass::showBooks(BookClass library[], int totalBooks)
{
	for (int i = 0; i < totalBooks - 1; i++)
	{
		library[i].displayBookInfo();
	}
}
int main()
{
  cout << "Hello World!\n"; 
  BookClass bookLibrary[MAX_BOOKS_MAIN];
  int counter = 0, totalBooks = 0, findBook = 0, choice = 0;
  bool loopBreak = false;;

  //calls the function to read the text file of books into an array 
  BookClass::getBooks(bookLibrary, counter);
  //set's the counter to total books
  totalBooks = counter;

}

