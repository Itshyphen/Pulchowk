//
// Created by Hyphen on 2/22/2020.
//
#include "../headers/Avatar.h"
#include "../headers/Game.h"
#include <iostream>
#include "../headers/Button.h"
#include "../headers/TextField.h"
bool isMale=true;
std::string nam;

Avatar::Avatar()
{
}

void Avatar::Start()
{
    //Creating the window
    window.create(sf::VideoMode(800, 600), "PULCHOWK", sf::Style::Default);
    selectedIndex=0;
    //Options in the avatar screen
    sf::Text menu[4];
    sf::Text Title;
    if (!font.loadFromFile("../res/font/arial.ttf")) {
        // handle error
    }

    //Defining the button and textfield properties for name entering field
    Button text;
    text.setButton("", { 100, 30 }, 30, sf::Color::White, sf::Color::Black);
    text.setFont(font);
    text.setPosition({ 390, 200 });

    TextField name(20, sf::Color::Black);
    name.setPosition({400, 200 });
    name.setFont(font);

    //Setting the button properties for buttons of gender selection
    Button male;
    male.setButton(m, { 100, 30 }, 30, sf::Color::White, sf::Color::Black);
    male.setFont(font);
    male.setPosition({ 370, 300 });

    Button female;
    female.setButton(f, { 100, 30 }, 30, sf::Color::White, sf::Color::Black);
    female.setFont(font);
    female.setPosition({ 480, 300 });

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::KeyPressed:
                    playerInput(event.key.code, true);
                    break;
                case sf::Event::TextEntered:
                    //Allow to enter the text and convert the entered character to unicode
                    name.typedOn(event);
                    break;
                case sf::Event::KeyReleased:
                    playerInput(event.key.code, false);
                    break;

                case sf::Event::MouseButtonPressed:
                    //Gender selection is controlled by the mouse click

                    if (male.isMouseOver(window)) {
                        //Set the initial color of male button Cyan
                        male.setBackColor(sf::Color::Black);
                        male.setTextColor(sf::Color::White);
                        //Changed color after selection Magenta
                        female.setBackColor(sf::Color::White);
                        female.setTextColor(sf::Color::Black);
                        //Gender selected to male
                        isMale=true;
                    }

                    if (female.isMouseOver(window)) {
                        //Set the initial color of the female button Cyan
                        female.setBackColor(sf::Color::Black);
                        female.setTextColor(sf::Color::White);
                            //Changed color after selection Magenta
                        male.setBackColor(sf::Color::White);
                        male.setTextColor(sf::Color::Black);
                        //Gender selected to female
                            isMale=false;
                    }


                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        //Design for the interface of Avatar screen
        Title.setString("Enter Your Details:");
        Title.setPosition(sf::Vector2f(100,120));
        Title.setFont(font);
        Title.setStyle(sf::Text::Bold);
        Title.setFillColor(sf::Color::Red);

        menu[0].setString(" Your Name");
        menu[0].setPosition(sf::Vector2f(100,200));

        menu[1].setString(" Gender");
        menu[1].setPosition(sf::Vector2f(100,300));

        menu[2].setString(" Save");
        menu[2].setPosition(sf::Vector2f(150,500));

        menu[3].setString(" Back");
        menu[3].setPosition(sf::Vector2f(350,500));

        //Initializing color and fonts of the options in avatar screen
        for(int j=0;j<4;j++)
        {
            menu[j].setFont(font);
            menu[j].setStyle(sf::Text::Bold);
            menu[j].setCharacterSize(30);
            menu[j].setFillColor(sf::Color::White);
        }

        //Load the background image
        image.loadFromFile("../textures/avatar.PNG");
        loadImage.setTexture(image);

        window.clear(sf::Color::White);
        window.draw(loadImage);
        for (int i = 0; i < 4; i++)
        {
            menu[i].setFillColor(i == selectedIndex ? sf::Color::Red : sf::Color::White);
            //Draw the each options like name , gender, save and back
            window.draw(menu[i]);
        }
        window.draw(Title);
        //Draw the tex enter field
        text.drawTo(window);
        name.drawTo(window);
        //Draw the buttons
        male.drawTo(window);
        female.drawTo(window);
        window.display();

    }
    nam=name.getText();
    //Displaying the name and gender of the player in terminal
    std::cout<<"\nPlayer:"<<nam<<"\nGender:"<<(isMale ? m : f);
}

//Takes the player input
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
    else if(not up and selectedIndex != 3) selectedIndex++;
}
void Avatar::GetPressed()
{
    switch (selectedIndex)
    {
        case(1) :
            //Select the gender
            break;

        case(0):
            //Enter the player name
            break;
        case(3):
            window.close();
            back.Start();
            break;
        case(2):
            window.close();
            Game game("PULCHOWK");
            break;
    }
}


//Destructor
Avatar::~Avatar()
{
window.close();
}
