#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BasicEnemy : public Character
{
	
	string attackName;

public:
	// constructer
	BasicEnemy() {};
	BasicEnemy(string name, int health, int strength, string attack);
	//setter
	void setBasicEnemyAttack(string attack);
	//getter
	string getBasicEnemyAttackName() { return attackName; }
};

