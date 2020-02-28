//
// Created by ppok on 2020-02-15.
//

#include "../header/Rect.h"

void Rect::setTiles(const std::string& texture, sf::Vector2u tileSize,const int* tileArray,int height,int width){
  tileMap.loadFromFile(texture);

  vertices.setPrimitiveType(sf::Quads);
  vertices.resize(height * width * 4);
  // the size of each sub-rectangle is 15 x 15, and each rectangle contains 4 vertices, so the size of the
  // vertex array will be resized to 15 x 15 x 4 (memory optimization)

  for (unsigned int i=0;i<width;i++){
    for (unsigned int j=0;j<height;j++){
      int currentTile = tileArray[i + j*width];
      // for loop 1, tileArray[0 + 0 * 15] = tileArray[0]
      // for loop 1, tileArray[0 + 1 * 15] = tileArray[15] i.e. just one tile below the origin tile at (0,0)
      // for loop 1, tileArray[0 + 2 * 15] = tileArray[30], 3rd tile in the y-axis below tile at (0,0)

      // haven't understood the concept behind tu and tv, just know that it works for each iteration of the loop
      // value of tu and tv depends on the value of currentTile's texture value
      unsigned int tu = currentTile % (tileMap.getSize().x / tileSize.x);
      unsigned int tv = currentTile / (tileMap.getSize().x / tileSize.x);

      // go to the pointer of the textArray[0 or 1 or 2 depending on the loop
      // multiply by 4 because 4 consecutive vertices in the vertex array for one sub-rectangle
      sf::Vertex* pointCoordinates = &vertices[(i + j * width) * 4];

      pointCoordinates[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
      pointCoordinates[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
      pointCoordinates[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
      pointCoordinates[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

      pointCoordinates[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
      pointCoordinates[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
      pointCoordinates[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
      pointCoordinates[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
    }
  }
}

// overloading the draw function
// target is the window
// states is the texture reference we had to pass before to draw vertex array on screen
void Rect::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();

  states.texture = &tileMap;
  target.draw(vertices,states);
}