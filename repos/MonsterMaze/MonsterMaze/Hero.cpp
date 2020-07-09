// MonsterMaze.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "Hero.h"
#include "BasicEnemy.h"
#include "Boss.h"
//#include "MonsterMaze.cpp"

using namespace std;

//constructor to input a hero 
Hero::Hero(string name, int health, int strength)
{
	getCharacterInfo(name, health, strength);
}

//setter to get hero power
void Hero::setHeroPower(Power power)
{
	hPower = power;
}
//setter to get hero item
void Hero::setHeroItem(Item item)
{
	hItem = item;
}
//setter to get hero type
void Hero::setPlayerType(PlayerType type)
{
	pType = type;
}