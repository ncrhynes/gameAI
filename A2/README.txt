-------------------------------------------------------------------------------
COMP 4303 - Assignment 2
-------------------------------------------------------------------------------

Submission:

For this assignment you will submit one file: src/TronAI.cpp, as you should
only be modifying this file for this assignment. If you submit any additional
files, this will result in a loss of marks.

YOU MUST INCLUDE THE FOLLOWING INFO IN A COMMENT AT THE TOP OF the file:
- ALL students' full names, cs usernames, and student numbers
- If you did not get a specific feature to work please explain what you tried,
  to do to get it to work, and partial marks may be given for effort.

-------------------------------------------------------------------------------
Program Specification
-------------------------------------------------------------------------------

In this assignment you will be writing an AI for the game of TRON. You only
need to modify the TronAI_Student::getAction function within src/TronAI.cpp

Yor function return an unsigned integer (size_t) corresponding to the index
of the action to be taken in the m_directions vector defined in TronLevel.h

// Legal Directions                     0=UP     1=DOWN  2=LEFT   3=RIGHT
std::vector<Direction> m_directions = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };;

Directions are stored as a struct with an x and y variable denoting the
change in x and y change if that direction is chosen to move. For example,
moving right is a shift of 1 in the x-direction and 0 in the y-direction,
so the resulting Direction is {1, 0}. In this environment y increases in
the downward direction, so the Down Direction will be {0, 1}. Example
usage of Direction can be seen in the example AIs in TronAI.cpp 
  
Misc:
- The 'R' key restarts the level
- The 'ESC' key closes the game

Configuration File:

The configuration file will specify the level size, as well as the properties
of each of the players in the game. The first line of the file has the
following format, while the Player line syntax follows afterward.

W H S
- This line defines the size of the Tron playing area
  Game Width       W        int
  Game Height      H        int
  Cell Size        S        int (measured in screen pixels)
  
Player Specification:
Player AI X Y R GB
  AI Name           AI         string (hard coded in TronLevel.cpp)
  Starting Cell     X Y        int
  Cell Color        FR,FG,FB   int,int,int (from 0-255)  