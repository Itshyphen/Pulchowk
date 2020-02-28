//
// Created by Hyphen on 2/22/2020.
//

#ifndef PULCHOWK_AVATAR_H
#define PULCHOWK_AVATAR_H

#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"

class Avatar
{
private:
    sf::Font font;
    sf::RenderWindow window2;
    std::string m="Male",f="Female";
    int selectedIndex=0;
    bool isPressedUp=false, isPressedDown=false, isPressedEnter=false;
    MainMenu back;
    void playerInput(sf::Keyboard::Key &key, bool isPressed);
    void MoveUp(bool up);
    bool GetPressed();
    void Profile();

public:
    std::string nam;
    bool isMale;
    Avatar();
    ~Avatar();
    void Start();

};


#endif //PULCHOWK_AVATAR_H
