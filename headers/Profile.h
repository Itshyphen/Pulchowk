//
// Created by Hyphen on 3/4/2020.
//

#ifndef PULCHOWK_PROFILE_H
#define PULCHOWK_PROFILE_H

#include <iostream>
#include <fstream>
#include<SFML/Graphics.hpp>
#include "Button.h"
#include "Avatar.h"

class Profile{
private:
    std::string line;
    std::ifstream file;
    std::string lines=" ";

public:
    void Start()
    {
        sf::Font font;
        if (!font.loadFromFile("../res/font/arial.ttf")) {
            // handle error
        }
        file.open("Profile.txt");
        if(file.is_open())
        {
            while(std::getline(file, line))
            {
                //Getting every line of the .txt file and putting it in the 'line' string
                lines=lines+line+"\n";
            }
        }

        sf::RenderWindow windows(sf::VideoMode(800, 600), "PULCHOWK");
        sf::Text text(lines, font, 40);
        text.setPosition(20,20);

        Button texts;
        texts.setButton("Back", { 140, 50 }, 40, sf::Color::White, sf::Color::Black);
        texts.setFont(font);
        texts.setPosition({ 600, 520 });

        while (windows.isOpen())
        {
            sf::Event event;
            while (windows.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    windows.close();
                if(event.type== sf::Event::MouseButtonPressed)
                    if (texts.isMouseOver(windows)) {
                        windows.close();
                        MainMenu mainmenu;
                        mainmenu.Start();
                    }
            }

            windows.clear();
            windows.draw(text);
            texts.drawTo(windows);
            windows.display();
        }
    }
};

#endif //PULCHOWK_PROFILE_H
