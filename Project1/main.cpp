
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "Game.h" 
#include "Game.h" 
#include "Arena.h" 
#include "Arena.h" 
#include "Previous.h" 
#include "Previous.h" 
#include "Player.h" 
#include "Player.h" 
#include "Robot.h" 
#include "Robot.h" 
#include "globals.h" 
#include "globals.h" 

int main()
{
    // Initialize the random number generator.  (You don't need to
    // understand how this works.)
    srand(static_cast<unsigned int>(time(0)));

    // Create a game
    // Use this instead to create a mini-game:   Game g(3, 3, 2);
    Game g(5, 5, 2);

    // Play the game
    g.play();
}