////#include <string>
////#include <iostream>
////#include <list>
////#include <cstdlib>
////#include <ctime>
////#include <SFML/Window.hpp>
////#include <SFML/Graphics.hpp>
////using namespace std;
////
////static const int WINDOW_WIDTH = 512, WINDOW_HEIGHT = 512;
////static const int TILES_WIDE = 8, TILES_HIGH = 8;
////static const int TILE_WIDTH = WINDOW_WIDTH/TILES_WIDE, TILE_HEIGHT = WINDOW_HEIGHT/TILES_HIGH;
////
////enum Tile {
////    TILE_WATER,
////    TILE_DIRT,
////    TILE_INVALID,
////};
////
////class Map {
////public:
////    Map(){}
////    Map(string mapString){
////        // Convert map string into tiles
////        if (mapString.length()!=TILES_WIDE*TILES_HIGH){
////            cerr << "map string is wrong length!";
////            return;
////        }
////
////        for(int i=0;i<TILES_WIDE;i++){
////            for(int j=0;j<TILES_HIGH;j++){
////                char c = mapString[i + j*TILES_WIDE];
////                Tile tile;
////                switch (c){
////                    case ' ': tile = TILE_DIRT; break;
////                    case '~': tile = TILE_WATER; break;
////                    default: tile = TILE_INVALID; break;
////                }
////                setTile(i, j, tile);
////            }
////        }
////    }
////
////    Tile tile(int i, int j){
////        return mTiles[i + j*TILES_WIDE];
////    }
////
////    void setTile(int i, int j, Tile t){
////        if (isValidIndex(i,j)){
////            mTiles[i + j*TILES_WIDE] = t;
////        }
////    }
////
////protected:
////
////    bool isValidIndex(int i, int j){
////        return (i>=0 && i<TILES_WIDE && j>=0 && j<TILES_HIGH);
////    }
////
////    Tile mTiles[TILES_WIDE*TILES_HIGH];
////};
////
////// Base class for all moveable things
////struct Entity {
////    // Actual position
////    int i, j;
////
////    // these are used for position interpolation
////    bool isMoving;
////    int oldI, oldJ;
////    float pi, pj;
////};
////
////struct Player: Entity {
////
////};
////
////enum MonsterType {RED_ZOMBIE, GREEN_ZOMBIE};
////struct Monster: Entity {
////    MonsterType type;
////};
////
////enum GameState {
////    WAITING_FOR_PLAYER_INPUT,
////    UPDATING_PLAYER,
////    UPDATING_MONSTERS,
////
////    // Other game states may be
////    // TITLE_SCREEN
////    // DEATH_SCREEN
////    // UPDATING_BOMBS
////    // etc..
////};
////
////struct Game {
////    GameState state;
////    sf::Clock clock;
////    Map map;
////    Player player;
////    list<Monster> monsters;
////};
////
////// Checks to see if theres a monster here
////bool isMonsterHere(Game& game, int i, int j){
////    for(auto monster: game.monsters){
////        if (monster.i==i && monster.j==j) return true;
////    }
////    return false;
////}
////
////// Checks to see if theres a player here
////bool isPlayerHere(Game& game, int i, int j){
////    if (game.player.i==i && game.player.j==j) return true;
////    else return false;
////}
////
////// Linear interpolation
////float lerp(float a, float b, float t){
////    return a*(1-t) + b*t;
////}
////
////int main(){
////    srand(time(NULL)); // seed randomiser
////    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game");
////
////    // Setup game
////    Game game;
////    game.state = WAITING_FOR_PLAYER_INPUT;
////
////    // Setup map
////    string mapString =
////            "        "
////            " ~~~ ~~ "
////            "        "
////            " ~    ~ "
////
////            " ~    ~ "
////            " ~    ~ "
////            " ~~ ~~~ "
////            "        ";
////    game.map = Map(mapString);
////
////    // Setup player
////    game.player.i = 0;
////    game.player.j = 0;
////    game.player.isMoving = false;
////    game.player.oldI = 0;
////    game.player.oldJ = 0;
////    game.player.pi = 0.0f;
////    game.player.pj = 0.0f;
////
////    // Create some monsters
////    const int NUM_MONSTERS = 6;
////    for(int i=0;i<NUM_MONSTERS;i++){
////        MonsterType type = GREEN_ZOMBIE;
////
////        double random = (1.0*rand())/RAND_MAX;
////        if (random > 0.8){
////            type = RED_ZOMBIE;
////        }
////
////        // Find an empty dirt spot to place the monster
////        int placeI = 0, placeJ = 0;
////        while(true){
////            int ri = rand()%TILES_WIDE;
////            int rj = rand()%TILES_HIGH;
////
////            // Check for collision with player or other zombies
////            bool canPlaceHere = true;
////            canPlaceHere = !isPlayerHere(game, ri, rj);
////            canPlaceHere = canPlaceHere && !isMonsterHere(game, ri, rj);
////            canPlaceHere = canPlaceHere && game.map.tile(ri, rj)==TILE_DIRT;
////            if (canPlaceHere){
////                placeI = ri;
////                placeJ = rj;
////                break;
////            }
////            // else keep trying
////        }
////
////        Monster monster;
////        monster.type = type;
////        monster.i = placeI;
////        monster.j = placeJ;
////        monster.isMoving = false;
////        monster.oldI = monster.i;
////        monster.oldJ = monster.j;
////        monster.pi = (float) placeI;
////        monster.pj = (float) placeJ;
////
////        game.monsters.push_back(monster);
////    }
////
////    // Start loop
////    game.clock.restart();
////    while (window.isOpen())
////    {
////        // Manage Input
////
////        sf::Event event;
////        while (window.pollEvent(event))
////        {
////            if (event.type == sf::Event::Closed){
////                window.close();
////            }
////
////            if (game.state==WAITING_FOR_PLAYER_INPUT){
////                if (event.type==sf::Event::KeyPressed){
////                    int di = 0, dj = 0; // the direction to move in
////                    switch (event.key.code){
////                        case sf::Keyboard::Left: di = -1; break;
////                        case sf::Keyboard::Right: di = 1; break;
////                        case sf::Keyboard::Up: dj = -1; break;
////                        case sf::Keyboard::Down: dj = 1; break;
////                        default: break;
////                    }
////
////                    if (di!=0 || dj!=0){
////                        // Player wants to move so try to move him
////                        int i = game.player.i + di;
////                        int j = game.player.j + dj;
////
////                        // Check targe tile for collision
////                        bool collision = false;
////                        Tile t = game.map.tile(i,j);
////                        switch (t){
////                            case TILE_WATER: case TILE_INVALID: collision = true; break;
////                            default: break;
////                        }
////                        collision = collision || isMonsterHere(game, i, j);
////
////                        if (!collision){
////                            // Can move there
////                            game.player.oldI = game.player.i;
////                            game.player.oldJ = game.player.j;
////                            game.player.i = i;
////                            game.player.j = j;
////                            game.player.isMoving = true;
////                            game.state = UPDATING_PLAYER;
////                            game.clock.restart();
////                        }
////                    }
////                }
////            }
////        }
////
////        // Update other game state etc
////        switch (game.state){
////            case WAITING_FOR_PLAYER_INPUT:
////            {
////                // Player gets only a short time to make a move
////                // The logic of movement is handled in the event handled
////                static const float MAX_TIME_TO_MOVE = 2.0f;
////                float t = game.clock.getElapsedTime().asSeconds();
////                if (t >= MAX_TIME_TO_MOVE){
////                    game.state = UPDATING_PLAYER;
////                    game.clock.restart();
////                }
////                break;
////            }
////            case UPDATING_PLAYER:
////            {
////                static const float MOVE_SPEED = 0.2f; // seconds it takes to move
////                float t = game.clock.getElapsedTime().asSeconds();
////                t = min(MOVE_SPEED, t);
////
////                if (game.player.isMoving){
////                    game.player.pi = lerp(game.player.oldI, game.player.i, t/MOVE_SPEED);
////                    game.player.pj = lerp(game.player.oldJ, game.player.j, t/MOVE_SPEED);
////                }
////
////                if (t >= MOVE_SPEED){
////                    game.player.pi = game.player.i;
////                    game.player.pj = game.player.j;
////                    game.player.oldI = game.player.i;
////                    game.player.oldJ = game.player.j;
////                    game.player.isMoving = false;
////                    game.state = UPDATING_MONSTERS;
////                    game.clock.restart();
////
////                    // We now update all monsters
////                    for(auto& monster: game.monsters){
////                        // Monsters move randomly
////                        // and sometimes stay still
////                        double random = (1.0*rand())/RAND_MAX;
////                        if (random > 0.6){
////                            // stay still
////                            continue;
////                        }
////
////                        // Here's a list of possible directions (di,dj)
////                        static const int DIRS[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
////
////                        // randomly index into the list
////                        int randomDirIndex = rand()%4;
////
////                        // And then try each direction in turn
////                        for(int dir=0;dir<4;dir++){
////                            int index = (dir + randomDirIndex)%4;
////                            int di = DIRS[index][0];
////                            int dj = DIRS[index][1];
////                            int i = monster.i + di;
////                            int j = monster.j + dj;
////
////                            // Check targe tile for collision
////                            bool collision = false;
////                            Tile t = game.map.tile(i,j);
////                            switch (t){
////                                case TILE_WATER: case TILE_INVALID: collision = true; break;
////                                default: break;
////                            }
////                            collision = collision || isPlayerHere(game, i, j) || isMonsterHere(game, i, j);
////
////                            if (!collision){
////                                // Can move there
////                                monster.oldI = monster.i;
////                                monster.oldJ = monster.j;
////                                monster.i = i;
////                                monster.j = j;
////                                monster.isMoving = true;
////                                break;
////                            }
////                        }
////                    }
////                }
////                break;
////            }
////            case UPDATING_MONSTERS:
////            {
////                static const float MOVE_SPEED = 0.4f; // seconds it takes a zombie to move
////                float t = game.clock.getElapsedTime().asSeconds();
////                t = min(MOVE_SPEED, t);
////                for(auto& monster: game.monsters){
////                    if (monster.isMoving){
////                        monster.pi = lerp(monster.oldI, monster.i, t/MOVE_SPEED);
////                        monster.pj = lerp(monster.oldJ, monster.j, t/MOVE_SPEED);
////                    }
////                }
////                if (t >= MOVE_SPEED){
////                    for(auto& monster: game.monsters){
////                        monster.oldI = monster.i;
////                        monster.oldJ = monster.j;
////                        monster.isMoving = false;
////                    }
////                    game.state = WAITING_FOR_PLAYER_INPUT;
////                    game.clock.restart();
////                }
////                break;
////            }
////        }
////
////        // Draw
////        window.clear(sf::Color::Black);
////
////        // Draw map
////        for(int i=0;i<TILES_WIDE;i++){
////            for(int j=0;j<TILES_HIGH;j++){
////                sf::RectangleShape tileRectangle(sf::Vector2f(TILE_WIDTH, TILE_HEIGHT));
////
////                // Convert i,j to top-left screen position of this tile
////                int x = i * TILE_WIDTH;
////                int y = j * TILE_HEIGHT;
////                tileRectangle.setPosition(x, y);
////
////                // Set rect colour based on tile type
////                sf::Color colour;
////                Tile tile = game.map.tile(i,j);
////                switch (tile){
////                    case TILE_DIRT: colour = sf::Color::Black; break;
////                    case TILE_WATER: colour = sf::Color::Blue; break;
////                    default: colour = sf::Color::Magenta; break;
////                }
////                tileRectangle.setFillColor(colour);
////                window.draw(tileRectangle);
////            }
////        }
////
////        // Draw player
////        {
////            static const int PLAYER_SIZE = TILE_WIDTH/2;
////            sf::RectangleShape playerRectangle(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
////            int x = game.player.pi * TILE_WIDTH + (TILE_WIDTH - PLAYER_SIZE)/2;
////            int y = game.player.pj * TILE_HEIGHT + (TILE_HEIGHT - PLAYER_SIZE)/2;
////            playerRectangle.setPosition(x, y);
////            playerRectangle.setFillColor(sf::Color::White);
////            window.draw(playerRectangle);
////        }
////
////        // Draw monsters
////        for(auto monster: game.monsters){
////            static const int MONSTER_SIZE = TILE_WIDTH - 10;
////            sf::RectangleShape monsterRectangle(sf::Vector2f(MONSTER_SIZE, MONSTER_SIZE));
////            int x = monster.pi * TILE_WIDTH + (TILE_WIDTH - MONSTER_SIZE)/2;
////            int y = monster.pj * TILE_HEIGHT + (TILE_HEIGHT - MONSTER_SIZE)/2;
////            monsterRectangle.setPosition(x, y);
////
////            // Choose colour based on type
////            sf::Color color;
////            if (monster.type==RED_ZOMBIE) color = sf::Color::Red;
////            else if (monster.type==GREEN_ZOMBIE) color = sf::Color::Green;
////            monsterRectangle.setFillColor(color);
////            window.draw(monsterRectangle);
////        }
////
////        window.display();
////    }
////    return 0;
////}
//
//
//#include<SFML/Graphics.hpp>
//
//class Collision
//{
//public:
//    Collision(sf::RectangleShape& player);
//    ~Collision();
//
//    void    Move(float dx,float dy){player.move(dx,dy);}
//
//    bool CheckCollision(Collision& other,float push);
//    sf::Vector2f GetPosition(){return player.getPosition();}
//    sf::Vector2f GetHalfSize(){return player.getSize()/2.0f;}
//
//private:
//    sf::RectangleShape player;
//};
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
class Collision
{
private:
    sf::Sprite player;
    sf::Sprite object;
public:
    bool satRectangleAndPoints(const sf::Vector2f rectangleSize, const std::array<sf::Vector2f, 4>& points)
        {
            bool allPointsLeftOfRectangle{ true };
            bool allPointsRightOfRectangle{ true };
            bool allPointsAboveRectangle{ true };
            bool allPointsBelowRectangle{ true };
            for (auto& point : points)
            {
                if (point.x >= 0.f)
                    allPointsLeftOfRectangle = false;
                if (point.x <= rectangleSize.x)
                    allPointsRightOfRectangle = false;
                if (point.y >= 0.f)
                    allPointsAboveRectangle = false;
                if (point.y <= rectangleSize.y)
                    allPointsBelowRectangle = false;
            }
            return !(allPointsLeftOfRectangle || allPointsRightOfRectangle || allPointsAboveRectangle || allPointsBelowRectangle);
        }


/* returns a boolean representing if the two objects' rectangular boundaries are colliding
 allows the collision level to be specified:
     0: AABB (axis-aligned boundaries boxes)
     1: tests if any corners are inside opposite rectangle (performs level 0 first)
     2: SAT (separating axis theorem) (performs levels 0 and 1 first)
    -1: maximum level (default) (performs levels 0, 1 and 2)*/
    bool areColliding(const sf::Sprite player, const sf::Sprite object, const int collisionLevel = -1)
    {
        // checking the axis-aligned bounding box:AABB
        const bool level0{player.getGlobalBounds().intersects(object.getGlobalBounds()) };
        if (!level0 || collisionLevel == 0)
            return level0;

        // any corners inside opposite rectangle
        const sf::Transform transform1{player.getTransform() };
        const sf::Transform transform2{object.getTransform() };
        const sf::Transform inverseTransform1{player.getInverseTransform() };
        const sf::Transform inverseTransform2{object.getInverseTransform() };
        const sf::FloatRect rect1Bounds{player.getLocalBounds() };
        const sf::FloatRect rect2Bounds{object.getLocalBounds() };
        const sf::Vector2f rect1Size{ rect1Bounds.width, rect1Bounds.height };
        const sf::Vector2f rect2Size{ rect2Bounds.width, rect2Bounds.height };
        const sf::Vector2f rect1TopLeft{ inverseTransform2.transformPoint(transform1.transformPoint({ 0.f, 0.f })) };
        const sf::Vector2f rect1TopRight{ inverseTransform2.transformPoint(transform1.transformPoint({ rect1Size.x, 0.f })) };
        const sf::Vector2f rect1BottomRight{ inverseTransform2.transformPoint(transform1.transformPoint(rect1Size)) };
        const sf::Vector2f rect1BottomLeft{ inverseTransform2.transformPoint(transform1.transformPoint({ 0.f, rect1Size.y })) };
        const sf::Vector2f rect2TopLeft{ inverseTransform1.transformPoint(transform2.transformPoint({ 0.f, 0.f })) };
        const sf::Vector2f rect2TopRight{ inverseTransform1.transformPoint(transform2.transformPoint({ rect2Size.x, 0.f })) };
        const sf::Vector2f rect2BottomRight{ inverseTransform1.transformPoint(transform2.transformPoint(rect2Size)) };
        const sf::Vector2f rect2BottomLeft{ inverseTransform1.transformPoint(transform2.transformPoint({ 0.f, rect2Size.y })) };
        const bool level1{ (
                                   (rect1Bounds.contains(rect2TopLeft)) ||
                                   (rect1Bounds.contains(rect2TopRight)) ||
                                   (rect1Bounds.contains(rect2BottomLeft)) ||
                                   (rect1Bounds.contains(rect2BottomRight)) ||
                                   (rect2Bounds.contains(rect1TopLeft)) ||
                                   (rect2Bounds.contains(rect1TopRight)) ||
                                   (rect2Bounds.contains(rect1BottomLeft)) ||
                                   (rect2Bounds.contains(rect1BottomRight))) };
        if (level1 || collisionLevel == 1)
            return level1;

        // LEVEL 2 (SAT)
        std::array<sf::Vector2f, 4> rect1Points
                {
                        rect1BottomLeft,
                        rect1BottomRight,
                        rect1TopRight,
                        rect1TopLeft,
                };
        if (!satRectangleAndPoints(rect2Size, rect1Points))
            return false;
        std::array<sf::Vector2f, 4> rect2Points
                {
                        rect2BottomLeft,
                        rect2BottomRight,
                        rect2TopRight,
                        rect2TopLeft,
                };
        return satRectangleAndPoints(rect1Size, rect2Points);
    }
};