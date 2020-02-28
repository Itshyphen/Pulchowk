//
// Created by Hyphen on 2/22/2020.
//
#include "Avatar.h"
#include <iostream>
#include <Button.h>
#include <Textbox.h>

Avatar::Avatar()
{
}

void Avatar::Start()
{
    window2.create(sf::VideoMode(800, 600), "PULCHOWK", sf::Style::Default);
    selectedIndex=0;

    sf::Text menu[5];
    if (!font.loadFromFile("../res/font/arial.ttf")) {
        // handle error
    }

    Button text;
    text.setButton("", { 100, 30 }, 30, sf::Color::White, sf::Color::Black);
    text.setFont(font);
    text.setPosition({ 390, 100 });
    Textbox name(20, sf::Color::Black, true);
    name.setPosition({400, 100 });
    name.setFont(font);

    Button male;
    male.setButton(m, { 100, 30 }, 30, sf::Color::Magenta, sf::Color::Black);
    male.setFont(font);
    male.setPosition({ 370, 200 });
    Button female;
    female.setButton(f, { 100, 30 }, 30, sf::Color::Magenta, sf::Color::Black);
    female.setFont(font);
    female.setPosition({ 480, 200 });

    while (window2.isOpen())
    {
        sf::Event event;

        while (window2.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::KeyPressed:
                    playerInput(event.key.code, true);
                    break;
                case sf::Event::TextEntered:
                    name.typedOn(event);
                    break;
                case sf::Event::KeyReleased:
                    playerInput(event.key.code, false);
                    break;
                case sf::Event::MouseButtonPressed:
                    if (male.isMouseOver(window2)) {
                        male.setBackColor(sf::Color::Cyan);
                        female.setBackColor(sf::Color::Magenta);

                        isMale=true;
                    }
                    if (female.isMouseOver(window2)) {
                            female.setBackColor(sf::Color::Cyan);
                            male.setBackColor(sf::Color::Magenta);
                            isMale=false;
                    }


                    break;
                case sf::Event::Closed:
                    window2.close();
                    break;
            }
        }
        menu[0].setString(" Your Name");
        menu[0].setPosition(sf::Vector2f(100,100));

        menu[1].setString(" Gender");
        menu[1].setPosition(sf::Vector2f(100,200));

        menu[2].setString(" Your Profile");
        menu[2].setPosition(sf::Vector2f(100,300));

        menu[3].setString(" Save");
        menu[3].setPosition(sf::Vector2f(150,500));

        menu[4].setString(" Back");
        menu[4].setPosition(sf::Vector2f(350,500));

        for(int j=0;j<5;j++)
        {
            menu[j].setFont(font);
            menu[j].setStyle(sf::Text::Bold);
            menu[j].setCharacterSize(25);
            menu[j].setFillColor(sf::Color::Black);
        }
        window2.clear(sf::Color::White);
        for (int i = 0; i < 5; i++)
        {
            menu[i].setFillColor(i == selectedIndex ? sf::Color::Red : sf::Color::Black);
            window2.draw(menu[i]);
        }
        text.drawTo(window2);
        name.drawTo(window2);
        male.drawTo(window2);
        female.drawTo(window2);
        window2.display();

    }
    nam=name.getText();
    std::cout<<"\nPlayer:"<<nam<<"\nGender:"<<(isMale==true?m:f);
}

void Avatar::playerInput(sf::Keyboard::Key & key, bool isPressed)
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

void Avatar::MoveUp(bool up=true)
{
    if (up and selectedIndex >= 0) selectedIndex--;
    else if(not up and selectedIndex != 4) selectedIndex++;
}
bool Avatar::GetPressed()
{
    switch (selectedIndex)
    {
        case(1) :
            break;
        case(2):
            Profile();
        case(3):

            window2.close();
            back.Start();
            break;
        case(4):
            window2.close();
            back.Start();
            break;
        case(0):
            break;
    }
}

void Avatar::Profile()
{
    window2.create(sf::VideoMode(800, 600), "PULCHOWK", sf::Style::Default);
    window2.clear(sf::Color::White);
    window2.display();
}

Avatar::~Avatar()
{
window2.close();
}