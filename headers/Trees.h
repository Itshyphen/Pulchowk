//
// Created by ppok on 2020-02-27.
//

#ifndef SFML_TREES_H
#define SFML_TREES_H


#include "../headers/Object.h"

class Trees: public Object {
  private:
    void defSprite(sf::Vector2f pos);
    void setTrees();
    int currentTree;
  public:
    Trees();
    ~Trees();
};


#endif //SFML_TREES_H
