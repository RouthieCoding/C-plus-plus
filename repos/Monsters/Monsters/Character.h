#include <string>
//#include "Hero.h"
using namespace std;

class Character
{
	int characterHealth = 0, characterStrength = 0;
	string characterName = "t";

public:
	// constructer
	//Character() {};
	//Character(int health, int strength);
	Character(string name, int health, int strength);
	
	//prototypes
	void displayCharacter();
	//setters
	void setCharacterName(string name);
	void setCharacterHealth(int health);
	void setCharacterStrength(int strength);
	//getters
	string setCharacterName() { return characterName; }
	int setCharacterHealth() { return characterHealth; }
	int setCharacterStrength() { return characterStrength; }

};

//Character::Character(int health, int strength)
//{
//	setCharacterHealth(health);
//	setCharacterStrength(strength);
//}
Character::Character(string name, int health, int strength)
{
	setCharacterName(name);
	setCharacterHealth(health);
	setCharacterStrength(strength);
}
void Character::displayCharacter()
{
	cout << characterName << " " << characterHealth << " " << characterStrength;
}
void Character::setCharacterName(string name)
{
	characterName = name;
}
void Character::setCharacterHealth(int health)
{
	characterHealth = health;
}
void Character::setCharacterStrength(int strength)
{
	characterStrength = strength;
}