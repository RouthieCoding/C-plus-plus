#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Boss : public BasicEnemy
{
	Item bossItem;
public:
	// constructer
	Boss(string name, int health, int strength, string attack);
	//setters
	void setBossItem(Item bossItem);
	//getters
	Item getBossItem() { return bossItem; }
};