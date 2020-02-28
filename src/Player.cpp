//
// Created by ppok on 2020-02-15.
//

#include <Game.h>
#include "../header/Player.h"

Player::Player(){
  playerTexture.loadFromFile("../textures/7d595a64c99a634d94759de8096cca14.png");
  imageCount.x = 4; // no of rows
  imageCount.y = 4; // no of columns

  player.setTexture( playerTexture);
  //Set(playerTexture, sf::Vector2u(3,9),0.3f,100.0f);
  faceRight=true;

  //set origin to the center of the selected intRect
  player.setOrigin(player.getTexture()->getSize().x * 0.5 / imageCount.x, player.getTexture()->getSize().y * 0.5 / imageCount.y);
  player.setScale(sf::Vector2f(0.03f,0.03f));
  speed = 100.0f;
}

void Player::update(float& deltaTime, sf::View& view){
  // pass both variables as reference, especially view as you want to update the same view
  sf::Vector2f movement(0.0f,0.0f); // increments added to position when a key is pressed

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){ // move left when A is pressed
    movement.x -= speed * deltaTime; // speed * velocity = distance covered
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){ // move right when D is pressed
    movement.x += speed * deltaTime;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
    movement.y -= speed * deltaTime;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
    movement.y += speed * deltaTime;
  }

  if(movement.x == 0.0f and movement.y == 0.0f){
    row = 0;
  }
  else if (movement.x != 0.0f){
    row = 2; // row for side movement
    faceRight = movement.x <= 0.0f;
  }
  else if (movement.y < 0.0f){
    row = 1;
  }
  else{
    row = 0;
  }

  player.setTextureRect(animation.getUVRect());
  if(keyPress()){
    animation.update(row,deltaTime,faceRight,false);
  }
  else if (!keyPress() && (animation.curImgx() == 1 || animation.curImgx() == 3)){
    // if the image is that of partially walking, switch to still one if no key is pressed as well
    animation.update(row,deltaTime,faceRight,true);
  }
    //const bool areColliding=collision::areColliding(player, ) ;
    Game g;
    std::cout<<g.areColliding;
    if (g.areColliding-6) {
        player.setColor(sf::Color::Green);
    }
    else {
        player.move(movement);
    }

  // move the coordinates of the player by adding the coordinates of movement

  // set the center of the view to the center of where the player is moved
  view.setCenter(sf::Vector2f(player.getPosition().x, player.getPosition().y));
}

sf::Sprite Player::getSprite(){
  return player;
}

bool Player::keyPress(){
  // returns true if a movement key (A,S,D,W) is pressed
  return sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
         sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S);
}

void Player::draw(sf::RenderTarget &tar, sf::RenderStates states) const {
  tar.draw(player);
}

//void Player::Set(const std::string &texture, sf::Vector2u imageCount, float switchTime, float speed) {

