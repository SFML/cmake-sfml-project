//
// Created by Viper on 3/31/2026.
//
#pragma once
#include <SFML/Graphics.hpp>

/////////////////////////////
//Variables///
/////////////////////////////
int targetFPS;
bool vSyncEnabled;
bool keyRepeatEnabled;
unsigned int windowWidth;
unsigned int windowHeight;
sf::RenderWindow* windowPTR;

/////////////////////////////
///Protos///
////////////////////////////
void windowInit( sf::RenderWindow& window, unsigned int windowHeightX, unsigned int windowWidthX, int fpsX, bool vSyncX, bool keyRepeatX );

void windowClose( sf::RenderWindow& window );

void windowFPS(sf::RenderWindow& window, int fpsX);

void windowVSync(sf::RenderWindow& window, bool vSyncX);

void windowKeyRepeat(sf::RenderWindow& window, bool keyRepeatX);

///////////////////////////////
///Function Definitions///
///////////////////////////////
void windowInit(sf::RenderWindow &window, int windowHeightX, const int windowWidthX,
    int fpsX, bool vSyncX, bool keyRepeatX) {

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
