//
// Created by ppok on 2020-02-15.
//

#ifndef SFML_RECT_H
#define SFML_RECT_H


#include <SFML/Graphics.hpp>
#include <iostream>

class Rect: public sf::Drawable, public sf::Transformable{ // inherits from base class drawable and transformable
  public:
    void setTiles(const std::string& texture, sf::Vector2u tileSize,const int* tileArray,int height,int width);

  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; // virtual because we will overload it
    sf::Texture tileMap;
    sf::VertexArray vertices;
};

#endif //SFML_RECT_H
