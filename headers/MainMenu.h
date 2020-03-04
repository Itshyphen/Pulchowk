//
// Created by Hyphen on 2/18/2020.
//
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>

class MainMenu
{
private:
    sf::Font font;
    sf::RenderWindow window;
    int selectedIndex;
    bool isPressedUp=false, isPressedDown=false, isPressedEnter=false;

    //Defining texture and image for background
    sf::Texture image;
    sf::Sprite loadImage;

    void drawMenu();
    void playerInput(sf::Keyboard::Key &key, bool isPressed);
    void MoveUp(bool up);
    void GetPressed();
    void Rules();

public:
    MainMenu();
    ~MainMenu();
    void Start();

};


