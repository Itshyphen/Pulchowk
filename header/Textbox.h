//
// Created by Hyphen on 2/22/2020.
//

#ifndef PULCHOWK_TEXTBOX_H
#define PULCHOWK_TEXTBOX_H

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>


class Textbox {
public:
    sf::Text textbox;

    //Parameterized constructor
    Textbox(int size, sf::Color color, bool sel) {
        textbox.setCharacterSize(size);
        textbox.setFillColor(color);
        isSelected = sel;

        // Check if the textbox is selected upon creation and display it accordingly:
        if(isSelected)
            textbox.setString("_");
        else
            textbox.setString("");
    }

    // Make sure font is passed by reference:
    void setFont(sf::Font &fonts) {
        textbox.setFont(fonts);
    }

    void setPosition(sf::Vector2f point) {
        textbox.setPosition(point);
    }

    // Set char limits:
    void setLimit(bool ToF) {
        hasLimit = ToF;
    }

    void setLimit(bool ToF, int lim) {
        hasLimit = ToF;
        limit = lim - 1;
    }

    //Get the entered text
    std::string getText() {
        return text.str();
    }

    //Draw the textbox to the window
    void drawTo(sf::RenderWindow &window) {
        window.draw(textbox);
    }

    // Function for event loop:
    void typedOn(sf::Event input) {
        if (isSelected) {
            int charTyped = input.text.unicode;

            // Only allow normal inputs:
            if (charTyped < 128) {
                if (hasLimit) {
                    // If there's a limit, don't go over it:
                    if (text.str().length() <= limit) {
                        inputLogic(charTyped);
                    }
                        // But allow for char deletions:
                    else if (text.str().length() > limit && charTyped == 8) {
                        deleteLastChar();
                    }
                }
                    // If no limit exists, just run the function:
                else {
                    inputLogic(charTyped);
                }
            }
        }
    }
private:

    std::ostringstream text;
    bool isSelected = false;
    bool hasLimit = false;
    int limit = 0;

    // Delete the last character of the text:
    void deleteLastChar() {
        std::string t = text.str();
        std::string newT = "";
        for (int i = 0; i < t.length() - 1; i++) {
            newT += t[i];
        }
        text.str("");
        text << newT;
        textbox.setString(text.str() + "_");
    }

    // Get user input:
    void inputLogic(int charTyped) {
        // If the key pressed isn't delete, or the two selection keys, then append the text with the char:
        if (charTyped != 8 && charTyped != 13 && charTyped != 27) {
            text << static_cast<char>(charTyped);
        }
            // If the key is delete, then delete the char:
        else if (charTyped == 8) {
            if (text.str().length() > 0) {
                deleteLastChar();
            }
        }
        // Set the textbox text:
        textbox.setString(text.str() + "_");
    }
};
#endif //PULCHOWK_TEXTBOX_H
