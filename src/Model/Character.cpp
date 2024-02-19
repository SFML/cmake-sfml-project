#include <iostream>
using namespace std;

class Character {

    //private variables
    private:
        int xLoc;
        int yLoc;
        int health;
        int attack;

    public:
        //constructor
        Character(int x, int y, int h, int a) {
            xLoc = x;
            yLoc = y;
            health = h;
            attack = a;
        }
        //setting the information of character
        void setLocation(int newX, int newY) {
            xLoc = newX;
            yLoc = newY;
        }

        void setHealth(int newHealth) {
            health = newHealth;
        }

        void setAttack(int newAttack) {
            attack = newAttack;
        }

        //getting the information of character
        int getLocation() {
            return xLoc, yLoc;
        }

        int getHealth() {
            return health;
        }
        
        int getAttack() {
            return attack;
        }
};