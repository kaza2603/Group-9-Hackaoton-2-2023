#include <iostream>
#include <fstream>
#include "Game.h"
using namespace std;

void saveGame(Player,Player,int);

class Maps //Linked List
{
private:
    struct Stage{
    string stagename;
    string description;
    Player player;
    Enemy enemy;
    Stage* next;
    Stage* back;
                 };
    Stage* FirstStage;
    Stage* LastStage;
public:
    // Constructor
    Maps()
    {
        FirstStage = nullptr;
        LastStage = nullptr;
    }

    void appendLevel(string n,string desc,Enemy enemy) {
        Stage* newStage = new Stage;
        Stage* currentStage = nullptr;
        newStage->stagename =n;
        newStage->description = desc;
        newStage->enemy = enemy;

        newStage->next = nullptr;
        newStage->back = nullptr;


        if (FirstStage == nullptr) {
            // If the list is empty, make the new node the head and tail
            FirstStage = newStage;
            LastStage = newStage;
        } else {
            //set nodePtr to NewNode
            currentStage = LastStage;

            // Append the new node after the tail
            currentStage->next = newStage;
            LastStage = newStage;
            newStage->back = currentStage;

        }

    }

    void TraverseLevel(Player &p1,Player &p2,int stagenum) {
            int input,currentstagenum=0;
            string inputshop;
            Stage* currentStage = FirstStage;   //current stage same as nodePtr

            Enemy e;
            string name,desc;
            while (currentStage != nullptr) {
                currentstagenum++; //update stage level

                if(currentstagenum == stagenum)
                {

                e = currentStage->enemy;
                name = currentStage->stagename;
                desc = currentStage->description;

                cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                cout << "\nNow both of you are at "<< currentStage->stagename <<endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                StartGame(p1,p2,e,name,desc);

                cout << "\nEnter 1 to go to next level";
                cout << "\nEnter 2 to play again  this level";
                cout << "\nEnter 3 to play level before";
                cout << "\nEnter 4 to go to shop";
                cout << "\nEnter 5 to save and exit game" << endl;

                cin  >> input;
                while(input >0 && currentStage != nullptr){
                switch(input)
                {

                  case 1:
                  currentstagenum++; //update stage level

                  currentStage = currentStage->next;
                  e = currentStage->enemy;
                  name = currentStage->stagename;
                  desc = currentStage->description;
                  cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                  cout << "\nNow both of you are at "<< currentStage->stagename <<endl;
                  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                  StartGame(p1,p2,e,name,desc);
                  break;

                  case 2:
                  if(p1.getHealth() <=0 || p2.getHealth() <=0) //case player is died and restart game
                  {
                    p1.setHealth(5000);p2.setHealth(5000);
                  }

                  StartGame(p1,p2,e,name,desc);
                  break;

                  case 3:
                  if(currentStage->back == nullptr){cout << "This is the first Stage!";}
                  else {currentStage = currentStage->back;
                  e = currentStage->enemy;
                  name = currentStage->stagename;
                  desc = currentStage->description;

                  currentstagenum--; //update stage level

                  if(p1.getHealth() <=0 || p2.getHealth() <=0) //case player is died and restart game
                  {
                    p1.setHealth(5000);p2.setHealth(5000);
                  }
                  StartGame(p1,p2,e,name,desc);
                  }
                  break;

                  case 4:
                  cout <<"\nFor Player 1 or Player 2 (Enter player1 or player2)";cin >> inputshop;
                  if(inputshop == "player1")
                   {
                     p1.Shop();break;
                   }
                     else {p2.Shop();break;}
                   break;

                  case 5:
                    saveGame(p1,p2,currentstagenum);
                    exit(0);
                }
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                cout << "\nNow both of you are at "<< currentStage->stagename <<endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                cout << "\nEnter 1 to go to next level";
                cout << "\nEnter 2 to play again  this level";
                cout << "\nEnter 3 to play level before";
                cout << "\nEnter 4 to go to shop";
                cout << "\nEnter 5 to save and exit game" << endl;
                cin  >> input;
           }
       }
       else currentStage = currentStage->next;    //to update linked list
    }
}
};



void saveGame(Player p1,Player p2,int stagenum)
{
    ofstream outputFile;
    outputFile.open("GameData.txt",ios::out);

    outputFile << p1.getPlayerName() <<endl;
    outputFile << p1.getHealth() <<endl;
    outputFile << p1.getCoin() <<endl;
    outputFile << p1.getPhyDamage() <<endl;
    outputFile << p1.getMageDamage() <<endl;

    outputFile << p2.getPlayerName() <<endl;
    outputFile << p2.getHealth() <<endl;
    outputFile << p2.getCoin() <<endl;
    outputFile << p2.getPhyDamage() <<endl;
    outputFile << p2.getMageDamage() <<endl;
    outputFile << stagenum;     //last data in file will be stagenum

    outputFile.close();
}

void loadGame(Player &p1,Player p2,Maps map)
{
    p1.setdamage(130);
    p2.setdamage(100);
    string p1name,p1health,p1coin,p1phydamage,p1magedamage,stagenum;
    string p2name,p2health,p2coin,p2phydamage,p2magedamage;
    ifstream inputFile;
    inputFile.open("GameData.txt",ios::in);

    while(inputFile >> p1name >> p1health >> p1coin >> p1phydamage >> p1magedamage >> p2name >> p2health >> p2coin >> p2phydamage >> p2magedamage >> stagenum){}

    p1.setName(p1name);
    p1.setHealth(stoi(p1health));
    p1.setCoin(stoi(p1coin)) ;
    p1.setPhyDamage(stoi(p1phydamage));
    p1.setMageDamage(stoi(p1magedamage));

    p2.setName(p2name);
    p2.setHealth(stoi(p2health));
    p2.setCoin(stoi(p2coin)) ;
    p2.setPhyDamage(stoi(p2phydamage));
    p2.setMageDamage(stoi(p2magedamage));

    map.TraverseLevel(p1,p2,stoi(stagenum));

}