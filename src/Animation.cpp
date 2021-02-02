//
// Created by ppok on 2020-02-15.
//

#include "../headers/Animation.h"

Animation::Animation(){
  switchTime = 0.3f; // time to switch between two images, modify from here
  currentImage.x = 0; // first image of the first row
  totalTime = 0.0f; // initially 0.0
}

void Animation::update(unsigned int& row, float& dTime, bool& faceRight, bool still){
  if (still){
    currentImage.x = 0;
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
    uvRect.left = currentImage.x * abs(uvRect.width);
    uvRect.width = abs(uvRect.width); // consider intRect width from left to right
  }
  else{
    uvRect.left = (currentImage.x+1) * abs(uvRect.width);
    uvRect.width = -abs(uvRect.width); // consider intRect width from right to left so negative
  }
}

unsigned int Animation::curImageX(){
  return currentImage.x;
}
