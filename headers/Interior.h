//
// Created by ppok on 2020-03-02.
//

#ifndef SFML_INTERIOR_H
#define SFML_INTERIOR_H


#include "../headers/Object.h"

class Interior: public Object {
  private:
    int tileSize; // size of each tile of the tile map
    int windowSize; // size of the window
    int tiles_per_row; // number of tiles per row

  public:
    Interior(const std::string& textLocation, int number_of_sprites, int sp_width, int sp_height, const int *textureNumbers, int tSize);
    void setPosForSprites(const int* posArray);
    void setScale(const float* scaleArray);
};


#endif //SFML_INTERIOR_H
