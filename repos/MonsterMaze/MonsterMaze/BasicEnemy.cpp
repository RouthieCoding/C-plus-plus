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

//constructor to input a basic enemy tyoe
BasicEnemy::BasicEnemy(string name, int health, int strength, string attack)
{
	getCharacterInfo(name, health, strength);
	setBasicEnemyAttack(attack);
}

//setter to get hero power
void BasicEnemy::setBasicEnemyAttack(string attack)
{
	attackName = attack;
}