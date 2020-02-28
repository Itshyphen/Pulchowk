//
// Created by ppok on 2020-02-15.
//

#include "../header/Game.h"
Game::Game(){}
void Game::Setup() {
  window.create({500,500,32},"Hello!");
  window.setFramerateLimit(120);
    sf::Texture texture;
    !texture.loadFromFile("../textures/grass1.png",sf::IntRect(20,20,20,20));
    s.setTexture(texture);
    s.setPosition(sf::Vector2f(100.0f,100.0f));

  p1.getSprite().setPosition(window.getSize().x * 0.5, window.getSize().y * 0.5); // set the sprite to middle of the screen

  // in level array you define what texture goes into what sub-rectangle of size 40x40.
  // the format is level[] = { rect1 rect2 rect3 rect4... and so on as per the picture you want
  // here for rect1 starting at (0,0) the texture will be the texture at position 0 of textures_ground.png
  const int level[] = {
          18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
          6,   6,  6,  6,  2,  2,  2,  7,  7,  7,  7,  7,  6,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  7,  7,  7,  7,  7,  7,
          6,   6,  6,  6,  2,  2,  2,  7,  7,  7,  7,  7,  6,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  7,  7,  7,  7,  7,  7,
          19, 19,  6,  6,  2,  2,  2,  7,  7,  7,  7,  7,  6,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  7,  7,  7,  7,  7,  7,
          7,  19,  6,  6,  7,  7,  7,  7,  7,  7,  7,  7,  6,  6,  6,  6,  6,  6,  6,  6,  2,  2,  2,  2,  6,  6, 19,  2,  2,  2,
          7,  19,  6,  6,  7,  7,  7,  7,  7,  7,  7,  7,  6,  7,  7,  7,  7,  7,  7,  6,  2,  2,  2,  2,  6,  6, 19,  2,  2,  2,
          7,  19,  6,  6,  7,  7,  7,  7,  7,  7,  7,  7,  6,  7,  7,  7,  7,  7,  7,  6,  2,  2,  2,  2,  7,  7, 19,  2,  2,  2,
          7,  19,  6,  6,  7,  7,  7,  7,  7,  7,  7,  7,  6,  7,  7,  7,  7,  7,  7,  6,  2,  2,  2,  2,  7,  7, 19,  2,  2,  2,
          7,  19,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  2,  2,  2,  2,  7,  7, 19,  2,  2,  2,
          7,  19,  6,  6,  6,  6,  6,  6,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  7,  7, 19,  2,  2,  2,
          7,  19,  6,  6,  6,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  7,  7, 19,  2,  2,  2,
          7,  19,  6,  6,  6,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  7,  7, 19, 19, 19, 19,
          7,  19,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
          19, 19,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
          6,   6,  6,  6,  6,  2,  2,  2,  2,  2,  2,  6,  6,  2,  2,  2,  2,  2,  2, 19, 19,  6,  6, 19,  2,  2,  2,  2,  2,  2,
          2,   2,  2,  6,  6,  2,  2,  2,  2,  2,  2,  6,  6,  2,  2,  2,  2,  2,  2, 19, 19,  6,  6, 19,  2,  2,  2,  2,  2,  2,
          2,   2,  2,  6,  6,  2,  2,  2,  2,  2,  2,  6,  6,  2,  2,  2,  2,  2,  2, 19, 19,  6,  6, 19,  2,  2,  2,  2,  2,  2,
          2,   2,  2,  6,  6,  2,  2,  2,  2,  2,  2,  6,  6,  2,  2,  2,  2,  2,  2, 19, 19,  6,  6, 19,  2,  2,  2,  2,  2,  2,
          2,   2,  2,  6,  6,  2,  2,  2,  2,  2,  2,  6,  6,  2,  2,  2,  2,  2,  2, 19, 19,  6,  6, 19,  2,  2,  2,  2,  2,  2,
          2,   2,  2,  6,  6,  2,  2,  2,  2,  2,  2,  6,  6,  2,  2,  2,  2,  2,  2, 19, 19,  6,  6, 19,  2,  2,  2,  2,  2,  2,
          4,   4,  7,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6, 19,  2,  2,  2,  2,  2,  2,
          4,   4,  7,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6, 19,  2,  2,  2,  2,  2,  2,
          4,   4,  7,  6,  6,  7,  7,  2,  2,  2,  2,  2,  6,  2,  2,  2,  2,  2,  2, 19, 19,  6,  6, 19,  2,  2,  2,  2,  2,  2,
          2,   2,  2,  2,  2,  2,  7,  2,  2,  2,  2,  2,  6,  2,  2,  2,  2,  2,  2,  7,  7,  6,  6, 19,  2,  2,  2,  2,  2,  2,
          2,   2,  2,  2,  2,  2,  7,  2,  2,  2,  2,  2,  6,  2,  2,  2,  2,  2,  2,  7,  7,  6,  6, 19,  2,  2,  2,  2,  2,  2,
          2,   2,  2,  2,  2,  2,  7,  2,  2,  2,  2,  2,  6,  2,  2,  2,  2,  2,  2, 19, 19,  6,  6, 19,  2,  2,  2,  2,  2,  2,
          2,   2,  2,  2,  2,  2,  7,  2,  2,  2,  2,  2,  6,  2,  2,  2,  2,  2,  2, 19, 19,  6,  6, 19,  2,  2,  2,  2,  2,  2,
          2,   2,  2,  2,  2,  2,  7,  7,  7,  7,  7,  7,  7,  2,  2,  2,  2,  2,  2, 19, 19,  6,  6, 19,  2,  2,  2,  2,  2,  2,
          18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
          18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
  };
  map1.setTiles("../textures/textures_ground_20x20.png",sf::Vector2u(20,20),level,30,30);
  // height = 600 (windowHeight) / 40 (tileHeight) = 15 (same for width since the window is a square
  setView();
  std::cout<<areColliding;
}

void Game::run(){
  dTime = 0.0f;

  while (window.isOpen()){
    dTime = clock.restart().asSeconds();
    sf::Event event{};
    while(window.pollEvent(event)){
      switch (event.type)
      {
        case sf::Event::Closed:
          window.close();
          break;

        default:
          break;
      }
    }
    window.clear(sf::Color::White);
    window.draw(map1); // the draw function is overloaded so you don't have to add the texture along with draw
    p1.update(dTime,view);
    Collision c;

    //This is the part of collision detection of player and passed object
    areColliding=c.areColliding(p1.getSprite(), s);
    std::cout<<areColliding;
    window.draw(p1.getSprite());
    window.draw(s);
    window.setView(view); // since the player position has changed, set the view as per the new player coordinates
    window.display();
  }
}

void Game::setView(){
  view.setCenter(sf::Vector2f(p1.getSprite().getPosition().x, p1.getSprite().getPosition().y));
  view.setSize(sf::Vector2f(400,400));
  view.zoom(0.5f);
}


