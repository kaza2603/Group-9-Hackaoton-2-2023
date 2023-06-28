#include "Character.h"
#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
using namespace std;


class Player : public Character {
private:
    string role;
    int coin;
    int phydamage;
    int magedamage;

public:

    Player()
    {
      Character :: setHealth(7000);
      Character :: setdamage(0);
      coin = 0;
      phydamage = 0;
      magedamage = 0;
    }

    void SubCoin(int num) //subtract player gold after purchase item
    {
      coin -= num;
    }
    void AddCoin(int num)  //subtract player gold after purchase item
    {
      coin += num;
    }
    int getBasicAttack()
    {
      return Character :: getDamage();
    }
    string getRole() const {
        return role;
    }
    void setName(string n)
    {
    	Character :: setName(n);
	  }
    string getPlayerName()
    {
    	return Character :: getName();
	}

    void setCoin(int gold)  {
        coin = gold;
    }

    int getCoin() const {
        return coin;
    }

    int getPhyDamage() const {
        return phydamage;
    }

    void setPhyDamage(int d) {
        phydamage = d;
    }

    int getMageDamage() const {
        return magedamage;
    }

    void setMageDamage(int d) {
        magedamage=d;
    }

    void DisplayPlayerInfo(Player p1,Player p2)
    {
      cout <<"\n```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````"<< endl;
      cout << "Player 1 health now =" << p1.getHealth() << "  Player 2 health now =" << p2.getHealth() ;
      cout << "\nPlayer 1 Gold: " << p1.getCoin() << "  Player 2 Gold: " << p2.getCoin();
      cout << "\nPlayer 1 Basic Attack:" << p1.getBasicAttack() << "  Player 2 Basic Attack:" << p2.getBasicAttack() <<"  Player 1 Weapon Damage :" << phydamage << "  Player 2 Magic Skill Damage :" << magedamage;
      cout <<"\n```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````"<< endl;

    }

    void PlayertakeDamage(int damage) {
          Character :: takeDamage(damage);
        }

    void HealPlayer(int num) {
          Character :: AddHealth(num);
        }

    void Shop();
};



#endif