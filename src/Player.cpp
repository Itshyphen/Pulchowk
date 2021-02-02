#include "../headers/Player.h"
Player::Player(){
    extern bool isMale;
    std::string source="../textures/character-bg-erased.png";
    if(isMale!=1) {
        //If the character is male, pass the male sprite
        source="../textures/female.png";
    }

    playerTexture.loadFromFile(source);


    Animation::imageCount.x = 4; // no of rows, only Animation class requires this
    Animation::imageCount.y = 4; // no of columns
    player.setTexture(playerTexture);

    Animation::uvRect.height = playerTexture.getSize().y / static_cast <float>(imageCount.y);
    Animation::uvRect.width =  playerTexture.getSize().x / static_cast <float>(imageCount.x);

    //set origin to the center of the selected intRect
    player.setOrigin(player.getTexture()->getSize().x * 0.5f / 4, player.getTexture()->getSize().y * 0.5f / 4);
    player.setScale(sf::Vector2f(0.04f,0.04f));
    speed = 100.0f;
}

void Player::update(float& deltaTime, sf::View& view){
    sf::Vector2f movement(0.0f,0.0f); // increments added to position when a key is pressed
    extern bool areColliding[58];
    //define the collision variable for  all the collision
    bool collide=false;
    for(int i=0;i<58;i++)
    {
        //If collision of the player with any object occurs collide gets true
        collide=collide||areColliding[i];
    }
    //If not player collided with any buildings and trees then only allow the player to move
    if(!collide) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)||sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { // move left when A is pressed
            movement.x -= speed * deltaTime; // speed * velocity = distance covered
            place = Left;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)||sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { // move right when D is pressed, else if because we need to prevent diagonal movement i.e. only one key pressed at a time
            movement.x += speed * deltaTime;
            place = Right;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)||sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            movement.y -= speed * deltaTime;
            place = Up;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)||sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            movement.y += speed * deltaTime;
            place = Down;
        }
    }
    //Collision with the wall
    //Here we used window size and player size to check the collision with wall
    //Player size=5*10 and window size=600*600
    if (player.getPosition().x <=  5)//If player goes out along left of the map
    {
        if (movement.x<0)
            movement.x = 0;//Set the movement to 0
        //Set the position of the player at the left extreme point of the map
        player.setPosition(5, player.getPosition().y);
    }

    else if(player.getPosition().x >= 595)//If player goes out along right of the map
    {
        if(movement.x>0)
            movement.x = 0;//Set the movement to 0
        //Set the position of the player at the right extreme point of the map
        player.setPosition(595, player.getPosition().y);
    }

    if (player.getPosition().y <=  10)////If player goes above the map
    {
        if (movement.y<0)
            //Set the  y directional movement to 0
            movement.y = 0;
        //Set the position of the player at the top extreme point of the map
        player.setPosition(player.getPosition().x,10);
    }

    else if(player.getPosition().y >= 590)//If the player goes bottom of the map
    {
        if(movement.y>0)
            movement.y = 0;//Set the movement to 0
        //Set the position of the player at the bottom extreme point of the map
        player.setPosition( player.getPosition().x,590);
    }


    if(movement.x == 0.0f and movement.y == 0.0f)
        row = 0;
    else if (movement.x != 0.0f){
        row = 2;
        faceRight = movement.x <= 0.0f;
    }
    else if (movement.y < 0.0f){
        row = 1;
    }
    else{
        row = 0;
    }

    player.setTextureRect(Animation::uvRect);
    if(keyPress()){
        Animation::update(row,deltaTime,faceRight,false);
    }
    else if (!keyPress() && (Animation::curImageX() == 1 || Animation::curImageX() == 3)){
        Animation::update(row,deltaTime,faceRight,true);
    }


    // get the position of the player to update the position after collision
    const float x=player.getPosition().x;
    const float y=player.getPosition().y;

    //If player collided with any of the objects,update the position of player
    if(collide)
    {
        //Player is moving right and get collided, minus the x coordinate of player by 0.1 pixel
        if(place==Right){player.setPosition(sf::Vector2f(x-0.1,y));}
            //Player is moving left and get collided, plus the x coordinate of player by 0.1 pixel
        else if(place==Left){player.setPosition(sf::Vector2f(x+0.1,y));}
            //Player is moving up and get collided, plus the y coordinate of player by 0.1 pixel
        else if(place==Up){player.setPosition(sf::Vector2f(x,y+0.1));}
            //Player is moving down and get collided, minus the y coordinate of player by 0.1 pixel
        else if(place==Down){player.setPosition(sf::Vector2f(x,y-0.1));}
    }
    else{
        player.move(movement);// move the coordinates of the player by adding the coordinates of movement
    }
    view.setCenter(sf::Vector2f(player.getPosition().x, player.getPosition().y)); // set the center to player's position
}

bool Player::keyPress(){
    return sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
           sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)||sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
           sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
}

void Player::draw(sf::RenderTarget &tar, sf::RenderStates states) const {
    tar.draw(player);
}

sf::Sprite &Player::getSprite() {
    return player;
}
//The logic part of a Player:
//void Player::setName(std::string sample) {
//    name = sample;
//}
//
//void Player::setGender(unsigned int val) {
//    gender = val;
//}
//
//void Player::setTime(unsigned int t_val) {
//    time = t_val;
//}
//
//void Player::setBuilding(Building &building_obj) {
//    building = building_obj;
//}

void Player::setAcademics(int a_val) {
    params["academics"] = a_val;
}

void Player::setFun(int f_val) {
    params["fun"] = f_val;
}

void Player::setSocial(int s_val) {
    params["social"] = s_val;
}

void Player::setEnergy(int e_val) {
    params["energy"] = e_val;
}

void Player::setMoney(int m_val) {
    params["money"] = m_val;
}

void Player::setMaterials(int mat_val) {
    params["materials"] = mat_val;
}

int Player::getEnergy() {
    return params["energy"];
}

int Player::getMaterials() {
    return params["materials"];
}

int Player::getSocial() {
    return params["social"];
}

int Player::getFun() {
    return params["fun"];
}

int Player::getMoney() {
    return params["money"];
}

int Player::getAcademics() {
    return params["academics"];
}

void Player::setActivity(Activity a_obj) {
    activity = a_obj;
}

void Player::updateScore(float deltaTime) {
    std::vector<std::pair<std::string,int>> perks = activity.get_perks();
    std::vector<std::pair<std::string,int>> deduces = activity.get_deducements();
    std::vector<std::pair<std::string,int>>::const_iterator it;

    for(it = perks.begin(); it != perks.end(); it++) {
        params[it->first] += it->second * deltaTime;
    }

    for(it = deduces.begin(); it != deduces.end(); it++) {
        params[it->first] -= it->second * deltaTime;
        //We dont want our scores to be negative. So just delete them.
        if (params[it->first] < 0) {
            params[it->first] = 0;
        }
    }
}

/*
Building Player::getBuilding() {
    return building;
}
 */
/*
std::string Player::getBuildingName() {
    return building.getName();
}



//When a player enters a new building, we'll add and deduce perks.
void Player::Enter() {

    std::cout << "So we're going to enter the building." << std::endl;

    add_perk();
    deduce_perk();
}

//Just adding perks to the player after entering a new building.
void Player::add_perk() {
    Activity activity =  building.getActivity();
    std::vector<std::pair<std::string,int>> perks = activity.get_perks();
    std::vector<std::pair<std::string,int>>::const_iterator it;

    for(it = perks.begin(); it != perks.end(); it++) {
        params[it->first] += it->second;
        params[it->first] = params[it->first]%100;
    }
}

//Subtracts necessary scores to perform an activity.
void Player::deduce_perk() {
    Activity activity = building.getActivity();
    std::vector<std::pair<std::string,int>> deduces = activity.get_deducements();
    std::vector<std::pair<std::string,int>>::const_iterator it;


    for(it = deduces.begin(); it != deduces.end(); it++) {
        params[it->first] -= it->second;
    }
}


//Displays player stats to the console.
void Player::show_stats() {
    std::cout << "Player stats:"  << std::endl;
    std::cout << "Academics: " << getAcademics() << std::endl;
    std::cout << "Social: " << getSocial() << std::endl;
    std::cout << "Materials: " << getMaterials() << std::endl;
    std::cout << "Fun: " << getFun() << std::endl;
    std::cout << "Energy: " << getEnergy() << std::endl;
    std::cout << "Money: " << getMoney() << std::endl;
}
 */

//This gives us our final total score out of 100.
//int Player::getScore() {
//    int ans = 0;
//    ans = params["materials"] + params["energy"] + params["academics"] + params["money"] + params["fun"] + params["social"];
//
//    return ans/6;
//}

//This returns a string showing highest score to the game over screen.
std::string Player::getHighestScore() {
    std::string highest;
    int highest_val = 0;

    std::map<std::string, int>::const_iterator it;
    for(it = params.begin(); it != params.end(); it++) {
        if (it->second > highest_val) {
            highest_val = it->second;
            highest = it->first;
        }
    }
    return "Highest in :" + highest + " " + std::to_string(highest_val);
}

//This returns a string showing lowest score to the game over screen.
std::string Player::getLowestScore() {
    std::string lowest;
    int lowest_val = INT8_MAX;

    std::map<std::string, int>::const_iterator it;
    for(it = params.begin(); it != params.end(); it++) {
        if (it->second < lowest_val) {
            lowest_val = it->second;
            lowest = it->first;
        }
    }
    return "Lowest in :" + lowest + " " + std::to_string(lowest_val);
}
