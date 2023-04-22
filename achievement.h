#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include<iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include<string>
#include<fstream>

using namespace std;
struct enemy{
    int damage;
    char sym;
};

void inputdata(vector<int> d);
void doublesame(int health, int phealth);
void toostrong(int health, int boss);
void sameasboss(int health, int boss);
void win10(int winLv);
void fast(double time);
void continuegame(int loginNo);
void lucky(int health,int level);
void check(int health, int phealth, int boss, int winLv, double time);
vector<int> record();
int totalachievement();
int addingyourhealth(char sym, int num, int current);
int getaccuratepath(int levels, enemy** enemylist, char normal[4]);
void initialization(enemy** enemy, int level, char normal[4]);
void prtseparatecharacter();
void prtbrd();
void run(int *health, int *currentlevel, int boss, int level);
string login();
void ranking(int level, string accname, double besttime, int totalachievement);
void prtcharacter(string character);
void prtrank(int level);

#endif