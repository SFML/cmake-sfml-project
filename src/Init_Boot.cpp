#pragma once
#include "Init_Boot.h"

inline void windowInit( sf::RenderWindow& window, unsigned int windowHeightX,
    unsigned int windowWidthX, int fpsX, bool vSyncX, bool keyRepeatX ) {

    //////windowInit Variables/////////
    targetFPS = fpsX;
    vSyncEnabled = vSyncX;
    keyRepeatEnabled = keyRepeatX;
    windowWidth = windowWidthX;
    windowHeight = windowHeightX;
    windowPTR = &window;

    ////////windowInit Instructions////////
    windowPTR->create( sf::VideoMode( { windowWidth, windowHeight } ), "SFML works!" );
    windowPTR->setFramerateLimit( targetFPS );
    windowPTR->setVerticalSyncEnabled( vSyncEnabled );
    windowPTR->setKeyRepeatEnabled( keyRepeatEnabled );
    windowPTR->clear();
    windowPTR->requestFocus();
    //
}
