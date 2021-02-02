//
// Created by ppok on 2020-02-28.
//
#include "../headers/Interior.h"
#include "../headers/Building.h"

Building::Building() {
    texture.clear();
    texture.reserve(5);
    for(int i=0;i<5;i++) {
        texture.emplace_back(sf::Texture());
    }

    texture[0].loadFromFile("../textures/Department-tileset-low.png");
    texture[1].loadFromFile("../textures/bike-park.png");
    texture[2].loadFromFile("../textures/ictc-with-door.png");
    texture[3].loadFromFile("../textures/canteen-robo-lib-cit.png");
    texture[4].loadFromFile("../textures/guard-locus-toilet-workshop-small.png");

    sprite_vector.reserve(14); // we know beforehand we need 14 sprites throughout

    // now to store 14 sprites with their textures in the vector array, which we will modify later on
    for (int i=0;i<4;i++){
        sprite_vector.emplace_back(texture[3]);
    }
    for(int i=0;i<4;i++){
        sprite_vector.emplace_back(texture[4]);
    }
    sprite_vector.emplace_back(texture[2]);
    sprite_vector.emplace_back(texture[1]);

    for (int i=0;i<4;i++) {
        sprite_vector.emplace_back(texture[0]);
    }

    setBuildingPosition();
    setInteriorMaps();
    setAllowedTiles();
    setInteriorEnvironment();

    setBuildingNames();
    setBuildingActivity();
}

Building::~Building() {
    sprite_vector.clear();
    sprite_vector.shrink_to_fit();

    texture.clear();
    texture.shrink_to_fit();

    allowedTiles.clear();
    allowedTiles.shrink_to_fit();

    interiorMaps.clear();
    interiorMaps.shrink_to_fit();
}

void Building::setBuildingPosition() {
    // canteen
    buildingAttributes(sf::Vector2f(0,28),0,120,sf::IntRect(0,0,120,120)); // as the function name suggests, all building except the department
    // cit
    buildingAttributes(sf::Vector2f(13,20),1,120,sf::IntRect(360,0,120,120));
    // library
    buildingAttributes(sf::Vector2f(13,28),2,120,sf::IntRect(240,0,120,120));
    // robotics
    buildingAttributes(sf::Vector2f(5,20),3,120,sf::IntRect(120,0,120,120));
    // guard (or ATM depends)
    buildingAttributes(sf::Vector2f(4,4),4,60,sf::IntRect(0,0,60,60));
    // LOCUS office
    buildingAttributes(sf::Vector2f(3,12),5,60,sf::IntRect(60,0,60,60));
    // Toilet (behind administration one)
    buildingAttributes(sf::Vector2f(0,19),6,60,sf::IntRect(120,0,60,60));
    // Workshop
    buildingAttributes(sf::Vector2f(8,25),7,60,sf::IntRect(180,0,60,60));
    // ICTC
    buildingAttributes(sf::Vector2f(24,28),8,280);
    // Bike Stand
    buildingAttributes(sf::Vector2f(26,10),9,120);

    // Department Building (Electronics, Computer, Electrical)
    buildingAttributes(sf::Vector2f(15,4),10,100, sf::IntRect(60, 0, 180, 100));
    buildingAttributes(sf::Vector2f(21,7),11,100, sf::IntRect(0, 0, 60, 100));
    buildingAttributes(sf::Vector2f(21,5),12,100, sf::IntRect(0, 60, 60, 40));
    buildingAttributes(sf::Vector2f(6,12),13,100,sf::IntRect(240, 0, 360, 100));
}

void Building::buildingAttributes(sf::Vector2f pos, int buildingNumber, float buildingHeight, sf::IntRect texturePart) {
    sprite_vector[buildingNumber].setOrigin(0,buildingHeight); // set the origin to your convenience
    sprite_vector[buildingNumber].setPosition(sf::Vector2f(pos.x * 20,pos.y * 20)); // set the position for each element in the building sprite
    sprite_vector[buildingNumber].setTextureRect(texturePart);

}

void Building::buildingAttributes(sf::Vector2f pos, int buildingNumber, float buildingHeight) {
    sprite_vector[buildingNumber].setOrigin(0,buildingHeight); // set the origin to your convenience, now it is set to (0, buildingHeight)
    sprite_vector[buildingNumber].setPosition(sf::Vector2f(pos.x * 20,pos.y * 20)); // set the position for each element in the building sprite
}

void Building::setInteriorMaps() {
    // for now, I'll be drawing tile maps for the interior of each building
    // add sprites and background texture, whoever works on it
    interiorMaps.reserve(9);

    // add 9 tile maps to vector for 9 buildings enter-able for now
    for (int i =0;i<9;i++) {
        interiorMaps.emplace_back(Rect());
    }

    int buildingMap[100];
    // for now the tilemap of each building is same, so use for loops to add the tiles from the texture rect
    // use the same array because the tilemap for each building is the same
    for (int i =0;i<20;i++){
        buildingMap[i] = 1; // texture number 1 for all tiles starting from 0 to 19 of the floor
    }

    for (int i =20;i<30;i++){
        buildingMap[i] = 2;
    }

    for (int i =30;i<40;i++){
        buildingMap[i] = 3;
    }

    for (int i =40;i<100;i++){
        buildingMap[i] = 0;
    }

    // will use 40x40 tiles for now, 10 in the horizontal, 10 in the vertical, 10 in the horizontal
    // for building 0, the map will be 0. One-one correspondence/function (indirect way to use c++ maps)
    interiorMaps[Canteen].setTiles("../textures/Interior/Canteen/canteen-tileset(1).png",sf::Vector2u(40,40),buildingMap,10,10);
    interiorMaps[CIT].setTiles("../textures/Interior/CIT/cit-tileset(1).png",sf::Vector2u(40,40),buildingMap,10,10);
    interiorMaps[Library].setTiles("../textures/Interior/Library/library-tileset(1).png",sf::Vector2u(40,40),buildingMap,10,10);
    interiorMaps[Robotics].setTiles("../textures/Interior/Robotics/robotics-tileset(1).png",sf::Vector2u(40,40),buildingMap,10,10);
    interiorMaps[ATM].setTiles("../textures/Interior/ATM/atm-tileset(1).png",sf::Vector2u(40,40),buildingMap,10,10);
    interiorMaps[LOCUS].setTiles("../textures/Interior/LOCUS/locus-tileset(1).png",sf::Vector2u(40,40),buildingMap,10,10);
    interiorMaps[Toilet].setTiles("../textures/Interior/Toilet/toilet-tileset(1).png",sf::Vector2u(40,40),buildingMap,10,10);
    interiorMaps[ICTC].setTiles("../textures/Interior/ICTC/ictc-tileset(1).png",sf::Vector2u(40,40),buildingMap,10,10);
    /*
     * the setTiles accepts five parameters, just like in the Rect class
     * we have a vector of Rect class here, code re-usability
     */
    interiorMaps[Department].setTiles("../textures/Interior/Classroom/class-tileset-2(1).png",sf::Vector2u(40,40),buildingMap,10,10);
}

std::vector<Rect>& Building::returnMap() {
    // used to render the maps in the game.cpp, store a different type of object in the future, not necessarily tile maps
    return interiorMaps;
}

void Building::setAllowedTiles() {
    // the coordinates of the tiles from where the player is allowed to enter the building
    // usually the tile just before the door
    allowedTiles.emplace_back(sf::Vector2u(4,28));
    allowedTiles.emplace_back(sf::Vector2u(17,20));
    allowedTiles.emplace_back(sf::Vector2u(17,28));
    allowedTiles.emplace_back(sf::Vector2u(9,20));
    allowedTiles.emplace_back(sf::Vector2u(5,4));
    allowedTiles.emplace_back(sf::Vector2u(4,12));
    allowedTiles.emplace_back(sf::Vector2u(1,19));
    allowedTiles.emplace_back(sf::Vector2u(28,28));
    allowedTiles.emplace_back(sf::Vector2u(22,12));


}

const std::vector<sf::Vector2u> &Building::getAllowedTiles() const {
    return allowedTiles;
}

void Building::setInteriorEnvironment() {
    interiorEnvironment.clear();
    interiorEnvironment.reserve(9);

    // select which textures you want to choose from the tileset
    // select where to place each tile, by default I have set the origin at (0, spriteHeight)
//    const float scale_classroom[] = {2.0f,2.0f,2.0f,2.0f}; // select the scale factors for each sprite with corresponding textures 1,2,3,4

    const int texture_canteen[] = {0,1,2};
    const int texture_CIT[] = {0,0,1,1,2};
    const int texture_Library[] = {0,1,4};
    const int texture_Robotics[] = {0,1,2};
    const int texture_ATM[] = {0,1};
    const int texture_Locus[] = {0,1,2};
    const int texture_Toilet[] = {1,2,3};
    const int texture_ICTC[] = {0,1,2};
    const int texture_classroom[] = {1,2,3,4};

    const int position_canteen[] = {40,46,90,96};
    const int position_cit[] = {61,68,91,98,38};
    const int position_library[] = {30,36,90};
    const int position_robotics[] = {30,80,36};
    const int position_atm[] = {33,35};
    const int position_locus[] = {40,80,46};
    const int position_toilet[] = {60,63,66};
    const int position_ictc[] = {83,30,36};
    const int position_classroom[] = {84,64,24,44};

    const float scale_library[] = {0.75f,0.75f,0.5f};
    const float scale_LOCUS[] = {0.5f,0.5f,0.5f};
/*
 * send the following parameters to the constructor of the Interior class
 * 1) the location for the Tileset
 * 2) number of sprites you want to draw in the room
 * 3) the width of each sprite (the tileset MUST HAVE all textures of EQUAL WIDTH)
 * 4) the height of each sprite (the tileset MUST HAVE all textures of EQUAL HEIGHT)
 * 5) the texture array, each integer element being the texture you want to use (the first texture in the tileset has coordinate 0)
 * 6) the tile size, it is the size of the tile you have used to draw the vertex array map (here we have filled the background with 40X40 tiles, so tSize = 40)
 */
    interiorEnvironment.emplace_back(Interior("../textures/Interior_Sprites/Canteen.png",3,160,80,texture_canteen,40));
    interiorEnvironment.emplace_back(Interior("../textures/Interior_Sprites/CIT_80x80.png",5,80,80,texture_CIT,40));
    interiorEnvironment.emplace_back(Interior("../textures/Interior_Sprites/library-sprites.png",3,160,160,texture_Library,40));
    interiorEnvironment.emplace_back(Interior("../textures/Interior_Sprites/Robotics.png",3,240,160,texture_Robotics,40));
    interiorEnvironment.emplace_back(Interior("../textures/Interior_Sprites/ATM_120x80.png",2,80,120,texture_ATM,40));
    interiorEnvironment.emplace_back(Interior("../textures/Interior_Sprites/Locus-office.png",3,200,160,texture_Locus,40));
    interiorEnvironment.emplace_back(Interior("../textures/Interior_Sprites/toilet-spritesheet.png",3,90,240,texture_Toilet,40));
    interiorEnvironment.emplace_back(Interior("../textures/Interior_Sprites/ICTC.png",3,160,160,texture_ICTC,40));
    interiorEnvironment.emplace_back(Interior("../textures/Classroom_texture_70x40.png",4,72,40,texture_classroom,40));

    /*
     * the position array contains the number of the tile (in the tilemap we have drawn before) where we want the sprite to be drawn.
     * for example, if you want to draw a sprite at the location of the tile 45, pass 45 as of the values of the position array
     */
    interiorEnvironment[Canteen].setPosForSprites(position_canteen);
    interiorEnvironment[CIT].setPosForSprites(position_cit);
    interiorEnvironment[Library].setPosForSprites(position_library);
    interiorEnvironment[Robotics].setPosForSprites(position_robotics);
    interiorEnvironment[ATM].setPosForSprites(position_atm);
    interiorEnvironment[LOCUS].setPosForSprites(position_locus);
    interiorEnvironment[Toilet].setPosForSprites(position_toilet);
    interiorEnvironment[ICTC].setPosForSprites(position_ictc);
    interiorEnvironment[Department].setPosForSprites(position_classroom);

    interiorEnvironment[Library].setScale(scale_library);
    interiorEnvironment[LOCUS].setScale(scale_LOCUS);
    // pass the array with scale factor for each sprite starting from index 0
    // must correspond to the texture_classroom array and position array
}

const std::vector<Interior> &Building::getInteriorEnvironment() const {
    return interiorEnvironment;
}


void Building::setBuildingActivity() {
  //We will construct instances of different activites and assign them to a vector

  //attend_lecture
  Activity attend_lecture("attend_lecture");
  attend_lecture.add_deducements("energy", 10);
  attend_lecture.add_perks("academics", 5);
  attend_lecture.add_perks("social", 5);

  //chit_chat
  Activity chit_chat("chit_chat");
  chit_chat.add_perks("fun", 20);
  chit_chat.add_deducements("academics", 5);
  chit_chat.add_perks("social", 15);

  //study
  Activity study("study");
  study.add_threshold("materials", 20);
  study.add_threshold("energy", 25);
  study.add_deducements("social", 10);
  study.add_deducements("energy", 20);
  study.add_perks("academics", 20);

  //build_robotics
  Activity build_robotics("build_robotics");
  build_robotics.add_deducements("money", 20);
  build_robotics.add_perks("academics", 10);
  build_robotics.add_perks("materials", 35);

  //eat_snacks
  Activity eat_snacks("eat_snacks");
  eat_snacks.add_deducements("money", 20);
  eat_snacks.add_perks("energy", 30);

  //attend_seminar
  Activity attend_seminar("attend_seminar");
  attend_seminar.add_deducements("energy", 20);
  attend_seminar.add_perks("social", 20);
  attend_seminar.add_deducements("money", 5);

  //take_money
  Activity take_money("Take Money");
  take_money.add_perks("money", 55);

  //Surf_internet
  Activity surf_internet("Surf Internet");
  surf_internet.add_deducements("academics", 15);
  surf_internet.add_deducements("energy", 5);
  surf_internet.add_perks("social", 25);
  surf_internet.add_perks("fun", 10);

  //Take_a_leak
  Activity take_a_leak("Take a Leak");
  take_a_leak.add_deducements("materials", 5);
  take_a_leak.add_perks("energy", 15);
  take_a_leak.add_perks("social" , 5);

  building_activities.push_back(eat_snacks);
  building_activities.push_back(surf_internet);
  building_activities.push_back(study);
  building_activities.push_back(build_robotics);
  building_activities.push_back(take_money);
  building_activities.push_back(chit_chat);
  building_activities.push_back(take_a_leak) ;
  building_activities.push_back(attend_seminar);
  building_activities.push_back(attend_lecture);

}
void Building::setBuildingNames() {
    building_names.push_back("Lab");
    building_names.push_back("FSU HALL");
    building_names.push_back("LECTURE HALL");
    building_names.push_back("SEMINAR HALL");
    building_names.push_back("ADMINISTRATIVE BUILDING");
    building_names.push_back("LIBRARY");
    building_names.push_back("STATIONERY");
    building_names.push_back("PLAYGROUND");
    building_names.push_back("MUSIC HALL");
}

Activity Building::getBuildingActivity(int index) {
    return building_activities[index];
}


