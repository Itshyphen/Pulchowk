

#ifndef PULCHOWK_BUILDING_H
#define PULCHOWK_BUILDING_H


#include <SFML/System.hpp>
#include "Object.h"
#include "Rect.h"
#include "Interior.h"
#include "Activity.h"


class Building: public Object {
  private:
    std::vector<Rect> interiorMaps;
    std::vector<Interior> interiorEnvironment;
    enum Build{Canteen=0,CIT,Library,Robotics,ATM,LOCUS,Toilet,ICTC,Department}; // enum to make code more readable
    std::vector<sf::Vector2u> allowedTiles;
    std::vector<std::string> building_names;
    std::vector<Activity> building_activities;

    void setInteriorMaps(); // set the interior map i.e. the tiled structure
    void setBuildingPosition(); // set the position of the building
    void setAllowedTiles(); // set the tiles from where to enter into the building
    void setInteriorEnvironment(); // set the sprites location inside the building
    void setBuildingNames();
    void setBuildingActivity();
    // function overloading here
    void buildingAttributes(sf::Vector2f pos, int buildingNumber, float buildingHeight, sf::IntRect texturePart); // function for buildings whose textures are available in tiles
    void buildingAttributes(sf::Vector2f pos, int buildingNumber, float buildingHeight); // function for buildings whose textures are a single building only

  public:
    Building();
    ~Building();

    std::vector<Rect>& returnMap(); // returns a vector of the mapped tiles (interior)
    const std::vector<sf::Vector2u> &getAllowedTiles() const; // returns a vector of the allowed tiles (exterior)
    const std::vector<Interior> &getInteriorEnvironment() const; // returns a vector of the sprites (interior)
    Activity getBuildingActivity(int);
};


#endif //PULCHOWK_BUILDING_H
