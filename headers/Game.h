//
// Created by ppok on 2020-02-15.
//

#ifndef PULCHOWK_GAME_H
#define PULCHOWK_GAME_H

#include <SFML/Graphics.hpp>
#include "Rect.h"
#include "Player.h"
#include "Trees.h"
#include "Building.h"
#include "Players.h"
#include "Time.h"

class Game{
public:
    Game();
    Game(std::string title);
    void run();
    void splashScreen(float dt,const sf::Text& welcome); // function to call a splash screen when needed

    void updateScoreboardPosition();
    void updateScoreboardScore();
    static void initialilze_Player_Stats(Player&);
    void updateTimebar();
    void setTimebar();
    void showGameOver();

private:
    sf::RenderWindow window;
    sf::View view;
    sf::Clock clock, clock_2;

    float dTime;
    float splashTime; //starting time for splashScreen
    float insideTime = 0.0f,
    insideTimeAdder = 0.0f;

    Player p1;
    Rect map1;
    Trees tree;
    int social=0;
    Building building;
    Players avatar;
    bool isInside; // boolean value to check if the user is inside the building or not
    int buildingNumberEntered; // number of building entered is stored here
    static bool Colliding(const sf::Sprite&,const sf::Sprite&);
    void Exit();
    void WriteFile();

    bool isGameOver = false;//If true gameover screen will be rendered.

    DisplayTime time1;
    std::vector<sf::Text> scoreboard;
    sf::Font font;
    sf::Text time_board;
    sf::Text score[7];


};
#endif //SFML_GAME_H
