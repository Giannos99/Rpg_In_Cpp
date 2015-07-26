# include <iostream>
#include "classrpg.h"
# include <ctime>
#include <string>

using namespace std;

Item * random_Item(){
    int x;
    x=rand()%3;
    if(x==0)
            return new Weapon;
    else if(x==1)
            return new Armor;
    else
            return new Potion;
            
    }
Hero * random_Hero(){
    int x;
    x=rand()%3;
    if(x==0)
            return new Warrior;
    else if(x==1)
            return new Sorcerer;
    else
            return new Paladin;
            
    }
Monster * random_Monster(){
    int x;
    x=rand()%3;
    if(x==0)
            return new Dragon;
    else if(x==1)
            return new Exoskeleton;
    else
            return new Spirit;
            
}
void printstatistics(Item *iptr,Spell *sptr,Monster *mptr,Hero *hptr/*,int j*/){
   /*  if(j==0)
             return;*/
     if(/*j==1 && */iptr!=NULL){
              if(iptr->isWeapon()==1){
                                      cout<<"Weapons' name= "<<iptr->get_name()<<endl<<"value= "<<iptr->get_value()<<endl<<"required level= "<<iptr->get_levelrequired()<<endl;
                                      cout<<"damage= "<<iptr->get_damage()<<endl;
                                      if(iptr->get_type()==1)
                                      cout<<"type= two-handed"<<endl;
                                      else 
                                      cout<<"type= one-handed"<<endl;
                                      }
              if(iptr->isArmor()==1){
                                     cout<<"Armors' name= "<<iptr->get_name()<<endl<<"value= "<<iptr->get_value()<<endl<<"required level= "<<iptr->get_levelrequired()<<endl;
                                     cout<<"armors' defence= "<<iptr->get_armor()<<endl;
                                     }
              if(iptr->isPotion()==1){
                                      cout<<"Potions' name= "<<iptr->get_name()<<endl<<"value= "<<iptr->get_value()<<endl<<"required level= "<<iptr->get_levelrequired()<<endl;
                                      cout<<"potions' bonus= "<<iptr->get_bonus()<<endl<<"potions' damage= "<<iptr->get_penalty()<<endl;
                                      }
              }
     if(/*j==2 && */sptr!=NULL){
              if(sptr->isIceSpell()==1){
                                        cout<<"Spells' name= "<<sptr->get_name()<<endl<<"value= "<<sptr->get_value()<<endl<<"required level= "<<sptr->get_levelrequired()<<endl;
                                        cout<<"damage= "<<sptr->get_damage()<<endl<<"manacost= "<<sptr->get_manacost()<<endl<<"It has disabling effects to opponents"<<endl;
                                        }
              if(sptr->isFireSpell()==1){
                                        cout<<"Spells' name= "<<sptr->get_name()<<endl<<"value= "<<sptr->get_value()<<endl<<"required level= "<<sptr->get_levelrequired()<<endl;
                                        cout<<"damage= "<<sptr->get_damage()<<endl<<"manacost= "<<sptr->get_manacost()<<endl<<"It decreases opponents defence"<<endl;
                                        }
              if(sptr->isLightingSpell()==1){
                                             cout<<"Spells' name= "<<sptr->get_name()<<endl<<"value= "<<sptr->get_value()<<endl<<"required level= "<<sptr->get_levelrequired()<<endl;
                                             cout<<"damage= "<<sptr->get_damage()<<endl<<"manacost= "<<sptr->get_manacost()<<endl<<"It decreases opponents' chance to avoid attacks"<<endl;
                                             }
              }
     if(/*j==3 && */hptr!=NULL){
              
                                   cout<<"Heros' name= "<<hptr->get_name()<<endl<<"Heros' health= "<<hptr->get_healthpower()<<endl<<"Heros' level= "<<hptr->get_level()<<endl;
                                   if(hptr->isWarrior()==1){
                                                           cout<<"Heros' type= Warrior"<<endl<<"Heros' mana pool= "<<hptr->get_magicpower()<<endl<<"Heros' strength= "<<hptr->get_strength()<<endl;
                                                           cout<<"Heros' dexterity= "<<hptr->get_dexterity()<<endl<<"Heros' agility = "<<hptr->get_agility()<<endl<<"Heros' experience= "<<hptr->get_experience()<<endl;
                                                           cout<<"Heros' money= "<<hptr->get_money()<<endl;
                                                           }
                                   if(hptr->isSorcerer()==1){
                                                            cout<<"Heros' type= Sorcerer"<<endl<<"Heros' mana pool= "<<hptr->get_magicpower()<<endl<<"Heros' strength= "<<hptr->get_strength()<<endl;
                                                            cout<<"Heros' dexterity= "<<hptr->get_dexterity()<<endl<<"Heros' agility = "<<hptr->get_agility()<<endl<<"Heros' experience= "<<hptr->get_experience()<<endl;
                                                            cout<<"Heros' money= "<<hptr->get_money()<<endl;
                                                            }
                                   if(hptr->isPaladin()==1){
                                                           cout<<"Heros' type= Paladin"<<endl<<"Heros' mana pool= "<<hptr->get_magicpower()<<endl<<"Heros' strength= "<<hptr->get_strength()<<endl;
                                                           cout<<"Heros' dexterity= "<<hptr->get_dexterity()<<endl<<"Heros' agility = "<<hptr->get_agility()<<endl<<"Heros' experience= "<<hptr->get_experience()<<endl;
                                                           cout<<"Heros' money= "<<hptr->get_money()<<endl;
                                                           }
              }
     if(/*j==4 && */mptr!=NULL){
              
                                        if(mptr->isDragon()==1){ 
                                                                cout<<"Monster is Dragon"<<endl<<"Monsters' health= "<<mptr->get_healthpower()<<endl<<"Monsters' level= "<<mptr->get_level()<<endl;
                                                                cout<<"Monsters' damage= "<<mptr->get_mdamage()<<endl<<"Monsters' defence= "<<mptr->get_mdefence()<<endl;
                                                                if(mptr->get_mchance()==1)
                                                                cout<<"Monsters' chance to avoid an attack is low"<<endl;
                                                                else
                                                                cout<<"Monsters' chance to avoid an attack is high"<<endl;
                                                                }
                                        if(mptr->isExoskeleton()==1){
                                                                     cout<<"Monster is Exoskeleton"<<endl<<"Monsters' health= "<<mptr->get_healthpower()<<endl<<"Monsters' level= "<<mptr->get_level()<<endl;
                                                                     cout<<"Monsters' damage= "<<mptr->get_mdamage()<<endl<<"Monsters' defence= "<<mptr->get_mdefence()<<endl;
                                                                     if(mptr->get_mchance()==1)
                                                                     cout<<"Monsters' chance to avoid an attack is low"<<endl;
                                                                     else
                                                                     cout<<"Monsters' chance to avoid an attack is high"<<endl;
                                                                     }
                                        if(mptr->isSpirit()==1){
                                                                cout<<"Monster is Spirit"<<endl<<"Monsters' health= "<<mptr->get_healthpower()<<endl<<"Monsters' level= "<<mptr->get_level()<<endl;
                                                                cout<<"Monsters' damage= "<<mptr->get_mdamage()<<endl<<"Monsters' defence= "<<mptr->get_mdefence()<<endl;
                                                                if(mptr->get_mchance()==1)
                                                                cout<<"Monsters' chance to avoid an attack is low"<<endl;
                                                                else
                                                                cout<<"Monsters' chance to avoid an attack is high"<<endl;
                                                                }
              }
     

}
/*Player * random_Player(){
    int x;
    x=rand()%4;
    if(x==0)
            return new Chaser;
    else if(x==1)
            return new Beater;
    else if(x==2)
            return new Keeper;
    else
            return new Seeker;
            
    }
Ball * random_Ball(){
    int x;
    x=rand()%3;
    if(x==0)
            return new Red;
    else if(x==1)
            return new Black;
    else 
            return new Gold;
            
    }
Spell * random_Spell(){
      int x;
      x=rand()%4;
      if(x==0)
            return new InvalidSpells;
      else if(x==1)
            return new PenaltySpells;
      else if(x==2)
            return new BonusSpells;
      else
            return new JamSpells;
      }
      */
string random_swordname(void){
    string name;
    int r;
    r=(rand()%8+2)+rand()%2;
    if(r==2)
            return name="Calcite Staff";
    else if(r==3)
         return name="Wizard Sword";
    else if(r==4)
         return name="Double-Edge";
    else if(r==5)
         return name="Razzmatazz";
    else if(r==6)
         return name="Crystal Sword";
    else if(r==7)
         return name="Bizarre Staff";
    else if(r==8)
         return name="Basilisk Steel";
    else if(r==9)
         return name="Stunning Steel";
    else 
         return name="Deathbringer";

}
string random_armorname(void){
    string name;
    int r;
    r=(rand()%8+2)+rand()%2;
    if(r==2)
            return name="Golem Shield";
    else if(r==3)
         return name="Rescue Shield";
    else if(r==4)
         return name="Shield of Hope";
    else if(r==5)
         return name="Phoenix Shield";
    else if(r==6)
         return name="Blessed Shield";
    else if(r==7)
         return name="Glorious Shield";
    else if(r==8)
         return name="Magic Shield";
    else if(r==9)
         return name="Pearl Shield";
    else 
         return name="Platinum Shield";

}

string random_potionname(void){
    string name;
    int r;
    r=(rand()%8+2)+rand()%2;
    if(r==2)
            return name="Hi-Potion";
    else if(r==3)
         return name="Holy Water";
    else if(r==4)
         return name="Dream Powder";
    else if(r==5)
         return name="Blessed Gem";
    else if(r==6)
         return name="Amulet";
    else if(r==7)
         return name="Door to Tomorrow";
    else if(r==8)
         return name="Underdog's Secret";
    else if(r==9)
         return name="Winning Formula";
    else 
         return name="Elixir";

}
string random_spellname(void){
    string name;
    int r;
    r=(rand()%8+2)+rand()%2;
    if(r==2)
            return name="Salamander’s Blade";
    else if(r==3)
         return name="Sinkhole";
    else if(r==4)
         return name="Endless Depth";
    else if(r==5)
         return name="Kharmic Intent";
    else if(r==6)
         return name="Channel Energy";
    else if(r==7)
         return name="Demon’s Rage";
    else if(r==8)
         return name="Judgment";
    else if(r==9)
         return name="Wrath of God";
    else 
         return name="Gale";

}
string random_heroname(void){
    string name;
    int r;
    r=(rand()%8+2)+rand()%2;
    if(r==2)
            return name="Heironeous";
    else if(r==3)
         return name="Olidammara";
    else if(r==4)
         return name="Roykyn";
    else if(r==5)
         return name="St. Cuthbert";
    else if(r==6)
         return name="Urdlen";
    else if(r==7)
         return name="Jubilex";
    else if(r==8)
         return name="Shekinester";
    else if(r==9)
         return name="Grankhul";
    else 
         return name="Squerrik";

}
int random11_12(void){
    
    int r;
     
    r=(rand()%2)+11;
   return r;
}
int random600_1000(void){
    
    int r;
     
    r=(rand()%4+6)+rand()%2;;
   return r*100;
}
int random1_3(void){
    
    int r;
     
    r=(rand()%3+1);
   return r;
}

