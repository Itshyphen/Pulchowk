//
// Created by Hyphen on 2/18/2020.
//
#include "Game.h"
#include <iostream>
#include <Avatar.h>

MainMenu::MainMenu()= default;
MainMenu::MainMenu(const std::string& title)

{
    window1.create(sf::VideoMode(800, 600), "PULCHOWK", sf::Style::Default);
    selectedIndex=0,
            isPressedUp=false;
    isPressedDown=false;
    isPressedEnter=false;
}

void MainMenu::Start()
{
    while (window1.isOpen())
    {
        sf::Event event{};
        while (window1.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::KeyPressed:
                    playerInput(event.key.code, true);
                    break;


                case sf::Event::KeyReleased:
                    playerInput(event.key.code, false);
                    break;
                case sf::Event::Closed:
                    window1.close();
                    break;
            }
        }
        drawMenu();
    }
}

void MainMenu::drawMenu()
{

    sf::Text menu[5];
    if (!font.loadFromFile("../res/font/arial.ttf")) {
        // handle error
    }

    menu[0].setString(" Play");
    menu[0].setPosition(sf::Vector2f(359,100));

    menu[1].setString(" Profile");
    menu[1].setPosition(sf::Vector2f(350,200));

    menu[2].setString(" Setting");
    menu[2].setPosition(sf::Vector2f(350,300));

    menu[3].setString(" About");
    menu[3].setPosition(sf::Vector2f(355,400));

    menu[4].setString(" Exit");
    menu[4].setPosition(sf::Vector2f(359,500));

    for(int j=0;j<5;j++)
    {
        menu[j].setFont(font);
        menu[j].setStyle(sf::Text::Bold);
        menu[j].setCharacterSize(25);
        menu[j].setFillColor(sf::Color::Black);
    }
        window1.clear(sf::Color::White);
        for (int i = 0; i < 5; i++)
        {
            menu[i].setFillColor(i == selectedIndex ? sf::Color::Red : sf::Color::Black);
            window1.draw(menu[i]);
        }
        window1.display();

}

void MainMenu::playerInput(sf::Keyboard::Key & key, bool isPressed)
{
    switch (key){
        case sf::Keyboard::Up:
            isPressedUp=isPressed;
            break;
        case sf::Keyboard::Down:
            isPressedDown=isPressed;
            break;
        case sf::Keyboard::Return:
            isPressedEnter=isPressed;
            break;
    }
    if(isPressedUp)
        MoveUp(true);
    if(isPressedDown)
        MoveUp(false);
    if(isPressedEnter)
        GetPressed();
}

void MainMenu::MoveUp(bool up=true)
{
    if (up and selectedIndex >= 0) selectedIndex--;
    else if(not up and selectedIndex != 4) selectedIndex++;
}
void MainMenu::GetPressed()
{
    Avatar avatar;
    switch (selectedIndex)
    {
        case(1) :
            window1.close();
            avatar.Start();
            break;
        case(2):
            exit(0);
        case(3):
            exit(0);
        case(4):
            exit(0);
        case(0):
            window1.close();
            Game game("PULCHOWK");
            game.run();
            break;

    }
}

MainMenu::~MainMenu()
= default;