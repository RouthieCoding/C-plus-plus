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

//constructor to input a boss type
Boss::Boss(string name, int health, int strength, string attack)
{
	getCharacterInfo(name, health, strength);
	setBasicEnemyAttack(attack);
}

//setter to get boss item
void Boss::setBossItem(Item item)
{
	bossItem = item;
}