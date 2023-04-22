# COMP2113_GP107

-------------------------
NAME: text-based ////// story-telling game with the context of adventure

-------------------------
Group members:

NAME: Lee Sze Yat
UID: 3036065707

NAME: Chu Tsun Hang 
UID: 3036063747


-------------------------
Background settings

Description:  In this game, you will encounter different enemies in different layers.

How to play? 
The game has a total of 10 levels. 
Your strength will be initialized at 1.
In each level, you will face 3 enemies, with each of them representing a different damages or healing. For example, -3 ,  +5 ,  /6  for each enemies respectively. 
You have to choose which enemy to attack and get the strength after calculation. 
Finally, passing all layers will come across a boss with a certain health, only if you strength is higher than the boss can you beat it. 
If you successfully kill the boss, then you will pass to next level, otherwise, stuck in the same level and replay.

At level 1, you need to complete 3 layers, 4 layers for level 2, and so on. Finally, you will face a final boss in each level. 

You can choose to save and quit the game in each level.

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
#include <fstream>: manipulation of files (hero status saving and loading)
#include <string>: string manipulation
#include <iomanip>: setw(), setfill(), etc. (UI design)
#include <vector>: vector manipulation (dynamic array management)
#include <cstdlib>: rand(), srand() for generating randomness 
#include <ctime>: time(0) to set random seed


-------------------------
Compilation and execution instructions:
Step 1: Aftering cloning the URL, simply 'make main' in the terminal and execute the main to start the game. 
Step 2: Follow the game instructions and enjoy the game!

