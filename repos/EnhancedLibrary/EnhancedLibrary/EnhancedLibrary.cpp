// Ryan Routhier
// EnhancedLibrary.cpp
// 07/17/2019
//This program takes in a books text file that lists the books that belong to Nancy's library. The user can search throught these books from an easy to use menu system that can display all the book information
//or just the titles. The user can also check out a book as well as return a book.

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include "BookClass.h"

using namespace std;

//const to limit books for program space
const int MAX_BOOKS_MAIN = 100;


int main()
{

	BookClass bookLibrary[MAX_BOOKS_MAIN];
	int counter = 0, totalBooks = 0, findBook = 0, choice = 0;
	bool loopBreak = false;;

	//calls the function to read the text file of books into an array 
	getBooks(bookLibrary, counter);
	//set's the counter to total books
	totalBooks = counter;

	//while loop to run the menu
	while (loopBreak != true)
	{
		//calls the menu and returns the choice
		choice = getMenuChoice();
		switch (choice)
		{
			//calls function to show all book information
		case 1: showBooks(bookLibrary, totalBooks);
			break;
			//calls function to show just titles
		case 2: showTitles(bookLibrary, totalBooks);
			break;
			//calls function to allow to search for a title
		case 3: findTitles(bookLibrary, totalBooks, findBook);

			//if book was found it will return the proper result
			if (findBook >= 0)
			{
				cout << bookLibrary[findBook].numInStock << " copies of " << bookLibrary[findBook].title << " are left in stock\n";
			}
			else 
			{
				cout << "Sorry we do not match that book\n";
			}
			break;
			//calls function to allow user to check out a book
		case 4: checkOutBook(bookLibrary, totalBooks, findBook);
			break;
			//calls function to allow user to return a book
		case 5: returnBook(bookLibrary, totalBooks, findBook);
			break;
			//makes loopBreak true which will end the main while loop
		case 6: loopBreak = true;
			break;
		default:
			break;
		}
	}
	//ends the program
	return 0;

}
