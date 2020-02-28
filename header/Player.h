//
// Created by ppok on 2020-02-15.
//

#ifndef SFML_PLAYER_H
#define SFML_PLAYER_H

#include "Animation.h"
#include "Collision.h"

class Player:public sf::Drawable{
  public:
    //void Set(const std::string& texture, sf::Vector2u imageCount, float switchTime,float speed);
    Player();
    void update(float &deltaTime, sf::View& view);
    sf::Sprite getSprite();
    bool keyPress();

  private:
    sf::Sprite player;
    unsigned int row;
    float speed;
    bool faceRight;
    Animation animation;
    sf::Vector2u imageCount;

    sf::Texture playerTexture;
    virtual void draw(sf::RenderTarget& tar,sf::RenderStates states) const;
};

#endif //SFML_PLAYER_H
