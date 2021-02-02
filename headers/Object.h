//
// Created by ppok on 2020-02-27.
//

#ifndef SFML_OBJECT_H
#define SFML_OBJECT_H


#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Object {
  protected:
    std::vector<sf::Texture> texture;
    std::vector<sf::Sprite> sprite_vector;
    float spriteHeight;
    float spriteWidth;
  public:
    const std::vector<sf::Sprite> &getSpriteVector() const {
        return sprite_vector;
    }
};


#endif //SFML_OBJECT_H
