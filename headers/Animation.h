
#ifndef PULCHOWK_ANIMATION_H
#define PULCHOWK_ANIMATION_H

#include <SFML/Graphics.hpp>

class Animation{
  public:
    Animation();

  protected:
    void update(unsigned int& row, float& dTime, bool& faceRight, bool still);
    unsigned int curImageX();

    sf::Vector2u imageCount;
    sf::IntRect uvRect;

  private:
    // these parameters shouldn't be modified, even by derived classes as we need all the animations
    // within the game to occur with the same frame rate
    // also, currentImage can be accidentally modified within the derived class, which can cause the animation to crash

    sf::Vector2u currentImage;
    float switchTime; // total time between switching images, frame rate
    float totalTime; // total time spent since the last image
};

#endif //PULCHOWK_ANIMATION_H
