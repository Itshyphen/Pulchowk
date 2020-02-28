//
// Created by ppok on 2020-02-15.
//

#ifndef SFML_ANIMATION_H
#define SFML_ANIMATION_H

#include <SFML/Graphics.hpp>

class Animation{
  public:
    Animation();

    void update(unsigned int,float&,bool,bool);
    sf::IntRect getUVRect();
    unsigned int curImgx();

  private:

    sf::Vector2u imageCount; // number of images in the sprite sheet (here 4 in row and 4 in column)
    sf::Vector2u currentImage; // coordinates to specify the current image
    sf::Texture playTexture;
    sf::IntRect uvRect;

    float switchTime; // total time between switching images, frame rate
    float totalTime; // total time spent since the last image
};

#endif //SFML_ANIMATION_H
