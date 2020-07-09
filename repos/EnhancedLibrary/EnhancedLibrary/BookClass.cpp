//#include "pch.h"
//#include <iostream>
//#include <string>
//#include <fstream>
//#include "BookClass.h"
//
//using namespace std;
//
////const to limit books for program space
//const int MAX_BOOKS = 100;
//
////creats a book class used to define what a book is 
//class BookClass
//{
//	//makes data public so other functions can access it
//public:
//	string title, author, publisher, isbn;
//	double price;
//	int year, numInStock, counter = 0;
//
//	//functions to store books information  
//	void storeBook(string bookTitle, string authorName, string bookPublisher, string bookISBN, double bookPrice, int bookYear, int booksInStock)
//
//	{
//		title = bookTitle;
//		author = authorName;
//		publisher = bookPublisher;
//		isbn = bookISBN;
//		price = bookPrice;
//		year = bookYear;
//		numInStock = booksInStock;
//
//	}
//
//
//	//Displays the contents of the BookClass member variables
//	void displayBookInfo()
//	{
//
//		cout << title
//			<< "\nauthor: " << author
//			<< "\npublisher: " << publisher
//			<< "\nisbn: " << isbn
//			<< "\nprice: " << price
//			<< "\nyear: " << year
//			<< "\nnumber of copies: " << numInStock << endl << endl;
//	}
//
//
//	//Subtracts 1 from the numInStock member variable
//	void checkOutBook()
//	{
//		cout << "book checked out \n";
//		numInStock -= 1;
//	}
//
//	//Adds 1 to the numInStock member variable
//	void returnBook()
//	{
//		cout << "book returned \n";
//		numInStock += 1;
//	}
//
//	// Returns the value in numInStock
//	int getNumInStock() { return numInStock; }
//	// Returns the value in title
//	string getTitle() { return title; }
//};
//
////Function to read the text file of books in
//
//
