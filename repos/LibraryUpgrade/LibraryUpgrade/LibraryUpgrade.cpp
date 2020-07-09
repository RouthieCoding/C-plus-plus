// Ryan Routhier
// EnhancedLibrary.cpp
// 07/17/2019
//This program takes in a books text file that lists the books that belong to Nancy's library. The user can search throught these books from an easy to use menu system that can display all the book information
//or just the titles. The user can also check out a book as well as return a book.

#include <iostream>
#include <string>
#include <fstream>
#include "BookClass.h"

using namespace std;
//to load data from a file into the BookClass class
void getBooks(BookClass bookHolder[], int& counter)
{
	ifstream bookFile;
	string bookTitle, authorName, bookPublisher, bookISBN, extra;
	double bookPrice = 1;
	int bookYear = 2001, booksInStock = 0;
	//opens book text
	bookFile.open("books.txt");
	//loop to run until the book file is empty
	while (bookFile)
	{
		//gets the book information into local variables
		getline(bookFile, bookTitle);
		getline(bookFile, authorName);
		getline(bookFile, bookPublisher);
		getline(bookFile, bookISBN);
		bookFile >> bookPrice;
		bookFile >> bookYear;
		bookFile >> booksInStock;
	
		//stores book information in a BookClass array
		bookHolder[counter].storeBook(bookTitle, authorName, bookPublisher, bookISBN, bookPrice, bookYear, booksInStock);
		//counter to count the array up for new books
		counter++;
	}
}

//To load the main menu for the program
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

//function to show user all the books and information
void showBooks(BookClass library[], int totalBooks)
{
	for (int i = 0; i < totalBooks - 1; i++)
	{
		library[i].displayBookInfo(library[i]);
	}
}
//function to show user all book titles
void showTitles(BookClass library[], int totalBooks)
{
	cout << "The Book Titles\n\n";

	for (int i = 0; i < totalBooks - 1; i++)
	{
		cout << library[i].getTitle() << endl;
	}
}
//functions to let user look for a specific book
void findTitles(BookClass library[], int totalBooks, int& findBooks)
{
	int bookCounter = 0, holder;
	string temp = " ";
	bool found = false;

	//ignore was needed to cancel out a \n
	cin.ignore();
	cout << "Enter Book Title: ";
	getline(cin, temp);
	//loop searches for book
	for (int i = 0; i < totalBooks; i++)
	{
		if (temp == library[i].getTitle())
		{
			findBooks = bookCounter;
			found = true;
		}
		bookCounter++;
	}
	holder = findBooks;
	//if book isn't found set's findbooks to -1
	if (found != true)
	{
		findBooks = -1;
	}

}

//function to let user return a book if they have the book
void returnBook(BookClass library[], int totalBooks, int findBooks)
{
	findTitles(library, totalBooks, findBooks);
	if (findBooks >= 0)
	{
		library[findBooks].setNumInStock(library[findBooks].getNumInStock() + 1);
		cout << library[findBooks].getTitle() << " returned. We now have " << library[findBooks].getNumInStock() << " copies in stock\n";
	}
	else if (findBooks == -1)
	{
		cout << "Sorry we do not match that book\n";
	}


}

int main()
{
	BookClass Books[MAX_BOOKS];
	int counter = 0, totalBooks = 0, findBook = 0, choice = 0;
	bool loopBreak = false;

	getBooks(Books, counter);
	//set's the counter to total books
	totalBooks = counter;
	while (loopBreak != true)
	{
		//calls the menu and returns the choice
		choice = getMenuChoice();
		switch (choice)
		{
			//calls function to show all book information
		case 1: showBooks(Books, totalBooks);
			break;
			//calls function to show just titles
		case 2: showTitles(Books, totalBooks);
			break;
			//calls function to allow to search for a title
		case 3: findTitles(Books, totalBooks, findBook);

			//if book was found it will return the proper result
			if (findBook >= 0)
			{
				cout << Books[findBook].getNumInStock() << " copies of " << Books[findBook].getTitle() << " are left in stock\n";
			}
			else
			{
				cout << "Sorry we do not match that book\n";
			}
			break;
			//calls function to allow user to check out a book
		case 4: 
			findTitles(Books, totalBooks, findBook);
			if (findBook >= 0)
			{
				Books[findBook].setNumInStock(Books[findBook].getNumInStock() - 1);
				cout << Books[findBook].getTitle() << " checked-out. We now have " << Books[findBook].getNumInStock() << " copies in stock\n";
			}
			else if (findBook == -1)
			{
				cout << "Sorry we do not match that book\n";
			}
			else if (findBook == 0)
			{
				cout << "Sorry we are out of copies\n";
			}
			Books[findBook].checkOutBook(Books[findBook]);
			break;
			//calls function to allow user to return a book
		case 5:
			findTitles(Books, totalBooks, findBook);
			if (findBook >= 0)
			{
				Books[findBook].setNumInStock(Books[findBook].getNumInStock() + 1);
				cout << Books[findBook].getTitle() << " returned. We now have " << Books[findBook].getNumInStock() << " copies in stock\n";
			}
			else if (findBook == -1)
			{
				cout << "Sorry we do not match that book\n";
			}
			Books[findBook].returnBook(Books[findBook]);
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