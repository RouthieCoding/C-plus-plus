// Ryan Routhier
// EnhancedLibrary.cpp
// 07/17/2019
//This program does

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX_BOOKS = 100;

void storeBook(string bookTitle, string authorName, string bookPublisher, string bookISBN, double bookPrice, int bookYear, int booksInStock, int counter)

{
	string title, author, publisher, isbn;
	double price;
	int year, numInStock, counter = 0;

	title = bookTitle;
	author = authorName;
	publisher = bookPublisher;
	isbn = bookISBN;
	price = bookPrice;
	year = bookYear;
	numInStock= booksInStock;
}
int main()
{
	ifstream bookFile;
	string bookTitle, authorName, bookPublisher, bookISBN;
	double bookPrice = 1;
	int bookYear = 2001, booksInStock = 0;
	bookFile.open ("books.txt");
	while (bookFile)
	{
		bookFile >> bookTitle;
		cout << bookTitle;
		getline(bookFile, bookTitle, '\n');
		cout << bookTitle << " ";
		getline(bookFile, authorName, '\n');
		cout << authorName << " ";
		getline(bookFile, bookPublisher, '\n');
		cout << bookPublisher << " ";

		bookFile >> bookISBN;
		cout << bookISBN << " ";


		bookFile >> bookPrice;
		cout << bookPrice << " ";

		bookFile >> bookYear;
		cout << bookYear << " ";
		bookFile >> booksInStock;
		cout << booksInStock << " ";
		bookHolder[counter].storeBook(bookTitle, authorName, bookPublisher, bookISBN, bookPrice, bookYear, booksInStock, counter);

		//counter++;
		//cout << counter;

	}

return 0;
}
