#include <iostream>
using namespace std;

class Farmer : public Character {
public:
    Farmer(int x, int y, int health, int attack) : Character(x, y, h, a) {
        cout << "Farmer constructor" << endl;
        x = 0;
        y = 0;
        health = 100;
        attack = 5;
    }
};
