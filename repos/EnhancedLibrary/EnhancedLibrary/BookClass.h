#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include "BookClass.h"

using namespace std;

//const to limit books for program space
const int MAX_BOOKS = 100;

//creats a book class used to define what a book is 
class BookClass
{
	//makes data public so other functions can access it
public:
	string title, author, publisher, isbn;
	double price;
	int year, numInStock, counter = 0;

	//functions to store books information  
	void storeBook(string bookTitle, string authorName, string bookPublisher, string bookISBN, double bookPrice, int bookYear, int booksInStock)

	{
		title = bookTitle;
		author = authorName;
		publisher = bookPublisher;
		isbn = bookISBN;
		price = bookPrice;
		year = bookYear;
		numInStock = booksInStock;

	}


	//Displays the contents of the BookClass member variables
	void displayBookInfo()
	{

		cout << title
			<< "\nauthor: " << author
			<< "\npublisher: " << publisher
			<< "\nisbn: " << isbn
			<< "\nprice: " << price
			<< "\nyear: " << year
			<< "\nnumber of copies: " << numInStock << endl << endl;
	}


	//Subtracts 1 from the numInStock member variable
	void checkOutBook()
	{
		cout << "book checked out \n";
		numInStock -= 1;
	}

	//Adds 1 to the numInStock member variable
	void returnBook()
	{
		cout << "book returned \n";
		numInStock += 1;
	}

	// Returns the value in numInStock
	int getNumInStock() { return numInStock; }
	// Returns the value in title
	string getTitle() { return title; }
};

void storeBook(string bookTitle, string authorName, string bookPublisher, string bookISBN, double bookPrice, int bookYear, int booksInStock)

{
	title = bookTitle;
	author = authorName;
	publisher = bookPublisher;
	isbn = bookISBN;
	price = bookPrice;
	year = bookYear;
	numInStock = booksInStock;

}
//Function to read the text file of books in

void getBooks(BookClass bookHolder[MAX_BOOKS], int &counter)
{
	ifstream bookFile;
	string bookTitle, authorName, bookPublisher, bookISBN;
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
		storeBook(bookTitle, authorName, bookPublisher, bookISBN, bookPrice, bookYear, booksInStock);
		//counter to count the array up for new books
		counter++;

	}
}


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

//function to show user all the books and information
void showBooks(BookClass library[], int totalBooks)
{
	for (int i = 0; i < totalBooks - 1; i++)
	{
		library[i].displayBookInfo();
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
void findTitles(BookClass library[], int totalBooks, int &findBooks)
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
		library[findBooks].numInStock += 1;
		cout << library[findBooks].title << " returned. We now have " << library[findBooks].numInStock << " copies in stock\n";
	}
	else if (findBooks = -1)
	{
		cout << "Sorry we do not match that book\n";
	}


}
//function to let user check out a book unless there are no copies left
void checkOutBook(BookClass library[], int totalBooks, int findBooks)
{
	findTitles(library, totalBooks, findBooks);
	if (findBooks >= 0)
	{
		library[findBooks].numInStock -= 1;
		cout << library[findBooks].title << " checked-out. We now have " << library[findBooks].numInStock << " copies in stock\n";
	}
	else if (findBooks = -1)
	{
		cout << "Sorry we do not match that book\n";
	}
	else if (findBooks = 0)
	{
		cout << "Sorry we are out of copies\n";
	}

}