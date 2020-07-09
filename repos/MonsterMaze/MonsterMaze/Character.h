#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Character
{
	int characterHealth = 0, characterStrength = 0;
	string characterName = "t";

public:
	// constructer
	Character() {};
	Character(string name, int health, int strength);
	
	//prototypes
	void displayCharacter();
	void getCharacterInfo(string name, int health, int strength);
	//setters
	void setCharacterName(string name);
	void setCharacterHealth(int health);
	void setCharacterStrength(int strength);
	//getters
	string getCharacterName() { return characterName; }
	int getCharacterHealth() { return characterHealth; }
	int getCharacterStrength() { return characterStrength; }

};