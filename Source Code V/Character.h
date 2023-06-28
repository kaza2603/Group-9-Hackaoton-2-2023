using namespace std;
#include<iostream>

class Character {
private:
    string name;
    int damage;
    int health;

public:
  Character()
  {
    name = "";
    damage=0;
    health =0;
  }

  void setHealth(int h)
  {
    health = h;
  }
  Character(string n,int d,int h)
  {
    name = n;
    damage = d;
    health = h;
  }
    void setName(string n)
    {
    	name = n;
	}
    string getName() const {
        return name;
    }

    int getHealth() const {
        return health;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0)
            health = 0;
        }

    void setdamage(int d)
    {
      damage = d;
    }

    int getDamage()
    {
      return damage;
    }

    void AddHealth(int num)
    {
      health += num;
    }
};