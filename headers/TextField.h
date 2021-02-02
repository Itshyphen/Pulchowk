//
// Created by Hyphen on 2/22/2020.
//

#ifndef PULCHOWK_TEXTFIELD_H
#define PULCHOWK_TEXTFIELD_H

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

class TextField {
private:
    //Take input and write to the string
    std::ostringstream text;
public:
    sf::Text textfield;
    //Initializes the color, character size of the text to be entered
    TextField(int size, const sf::Color color) {
        textfield.setCharacterSize(size);
        textfield.setFillColor(color);

        // Initially Display _ in the textfield
            textfield.setString("_");

    }

    // Make sure font is passed by reference:
    void setFont(sf::Font &fonts) {
        textfield.setFont(fonts);
    }
    //Set the position of text entering field
    void setPosition(sf::Vector2f point) {
        textfield.setPosition(point);
    }
    //Return the entered text
    std::string getText() {
        return text.str();
    }

    //Draw the textfield to the window
    void drawTo(sf::RenderWindow &window) {
        window.draw(textfield);
    }

    // Function for event loop:
    void typedOn(sf::Event input) {
        //Convert the each character entered to unicode
            int charTyped = input.text.unicode;

            // Only allow normal inputs:
            if (charTyped < 128) {
               // Convert each unicode to character to display
                text << static_cast<char>(charTyped);
                // Set the textfield text:
                textfield.setString(text.str() + "_");
            }
    }

};
#endif //PULCHOWK_TEXTFIELD_H
