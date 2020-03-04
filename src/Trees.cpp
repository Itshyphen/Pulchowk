//
// Created by ppok on 2020-02-27.
//

#include "../headers/Trees.h"

Trees::Trees(){
  texture.clear();
  texture.emplace_back(sf::Texture());
  texture[0].loadFromFile("../textures/tree-shadow-erased.png");

  spriteHeight = 107;
  spriteWidth = 54;

  sprite_vector.reserve(25);
  for (int i=0;i<25;i++){
    sprite_vector.emplace_back(texture[0],sf::IntRect(0,0, static_cast<int>(spriteWidth), static_cast<int>(spriteHeight)));
    sprite_vector[i].setScale(0.74074f,0.74074f);
    sprite_vector[i].setOrigin((spriteWidth)/2,static_cast<float>(spriteHeight));
  }

  currentTree = 0;
  setTrees();
}

void Trees::defSprite(sf::Vector2f pos) {

  sprite_vector[currentTree].setPosition(pos.x,pos.y);
  currentTree++;
}

void Trees::setTrees() {
  defSprite(sf::Vector2f(20 * 20,26 * 20));

  for(int i=3;i<=4;i++) {
    for (int j=7;j<12;j++) {
      defSprite(sf::Vector2f((j+0.5) * 20, i * 20));
    }
    for (int j=26;j<30;j++) {
      defSprite(sf::Vector2f((j+0.5) * 20, i * 20));
    }
  }

  for(int i=6;i<=11;i++){
    defSprite(sf::Vector2f((i+0.5) * 20, 28 * 20));
  }
}

Trees::~Trees() {
  sprite_vector.clear();
  sprite_vector.shrink_to_fit();

  texture.clear();
  texture.shrink_to_fit();
}

//const sf::Sprite &Trees::getTSprite() const {
//  return t_sprite;
//}
