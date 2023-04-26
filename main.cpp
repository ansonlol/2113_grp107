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

using namespace std;

/*
v6
1) for level 1, a total of 3 layers
2) create a accurate path with lenght 3, with the final value larger than 1(the boss value)
3) create a random list of unrelated enemies 
4) for each layer, 1 is from the accurate path, and other two is random
5) user type 1,2,3 to choose the path, 
    if the symbol is '/' it gets the floor of the quotient
6) print the current health of user
7) if the final health is less than the boss -> gg else, win move on to next level


remark
maybe make a story setting
create a name for the game;
*/




// adding your current health to the enemy's
// return the health after attack
int addingyourhealth(char sym, int num, int current){
        switch (sym){
            case '+':
                current+=num;
                return current;
            case '-':
                current-=num;
                return current;
            case '*':
                current*=num;
                return current;
            case '/':
                current/=num;
                return current;
        }
        return current;
}

// produce an accurate path that guarantee to be positive and larger than boss
// store the path into the correct enemylist
// return the health of the boss
int getaccuratepath(int levels, enemy** enemylist, char normal[4]){
    int* arr = new int[levels];

    char* symarr = new char[levels];
    
    srand(time(nullptr));
    int temp=1;
    while(temp <= 1){
        temp=1;
        int layer_of_all_divide = (levels-1)/2;
        for(int i=0; i<levels-layer_of_all_divide; i++){
            int symbol = rand()%3;
            int num = rand()%9+1;
            temp = addingyourhealth(normal[symbol], num, temp);
            
            arr[i] = num;
            symarr[i] = normal[symbol];
        }
        
        for(int i=levels-layer_of_all_divide; i<levels; i++){
            
            int num = rand()%9+1;
            temp = addingyourhealth('/', num, temp);
            
            arr[i] = num;
            symarr[i] = '/';
        }

    }

    for(int i=0; i<levels; i++){
        enemy* e = new enemy;
        e->damage = arr[i];
        e->sym = symarr[i];
        enemylist[i] = e;
    }

    delete[] arr;
    delete[] symarr;
    return temp;

}

// generate a board with 3 * n levels, depends on your level
// write the the board into enemy.txt file
// write the correct path to the correctpath.txt file
void initialization(enemy** enemy, int level, char normal[4]){

    ofstream outfile("enemy.txt");
    ofstream outf("correctpath.txt");
    srand(time(nullptr));
    int level_of_all_divide = (level-1)/2;
    for(int i=0; i<level-level_of_all_divide; i++){

        int positionofcorrrect = rand()%3;
        
           
        for(int j=0; j<3; j++){
            
            int symbol = rand()%4;
            int num = rand()%9+1;

            if(j == positionofcorrrect){
                outfile << enemy[i]->sym << enemy[i]->damage<<" ";
                outf << enemy[i]->sym << enemy[i]->damage<<"\n";
            }
            else{
                outfile << normal[symbol]<<num<<" ";
            }

        }
        outfile<<"\n";

    }
    for(int i=level-level_of_all_divide; i<level; i++){
        int positionofcorrrect = rand()%3;
           
        for(int j=0; j<3; j++){
            
            int num = rand()%9+1;

            if(j == positionofcorrrect){
                outfile << enemy[i]->sym << enemy[i]->damage<<" ";
                outf << enemy[i]->sym << enemy[i]->damage<<"\n";
            }
            else{
                outfile << '/' <<num<<" ";
            }

        }
        outfile<<"\n";
    }
    outfile.close();
    outf.close();
}
void prtseparatecharacter() {
    string ar[3];
    string line;
    int flag = 0, i = 0, j = 0;
    for (int a = 0; a < 3; a++) {
        ar[a] = to_string(rand() % 3 + 1);
    }
    string** arr = new string*[3];
    for (int i = 0; i < 3; i++) {
        arr[i] = new string[12];
        for (int j = 0; j < 12; j++) {
            arr[i][j] = "";
        }
    }
    while (i < 3) {
        ifstream infile("littleguy.txt");
        while (getline(infile, line)) {
            if (flag == 0 && line == ar[i]) {
                flag++;
            } else if (flag == 1 && line == ar[i]) {
                i++;
                j = 0;
                flag = 0;
                infile.close();
                break;
            } else if (flag == 1 && j < 12) {
                arr[i][j] = line;
                j++;
            }
        }
        infile.close();
    }
    for (int k = 0; k < 12; k++) {
        for (int l = 0; l < 3; l++) {
            cout << arr[l][k];
        }
        cout << endl;
    }
    delete[] arr;
}

// print the board obtain from the enemy.txt, 
// display the all the levels
void prtbrd(){

    ifstream infile("enemy.txt");
    
    string line, split[3];
    while(getline(infile, line)){
        cout << "        ";
        split[0] = line.substr(0, 2);
        split[1] = line.substr(3, 2);
        split[2] = line.substr(6, 2);
        for(int i=0; i<3; i++){
            cout << split[i] << "              ";
        }
        cout << endl;
        break;
    }
    infile.close();
}
void prtcharacter(string character){

    ifstream infile("num.txt");
    string line;
    int flag=0;
    while(getline(infile, line)){
        if(flag==0 && line==character)
            flag++;
        else if(flag==1 && line==character)
            break;
        else if(flag==1)
            cout << line <<endl;

    }
    infile.close();

}


// players can choose which enemy they want to attack by typing 1,2,3
// after they choose an enemy, their health will be adjusted
// loop the above before they have choose an enemy in each level
void run(int *health, int *currentlevel, int boss, int level){

    ifstream infile("enemy.txt");
    ofstream outfile("temp.txt");
    string line;

    int input, x, flag=0;
    int thealth = *health; 
    //cout << thealth << endl << endl;

    while(getline(infile, line)){

        if(flag==0){
            flag++;
            cout <<"       (1)              (2)              (3)"<<endl;
            cout <<"Current layer is "<<*currentlevel<<" out of "<<level<<" layers"<<endl;
            cout <<"Your health need to be larger than (the boss): "<<boss<<endl;
            cout << "Choose the enemy you want to attack 1, 2, or 3 (please input \"1\", \"2\", \"3\")"<<endl;
            cin >> input;
            switch(input){
                case 1:
                    x = line[1]-'0';
                    *health = addingyourhealth(line[0], x, thealth);
                    break;
                case 2:
                    x = line[4]-'0';
                    *health = addingyourhealth(line[3], x, thealth);
                    break;
                case 3:
                    x = line[7]-'0';
                    *health = addingyourhealth(line[6], x, thealth);
                    break;
                default:
                    cout << "Invalid input";
                    x=-1;
                    break;

            }
            cout <<"-----------------------------------------------------------------------------------"<<endl;
            cout << "Your health is now " ;
            cout << *health << endl;
            
        }
        else{
            outfile << line<<endl;
        }   
    }
    infile.close();
    outfile.close();
    remove("enemy.txt");
    rename("temp.txt", "enemy.txt");
    
}

string login(){
    int input;
    string accname, pw;
    
    ifstream infile("accountinfo.txt");
    string line;
    vector<string> acclist, pwlist;
    if(infile.is_open()){
        while(getline(infile, line)){
            int pos = line.find(" ");
            accname = line.substr(0, pos);
            pw = line.substr(pos+1);
            acclist.push_back(accname);
            pwlist.push_back(pw);
        }
    }
    infile.close();
    bool entireprocess = false;
    while(!entireprocess){    

            cout <<"If you are a new user, input 1"<<endl;
            cout <<"If you are a current user, input 2"<<endl;
            cin >>  input;

        if(input==1){

            bool create = false;
            while(!create){
                cout << "Please create your own account name (make sure it is unique):"<<endl;
                cin >> accname;
                bool unique = true;
                for(int i=0; i<acclist.size(); i++){
                    if(acclist[i] == accname){
                        cout << "The accout name has already been used, please input again"<<endl;
                        unique = false;
                    }
                }
                if(unique){
                    cout << "Create a password for you account" <<endl;
                    cin >> pw;
                    ofstream outfile("accountinfo.txt", ios::app);
                    outfile << accname << " " << pw << '\n';
                    cout << "Successful!"<<endl;
                    cout <<"-----------------------------------------------------------------------------------"<<endl;
        
                    outfile.close();
                    entireprocess=true;
                    create = true;
                }
                
            }
            
        }

        if(input==2){
            bool login = false;
            while(!login){
                cout << "Please type your own account name:"<<endl;
                cin >> accname;
                cout << "Please input your password" <<endl;
                cin >> pw;
                
                for(int i=0; i<acclist.size(); i++){
                    if(acclist[i] == accname && pwlist[i] == pw){
                        cout << "Login Successful"<<endl;
                        cout <<"-----------------------------------------------------------------------------------"<<endl;
        
                        login = true;
                        entireprocess=true;
                        break;
                    }
                }
                if(!login){
                    cout << "Incorrect account name or password, please try again"<<endl;
                }
            }   
        }
    }
    return accname;
}

void ranking(int level, string accname, double besttime, int totalachievement){
    string filee = "ranking " + to_string(level);
    ifstream infile(filee);
    string line;
    string str[4];
    map<double,pair<string,string>> match;

    if(infile.is_open()){
        getline(infile, line);
        while(getline(infile, line)){
            stringstream ss(line);
            int i = 0;
            while (getline(ss, str[i], ';')) {
                i++;
            }
            double time = stod(str[2]);
            match[time]={str[1],str[3]};
        }
        infile.close();
    }
    ofstream oufile(filee);
    oufile << "Ranking ; AccountName ; Time ; Achievement\n";
    match[besttime] = {accname,to_string(totalachievement)};
    int No = 1;
    for (const auto& e : match) {
        oufile << setw(3) << setfill('0') << No <<";"<< e.second.first << ";" << e.first << ";" << e.second.second << "\n";
        No++;
    }
    oufile.close();
}

void prtrank(int level){
    string filee = "ranking " + to_string(level);
    ifstream ifile(filee);
    string line;
    if(ifile.is_open()){
        while(getline(ifile,line)){
            cout << line << endl;
        }
    }
    else{
        cout << "Ranking of the level"<<level<< " does not exist" << endl;
    }
}


int main(){

    int yourheath=1, pasued=0, level=3, phealth = 0,lasttotal=0;
    double besttime=100000;
    string accname, line, input, data;
    char normal[4]={'/','-','+', '*'};
    vector<int> acdata;
    cout << endl << "WELCOME TO Tower of Valor" << endl << endl;
    //login part
    accname = login();
    ifstream infile(accname);
    if(infile.is_open()){
        getline(infile, line);
        int pos = line.find(" ");
        string slevel = line.substr(pos+1);
        level = stoi(slevel);
        cout << "Your current level is "<<level-2<<endl;
        cout << "The game will resume"<<endl;
        
        while(getline(infile, data, ' ')){
            acdata.push_back(stoi(data));
        }
        
        
    }
    else{
        for(int i = 0 ; i<8 ; i++){
            acdata.push_back(0);
        }
        cout << "It is your first time to play"<<endl;
        cout << "Your current level is 1" <<endl;
        level = 3;
    }
    inputdata(acdata);
    continuegame(acdata[0]);
    acdata[0]++;
    inputdata(acdata);

    cout << "Press any key to start fighting and revenging!!!"<<endl;
        cin >> input;
        cout <<"-----------------------------------------------------------------------------------"<<endl;

    infile.close();
    
    while(level<13){
        prtcharacter("level");
        prtcharacter(to_string(level-2));
        cout << "Welcome to the battle, beat the boss to rescue your country !!!"<<endl;
        cout << "Are you ready ?? (press 'p' to pause and save the game / press 's' to show the ranking and save the game / press any others to start)"<<endl;
        
        cin >> input;

        cout <<"-----------------------------------------------------------------------------------"<<endl;
        
        if(input == "p"){
            pasued = 1;
            break;
        }else if(input == "s"){
            string lev;
            cout<<"Which ranking you would like to be shown? (number of level)"<<endl;
            pasued = 1;
            cin >> lev;
            int le = stoi(lev);
            prtrank(le);
            break;
        }
        
        enemy* correctenemylist[13];

        int boss = getaccuratepath(level, correctenemylist, normal)-1;
        cout<<"You need to beat the boss with "<<boss <<" health in the final round !!!"<<endl;
        prtcharacter("boss");
        cout <<"-----------------------------------------------------------------------------------"<<endl;

        cout << "Your health is now " << yourheath <<endl;
        cout << "In this level, you have a total of "<<level<<" layers"<<endl;
        cout << "Press any key to start fighting !!!"<<endl;
        cin >> input;
        cout <<"-----------------------------------------------------------------------------------"<<endl;

        
        /*
        for(int i =0; i<level; i++){
            cout <<correctenemylist[i]->sym << correctenemylist[i]->damage<<endl;
        }
        */
        auto start = chrono::high_resolution_clock::now();
        initialization(correctenemylist, level, normal);
        int currentlevel = 1;
        for(int i=0; i<level; i++){
            prtbrd();
            prtseparatecharacter();
            run(&yourheath, &currentlevel, boss, level);
            currentlevel++;
        }
        
        auto end = chrono::high_resolution_clock::now();
        if(yourheath > boss){
            cout << "Excellence !! finish level " << level-2 << endl ;
            chrono::duration<double> elapsed = end - start;
            if(elapsed.count()<besttime){
                besttime = elapsed.count()/(level-3);
            }
            cout << " time: " << elapsed.count() << " seconds."<<endl;
            check(yourheath, phealth, boss, level, elapsed.count());
            cout<<endl;
            
            ranking(level-2,accname,elapsed.count(),totalachievement()-lasttotal);
            lasttotal = totalachievement();
        }
        else{
            sameasboss(yourheath,boss);
            cout << "GGGGG try again !!"<<endl <<endl;
            level--;
        }
        
        level++;
        yourheath=1;
    }
    if(level == 13){
        cout << "Congrats my warrior! You have finished all levels! The enemy is defeated and your country is saved forever!"<<endl;
        int k;
        cout << "Input 1 if you want to save the progress, Input 2 if you want to restart the game: ";
        cin >> k;
        if(k==2){
            level = 3;
            pasued = 1;
        }
    }
    if(pasued){
        
        ofstream oufile(accname);
        
        oufile << "Level: " << level <<endl;
        //oufile << loginNo << endl;
        acdata = record();
        for(int i = 0 ; i<8 ; i++){
            oufile << acdata[i] << " ";
        }
        oufile.close();
    }
    return 0;
}
