#include <iostream>
#include "Model/Farmer.cpp"
// will include grid class after noah makes it

using namespace std;

class FarmerController {
private:
    Farmer* farmer; // Pointer to the farmer character
    Grid* gameGrid; // Pointer to the game grid

public:
    FarmerController(Farmer* f, Grid* g) : farmer(f), gameGrid(g) {}

    // Method to listen for player movements and act accordingly
    void onPlayerMove(int newX, int newY) {
        int state = gameGrid->getState(newX, newY); // Get state of the new location

        switch (state) {
            case 1: // Case 1: Farmer can move
                movePlayer(newX, newY);
                break;
            case 2: // Case 2: Farmer must perform a task
                battleAlien();
                break;

            default:
                cout << "Unhandled state: " << state << endl;
        }

        if (gameGrid->isComplete()) {
            cout << "Level Complete!" << endl;
            // Handle level completion logic later
        }
    }
   
};
