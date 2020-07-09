// Monsters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "Hero.h"

using namespace std;

int main()
{
	int characterHealth = 0, characterStrength = 0;
	string characterName;

    cout << "Hello World!\n";
	//Character test(50, 100);
	Character test("Ryan", 50, 100);
	//Hero tester("Ryan", 50, 100);
	test.displayCharacter();
}

