# COMP2113_GP107

-------------------------
NAME: Tower of Valor 
TYPE: Text-based Game 
Targeting Audience: Kindergarten and Primary school students
AIM: Provide a leisure and interesting platform for students to practise basic mathematics

-------------------------
Group members:

NAME: Lee Sze Yat
UID: 3036065707

NAME: Chu Tsun Hang 
UID: 3036063747


-------------------------
Game Background Setting:
You are the prince of a once-prosperous kingdom, but it is now under attack by a powerful enemy force. As your people suffer and your kingdom falls into chaos, you find yourself trapped at the bottom of a towering fortress. The only way to save your people is to fight your way through each floor of the fortress, defeating the enemies that stand in your way and gaining strength along the way.

Each floor presents new challenges and enemies, from simple foot soldiers to powerful bosses. As you defeat each foe, you will gain experience and power, allowing you to grow stronger and more capable. But the road ahead is long and perilous, and the fate of your kingdom hangs in the balance.

Can you rise to the challenge and overcome the enemy forces? Only by defeating the final boss at the top of the tower can you hope to rescue your people and restore your kingdom to its former glory.

How to play? 
The game has a total of 10 levels. 
Your strength will be initialized at 1.
In each level, you will face 3 enemies, with each of them representing a different damages or healing. For example, -3 ,  +5 ,  /6  for each enemies respectively. 
You have to choose which enemy to attack and get the strength after calculation. 
Finally, passing all layers will come across a boss with a certain health, only if you strength is higher than the boss can you beat it. 
If you successfully kill the boss, then you will pass to next level, otherwise, stuck in the same level and replay.
It is guaguaranteed that there exist at least one path that result in a health larger than the boss.

At level 1, you need to complete 3 layers, 4 layers for level 2, and so on. Finally, you will face a final boss in each level. 

You can choose to save and quit the game in each level.

After finish each level, your time taken to complete the level will be recorded and compared to other users
You display the ranking in each level

Meanwhile, we have 7 extra challenges/achievements prepared for you
1)REAL FANS: login the game for the second time
2)STRONGGGG: your health is double, triple or larger than the boss
3)TIE: your health is same as the boss
4)CLEAR: win consequently 10 levels
5)FAST: finish the level within 5 seconds
6)UNCHANGE: the health is same as the previous level you achieved
7)LUCKY: your health is same as the level and you win


-------------------------
Features:

The program encompass the following coding elements:

1. Generation of random game sets or events:
- The 3 enemies on each layers are randomly generated 
- The damages or healing (the mathematical symbol and integer) of enemies are randomly generated
- The strength of boss for each levels is generated randomly according to the damages or healing in the layers in the level

2. Data structures for storing game status:
- Integer (yourheath, level, totalachievement)
- Double (time)
- Vector (list that contain the achievements of the player)
- String (accountName,  etc.) 
- structs (enemy) storing the mathematic symbol and the integer ranging from 1-9

3. Dynamic memory management:
- In the getaccuratepath function, we use 2 dynmaic array to store the array of mathemattical symbol and damges.
- After writing the array into the files, the array will be deleted.

4. File input/output:
- input "littleguy.txt" for printing the enemies of each layers
- input and output "enemy.txt" for the random data of 3 enemies of each layers
- input "num.txt" for printing "level" and integer 0-9 in ASCII art way
- input and output "accountinfo.txt" for the login of current players and sign in of new player
- input and output "ranking (level)" to record the players' accountname, time to finish the level and the achievement has reached for the level, and show the ranking of the level
- input and output "(accountname)" to save the player's data for resuming the game

5. Program codes in multiple files:
The program is saved in multiple files. The main cpp files are:
- main.cpp: controls main logic of the game
- achievement.cpp: record and check whether the conditions of achievement are met


-------------------------
C/C++ libraries:
All the libraries used are mentioned in class, listed as follows:
#include <iostream>
#include <fstream>: manipulation of files (users' accounts storage)
#include <string>: string manipulation
#include <iomanip>: setw(), setfill()
#include <vector>: 
#include <cstdlib>: rand(), srand()
#include <ctime>: time(0) to set random seed


-------------------------
Compilation and execution instructions:
- Type 'make main' in the terminal
- Type ./main
- Enjoy the game 

