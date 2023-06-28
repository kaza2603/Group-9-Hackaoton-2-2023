#include <iostream>
#include "Player.h"

class Item : Player
{
  private:
  string name;
  int cost;

  public:

  Item()
  {
    name = "";
    cost = 0;
  }

  void setItem(string n,int c,int phy,int mage)
  {

    name = n;
    cost = c;
    Player :: setPhyDamage(phy);
    Player :: setMageDamage(mage);
  }
  string getItemName()
  {
    return name;
  }
  int getItemCost()
  {
    return cost;
  }

  int getPhyItemDamage()
  {
    return Player :: getPhyDamage();
  }

  int getMageItemDamage()
  {
    return Player :: getMageDamage();
  }

};

Item ItemPhy[5];
Item ItemMage[5];

void initializeItems()
{
  ItemPhy[0].setItem("Bloodlust Axe", 250, 750, 0);
  ItemPhy[1].setItem("Windtalker", 150, 400, 0);
  ItemPhy[2].setItem("Blade of Despair", 700, 1300, 0);
  ItemPhy[3].setItem("Blade Of Heptasis", 300, 800, 0);
  ItemPhy[4].setItem("Metallic Roar", 375, 840, 0);

  ItemMage[0].setItem("Winter Truncheon", 150, 0, 400);
  ItemMage[1].setItem("Tailsman", 300, 0, 550);
  ItemMage[2].setItem("Ice Blade", 550, 0, 700);
  ItemMage[3].setItem("Clock of Destiny", 440, 0, 600);
  ItemMage[4].setItem("Gleam Reaper", 890, 0, 1570);
}

void Player :: Shop()
{

  int choice;
  cout << "\n\n-------Medina Legend Shop--------\n";
  cout << "1 for Weapon and 2 for Magic Spell  or 3 to buy foods to heal >>";
  cin >> choice;
  int selection;

    if(choice == 1){
    cout << "\nPlease select your item to buy\n";
    cout << "\nYour gold:" << getCoin();
    cout << "\n\n1.Bloodlust Axe        |Price --> 200  |Damage --> 750";
    cout << "\n2.Windtalker           |Price --> 150  |Damage --> 400";
    cout << "\n3.Blade of Dispair     |Price --> 700  |Damage --> 1300";
    cout << "\n4.Blade of Heptasis    |Price --> 300  |Damage --> 800";
    cout << "\n5.Metallic Roar        |Price --> 300  |Damage --> 840";

    cout << "\n\nWhat do you want to buy? >>";
    cin  >> selection;

    while (selection > 0){

        for(int i = 0; i < 5 ;i++)
        {
          if(selection == i+1)
          {
            if(coin >= ItemPhy[i].getItemCost())
            {
              phydamage += ItemPhy[i].getPhyItemDamage();
              SubCoin(ItemPhy[i].getItemCost());
              break;
            }
               else {
                cout << "\n##############################";
                cout << "\nYour Gold is insufficient !" << endl ;
                cout << "\n##############################" <<endl;
               break;}
          }
        }
        cout << "\nAnything else to buy?\n";
        cout << "\nYour gold:" << getCoin();
        cout << "\n\n1.Bloodlust Axe        |Price --> 200  |Damage --> 750";
        cout << "\n2.Windtalker           |Price --> 150  |Damage --> 400";
        cout << "\n3.Blade of Dispair     |Price --> 700  |Damage --> 1300";
        cout << "\n4.Blade of Heptasis    |Price --> 300  |Damage --> 800";
        cout << "\n5.Metallic Roar        |Price --> 300  |Damage --> 840";
        cout << "\nEnter 0 to exit" << endl;
        cout << "What do you want to buy? >>"  ;
        cin  >> selection;
    }
  }

  else if(choice == 2)
     {
    cout << "\nYour gold:" << getCoin();
    cout << "\nPlease select your magic spell to buy\n";
        cout << "\n\n1. Winter Truncheon        |Price --> 150  |Magical Damage --> 400\n";
        cout << "2. Tailsman                |Price --> 300  |Magical Damage --> 550\n";
        cout << "3. Ice Blade               |Price --> 350  |Magical Damage --> 700\n";
        cout << "4. Clock of Destiny        |Price --> 440  |Magical Damage --> 600\n";
        cout << "5. Gleam Reaper            |Price --> 890  |Magical Damage --> 1570\n";


    cout << "What do you want to buy? >>";
    cin  >> selection;
    while(selection > 0){
        for(int i = 0; i < 5 ;i++)
        {
          if(selection == i+1)
          {
            if(coin >= ItemMage[i].getItemCost())
            {
              magedamage += ItemMage[i].getMageItemDamage();
              SubCoin(ItemMage[i].getItemCost());
            }
               else {
                cout << "\n##############################" <<endl;
                cout << "Your Gold is insufficient !" << endl ;
                cout << "\n##############################" <<endl;}
          }
        }
        cout << "\nYour gold:" << getCoin();
        cout << "\nAnything else to buy?\n";
        cout << "\nPlease select your magic spell to buy\n";
        cout << "\n\n1. Winter Truncheon        |Price --> 150  |Magical Damage --> 400\n";
        cout << "2. Tailsman                |Price --> 300  |Magical Damage --> 550\n";
        cout << "3. Ice Blade               |Price --> 350  |Magical Damage --> 700\n";
        cout << "4. Clock of Destiny        |Price --> 440  |Magical Damage --> 600\n";
        cout << "5. Gleam Reaper            |Price --> 890  |Magical Damage --> 1570\n";
        cout << "Enter 0 to exit" << endl;
        cin  >> selection;

    }
  }

            else
            {
              cout << "\nPlease select your item to buy\n";
              cout << "\nYour gold:" << getCoin();
              cout << "\n1. Enchanted Apple  | Price --> 50  | Heal 350 Health" << endl;
              cout << "2. Purify water     | Price --> 70  | Heal 470 Health" << endl;

              cout << "What do you want to buy? >>";
              cin  >> selection;
              while(selection > 0){
                    if(selection == 1)
                    {
                      if(coin >= 50)
                      {
                        HealPlayer(350);
                        SubCoin(50);
                      }
                    else {
                      cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<endl;
                      cout << "Your Gold is insufficient !" << endl ;
                      cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<endl;
                          }

                      }
                    else if(selection == 2)
                    {
                      if(coin >= 70)
                      {
                        HealPlayer(4700);
                        SubCoin(70);
                      }
                    else {
                      cout << "\n##############################" <<endl;
                      cout << "Your Gold is insufficient !" << endl ;
                      cout << "\n##############################" <<endl;
                          }

                      }

              cout << "\nAnything else to buy?\n";
              cout << "\nPlease select your item to buy\n";
              cout << "\nYour gold:" << getCoin();
              cout << "\n1. Enchanted Apple  | Price --> 50  | Heal 350 Health" << endl;
              cout << "2. Purify water     | Price --> 70  | Heal 470 Health" << endl;
              cout << "Enter 0 to exit" << endl;
              cout << "What do you want to buy? >>";
              cin  >> selection;

            }
      }
}