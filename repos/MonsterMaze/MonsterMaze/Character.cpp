// MonsterMaze.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "Hero.h"
#include "BasicEnemy.h"
#include "Boss.h"

using namespace std;

//constructor to get player information
Character::Character(string name, int health, int strength)
{
	//function gets character information
	getCharacterInfo(name,health,strength);
}
//function uses setters to input character information
void Character::getCharacterInfo(string name, int health, int strength)
{
	setCharacterName(name);
	setCharacterHealth(health);
	setCharacterStrength(strength);
}
//function to display character information
void Character::displayCharacter()
{
	cout << characterName << " has " << characterHealth << " health and a strength of " << characterStrength;
}
//setter to get character name
void Character::setCharacterName(string name)
{
	characterName = name;
}
//setter to get character health
void Character::setCharacterHealth(int health)
{
	characterHealth = health;
}
//setter to get character strength
void Character::setCharacterStrength(int strength)
{
	characterStrength = strength;
}