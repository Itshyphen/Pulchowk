//
// Created by Hyphen on 2/22/2020.
//

#ifndef PULCHOWK_BUTTON_H
#define PULCHOWK_BUTTON_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Button {
private:
    sf::RectangleShape button;
    sf::Text text;

    int btnWidth;
    int btnHeight;

public:
    Button(){}
    //Set the text, size, background color and textcolor for the button
       void setButton(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor) {
        button.setSize(buttonSize);
        button.setFillColor(bgColor);

        btnWidth = buttonSize.x;
        btnHeight = buttonSize.y;

        text.setString(btnText);
        text.setCharacterSize(charSize);
        text.setFillColor(textColor);
    }

    // Pass font by reference:
    void setFont(sf::Font &fonts) {
        text.setFont(fonts);
    }

    //Pass the back color
    void setBackColor(sf::Color color) {
        button.setFillColor(color);
    }

    //Pass text color
    void setTextColor(sf::Color color) {
        text.setFillColor(color);
    }

    //Pass the position of the button
    void setPosition(sf::Vector2f point) {
        button.setPosition(point);

        // Set the position of text within the button
        float xPos = (point.x + btnWidth / 2) - (text.getLocalBounds().width / 2);
        float yPos = (point.y + btnHeight / 3.6) - (text.getLocalBounds().height / 2);
        text.setPosition(xPos, yPos);
    }

    //Draw the button and the text
    void drawTo(sf::RenderWindow &window) {
        window.draw(button);
        window.draw(text);
    }

    // Check if the mouse is within the bounds of the button:
    bool isMouseOver(sf::RenderWindow &window) {
        //Takes the mouse position
        int mouseX = sf::Mouse::getPosition(window).x;
        int mouseY = sf::Mouse::getPosition(window).y;

        //Takes the button position
        int btnPosX = button.getPosition().x;
        int btnPosY = button.getPosition().y;

        //If mouse position lies within the button then returns true
        if (mouseX < (btnPosX + btnWidth) && mouseX > btnPosX && mouseY < (btnPosY+btnHeight) && mouseY > btnPosY) {
            return true;
        }
        return false;
    }

};
#endif //PULCHOWK_BUTTON_H
