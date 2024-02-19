#include <iostream>
using namespace std;

class Alien : public Character {
public:
    Alien(int x, int y, int health, int attack) : Character(x, y, h, a) {
        cout << "Alien constructor" << endl;
        x = 0;
        y = 0;
        health = 100;
        attack = 5;
    }
    
};
