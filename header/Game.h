//
// Created by ppok on 2020-02-15.
//

#ifndef SFML_GAME_H
#define SFML_GAME_H

#include <SFML/Graphics.hpp>
#include "Rect.h"
#include "Player.h"

class Game{
  public:
    Game();
    void Setup();

    void setView();
    void run();

    friend class Player;
  private:
    sf::RenderWindow window;
    sf::View view;
    sf::Clock clock;
    bool areColliding;
    float dTime;
    sf::Sprite s;
    Player p1;
    Rect map1;
};

#endif //SFML_GAME_H
