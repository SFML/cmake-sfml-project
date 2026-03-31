//
// Created by Viper on 3/31/2026.
//

#ifndef TESTSFML1_INIT_BOOT_H
#define TESTSFML1_INIT_BOOT_H

#include <SFML/Graphics.hpp>

const int targetFPS = 60;
const bool vSyncEnabled = false;
const bool keyRepeatEnabled = false;
inline sf::RenderWindow* windowPTR{};

inline void windowInit( sf::RenderWindow& window ) {
    windowPTR = &window;
    window.create( sf::VideoMode( { 1024, 768 } ), "SFML works!" );
    window.setFramerateLimit( targetFPS );
    window.setVerticalSyncEnabled( vSyncEnabled );
    window.setKeyRepeatEnabled( keyRepeatEnabled );
    window.clear();
    window.requestFocus();
}

inline void windowClose( sf::RenderWindow& window ) {
    window.close();
}

inline void windowFPS(sf::RenderWindow& window, int fpsX) {
    window.setFramerateLimit( fpsX );
}

inline void windowVSync(sf::RenderWindow& window, bool vSyncX) {
    window.setVerticalSyncEnabled( vSyncX );
}

inline void windowKeyRepeat(sf::RenderWindow& window, bool keyRepeatX) {
    window.setKeyRepeatEnabled( keyRepeatX );
}

#endif //TESTSFML1_INIT_BOOT_H
