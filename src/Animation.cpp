//
// Created by ppok on 2020-02-15.
//

#include "../header/Animation.h"

Animation::Animation(){
  playTexture.loadFromFile("../textures/7d595a64c99a634d94759de8096cca14.png");
  imageCount = sf::Vector2u(4,4);
  switchTime = 0.3f; // switch images after 0.3f of pressing the movement keys

  currentImage.x = 0; // first image of the first row
  totalTime = 0.0f; // initially 0.0

  uvRect.height = playTexture.getSize().y / static_cast <float>(imageCount.y); // set the height for our intRect, total height / total number of images per column
  uvRect.width = playTexture.getSize().x/static_cast <float>(imageCount.x); // set the width for our intRect, total width / total number of images per row
}

sf::IntRect Animation::getUVRect(){
  return uvRect;
}

void Animation::update(unsigned int row, float& dTime, bool faceRight, bool still){
  if (still){
    currentImage.x = 0; // if no movement keys are pressed, reset to the first image of the row (that is the image where the player is still)
  }
  else{
    currentImage.y = row;
    totalTime += dTime;
    if (totalTime >= switchTime){
      totalTime -= switchTime; // deduct switchTime from totalTime if the condition is fulfilled
      currentImage.x++; // change to next image on the same row

      if (currentImage.x >= imageCount.x){
        currentImage.x = 0; // if the row ends, reset to first image
      }
    }
  }

  uvRect.top = currentImage.y * uvRect.height;

  if(faceRight){
    uvRect.left = currentImage.x * abs(uvRect.width); // For eg: 1 * width of one image
    uvRect.width = abs(uvRect.width); // consider intRect width from left to right
  }
  else{
    uvRect.left = (currentImage.x+1) * abs(uvRect.width);
    uvRect.width = -abs(uvRect.width); // consider intRect width from right to left so negative
  }
}

unsigned int Animation::curImgx(){
  return currentImage.x; // helper function to return the x coordinate of current image
}