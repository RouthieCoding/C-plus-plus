#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Power { SuperKick, DoubleAttack, IceBreath, FireBreath };
enum Item { Key, Potion, None };
enum PlayerType { Dwarf, Human };

class Hero : public Character
{
	Power hPower = (DoubleAttack);
	Item hItem = (None);
	PlayerType pType = (Dwarf);
public:
	// constructer
	Hero(string name, int health, int strength);
	//setters
	void setHeroPower(Power power);
	void setHeroItem(Item item);
	void setPlayerType(PlayerType type);
	//getters
	Power getHeroPower() { return hPower; }
	Item getheroItem() { return hItem; }
	PlayerType getPlayerType() { return pType; }
};
