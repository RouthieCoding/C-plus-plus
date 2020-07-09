#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <string>
//#include "Character.h"
//#include "Hero.h"
using namespace std;

class Hero : public Character
{
	int characterHealth = 0, characterStrength = 0;
	string characterName;
	
	//Hero() {};
	/*Hero(string name, int health, int strength);*/
};

//Hero::Hero(string name, int health, int strength)
//{
//	setCharacterName(name);
//	setCharacterHealth(health);
//	setCharacterStrength(strength);
//}
//Hero::Hero(string name, int health, int strength)
//{
//	Character::setCharacterName(name);
//	Character::Character::setCharacterHealth(health);
//	Character::Character::setCharacterStrength(strength);
//}
#endif // HERO_H