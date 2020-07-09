//Ryan Routhier
// MidTerm.cpp 
// 7/08/2019
// This program...

#include "pch.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

const int SIZE = 50, maxCards = 52;
//makes emuns to save card types
enum suits { CLUBS, DIAMONDS, HEARTS, SPADES };
enum cardValues { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

struct cards
{
	suits suit;
	cardValues card;
};

struct Address
{
	string street, city, state, zip;

};

struct Player
{
	string name;
	Address playerInfo;
};

void createDeck(cards deck[])
{
	for (suits i = CLUBS; i <= SPADES; i = static_cast<suits>(i + 1))
	{
		for (cardValues x = TWO; x <= ACE; x = static_cast<cardValues>(x + 1))
		{
			deck[x + (i * (maxCards / 4))].suit = static_cast<suits>(i);
			deck[x + (i * (maxCards / 4))].card = static_cast<cardValues>(x);
		}
	}
}
void deal(cards deck[], cards &card)
{
	//cout << "\nShuffling cards press return\n";
	//cin.ignore();
	//srand(time(0));
	card = deck[rand() % maxCards];
}
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


//Menu Output
int showMenu(int choice)
{
	cout << "\nMake a selection\n"
		<< "1: Join now and get $10.00 FREE\n"
		<< "2: To play Magic Cups\n"
		<< "3: To play War\n"
		<< "4: To play BlackJack\n"
		<< "5: To veiw high scores \n"
		<< "6: To cashout \n"
		<< "7: To Exit\n\n"
		<< "Please choose a number: ";
		cin >> choice;
		cout << endl;
	return choice;
}
Player playerInfo(Player newPlayer[SIZE], double &cash, string &currentPlayer)
{
	Player temp;
	//int nameLength;
	//char name[30];

	cin.ignore();
	//enter customer data in to record information
	cout << "Enter your full name: ";
	getline(cin, temp.name);
	currentPlayer = temp.name;
	//strncpy(name, currentPlayer);
	//nameLength = strlen(name
	
	//;
	//cout << nameLength;
	// name search here
	cout << "We will also need your address to send you a check\n"
		<< "Enter street address: ";
	
	getline(cin, temp.playerInfo.street);
	cout << "Enter city: ";
	cin >> temp.playerInfo.city;
	cout << "Enter state: ";
	cin.ignore();
	cin >> temp.playerInfo.state;
	cout << "Enter zip code: ";
	cin >> temp.playerInfo.zip;
	cin.ignore();
	//to raise the cash up to 10
	cash = 10;
	return temp;
	
}
int ballCups(double &cash, int highScore)
{
	
	char cups[20] = "|1| |2| |3| |4| |5|";//, cupFinal;
	char *strPtr = cups;
	int cupGuess,cupLocation,holder = 0, cupFinal = 0, count =0, x = 0;
	string loopBreak = "yes", temp;

	highScore = 0;

	while (loopBreak != "no")
	{
		temp = strPtr;
		cout << strPtr;

		
		
		cupLocation = rand() % 5 + 1;
		char c = '0' + cupLocation;
		//cout << c;
		while (cups[x] != c)
		{
			x++;
			//cout << x;
			//*strPtr = cups[x];
		}
		//cout << *strPtr;
		*(strPtr + x) = 'o';
		
		cout << cupLocation;
		for (int i = 0; i < 20; i++)
		{
			cout << cups[i];
		}
		cout << "guess a cup";
		cin >> cupGuess;
		if (cupGuess == cupLocation)
		{
			cout << "Congratulations you win\n";
			cash += 1;
			highScore += 1;
		}
		else if (cupGuess != cupLocation)
		{
			cout << "Sorry you lost\n";
			cash -= 1;
			highScore -= 1;
		}
		cout << "You have $" << fixed << setprecision(2) << cash << " left\n";
		cout << "Do you want to play again? (yes or no)";
		cin >> loopBreak;
		//tolower(loopBreak);
	}
	return highScore;
}
int war(double &cash, int highScore)
{
	cards deck[maxCards];
	cards playerCard,dealerCard;
	string card; 
	string loopBreak;

	highScore = 0;
	while (loopBreak != "no")
	{
		createDeck(deck);
		deal(deck, playerCard);
		cout << "Your card is: ";
		printCard(playerCard);
		cout << endl;
		deal(deck, dealerCard);
		cout << "The Dealers card is: ";
		printCard(dealerCard);
		cout << endl;
		//find winner
		
		if (playerCard.card > dealerCard.card)
		{
			cout << "Congrats you Win!" << endl;
			cash += 1;
			highScore += 1;
		}
		else if (playerCard.card < dealerCard.card)
		{
			cout << "Sorry you lost" << endl;
			cash -= 1;
			highScore -= 1;
		}
		else
		{
			cout << "It's a draw" << endl;
		}
		cout << "You have $" << fixed << setprecision(2) << cash << " left\n"
			 << "Do you want to play again? (yes or no)";
		cin >> loopBreak;
		cout << endl;
	}
	return highScore;
}
void highScore(double score[SIZE][3], string players[SIZE][3])
{
	cout << setw(25) << " " << "Top 5 scores for most money made in a sitting\n";
	
	cout << setw(21) << "Name" << setw(5) << "|" << setw(7) << "Magic Cups" << setw(3) << "|" << setw(12)
	               	 << "Name" << setw(3) << "|" << setw(5) << "War" << setw(3) << "|" << setw(15)
		             << "Name" << setw(3) << "|" << setw(11) << "BlackJack";
	for (int i = 0; i < 5; i++)
	{
		cout << "\n";
		int x = 0;
		    cout << setw(5) << i + 1 << ":";
			cout << setw(20) << players[i][x] << " ";
			cout << setw(4) << score[i][x] << " ";
		x = 1;
			cout << setw(20) << players[i][x] << " ";
			cout << setw(4) << score[i][x] << " ";
		x = 2;
			cout << setw(20) << players[i][x] << " ";
			cout << setw(4) << score[i][x] << " ";
	}
}
void playerCashout(Player playerCash[SIZE], double cash, string currentPlayer)
{
	int i = 0;

	while (currentPlayer != playerCash[i].name)
	{
		i++;
	}
	cout << "\t" <<playerCash[i].name << " " << playerCash[i].playerInfo.street << " " << playerCash[i].playerInfo.city << ", " 
		 << playerCash[i].playerInfo.state << " " << playerCash[i].playerInfo.zip << endl;
}
void scoreSort(double scores[SIZE][3], string names[SIZE][3],int game, string player, int newScore)
{
	int numHolder = 0;
	string strHolder;

	for (int i = 0; i < SIZE; i++)
	{
		//cout << scores[i][game];

		if (scores[i][game] < newScore)
		{
			//do one with a pointer
			cout << scores[i][game] << " " << newScore<<endl;
			numHolder = newScore;
			newScore = scores[i][game];
			scores[i][game] = numHolder;
			
			strHolder = player;
			player = names[i][game];
			names[i][game] = strHolder;

			cout << scores[i][game] << " " <<  " " << newScore << endl;
		}

	}
}
int main()
{
	
	Player players[SIZE];

	int choice = 0, counter = 0, highScoreHolder = 0, gameNum = 0;
	double cash = 0, scores[SIZE][3] = { 21,25,22,17,18,16,11,13,12,9,5,7,6,4,5 };
	bool loopBreak = false;
	string currentPlayer, leaderboardNames[SIZE][3] = { {"Gorden Freeman", "Samus Aran", "Leon Kennedy"},
														{"Master Chief", "Raiden", "Sonic"},
														{"Wario", "Clair Redfield", "Master Chief"},
														{"Samus Aran", "Laura Croft", "Solid Snake"},
														{"Leon Kennedy", "Mario", "Duke Nukem" } };

	//Header
	cout << "Welcome to Ry Guy's Casino" << endl;
	//main while loop

	while (loopBreak != true)
	{
		//calls and returns the menu choice
		choice = showMenu(choice);

		switch (choice)
		{
		case 1: players[counter] = playerInfo(players, cash, currentPlayer);
			counter++;
			break;
		case 2:   highScoreHolder = ballCups(cash, highScoreHolder); // Ball Game with c-string cups
			gameNum = 0;
			//highScoreHolder = 30;
			     scoreSort(scores, leaderboardNames, gameNum, currentPlayer,highScoreHolder);
			break;
		case 3: highScoreHolder = war(cash, highScoreHolder);
			gameNum = 1;
			scoreSort(scores, leaderboardNames, gameNum, currentPlayer, highScoreHolder);
			break;
		case 4:
			gameNum = 2;
			scoreSort(scores, leaderboardNames, gameNum, currentPlayer, highScoreHolder);
			break;
		case 5: highScore(scores, leaderboardNames);
			break;
		case 6: playerCashout(players,cash, currentPlayer);
			break; 
		case 7: loopBreak = true;
			break;
		default:
			cout << "\nPlease Enter a valid Option\n";
			break;
		}
	}

	return 0;
}
