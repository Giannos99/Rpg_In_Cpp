# include <iostream>
#include <string>
#include "classrpg.h"
# include <ctime>
/*Player * random_Player(void);
Ball * random_Ball(void);
Spell * random_Spell(void);*/
Item * random_Item(void);
Monster * random_Monster(void);
Hero * random_Hero(void);
using namespace std;
void printstatistics(Item *,Spell *,Monster*,Hero*/*,int*/);

int main (void){
    srand(time(0));
    Item *i1ptr=NULL;
    Spell *i2ptr=NULL;
    Monster *i4ptr=NULL;
    Hero *i5ptr=NULL;
    /*Weapon w;
    Armor a;
    Potion p;*/
    for(int i=0;i<20;i++){
    i1ptr=random_Item();
    i5ptr=random_Hero();
    i4ptr=random_Monster();
    printstatistics(i1ptr,i2ptr,i4ptr,i5ptr/*,3*/);
   
    }
      getchar();
    getchar();
}







/*Player *pl1_ptr;
    Player *pl2_ptr;
    Ball *b_ptr;
    Spell *s_ptr;    
    int period=0,k=0,j=0,game=0,N=-1;
    cout<<"Posous gurous 8elete na tre3ei ?(pathste 0 gia na tre3ei mexri telous) "<<endl;
    cin>>N;
    
                               
    do{                      
                
    b_ptr=random_Ball();
    s_ptr=random_Spell();
    pl1_ptr=random_Player();
    pl2_ptr=random_Player();
    if(game==2){
                pl1_ptr->setvalues(0,2,0);
                game=0;
                }
    if(game==3){
                pl2_ptr->setvalues(0,2,0);
                game=0;
                }
    
    s_ptr->Cast(pl1_ptr,pl2_ptr);
    b_ptr->Battle(pl1_ptr,&k,pl2_ptr,&j,&game);
    period++;
    }while(game!=1 && period!=N);
     if(k>j){
             cout<<"Score is "<<k<<"-"<<j<<" Team A won!!!"<<endl;
             }
             else if(k<j){
                  cout<<"Score is "<<k<<"-"<<j<<" Team B won!!!"<<endl;
                  }
                  else
                  cout<<"It's a tie..!"<<endl;*/
                  
