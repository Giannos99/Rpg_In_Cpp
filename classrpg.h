#include <iostream>
# include <ctime>
#include <string>

int random11_12(void);
int random600_1000(void);
int random1_3(void);
using namespace std;
string random_swordname(void);
string random_armorname(void);
string random_potionname(void);
string random_spellname(void);
string random_heroname(void);

class Item{
int value;
string name;
int levelrequired;
public:
Item(int x_,string y_,int z_)
{
      value=x_;
      name=y_;
      levelrequired=z_;
}
virtual bool isWeapon(){};
virtual bool isArmor(){};
virtual bool isPotion(){};
virtual int get_type(){};
virtual int get_damage(){};
virtual int get_armor(){};
virtual int get_bonus(){};
virtual int get_penalty(){};


int get_value(){return value;};
string get_name(){return name;};
int get_levelrequired(){return levelrequired;};
/*virtual void setvalues(int,int,int){};*/
/*virtual void getvalues(int *,int *,int *){};*/
virtual ~Item()
{
cout << "Item destroyed!" << endl;
}

//void operate(void);
};
class Weapon: public Item{
int damage,type/*0=one handed 1= two handed*/;
public:
Weapon():Item(random600_1000(),random_swordname(),random1_3()){type=rand()%2;if(type==1)damage=(rand()%100)+120;else damage=(rand()%80+50);cout << "I am a weapon!" << endl;};
bool isWeapon(){return 1;};
bool isArmor(){return 0;};
bool isPotion(){return 0;};
int get_damage(){return damage;};
int get_type(){return type;};
int get_armor(){return 0;};
int get_bonus(){return 0;};
int get_penalty(){return 0;};

/*void setvalues(int k,int j,int l){bonus+=k;penalty+=j;jammed=l;};
void getvalues(int *k,int *j,int *l){*k=bonus;*j=penalty;*l=jammed;};*/

~Weapon()
{
cout << "Weapon destroyed!" << endl;
}

};
class Armor: public Item{
int armor;
public:
Armor():Item(3*random600_1000(),random_armorname(),random1_3()){armor=3*(rand()%100+1);cout << "I am an armor!" << endl;};

bool isArmor(){return 1;};
bool isWeapon(){return 0;};
bool isPotion(){return 0;};
int get_damage(){return 0;};
int get_type(){return 0;};
int get_armor(){return armor;};
int get_bonus(){return 0;};
int get_penalty(){return 0;};

/*void setvalues(int k,int j,int l){bonus+=k;penalty+=j;jammed=l;};
void getvalues(int *k,int *j,int *l){*k=bonus;*j=penalty;*l=jammed;};*/

~Armor()
{
cout << "Armor destroyed!" << endl;
}
};
class Potion: public Item{
int bonus,penalty;
public:
Potion():Item(random600_1000()/2,random_potionname(),random1_3()){if(rand()%2){bonus=2*(rand()%100+50);penalty=0;}else {bonus=0;penalty=2*(rand()%100+50);}cout << "I am a potion!" << endl;};

bool isPotion(){return 1;};
bool isWeapon(){return 0;};
bool isArmor(){return 0;};
int get_damage(){return 0;};
int get_type(){return 0;};
int get_armor(){return 0;};
int get_bonus(){return bonus;};
int get_penalty(){return penalty;};

/*void setvalues(int k,int j,int l){bonus+=k;penalty+=j;jammed=l;};
void getvalues(int *k,int *j,int *l){*k=bonus;*j=penalty;*l=jammed;};*/

~Potion()
{
cout << "Potion destroyed!" << endl;
}
};

/******************************************/
class Spell{
int value;
string name;
int levelrequired;
int manacost;
int damage;
public:
Spell(int x_,string y_,int z_,int a_,int b_)
{
      value=x_;
      name=y_;
      levelrequired=z_;
      manacost=a_;
      damage=b_;
}
virtual bool isIceSpell(){};
virtual bool isFireSpell(){};
virtual bool isLightingSpell(){};
virtual int get_disable(){};
virtual int get_defend(){};
virtual int get_chance(){};

int get_value(){return value;};
string get_name(){return name;};
int get_levelrequired(){return levelrequired;};
int get_manacost(){return manacost;};
int get_damage(){return damage;};
/*virtual void setvalues(int,int,int){};*/
/*virtual void getvalues(int *,int *,int *){};*/
virtual ~Spell()
{
cout << "Spell destroyed!" << endl;
}

//void operate(void);
};
class IceSpell: public Spell{
int disable/*=1 otan meiwnei to euros tou antipalou gia ena guro,2 otan to meiwnei gia 2 ,ktl ktl*/;
public:
IceSpell():Spell(random600_1000()/2,random_spellname(),random1_3(),rand()%100+1,rand()%50+1){disable=random1_3();cout << "I am an Icespell!" << endl;};
bool isIceSpell(){return 1;};
bool isFireSpell(){return 0;};
bool isLightingSpell(){return 0;};
int get_disable(){return disable;};
int get_defend(){return 0;};
int get_chance(){return 0;};

/*void setvalues(int k,int j,int l){bonus+=k;penalty+=j;jammed=l;};
void getvalues(int *k,int *j,int *l){*k=bonus;*j=penalty;*l=jammed;};*/

~IceSpell()
{
cout << "Icespell destroyed!" << endl;
}

};
class FireSpell: public Spell{
int defend;/*meiwnei thn amuna opoiou xtuphsei gia n gurous*/;
public:
FireSpell():Spell(random600_1000()/2,random_spellname(),random1_3(),rand()%100+1,rand()%50+1){defend=random1_3();cout << "I am a FireSpell!" << endl;};
bool isIceSpell(){return 0;};
bool isFireSpell(){return 1;};
bool isLightingSpell(){return 0;};
int get_disable(){return 0;};
int get_defend(){return defend;};
int get_chance(){return 0;};


/*void setvalues(int k,int j,int l){bonus+=k;penalty+=j;jammed=l;};
void getvalues(int *k,int *j,int *l){*k=bonus;*j=penalty;*l=jammed;};*/

~FireSpell()
{
cout << "FireSpell destroyed!" << endl;
}

};
class LightingSpell: public Spell{
int chance;/*meiwnei thn pi8anothta apofughs epi8eshs tous epomenous gurous*/;
public:
LightingSpell():Spell(random600_1000()/2,random_spellname(),random1_3(),rand()%100+1,rand()%50+1){chance=random1_3();cout << "I am a LightingSpell!" << endl;};
bool isIceSpell(){return 0;};
bool isFireSpell(){return 0;};
bool isLightingSpell(){return 1;};
int get_disable(){return 0;};
int get_defend(){return 0;};
int get_chance(){return chance;};

/*void setvalues(int k,int j,int l){bonus+=k;penalty+=j;jammed=l;};
void getvalues(int *k,int *j,int *l){*k=bonus;*j=penalty;*l=jammed;};*/

~LightingSpell()
{
cout << "LightingSpell destroyed!" << endl;
}

};



/********************* 3EKINA ALLH CLASS**********************************************************/
class Living{
protected:      
int healthpower;
string name;
int level;
public:
Living(int x_,string y_,int z_)
{
      healthpower=x_;
      name=y_;
      level=z_;
}
virtual bool is_Hero(){};
virtual bool is_Monster(){};
virtual int get_magicpower(){};
virtual int get_strength(){};
virtual int get_dexterity(){};
virtual int get_agility(){};
virtual int get_money(){};
virtual int get_experience(){};
virtual int get_mdamage(){};
virtual int get_mdefence(){};
virtual int get_mchance(){};

int get_healthpower(){return healthpower;};
string get_name(){return name;};
int get_level(){return level;};
/*virtual void setvalues(int,int,int){};*/
/*virtual void getvalues(int *,int *,int *){};*/
virtual ~Living()
{
cout << "Living destroyed!" << endl;
}

//void operate(void);
};
class Hero: public Living{
int magicpower,strength,dexterity,agility,experience,money;
public:
Hero(int x1_,int x2_,int x3_,int x4_,int x5_,int x6_):Living(4*random600_1000(),random_heroname(),0)
{
      magicpower=x1_;
      strength=x2_;
      dexterity=x3_;
      agility=x4_;
      experience=x5_;
      money =x6_;         
}
virtual bool isWarrior(){};
virtual bool isSorcerer(){};
virtual bool isPaladin(){};
bool is_Hero(){return 1;};
bool is_Monster(){return 0;};
int get_magicpower(){return magicpower;};
int get_strength(){return strength;};
int get_dexterity(){return dexterity;};
int get_agility(){return agility;};
int get_money(){return money;};
int get_experience(){return experience;};
int get_mdamage(){return 0;};
int get_mdefence(){return 0;};
int get_mchance(){return 0;};
/*void setvalues(int k,int j,int l){bonus+=k;penalty+=j;jammed=l;};
void getvalues(int *k,int *j,int *l){*k=bonus;*j=penalty;*l=jammed;};*/

~Hero()
{
cout << "Hero destroyed!" << endl;
}

};

class Warrior: public Hero{

public:
Warrior():Hero(random600_1000()/2,3*rand()%300+200,random600_1000()/2,3*random600_1000(),0,0){cout<<"I'm a warrior"<<endl;};
bool isWarrior(){return 1;};
bool isSorcerer(){return 0;};
bool isPaladin(){return 0;};


/*void setvalues(int k,int j,int l){bonus+=k;penalty+=j;jammed=l;};
void getvalues(int *k,int *j,int *l){*k=bonus;*j=penalty;*l=jammed;};*/

~Warrior()
{
cout << "Warrior destroyed!" << endl;
}

};
class Sorcerer: public Hero{

public:
Sorcerer():Hero(3*random600_1000(),rand()%100+100,3*random600_1000(),3*random600_1000(),0,0){cout<<"I'm a sorcerer"<<endl;};
bool isWarrior(){return 0;};
bool isSorcerer(){return 1;};
bool isPaladin(){return 0;};


/*void setvalues(int k,int j,int l){bonus+=k;penalty+=j;jammed=l;};
void getvalues(int *k,int *j,int *l){*k=bonus;*j=penalty;*l=jammed;};*/

~Sorcerer()
{
cout << "Sorcerer destroyed!" << endl;
}

};
class Paladin: public Hero{

public:
Paladin():Hero(random600_1000()/2,3*rand()%300+200,3*random600_1000(),random600_1000()/2,0,0){cout<<"I'm a paladin"<<endl;};
bool isWarrior(){return 0;};
bool isSorcerer(){return 0;};
bool isPaladin(){return 1;};


/*void setvalues(int k,int j,int l){bonus+=k;penalty+=j;jammed=l;};
void getvalues(int *k,int *j,int *l){*k=bonus;*j=penalty;*l=jammed;};*/

~Paladin()
{
cout << "Paladin destroyed!" << endl;
}

};
class Monster: public Living{
int mdamage,mdefence,mchance;
public:
Monster(int x1_,int x2_,int x3_):Living(2*random600_1000(),"monster",random1_3())
{
      mdamage=x1_;
      mdefence=x2_;
      mchance=x3_;        
}
virtual bool isDragon(){};
virtual bool isExoskeleton(){};
virtual bool isSpirit(){};
bool is_Hero(){return 0;};
bool is_Monster(){return 1;};
int get_magicpower(){return 0;};
int get_strength(){return 0;};
int get_dexterity(){return 0;};
int get_agility(){return 0;};
int get_money(){return 0;};
int get_mdamage(){return mdamage;};
int get_mdefence(){return mdefence;};
int get_mchance(){return mchance;};
/*void setvalues(int k,int j,int l){bonus+=k;penalty+=j;jammed=l;};
void getvalues(int *k,int *j,int *l){*k=bonus;*j=penalty;*l=jammed;};*/

~Monster()
{
cout << "Monster destroyed!" << endl;
}

};

class Dragon: public Monster{

public:
Dragon():Monster(3*rand()%100+100,rand()%50+1,1/*chance to avoid 1=little, 2 = a lot*/){cout<<"I'm a Dragon"<<endl;};
bool isDragon(){return 1;};
bool isExoskeleton(){return 0;};
bool isSpirit(){return 0;};


/*void setvalues(int k,int j,int l){bonus+=k;penalty+=j;jammed=l;};
void getvalues(int *k,int *j,int *l){*k=bonus;*j=penalty;*l=jammed;};*/

~Dragon()
{
cout << "Dragon destroyed!" << endl;
}

};
class Exoskeleton: public Monster{

public:
Exoskeleton():Monster(rand()%50+100,rand()%150+1,1/*chance to avoid 1=little, 2 = a lot*/){cout<<"I'm an Exoskeleton"<<endl;};
bool isDragon(){return 0;};
bool isExoskeleton(){return 1;};
bool isSpirit(){return 0;};


/*void setvalues(int k,int j,int l){bonus+=k;penalty+=j;jammed=l;};
void getvalues(int *k,int *j,int *l){*k=bonus;*j=penalty;*l=jammed;};*/

~Exoskeleton()
{
cout << "Exoskeleton destroyed!" << endl;
}

};
class Spirit: public Monster{

public:
Spirit():Monster(rand()%50+100,rand()%50+1,2/*chance to avoid 1=little, 2 = a lot*/){cout<<"I'm a Spirit"<<endl;};
bool isDragon(){return 0;};
bool isExoskeleton(){return 0;};
bool isSpirit(){return 1;};


/*void setvalues(int k,int j,int l){bonus+=k;penalty+=j;jammed=l;};
void getvalues(int *k,int *j,int *l){*k=bonus;*j=penalty;*l=jammed;};*/

~Spirit()
{
cout << "Spirit destroyed!" << endl;
}

};
/*
class Ball{

public:
Ball(){}
virtual void Battle(Player *,int *,Player *,int *,int *){};
virtual ~Ball(){}

};
class Red: public Ball{

public:
Red()
{
cout << "I am a red ball!" << endl;
}

void Battle(Player *pl1_ptr,int *k,Player *pl2_ptr,int *j,int *game){
     int bonus1=0;                                    
     int penalty1=0;                                   
     int jammed1=0;                                   
     int bonus2=0;                                     
     int penalty2=0;                                    
     int jammed2=0;                                     
     pl1_ptr->getvalues(&bonus1,&penalty1,&jammed1);
     pl2_ptr->getvalues(&bonus2,&penalty2,&jammed2);
      if(pl1_ptr->isChaser() && pl2_ptr->isChaser()){
                             if (((pl1_ptr->get_power()+bonus1-penalty1)>(pl2_ptr->get_power()+bonus2-penalty2))&& jammed1!=1){
                                            *k+=10;
                                                                                                                       return;
                                                                                                                   }
                             else if(((pl1_ptr->get_power()+bonus1-penalty1)<(pl2_ptr->get_power()+bonus2-penalty2))&& jammed2!=1){
                                                                                                                   *j+=10;
                                                                                                                   return;
                                                                                                                   }
                             else
                             return;
      }
      if(!(pl1_ptr->isChaser())){
                                 if(pl2_ptr->isChaser() && jammed2!=1){
                                                        if(pl1_ptr->isKeeper() && jammed1!=1){
                                                        if(((pl1_ptr->get_power()+bonus1-penalty1)>=(pl2_ptr->get_power()+bonus2-penalty2)))
                                                        return;
                                                        }
                                                        else{
                                                             *j+=10;
                                                             return;
                                                        }
                                 }
      }
                                 
      if(!(pl2_ptr->isChaser())){
                                 if(pl1_ptr->isChaser() && jammed1!=1){
                                                        if(pl2_ptr->isKeeper() && jammed2!=1){
                                                        if((pl2_ptr->get_power()+bonus2-penalty2)>=(pl1_ptr->get_power()+bonus1-penalty1))
                                                        return;
                                                        }
                                                        else{
                                                             *k+=10;
                                                             return;
                                                             }
                                 }
      }                                                                                                                                       
     
     
     
     
     };
~Red()
{
cout << "Red ball destroyed!" << endl;
}
};
class Black: public Ball{

public:
Black()
{
cout << "I am a black ball!" << endl;
}

void Battle(Player *pl1_ptr,int *k,Player *pl2_ptr,int *j,int  *game){
     int bonus1=0;
     int penalty1=0;
     int jammed1=0;
     int bonus2=0;
     int penalty2=0;
     int jammed2=0;
     pl1_ptr->getvalues(&bonus1,&penalty1,&jammed1);
     pl2_ptr->getvalues(&bonus2,&penalty2,&jammed2);
     if(pl1_ptr->isBeater() && pl2_ptr->isBeater()){
                            if (((pl1_ptr->get_power()+bonus1-penalty1)>(pl2_ptr->get_power()+bonus2-penalty2))&& jammed1!=1){
                                                                                                                  *game=3;
                                                                                                                  return;
                                                                                                                  }
                            else if(((pl1_ptr->get_power()+bonus1-penalty1)<(pl2_ptr->get_power()+bonus2-penalty2))&& jammed2!=1){
                                                                                                                      *game=2;
                                                                                                                      return;
                                                                                                                      }
                            else
                            return;
     }
     if(!(pl1_ptr->isBeater())){
                                if(pl2_ptr->isBeater() && jammed2!=1){
                                                       *game=2;
                                                       return;
                                                       }
                                }
     if(!(pl2_ptr->isBeater())){
                                if(pl1_ptr->isBeater() && jammed1!=1){
                                                       *game=3;
                                                       return;
                                                       }
                                }
     return;
     
     
     };
     
~Black()
{
cout << "Black ball destroyed!" << endl;
}
};
class Gold: public Ball{

public:
Gold()
{
cout << "I am a golden ball!" << endl;
}
void Battle(Player *pl1_ptr,int *k,Player *pl2_ptr,int *j,int *game){
     int bonus1=0;
     int penalty1=0;
     int jammed1=0;
     int bonus2=0;
     int penalty2=0;
     int jammed2=0;
     pl1_ptr->getvalues(&bonus1,&penalty1,&jammed1);
     pl2_ptr->getvalues(&bonus2,&penalty2,&jammed2);
     if(pl1_ptr->isSeeker() && pl2_ptr->isSeeker()){
                            if (((pl1_ptr->get_power()+bonus1-penalty1)>(pl2_ptr->get_power()+bonus2-penalty2))&& jammed1!=1){
                                                                           *k+=150;
                                                                           *game=1;
                                                                           return;
                                                                           }
                            else if(((pl1_ptr->get_power()+bonus1-penalty1)<(pl2_ptr->get_power()+bonus2-penalty2))&& jammed2!=1){
                                                                           *j+=150;
                                                                           *game=1;
                                                                           return;
                                                                           }
                            else 
                            return;
     }
     if(!(pl1_ptr->isSeeker())){
                                if(pl2_ptr->isSeeker() && jammed2!=1){
                                                        *j+=150;
                                                        *game=1;
                                                        return;
                                                        }
                                }
     if(!(pl2_ptr->isSeeker())){
                                if(pl1_ptr->isSeeker() && jammed1!=1){
                                                        *k+=150;
                                                        *game=1;
                                                        return;
                                                        }
                                }
     return;
      
     };
~Gold()
{
cout << "Golden ball destroyed!" << endl;
}
};
/*
class Spell{

public:
Spell(){}
virtual void Cast(Player *,Player *){};
virtual ~Spell(){}

};
class InvalidSpells: public Spell{

public:
InvalidSpells()
{
cout << "I am an InvalidSpell!" << endl;
}
void Cast(Player *pl1_ptr,Player *pl2_ptr){
     return;
     };
~InvalidSpells()
{
cout << "InvalidSpell destroyed!" << endl;
}
};
class PenaltySpells: public Spell{

public:
PenaltySpells()
{
cout << "I am a PenaltySpell!" << endl;
}
void Cast(Player *pl1_ptr,Player *pl2_ptr){
     int x,a,b,c;
     x=rand()%2;
     if(x==0){
              pl1_ptr->getvalues(&a,&b,&c);
              pl1_ptr->setvalues(0,2,c);
              }
     else{
          pl2_ptr->getvalues(&a,&b,&c);
          pl2_ptr->setvalues(0,2,c);
          }
     return;
     };
~PenaltySpells()
{
cout << "PenaltySpell destroyed!" << endl;
}
};
class BonusSpells: public Spell{

public:
BonusSpells()
{
cout << "I am a BonusSpell!" << endl;
}
void Cast(Player *pl1_ptr,Player *pl2_ptr){
     int x,a,b,c;
     x=rand()%2;
     if(x==0){
              pl1_ptr->getvalues(&a,&b,&c);
              pl1_ptr->setvalues(2,0,c);
              }
     else{
          pl2_ptr->getvalues(&a,&b,&c);
          pl2_ptr->setvalues(2,0,c);
          }
     return;
     };
~BonusSpells()
{
cout << "BonusSpell destroyed!" << endl;
}
};
class JamSpells: public Spell{

public:
JamSpells()
{
cout << "I am a JamSpells!" << endl;
}
void Cast(Player *pl1_ptr,Player *pl2_ptr){
     int x;
     x=rand()%2;
     if(x==0){
              pl1_ptr->setvalues(0,0,1);
              }
     else{
          pl2_ptr->setvalues(0,0,1);
          }
              
     return;
     };
~JamSpells()
{
cout << "JamSpell destroyed!" << endl;
}
};

*/
