class Enemy : Character
{
  private :
  string powername;
  int    powerdamage;

  public:

  Enemy() : Character()
  {
    powername="";
    powerdamage= 0;

  }

  Enemy(string n,int d,int h,string pn,int pd) : Character(n,d,h)
  {
    powername=pn;
    powerdamage= pd;
  }

  string getEnemyName()
  {
    return Character :: getName();
  }

  int getEnemyHealth()
  {
    return Character :: getHealth();
  }

  int getEnemyDamage()
  {
    return Character :: getDamage();
  }

  int getEnemyPowerDamage()
  {
    return powerdamage;
  }

  string getEnemyPowerName()
  {
    return powername;
  }

  void EnemytakeDamage(int num)
  {
    Character :: takeDamage(num);
  }
};