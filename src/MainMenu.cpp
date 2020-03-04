//
// Created by Hyphen on 2/18/2020.
//
#include "../headers/Game.h"
#include <iostream>
#include <fstream>
#include "../headers/Avatar.h"
#include "../headers/Button.h"
#include "../headers/Profile.h"
#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\Rect.hpp>

MainMenu::MainMenu()= default;

void MainMenu::Start()
{
    selectedIndex=0;
    //Create the window
    window.create(sf::VideoMode(800, 600), "PULCHOWK", sf::Style::Default);
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                //Takes the player input
                case sf::Event::KeyPressed:
                    playerInput(event.key.code, true);
                    break;

                case sf::Event::KeyReleased:
                    playerInput(event.key.code, false);
                    break;

                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        drawMenu();
    }
}

void MainMenu::drawMenu()
{
    //Options for the menu
    sf::Text menu[2];
    if (!font.loadFromFile("../res/font/arial.ttf")) {
        // handle error
    }

    //Setting the properties of the menu option
    menu[0].setString(" Play");
    menu[0].setPosition(sf::Vector2f(359,320));

    menu[1].setString(" Profile");
    menu[1].setPosition(sf::Vector2f(350,400));


    //Setting the properties of the menu
    for(int j=0;j<2;j++)
    {
        menu[j].setFont(font);
        menu[j].setStyle(sf::Text::Bold);
        menu[j].setCharacterSize(40);
        menu[j].setFillColor(sf::Color::White);
    }

     //Load the background image
    image.loadFromFile("../textures/menu.PNG");
    loadImage.setTexture(image);

        window.clear(sf::Color::White);
        window.draw(loadImage);
        for (int i = 0; i < 2; i++)
        {
            //If selected change the color of the menu option to Red
            menu[i].setFillColor(i == selectedIndex ? sf::Color::Red : sf::Color::White);
            window.draw(menu[i]);
        }
        window.display();

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
    //While moving up decrease the selected index
    if (up and selectedIndex >= 0) selectedIndex--;
    //If not increase the selected index up to 4
    else if(not up and selectedIndex != 1) selectedIndex++;
}
void MainMenu::GetPressed()
{
    Avatar avatar;
    switch (selectedIndex)
    {
        case(0):
            window.close();
            Rules();
        case(1) :
            //Clear the menu window and draw the avatar screen
//            window.close();
//            Profile profile;
//            profile.Start();
            break;


//            Game game("PULCHOWK");
//            game.run();
            break;

    }
}

MainMenu::~MainMenu()
{}

void MainMenu::Rules() {
    sf::RenderWindow Rules(sf::VideoMode(800, 600), "PULCHOWK");
    Button text;
    text.setButton("Continue", { 140, 50 }, 40, sf::Color::White, sf::Color::Black);
    text.setFont(font);
    text.setPosition({ 600, 520 });

    sf::Texture rule;
    sf::Sprite rules;
    Avatar avatar;

    rule.loadFromFile("../textures/rules.png");
    rules.setTexture(rule);

    while (Rules.isOpen())
    {
        sf::Event event;
        while (Rules.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Rules.close();
            if(event.type== sf::Event::MouseButtonPressed)
                if (text.isMouseOver(Rules)) {
                Rules.close();
                avatar.Start();
                }

        }

        Rules.clear();
        Rules.draw(rules);
        text.drawTo(Rules);
        Rules.display();
    }

}


