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
- The monsters in the map are randomly generated in any position.
- The exit in the map are randomly generated in a fixed range of position.
- The attack power of the hero and the monster are in a ranom range.
- The items retrieved after fighting the monster are randomly generated.


2. Data structures for storing game status:
- Integer(Health points, magic level, attack power)
- Vector (list of items that the hero currently has)
- String (item type, descreption etc.), 
- 3 structs (item, position, status) tracking item information, position in the map as well as hero/monster status respectively.

3. Dynamic memory management:
- At the beginning of the game, the vector recording the items the hero has is empty. In the game whenever the hero gets an item, it will be pushed into the vector. Whenever the hero used an item during a fight, the vector will pop the item out. 
- The vector has certain size limit to prevent the hero storing too many items. 
- In the walking mode, the size of the vector is returned to show how many items that the hero currently has.

4. File input/output:
- 

5. Program codes in multiple files:
The program is saved in multiple files. The main cpp files are:
- main.cpp: controls main logic of the game
- preGame.cpp: covers assisting game set-ups such as intialization, saving&loading functions etc.
- inGame.cpp: mainly concerning the walking mode and the fighting mode of the game.
Besides mentioned above, there are many .txt files for UI and file I/O used, as well as Makefile and ultiple header files.


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

