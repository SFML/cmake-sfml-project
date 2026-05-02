//
// Created by Viper on 3/31/2026.
//
#pragma once
#include <SFML/Graphics.hpp>

/////////////////////////////
//Variables///
/////////////////////////////
inline int targetFPS;
inline bool vSyncEnabled;
inline bool keyRepeatEnabled;
inline unsigned int windowWidth;
inline unsigned int windowHeight;
inline sf::RenderWindow* windowPTR;

/////////////////////////////
///Protos///
////////////////////////////
inline void windowInit( sf::RenderWindow& window, unsigned int windowHeightX, unsigned int windowWidthX, int fpsX, bool vSyncX, bool keyRepeatX );

void windowClose( sf::RenderWindow& window );

void windowFPS(sf::RenderWindow& window, int fpsX);

void windowVSync(sf::RenderWindow& window, bool vSyncX);

void windowKeyRepeat(sf::RenderWindow& window, bool keyRepeatX);

///////////////////////////////
