#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Farmer.cpp"
#include "Alien.cpp"

class GameController {
private:
    Farmer player;
    Alien enemy;

public:
    GameController() : player(0, 0, 100, 5), enemy(0, 0, 100, 5) {}

    void movePlayer(int newX, int newY) {
        player.setLocation(newX, newY);
    }

    void battleAlien() {
        //battle between player and alien
        while (player.getHealth() > 0 && enemy.getHealth() > 0) {
            //player attacks
            int playerDamage = rand() % player.getAttack() + 1;
            enemy.setHealth(enemy.getHealth() - playerDamage);
            std::cout << "Player attacks Alien for " << playerDamage << " damage. Alien health: " << enemy.getHealth() << std::endl;

            if (enemy.getHealth() <= 0) {
                std::cout << "Alien defeated!" << std::endl;
                //drop component if alien dies
                //assuming setComponent method in Alien class to set the dropped component
                enemy.dropComponent();
                break;
            }

            //alien attacks
            int alienDamage = rand() % enemy.getAttack() + 1;
            player.setHealth(player.getHealth() - alienDamage);
            std::cout << "Alien attacks Player for " << alienDamage << " damage. Player health: " << player.getHealth() << std::endl;

            if (player.getHealth() <= 0) {
                std::cout << "Player defeated!" << std::endl;
                break;
            }
        }
    }

};
