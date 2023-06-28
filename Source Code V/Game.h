#include "Item.h"
#include "Enemy.h"

#include <cstdlib>
void StartGame(Player &p1,Player &p2,Enemy enemy,string name,string desc)
{
  p1.DisplayPlayerInfo(p1,p2);


   cout << "\n______________________________________________________________________________________________________________________    ";
   cout << "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<endl;
   cout << "Welcome " << p1.getPlayerName() <<" and "<< p2.getPlayerName() << " to " << name << endl;
   cout << desc  << endl;
   cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" <<endl;
   cout << "______________________________________________________________________________________________________________________   " <<endl;


   cout << "\n\nYou will be taking turn to defeat the enemy and remember player 1 can only use your fighting skill and player 2 can only use your magic skill" << endl;
   cout << "``````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;
   cout << enemy.getEnemyName() << "'s health : " << enemy.getEnemyHealth() << "  Enemy damage: " << enemy.getEnemyDamage() ;


   if(enemy.getEnemyPowerDamage() > 0) { // to indicate whether this just monster or villain(only villain have power)
   cout << "  Enemy special power: >>>>" << enemy.getEnemyPowerName() << "<<<<  Damage: " <<enemy.getEnemyPowerDamage()<<endl;
   cout << "You will fight "<< enemy.getEnemyName() << " at this level" ;}
   else{};

  srand(time(0));


    int input;

    cout << "\n#############################################################################" <<endl;
    cout << "INSTRUCTION : Enter 1 to use basic attack and 2 to use your individual skill" << endl;
    cout << "#############################################################################" << endl;
  do
  {
    if(p1.getHealth() > 0){
    cout << "\nPlayer 1 turn: ";cin >>input;
    int num1 = rand() %6 +1;  // generate between 1 and 6

    switch(input){
    case 1:
    if(num1 == 1||num1 == 3||num1 ==4||num1 == 5) //Make sure attack probabilty is higher
    {  cout << "\n##############################################" <<endl;
       cout << "You attacked " << enemy.getEnemyName() << " !  " <<endl;
       enemy.EnemytakeDamage(p1.getBasicAttack());
       cout << ">>" <<enemy.getEnemyName() << " health: " <<enemy.getEnemyHealth();
       cout << "\n##############################################" <<endl;
    }

    else
    { cout << "\n##############################################"<<endl;
      cout << "You missed that attack! ";
      cout << enemy.getEnemyName() << " health: " <<enemy.getEnemyHealth();
      cout << "\n##############################################"<<endl;
    }
    break;

    case 2:
    if(num1 == 1|| num1 == 3||num1 ==4||num1 == 5) //Make sure attack probabilty is higher
    {  cout << "\n##################################################################"<<endl;
       cout << "You attacked " << enemy.getEnemyName() << " by using fighting skill!"<< " with total damage " << p1.getPhyDamage() <<endl;
       enemy.EnemytakeDamage(p1.getPhyDamage());
       cout << enemy.getEnemyName() << " health: " <<enemy.getEnemyHealth();
       cout << "\n##################################################################"<<endl;
    }

    else
    { cout << "\n##############################################"<<endl;
      cout << "You missed that attack!" <<endl;
      cout << enemy.getEnemyName() << " health: " <<enemy.getEnemyHealth();
      cout << "\n##############################################"<<endl;
    }
    break; }
    }


    //------------Player2's turn---------------
    int num2 = rand() %6 +1;  // generate between 1 and 6
    if(p2.getHealth() >0){
    cout << "\n\nPlayer 2 turn : ";cin>>input;


    switch(input){
    case 1:
    if(num2 == 1||num2 == 2||num2 ==4||num2 == 5) //Make sure attack probabilty is higher
    {  cout << "\n##############################################"<<endl;
       cout << "You attacked " << enemy.getEnemyName() << " !  " <<endl;
       enemy.EnemytakeDamage(p2.getBasicAttack());
       cout << ">>" <<enemy.getEnemyName() << " health: " <<enemy.getEnemyHealth();
       cout << "\n##############################################"<<endl;
    }

    else
    { cout << "\n##############################################"<<endl;
      cout << "You missed that attack! " <<endl;
      cout << enemy.getEnemyName() << " health: " <<enemy.getEnemyHealth();
      cout << "\n##############################################"<<endl;
    }
    break;

    case 2:
    if(num2 == 1|| num2 == 2||num2 ==4||num2 == 5) //Make sure attack probabilty is higher
    {  cout << "\n################################################################"<<endl;
       cout << "You attacked " << enemy.getEnemyName() << " by using magic skill! with total damage << p2.getMageDamage()";
       enemy.EnemytakeDamage(p2.getBasicAttack());
       cout << ">>" <<enemy.getEnemyName() << " health: " <<enemy.getEnemyHealth();
       cout << "\n################################################################"<<endl;
    }

    else
    { cout << "\n##############################################"<<endl;
      cout << "You missed that attack!";
      cout << enemy.getEnemyName() << " health: " <<enemy.getEnemyHealth();
      cout << "\n##############################################"<<endl;
    }
    break;

  }
}



  //---------Enemy's turn to attack--------------------
  int num3 = rand() %7 +1;  // generate between 1 and 6
  if(num2 == 1|| num2==3)   //if statement to give enemy chances to attack randomly Player 1
  { cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    cout << enemy.getEnemyName() << " attacks player 1 with damage " <<enemy.getEnemyDamage()<< " !" << endl;
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    p1.PlayertakeDamage(enemy.getEnemyDamage());
    p1.DisplayPlayerInfo(p1,p2);
  }
  else if(num2 == 2|| num2== 4)   //if statement to give enemy chances to attack randomly Player 2
  { cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    cout << enemy.getEnemyName() << " attacks player 2 with damage " <<enemy.getEnemyDamage() << " !" << endl;
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    p2.PlayertakeDamage(enemy.getEnemyDamage());
    p2.DisplayPlayerInfo(p1,p2);
  }
  else if(num2 == 7 || num2 == 5) // Enemy use power
  {
    if(enemy.getEnemyPowerDamage() > 0)   // to indicate whether enemy have power or not
      {
    cout << "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
    cout <<endl<< enemy.getEnemyName() << " use his power " << enemy.getEnemyPowerName() << "with Damage " << enemy.getEnemyPowerDamage() << " !";
    p1.PlayertakeDamage(enemy.getEnemyPowerDamage());
    p2.PlayertakeDamage(enemy.getEnemyPowerDamage());
    cout << "\nvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";
    p1.DisplayPlayerInfo(p1,p2);
      }
  }
  else {
        cout <<"\n\n++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout <<"\n" << enemy.getEnemyName() << " attacks You ! ";
        cout << "But You manage to avoid " << endl;
        cout <<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl; }

  }while((p1.getHealth() != 0 || p2.getHealth() != 0) && enemy.getEnemyHealth() != 0);

  p1.DisplayPlayerInfo(p1,p2);

    if(enemy.getEnemyHealth() == 0)
    { int goldPlayer1,goldPlayer2;
      goldPlayer1 = rand()%100 + 151; //generates a random gold between 151 and 250
      goldPlayer2 = rand()%100 + 151; //generates a random gold between 151 and 250
      cout << "\n----------------------------------------------------------------------";
      cout << "\n>>>Both of you have killed "<< enemy.getEnemyName() <<".  Player 1 Gold: " << goldPlayer1 << "  Player 2 Gold: " << goldPlayer2 << endl;
      p1.AddCoin(goldPlayer1);
      p2.AddCoin(goldPlayer2);
    }
        else if(p1.getHealth() == 0)
        {
          cout <<"\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
               <<"\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
          cout << p1.getPlayerName()<<" died!"<<endl;
          cout << "Go to previous stage to farm more golds to purchase more item";
          cout <<"\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
               <<"\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
        }
        else if(p2.getHealth() == 0)
        {
          cout <<"\n  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  "
               <<"\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
          cout << p2.getPlayerName()<<" died!"<<endl;
          cout << "Go to previous stage to farm more golds and don forget to purchase more item to increase your ability and power";
          cout <<"\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
               <<"\n  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX   \n";
        }

        if(p1.getHealth() == 0 && p2.getHealth() == 0)
        {
          p1.setHealth(5000);p2.setHealth(5000);
        }


        if(p1.getHealth() != 0 && p2.getHealth() != 0 && enemy.getEnemyName() == "Mamak Emperor")
        {
          cout << "\nContragulation! You guys have complete Medina Legend!";
        }

}
