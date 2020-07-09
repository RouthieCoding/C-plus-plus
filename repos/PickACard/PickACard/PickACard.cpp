//Ryan Routhier
// PickACard.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 7/2/2019
// This program creats a deck of cards to output to the user. Then the user must wait while the computer pulls a random card based off of the computer clock. The user must wait again while the computer
// prepares another random card again based off of the time on the computer. Finally the program compares the cards and outputs who the winner is.

#include "pch.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime> 


using namespace std;

//makes emuns to save card types
enum suits { CLUBS, DIAMONDS, HEARTS, SPADES };
enum cardValues { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

//const to limit max cards in the deck
const int maxCards = 52;

//makes a struct to hold the values of the cards
struct cards
{
	suits suit;
	cardValues card;
};

//creats a deck of cards which is held in memory based on the deck[] pointer
void createDeck(cards deck[])
{ for (suits i = CLUBS; i <= SPADES; i = static_cast<suits>(i + 1))
	{
		for (cardValues x = TWO; x <= ACE; x = static_cast<cardValues>(x + 1))
		{
			deck[x + (i * (maxCards / 4))].suit = static_cast<suits>(i);
			deck[x + (i * (maxCards / 4))].card = static_cast<cardValues>(x);
		}
	}
}

// prints the card number based off of the enum via switch statement
void printCard(cards print)
{
	switch (print.card) {
	case TWO:	cout << "Two";
		break;
	case THREE:	cout << "Three";
		break;
	case FOUR:	cout << "Four";
		break;
	case FIVE:	cout << "Five";
		break;
	case SIX:	cout << "Six";
		break;
	case SEVEN:	cout << "Seven";
		break;
	case EIGHT:	cout << "Eight";
		break;
	case NINE:	cout << "Nine";
		break;
	case TEN:	cout << "Ten";
		break;
	case JACK:	cout << "Jack";
		break;
	case QUEEN:	cout << "Queen";
		break;
	case KING:	cout << "King";
		break;
	case ACE:	cout << "Ace";
		break;
	}
	cout << " of ";
	// prints the suit of the card based off of enums via switch statement
	switch (print.suit) {
	case CLUBS:	    cout << "Clubs";
		break;
	case DIAMONDS:	cout << "Diamonds";
		break;
	case HEARTS:	cout << "Hearts";
		break;
	case SPADES:	cout << "Spades";
		break;
	}
}

//calls the print card function to output all the cards in the deck
void printDeck(cards deck[])
{
	for (int i = 0; i < maxCards; i++)
	{
		printCard(deck[i]);
		cout << endl;

	}
}
//deals a random card based off of the computer clock
void deal(cards deck[], cards &card)
{ 
	cout << "\nShuffling cards press return\n";
	cin.ignore();
	srand(time(0));
	card = deck[rand() % maxCards];
}
//Decides who the winner is based on which card is higher
void winner(cards card1, cards card2)
{
	//if card 1 is higher is displays it won
	if (card1.card > card2.card)
	{
		cout << "Card 1";
	}
	else if (card2.card > card1.card)
	{
		//if card 2 is higher is displays it won
		cout << "Card 2";
	}
	else
		//if the cards are tied or errorous then the match is a tie
		cout << "It's a draw";
}

int main()
{
	cards deck[maxCards];
	cards card1, card2;
	string card;
	//calls function to creat a deck of cards
	createDeck(deck);
	//outputs to user name of program
	cout << "Pick A Card\n\n"
	//outputs to user the deck of cards
		 << "The deck of cards : \n\n";
	//calls function to print all the cards
	printDeck(deck);
	//calls function to make a random card and store it in card1
	deal(deck, card1);


	cout << "Card 1 = "; 
	//calls function to output card 1 to user 
	printCard(card1);
	cout << endl;

	deal(deck, card2);
	//calls function to output card 1 to user 
	cout << "Card 2 = "; 
	printCard(card2);
	cout << endl << endl;

	cout << "The winner is: ";
	//calls function to decide who the winning card is
	winner(card1, card2);
	cout << endl;
}
