#include <iostream>
#include "Character.cpp"
using namespace std;

class Farmer : public Character {
public:
    Farmer(int x, int y, int health, int attack) : Character(x, y, health, attack) {
        cout << "Farmer constructor" << endl;
        x = 0;
        y = 0;
        health = 100;
        attack = 5;
    }
};
