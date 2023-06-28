#include "Maps.h"
#include <iostream>
#include <string>
using namespace std;


void start(Player &p1, Player &p2)
{
  initializeItems();  //initialize item array to be used in shop function
  Maps map;

  //Set Map stage and enemy
  Enemy Minion("Minions",50,100,"",0); //set Enemy Level 1 300
  map.appendLevel("The Dungeon Legends!","This is the Land of the Dawn, where the adventure begins. Look!, there is a lot of minions. Beat them to get some golds!",Minion);  //set Stage Level 1

  Enemy BlairWitch("Blair Witch", 85, 120," ",0);    //set Enemy Level 2 900
  map.appendLevel("Hidden Dawn", "This is the epitome of claustrophobia! You must find the treasure to escape the room before she gets you!", BlairWitch);  //set Stage Level 2

  Enemy Wizard("Wizard",150,140,"Magic Cast", 400);  //set Enemy Level 3 2500
  map.appendLevel("Enchanted Chamber,", "This is where magic & wisdom begin!", Wizard);   //set Stage Level 3


  Enemy MamakEmperor("Mamak Emperor",400,200,"Telekinetic Destruction",700);    //set Enemy Level 5 8000
  map.appendLevel("Mysterious Dawn","Welcome to Mysterious Dawn, Now you will be facing the final boss, MAMAK EMPEROR!, ",MamakEmperor);  //set Stage Level 5
  //

  string choice;

  cout << "\nLet's Rock!!!" << endl;

  cout << "Enter 'start' to start  or 'load' to load previous game>> ";
  cin  >> choice;
 while(choice != "")
 {
  if(choice == "start")
  {

    string name1,name2;
    cout << "Please enter your name for Player 1 (Role : Fighter): " ;
    cin  >> name1;
    cout << "Please enter your name for Player 2 (Role : Mage)   : "  ;
    cin  >> name2;

    p1.setName(name1);
    p2.setName(name2);
    p1.setdamage(130); //
    p2.setdamage(100);
    map.TraverseLevel(p1,p2,1); //where the game start
  }
        else if(choice == "load")
          {
            loadGame(p1,p2,map);
          }

          else {cout << "No such command!\n";}

  cout << "Enter start to start game or buy to purchase item >> ";
  cin  >> choice;

  }
}

int main()
{

    cout << "  __   __   _____    _____     ___     _   _      _         _       _____     ____     _____   _   _    _____" << endl;
    cout << " |  \\/  |  | ____|  |  __ \\   |_ _|   | \\ | |    / \\       | |     | ____|   / ___|   | ____| | \\ | |  |  __ \\" << endl;
    cout << " | |\\/| |  | |__    | |  | |   | |    | . ` |   / _ \\      | |     | |__    | |  _    | |__   |  \\| |  | |  | |" << endl;
    cout << " | |  | |  |  __|   | |  | |   | |    | |\\  |  / ___ \\     | |     |  __|   | |_| |   |  __|  | . ` |  | |  | |" << endl;
    cout << " |_|  |_|  |_____|  |_____/   |___|   |_| \\_| /_/    \_\\    | |___  | |___    \\____|   | |___  | |\\  |  |_____/" << endl;
    cout << "________________________________________________________________________________________________________________________________";

    Player p1,p2;
    start(p1,p2);


    return 0;
}