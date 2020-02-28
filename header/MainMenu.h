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
    sf::RenderWindow window1;
    int selectedIndex=0;
    bool isPressedUp{}, isPressedDown{}, isPressedEnter{};

    void drawMenu();
    void playerInput(sf::Keyboard::Key &key, bool isPressed);
    void MoveUp(bool up);
    void GetPressed();
    void about();

public:
    MainMenu();
    explicit MainMenu(const std::string& title);
    ~MainMenu();
    void Start();

};


