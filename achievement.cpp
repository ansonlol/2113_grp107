#include<iostream>
#include <cstdlib> // for rand() and srand()
#include <chrono>   // for time()
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include <iomanip>
#include "achievement.h"

vector<int> data0;

void inputdata(vector<int> d){
    data0 = d;
    data0.assign(d.begin(), d.end());
}

//(1)the health is same for two times
void doublesame(int health, int phealth){
    if(health==phealth){
        cout<<"Get \"UNCHANGE\" #"<< data0[1] <<" (you have the same health as your last level)"<<endl;
        data0[1]+=1;
    }
}

//(2)the health is double/triple of the boss
void toostrong(int health, int boss){
    if(health>=boss*2*(data0[2]+1)){
        cout<<"Get \"STRONGGGG\" #"<< data0[2] <<" (you have the health that is " << 2*(data0[2]+1) << "times of boss)"<<endl;
        data0[2]+=1;
    }
}

//(3)the health is same as the boss
void sameasboss(int health, int boss){
    if(health==boss){
        cout<<"Get \"TIE\" #"<< data0[3] <<" (you have the same health as the boss, but you still lose Oopsss)"<<endl;
        data0[3]+=1;
    }
}

//(4)win consequently 10 level
void win10(int winLv){
    if(winLv==10*(data0[4]+1)+2){
        cout<<"Get \"CLEAR "<< 10*(data0[4]+1) <<" LEVELS\""<<endl;
        data0[4]+=1;
    }
}

//(5)win time <= 5sec
void fast(double time,int level){
    if(time<=(level+3-data0[5])){
        cout<<"Get \"FAST\" #"<< data0[5] <<" (you have use less than "<< ((level+3-data0[5])/level) <<" second for each layers)"<<endl;
        data0[5]+=1;
    }
}

//(6)continue the game for two time (login)
void continuegame(int loginNo){
    int login[5] = {1, 3, 5, 10, 20};
    if(loginNo==login[data0[6]]){
        cout<<"Get \"REAL FANS\" (you have resumed the game for "<< loginNo <<" times)"<<endl;
        data0[6]+=1;
    }
}

//(7)win and the health is same as level
void lucky(int health,int level){
    if((level-2)==health){
        cout<<"GET \"LUCKY\" #"<< data0[7] <<" (you have the same health as the level, but you still clear the level)"<<endl;
        data0[7]+=1;
    }
}

//(8)

//checking achievement
void check(int health, int phealth, int boss, int level, double time){
    doublesame(health, phealth);
    toostrong(health, boss);
    sameasboss(health, boss);
    win10(level);
    fast(time, level);
    lucky(health,level);
}

vector<int> record(){
    return data0;
}

int totalachievement(){
    int total=0;
    for(int i = 1 ; i<data0.size() ; i++){
        total+=data0[i];
    }
    return total;
}
