//
// Created by ppok on 2020-02-15.
//

#ifndef SFML_PLAYER_H
#define SFML_PLAYER_H


#include "Animation.h"
#include "Activity.h"
#include "Building.h"
//Animation class is inherited by those characters that are animated, not others

class Player:public sf::Drawable, Animation{
  public:
    Player();
    Player(std::string title);
    void update(float &deltaTime, sf::View& view);
    bool keyPress();
    sf::Sprite &getSprite();

  private:
    unsigned int row;
    float speed;
    bool faceRight;
    sf::Sprite player;
    sf::Texture playerTexture;
    enum Direction{Left=1,Right,Up,Down};
    Direction place;
    Activity activity;

    std::string source;
    std::map<std::string, int> params;


    virtual void draw(sf::RenderTarget& tar,sf::RenderStates states) const;

public:

    void setActivity(Activity);

    int getAcademics();
    int getFun();
    int getSocial();
    int getMaterials();
    int getEnergy();
    int getMoney();

    //Building getBuilding();
    std::string getHighestScore();
    std::string getLowestScore();

    void setAcademics(int);
    void setFun(int);
    void setSocial(int);
    void setMaterials(int);
    void setEnergy(int);
    void setMoney(int);

    void updateScore(float);

};

#endif //SFML_PLAYER_H
