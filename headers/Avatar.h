//
// Created by Hyphen on 2/22/2020.
//

#ifndef PULCHOWK_AVATAR_H
#define PULCHOWK_AVATAR_H

#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include "../headers/MainMenu.h"


class Avatar
{
private:
    sf::Font font;
    sf::RenderWindow window;
    std::string m="Male",f="Female";
    int selectedIndex=0;
    bool isPressedUp=false, isPressedDown=false, isPressedEnter=false;

    //Defining texture and image for background
    sf::Texture image;
    sf::Sprite loadImage;
    MainMenu back;

    //Function for taking the player input
    void playerInput(sf::Keyboard::Key &key, bool isPressed);
    void MoveUp(bool up);

    //Function to called on selection
    bool GetPressed();

public:
    Avatar();
    ~Avatar();
    void Start();

};


#endif //PULCHOWK_AVATAR_H
