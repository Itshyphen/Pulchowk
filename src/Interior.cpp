//
// Created by ppok on 2020-03-02.
//

#include "../headers/Interior.h"

Interior::Interior(const std::string& textLocation, int number_of_sprites, int sp_width, int sp_height, const int *textureNumbers, int tSize):tileSize(tSize) {
    texture.clear();
    texture.reserve(1);
    texture.emplace_back(sf::Texture());
    texture[0].loadFromFile(textLocation); // we need only one texture for all sprites

    spriteWidth = sp_width;
    spriteHeight = sp_height;
    sprite_vector.clear();
    sprite_vector.reserve(number_of_sprites);

    for (int i=0;i<number_of_sprites;i++){
        sprite_vector.emplace_back(sf::Sprite(texture[0],sf::IntRect(textureNumbers[i] * spriteWidth,0,spriteWidth,spriteHeight)));
        // since we have only one row of texture set, the rect top is always zero
        // spriteWidth * textureNumber gives the location of the left line from where we have to start
    }

    windowSize = 400;
    tiles_per_row = windowSize / tileSize;
}

void Interior::setPosForSprites(const int *posArray) {
    for (int i=0;i<sprite_vector.size();i++){
        sprite_vector[i].setOrigin(sf::Vector2f(0,spriteHeight)); // the origin set to (0,spriteHeight) for my convenience, not necessary
        sprite_vector[i].setPosition(sf::Vector2f((posArray[i] % tiles_per_row) * tileSize,
                                                  static_cast<int>(posArray[i] / tiles_per_row) * tileSize));
        // say the posArray [i] = 84 i.e. tile number 84. tiles_per_row is 10.
        // (84 % 10) = 8 i.e. the row of the grid where we place the tile. Multiply by tileSize to get the exact x-coordinate.
        // (84 / 10) = 4 i.e. the column of the grid. Multiply by tileSize to get the exact y-coordinate.
    }
}

void Interior::setScale(const float *scaleArray) {
    for (int i=0;i<sprite_vector.size();i++){
        sprite_vector[i].setScale(scaleArray[i],scaleArray[i]);
        // set the scales for each sprite as input in the scaleArray.
    }
}
