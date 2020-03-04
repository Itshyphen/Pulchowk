//
// Created by Hyphen on 3/1/2020.
//

#include "../headers/Players.h"

Players::Players(){
    texture.clear();
    texture.reserve(15);
    for(int i=0;i<15;i++) {
        texture.emplace_back(sf::Texture());
    }

    sprite_vector.reserve(15);
    texture[0].loadFromFile("../textures/players/output-onlinepngtools(0).png");
    texture[1].loadFromFile("../textures/players/output-onlinepngtools (1).png");
    texture[2].loadFromFile("../textures/players/output-onlinepngtools (2).png");
    texture[3].loadFromFile("../textures/players/output-onlinepngtools (3).png");
    texture[4].loadFromFile("../textures/players/output-onlinepngtools (4).png");
    texture[5].loadFromFile("../textures/players/output-onlinepngtools (5).png");
    texture[6].loadFromFile("../textures/players/output-onlinepngtools (6).png");
    texture[7].loadFromFile("../textures/players/output-onlinepngtools (7).png");
    texture[8].loadFromFile("../textures/players/output-onlinepngtools (8).png");
    texture[9].loadFromFile("../textures/players/output-onlinepngtools (9).png");
    texture[10].loadFromFile("../textures/players/output-onlinepngtools (10).png");
    texture[11].loadFromFile("../textures/players/output-onlinepngtools (11).png");
    texture[12].loadFromFile("../textures/players/output-onlinepngtools (12).png");
    texture[13].loadFromFile("../textures/players/output-onlinepngtools (13).png");
    texture[14].loadFromFile("../textures/players/output-onlinepngtools (14).png");

    for(int i=0;i<15;i++) {
        sprite_vector.emplace_back(texture[i]);
    }
    setPlayers();
}

void Players::setPlayers() {
    sprite_vector[0].setPosition(sf::Vector2f(218,70)); // set the position for each element in the building sprite
    sprite_vector[1].setPosition(sf::Vector2f(200,70));
    sprite_vector[2].setPosition(sf::Vector2f(394,350));
    sprite_vector[3].setPosition(sf::Vector2f(385,118));
    sprite_vector[4].setPosition(sf::Vector2f(545,210));
    sprite_vector[5].setPosition(sf::Vector2f(525,213));
    sprite_vector[6].setPosition(sf::Vector2f(380,364));
    sprite_vector[7].setPosition(sf::Vector2f(226,371));
    sprite_vector[8].setPosition(sf::Vector2f(400,116));
    sprite_vector[9].setPosition(sf::Vector2f(395,532));
    sprite_vector[10].setPosition(sf::Vector2f(1,265));
    sprite_vector[11].setPosition(sf::Vector2f(406,364));
    sprite_vector[12].setPosition(sf::Vector2f(209,78));
    sprite_vector[13].setPosition(sf::Vector2f(394,370));
    sprite_vector[14].setPosition(sf::Vector2f(100,235));
    sprite_vector[15].setPosition(sf::Vector2f(540,212));
    for(int i=0;i<15;i++){
        sprite_vector[i].setScale(0.6,0.6);
    }

}

Players::~Players() {
    sprite_vector.clear();
    sprite_vector.shrink_to_fit();

    texture.clear();
    texture.shrink_to_fit();
}