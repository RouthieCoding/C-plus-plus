//Ryan Routhier
// MonsterMaze.cpp : This file contains the 'main' function. Program execution begins and ends there.
//8/3/2019
/* This program is a basic linear text based game. This game is made on a level system through switch layers in the
maze game function. It uses a function called enemyFight to pull in the hero and an enemy to fight which can allow the 
user to progress or to end the game. In the maze game switch cases the program also uses algorithm to randomly shuffle the passwords 
to progress on further. If the player is able to get all the way through the game the maze game function will return back true. This 
then logs the player into a binary file which can be viewed from the main menu.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Character.h"
#include "Hero.h"
#include "BasicEnemy.h"
#include "Boss.h"

using namespace std;

struct Player
{
	char name[30];
	int health, strength;
	PlayerType type;
};
//function to display player records info
void displayPlayer(Player newPlayer)
{	
	cout << newPlayer.name << " with " << newPlayer.health << " health left as a ";
	if (newPlayer.type == 0)
	{
		cout << "Dwarf" << endl;
	}
	else if (newPlayer.type == 1)
	{
		cout << "Human" << endl;
	}
}
//function to allow player to make a basic decision
int mazeDirection()
{
	int choice = 0;

	//gives user option to turn left or right
	cout << "\nShould you: \n"
		<< "Press 1 to turn left\n"
		<< "Press 2 to turn right\n"
		<< "Enter option: ";
	cin >> choice;
	while (choice < 1 || choice > 2)
	{
		cout << "Please enter 1 or 2: ";
		cin >> choice;
	}
	return choice;
}

//Function to allow a player to fight and then returns the players health
int enemyFight(Hero player, BasicEnemy badGuy, int &gameCounter, int &specialCounter)
{
	int choice = 0;
	bool loopBreak = false;
	
	//display enemy type
	cout << "\nYou have come across a " << badGuy.getCharacterName() << endl;
	
	//loop that runs until either the enemy is dead or player is dead
	while (badGuy.getCharacterHealth() > 0 && player.getCharacterHealth() > 0 )
	{
		//display the attack
		cout << "The " << badGuy.getCharacterName() << " attacks with " <<badGuy.getBasicEnemyAttackName() << " and you lose " << badGuy.getCharacterStrength() << " health\n";
		player.setCharacterHealth(player.getCharacterHealth() - badGuy.getCharacterStrength());
		
		//if player is killed it's game over
		if (player.getCharacterHealth() <= 0)
		{
			cout << "You have been killed by " << badGuy.getCharacterName() << "\n\n\t GAME OVER...";
			return -1;
		}
		// if player didn't die then the fight happens
		else
			{
				//display who is fighting
			player.displayCharacter();
			cout << " VS ";
			badGuy.displayCharacter();

			//allow player to pick a move
			if (specialCounter < 5)
			{
				cout << "\nShould you: \n"
					<< "Press 1 for normal attack\n"
					<< "Press 2 for special move( " << 5 - specialCounter << " remaining)\n"
					<< "Enter option: ";
				while (choice != 1 && choice != 2)
				{
					cin >> choice;

					//based on move selected do this
					switch (choice)
					{
					case 1:
						//if user does normal attack
						cout << player.getCharacterName() << " attacked with normal attack and did " << player.getCharacterStrength() << " damage.\n";
						badGuy.setCharacterHealth(badGuy.getCharacterHealth() - player.getCharacterStrength());
						break;
					case 2:
						//if user does special ability
						//double attack move
						if (player.getHeroPower() == DoubleAttack)
						{
							cout << player.getCharacterName() << " attacked with a Double Attack and did " << player.getCharacterStrength() * 2 << " damage.\n";
							badGuy.setCharacterHealth(badGuy.getCharacterHealth() - (player.getCharacterStrength() * 2));
							specialCounter++;
							break;
						}
						//superkick attack move
						else if (player.getHeroPower() == SuperKick)
						{
							cout << player.getCharacterName() << " attacked with Super Kick and did 50 damage.\n";
							badGuy.setCharacterHealth(badGuy.getCharacterHealth() - 50);
							specialCounter++;
							break;
						}
					default: 
						cout << "Please enter a 1 or 2: ";
						break;
					}
				}
			}
			else 
			{
				//if user runs out of special attacks
				cout << "\nYou are out of special moves and can only now normal attack\n";
				system("pause");
				//User must normal attack
				cout << player.getCharacterName() << " attacked with normal attack and did " << player.getCharacterStrength() << " damage.\n";
				badGuy.setCharacterHealth(badGuy.getCharacterHealth() - player.getCharacterStrength());
			}
		}

		cout << endl;
	}
	//if bad guy dies display it
	if (badGuy.getCharacterHealth() <= 0)
	{
		cout << player.getCharacterName() << " beat up the " << badGuy.getCharacterName() << endl;
	}
	//if player dies set the game to a dead state
	if (player.getCharacterHealth() <= 0)
	{
		gameCounter = -1;
	}
	//returns back player health
	return player.getCharacterHealth();
}
bool mazeGame(Hero player, int &finalHealth)
{
	int count, specialCounter = 0;
	string playerGuess;
	vector<char> cloud = {'c', 'l', 'o', 'u', 'd'};
	vector<char> widget = { 'w', 'i', 'd', 'g', 'e', 't' };
	bool loseGame = false;
	int gameCounter = 0, gameDirection = 0, choice = 0;
	
	//loads in enemies to it's proper constructor
	BasicEnemy toad("Toad", 10, 5,"Tongue Lash"), bat("Bat", 15, 10, "Wing Attack"), rat("Rat", 15, 10,"Bite Attack"), raccoon("Raccoon", 25, 10, "Scratch Attack"), gorilla("Gorilla", 40, 15, "Gorilla Smash");
	Boss iceDragon("Ice Dragon", 50, 20, "Ice Breath"), fireDragon("Fire Dragon", 50, 20, "Fire Breath");
	player.displayCharacter();
	
	//opening maze greeting and gives the ice dragon his key
	cout << "\nYou enter the maze with no clue where you are.\n";
	iceDragon.setBossItem(Key);

	//loop that runs until the bool loseGame becomes true or when game reaches the exit state of 10
	while (loseGame != true && gameCounter != 10)
	{
		//uses a switch to run through player levels
		switch (gameCounter)
		{
			//ends the game in a lose state
		case -1:
			loseGame = true;
			return false;
			break;
		case 0://the first level in the game
			cout << "You walk further down the hallway and are met with a decision.";

			//loop that allows player to either move on or lose game
			while (gameCounter != -1 && gameCounter != 1)
			{
				//calls function to allow user to move
				gameDirection = mazeDirection();
				switch (gameDirection)
				{
					//game moves on
				case 1:gameCounter++;
					break;
				case 2:
					////calls a fight with a toad
					player.setCharacterHealth(enemyFight(player, toad, gameCounter, specialCounter));
					if (player.getCharacterHealth() > 0)
					{
						cout << "\nSeems like this is a dead end so back to your previous decision\n";
						break;
					}
					else {
						gameCounter = -1;
						break;
					}
					break;
				}
				
			}

		case 1://the second level in the game
			cout << "\nYou make a left and find yourself walking down a hallway until you are met with another decision.";

			//loop that allows player to either move on or lose game
			while (gameCounter != -1 && gameCounter != 2)
			{
				//calls function to allow user to move
				gameDirection = mazeDirection();
				switch (gameDirection)
				{
					//calls a fight with bat
				case 1:player.setCharacterHealth(enemyFight(player, bat, gameCounter, specialCounter));
					if (player.getCharacterHealth() > 0)
					{
						cout << "\nSeems like this is a dead end so back to your previous decision\n";
					}
					else {
						gameCounter = -1;
					}
					break;
					//game moves on
				case 2:gameCounter++;
					break;
				}
			}
			break;
		case 2://the third level in the game
			cout << "\nYou come across a locked door that has a word that looks like jibberish.\n"
			     << "\n\t ";
			
			
			//word randomizer
		      random_shuffle(cloud.begin(), cloud.end());
			  //loop that allows player to either move on
			  while (playerGuess != "cloud")
			  {
				  // Display the vector's elements. 
				  for (count = 0; count < cloud.size(); count++)
				  {
					  cout << cloud[count] << " ";
				  }
				  cout << "...Maybe the word needs to be rearranged\nTake a guess: ";
				  cin >> playerGuess;
			  }
			  //game moves on
			  gameCounter++;
				  break;
		case 3://the fourth level in the game
			cout << "\nThe door opens and find yourself a new hallway until you are met with another decision.";

			//loop that allows player to either move on or lose game
			while (gameCounter != -1 && gameCounter != 4)
			{
				//calls function to allow user to move
				gameDirection = mazeDirection();
				switch (gameDirection)
				{
					//calls a fight with rat
				case 1:player.setCharacterHealth(enemyFight(player, rat, gameCounter, specialCounter));
					if (player.getCharacterHealth() > 0)
					{
						cout << "\nSeems like this is a dead end so back to your previous decision\n";
					}
					else {
						gameCounter = -1;
					}
					break;
					//game moves on
				case 2:gameCounter++;
					break;
				}
			}
			break;
		case 4://the fifth level in the game
			cout << "\nYou walk further down the hallway until you are met with a door on one side and another hallway on the other\n"
					 << "Should you: \n"
					 << "Press 1 to try the door\n"
					 << "Press 2 to walk the hallway\n"
					 << "Enter option: ";
			while (gameCounter != 5 && gameCounter != 8)
			{
			cin >> choice;
			switch (choice)
			{
				//calls function to allow user to move
					gameDirection = mazeDirection();
			case 1:
				if (player.getheroItem() != Key)
				{
					cout << "\nYou try the door but you need a key.\n"
						 << "Which only leaves you one option to walk down the hallway\n";
					gameCounter++;
				
				}
				else if (player.getheroItem() == Key)
				{
					cout << "\nYou use your key and the door opens\n";
					//game progresses to level 8
					gameCounter = 8;
				}
				break;
				//games moves to the next stage
			case 2:gameCounter++;
				break;
			default:
				cout << "Please enter a 1 or 2\n";
				break;
				}
			}
			
			break;
		case 5://the sixth level in the game
			cout << "\nYou walk down the hallway but at the end is a raccoon in full attack mode\n";

			//loop that allows player to either move on or lose game
			while (gameCounter != -1 && gameCounter != 6)
			{
				//calls a fight with a raccoon
				player.setCharacterHealth(enemyFight(player, raccoon, gameCounter, specialCounter));
				cout << "\nYou find a hole behind the raccoon to crawl through\n";
				//moves the game on
				gameCounter++;
			}
			break;
		case 6://the seventh level in the game
			cout << "\nAs you exit the hole you feel a freezing chill\n";
			//calls a fight with ice dragon if he still has the key
			if (iceDragon.getBossItem() == Key)
			{
				player.setCharacterHealth(enemyFight(player, iceDragon, gameCounter, specialCounter));
			}
		//gives the hero the key and takes it away from the dragon
			if (player.getCharacterHealth() > 0 && iceDragon.getBossItem() == Key)
			{
				cout << "\n" << player.getCharacterName() << " has slain " << iceDragon.getCharacterName() 
					 << " and has recieved a KEY\n";
				player.setHeroItem(Key);
				iceDragon.setBossItem(None);
				//game moves on
				gameCounter++;
			}
			else if (player.getCharacterHealth() > 0 && iceDragon.getBossItem() != Key)
			{
				//if you have already beat the dragon
				cout << "\nYou have already slain the " << iceDragon.getCharacterName() << " and already have the key.\n"
					<< "You need to find a place to use that key!\n";
				//game moves on
				gameCounter++;
				//lets player think where to use the key
				system("pause");
			}
			else {
				gameCounter = -1;
			}
			
			
			break;
		case 7://the eigth level in the game
			cout << "\nIn the Dragon lair you find a portal that has a word that looks like jibberish on it.\n"
				<< "\n\t ";


			//word randomizer
			random_shuffle(widget.begin(), widget.end());
			
			//loop that allows player to either move on 
			while (playerGuess != "widget")
			{
				// Display the vector's elements. 
				for (count = 0; count < widget.size(); count++)
				{
					cout << widget[count] << " ";
				}
				cout << "...Maybe the word needs to be rearranged\nTake a guess: ";
				cin >> playerGuess;
			}
			cout << "\nThe portal opens up to a hallway\n";

			//game goes back to level 4 to allow player to use key
			gameCounter = 4;
			break;
		case 8://the ninth level in the game
			cout << "\nYou walk further down the hallway and are met with a decision.";

			//loop that allows player to either move on or lose game
			while (gameCounter != -1 && gameCounter != 9)
			{
				//calls function to allow user to move
				gameDirection = mazeDirection();
				switch (gameDirection)
				{
				case 1:
					//games moves on
					gameCounter++;
					break;
					//calls a fight with a gorilla
				case 2:player.setCharacterHealth(enemyFight(player, gorilla, gameCounter, specialCounter));
					if (player.getCharacterHealth() > 0)
					{
						cout << "\nSeems like this is a dead end so back to your previous decision\n";
					}
					else {
						gameCounter = -1;
					}
					break;
				}
			}
			break;
		case 9://the last level in the game
			cout << "\nThe hallway leads to a larger Dragon lair in which you see an exit on the other side\n"
				 << "But what's this shadow figure blocking the way\n";
			//calls a fight with fire dragon
			player.setCharacterHealth(enemyFight(player, fireDragon, gameCounter, specialCounter));
			//if player wins 
			if (player.getCharacterHealth() > 0)
			{
				//outputs message
				cout << "\nWith the " << fireDragon.getCharacterName() << " slain " << player.getCharacterName() << " can now leave through the exit..." << endl;
				//sets final health
				finalHealth = player.getCharacterHealth();
				//ends the game loop
				gameCounter++;
				//returns the game bool as true
				return true;
				break;
			}
			else {
				gameCounter = -1;
				break;
			}
		default:
			break;
		}
	
	}
}
//function to get player name and load in his class type (will return a 1 or a 2)
int playerInfo(Player &player)
{
	char name[30];
	int choice = 0;

	//allows player to enter name
	cin.ignore();
	cout << "\nEnter your name: ";
	cin >> name;
	//copies name into player struct
	strcpy_s(player.name, name);
	//allows user to pick class
	cout << "\nPress 1 to be a Dwarf\n"
		<< "Press 2 to be a Human\n"
		<< "Enter option: ";
	//user has to pick one class or the other
	while (choice < 1 || choice > 2)
	{
		cin >> choice;
		//loads player struct with stats based on choice selected
		switch (choice)
		{
		case 1:
			player.health = 175;
			player.strength = 20;
			player.type = Dwarf;
			break;
		case 2:
			player.health = 150;
			player.strength = 10;
			player.type = Human;
			break;
		default:
			cout << "please enter 1 or 2";
			break;
		}
	}
	return choice;
}
// <---------- MAIN
int main()
{
	int power = 0, finalHealth = 0;

	string name;
	int playState = 0;
	bool loopBreak = false, gameCondition = false;
	
	fstream playerLog;
	Hero player(" ",0 ,0);
	Player newPlayer, displayHolder;
	
	//displays the header
	cout << "******************************\n"
		<< "*Welcome to the monster maze!*\n"
		<< "******************************\n";

	//main loop that runs the game
	while (loopBreak != true)
	{
		cout << "\nEnter 1 to play\n"
			<< "Enter 2 for records\n"
			<< "Enter 3 to exit\n"
			<< "Enter option: ";
			cin >> playState;
	
		//main switch that allows user to choose to play game view records or quit
		switch (playState)
		{
			//calls a function to get player info and then returns a int to set player ability
		case 1:
			
			power = playerInfo(newPlayer);
			player.setCharacterName(newPlayer.name);
			player.setCharacterHealth(newPlayer.health);
			player.setCharacterStrength(newPlayer.strength);
		//sets player ability
		if (power == 1)
		{
			player.setHeroPower(DoubleAttack);
		}
		else if (power == 2)
		{
			player.setHeroPower(SuperKick);
		}
		//Outputs to the user their selection
		cout << "Welcome " << newPlayer.name << " you have selected to be a ";
		if (newPlayer.type == 0)
		{
			cout << "Dwarf." << endl;
		}
		else if (newPlayer.type == 1)
		{
			cout << "Human." << endl;
		}
		//outputs to user the move they can do
		cout << "You can use your special move ";
		if (power == 1)
		{
			cout << "Double Attack 5 times\n";
		}
		else if (power == 2)
		{
			cout << "Super Kick 5 times\n";
		} 
		//calls a function to run the game and returns a bool if the player wins
			gameCondition = mazeGame(player, finalHealth);
			//sets health to final game health
			newPlayer.health = finalHealth;
			//breaks the main loop
			loopBreak = true;
			break;
		case 2:
			//opens the player log to view through records
			playerLog.open("playerLog.dat", ios::binary | ios::in | ios::out);
			//runs a loop to read through the player log
			cout << "********************************\n"
				<< "**Players to complete the game**\n";
			while (playerLog.read(reinterpret_cast<char*>(&displayHolder), sizeof(displayHolder)))
			{
		      //calls a function to display the player records
				displayPlayer(displayHolder);
			}
			break;
		case 3:
			//ends the program
			return 0;
			break;
		default: cout << "Please enter a valid option";
			break;
		}
		//if player wins message is shown and player info is recorded
		if (gameCondition == true)
		{
			cout << "\n\n\tCongratulations you have broke free from the maze!!\n";
			
			playerLog.open("playerLog.dat", ios::binary | ios::in | ios::out | ios::app);

			playerLog.write(reinterpret_cast<char*>(&newPlayer), sizeof(newPlayer));

			playerLog.close();
		}

	}
	
	
}
