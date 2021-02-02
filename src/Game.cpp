//
// Created by ppok on 2020-02-15.
//
#include "../headers/Game.h"
#include "../headers/Button.h"
#include <fstream>

bool areColliding[58];
extern std::string nam;
Game::Game(){}
Game::Game(std::string title){
    window.create({500,500,32},title);
    window.setFramerateLimit(120);
    isInside = false;
    splashTime = 0.0f;

    p1.getSprite().setPosition(window.getSize().x * 0.5f, window.getSize().y * 0.5f); // set the sprite to middle of the screen

    // in level array you define what texture goes into what sub-rectangle of size 40x40.
    // the format is level[] = { rect1 rect2 rect3 rect4... and so on as per the picture you want
    // here for rect1 starting at (0,0) the texture will be the texture at position 0 of textures_ground.png
    const int map_1[] = {
            18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
            6,   6,  6,  6,  2,  2,  2,  7,  7,  7,  7,  7,  6,  6,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  6,  6,  7,  7,  7,  7,
            6,   6,  6,  6,  2,  2,  2,  7,  7,  7,  7,  7,  6,  6,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  6,  6,  7,  7,  7,  7,
            19,  6,  6,  6,  2,  2,  2,  7,  7,  7,  7,  7,  6,  6,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  6,  6,  7,  7,  7,  7,
            7,   6,  6,  6,  7,  7,  7,  7,  7,  7,  7,  7,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  2,  2,  6,  6,  6,  6,  6,  6,
            7,   6,  6,  6,  7,  7,  7,  7,  7,  7,  7,  7,  6,  6,  7,  7,  7,  7,  7,  7,  7,  6,  2,  2,  6,  6, 19, 19, 19, 19,
            7,   6,  6,  6,  7,  7,  7,  7,  7,  7,  7,  7,  6,  6,  7,  7,  7,  7,  7,  7,  7,  6,  2,  2,  6,  6, 19, 19, 19, 19,
            7,   6,  6,  6,  7,  7,  7,  7,  7,  7,  7,  7,  6,  6,  7,  7,  7,  7,  7,  7,  7,  6,  2,  2,  6,  6, 19, 19, 19, 19,
            7,   6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  2,  2,  6,  6, 19, 19, 19, 19,
            7,   6,  6,  6,  6,  6,  6,  6,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  6,  6, 19, 19, 19, 19,
            7,   6,  6,  6,  6,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  6,  6, 19, 19, 19, 19,
            7,   6,  6,  6,  6,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  6,  6, 19, 19, 19, 19,
            7,   6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
            19,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
            6,   6,  6,  6,  6,  2,  2,  2,  2,  2,  2,  6,  6,  2,  2,  2,  2,  2,  2, 19, 19,  6,  6, 19,  2,  2,  2,  2,  2,  2,
            6,   6,  6,  6,  6,  2,  2,  2,  2,  2,  2,  6,  6,  2,  2,  2,  2,  2,  2, 19, 19,  6,  6, 19,  2,  2,  2,  2,  2,  2,
            2,   2,  2,  6,  6,  2,  2,  2,  2,  2,  2,  6,  6,  2,  2,  2,  2,  2,  2, 19, 19,  6,  6, 19,  2,  2,  2,  2,  2,  2,
            2,   2,  2,  6,  6,  2,  2,  2,  2,  2,  2,  6,  6,  2,  2,  2,  2,  2,  2, 19, 19,  6,  6, 19,  2,  2,  2,  2,  2,  2,
            2,   2,  2,  6,  6,  2,  2,  2,  2,  2,  2,  6,  6,  2,  2,  2,  2,  2,  2, 19, 19,  6,  6, 19,  2,  2,  2,  2,  2,  2,
            7,   6,  6,  6,  6,  2,  2,  2,  2,  2,  2,  6,  6,  2,  2,  2,  2,  2,  2, 19, 19,  6,  6, 19,  2,  2,  2,  2,  2,  2,
            7,   6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6, 19,  2,  2,  2,  2,  2,  2,
            7,   6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6, 19,  2,  2,  2,  2,  2,  2,
            7,   6,  6,  6,  6,  7,  6,  6,  2,  2,  2,  6,  6,  2,  2,  2,  2,  2,  2, 19, 19,  6,  6, 19,  2,  2,  2,  2,  2,  2,
            2,   2,  2,  2,  2,  2,  7,  7,  2,  2,  2,  6,  6,  2,  2,  2,  2,  2,  2, 19, 19,  6,  6, 19,  2,  2,  2,  2,  2,  2,
            2,   2,  2,  2,  2,  2,  7,  7,  2,  2,  2,  6,  6,  2,  2,  2,  2,  2,  2,  7,  7,  6,  6, 19,  2,  2,  2,  2,  2,  2,
            2,   2,  2,  2,  2,  2,  7,  7,  7,  7,  7,  6,  6,  2,  2,  2,  2,  2,  2,  7,  7,  6,  6, 19,  2,  2,  2,  2,  2,  2,
            2,   2,  2,  2,  2,  2,  7,  7,  7,  7,  7,  6,  6,  2,  2,  2,  2,  2,  2, 19, 19,  6,  6, 19,  2,  2,  2,  2,  2,  2,
            2,   2,  2,  2,  2,  2,  7,  7,  7,  7,  7,  7,  7,  2,  2,  2,  2,  2,  2, 19, 19,  6,  6, 19,  2,  2,  2,  2,  2,  2,
            6,   6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
            6,   6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,
    };
    map1.setTiles("../textures/textures_ground_20x20.png",sf::Vector2u(20,20),map_1,30,30);

    // height = 600 (windowHeight) / 20 (tileHeight) = 30 (same for width since the window is a square
    // that means there are 30 tiles vertically and 30 tiles horizontally

    view.setSize(sf::Vector2f(400,400));
    view.zoom(0.75f); // change the zoom scope here
    font.loadFromFile("../res/font/arial.ttf");

    scoreboard.clear();
    for(int i=0;i<7;i++){
        scoreboard.emplace_back(sf::Text());
    }

    for(int i=0; i<7; i++) {
        scoreboard[i].setCharacterSize(10);
        scoreboard[i].setFont(font);
        scoreboard[i].setFillColor(sf::Color::White);
    }
    initialilze_Player_Stats(p1);
    updateScoreboardScore();
    updateScoreboardPosition();
    setTimebar();
    updateTimebar();
    //Run the game
    run();
}

void Game::run() {
    dTime = 0.0f;
  while (window.isOpen()) {
    dTime = clock.restart().asSeconds();

      //Our time keeps on increasing at 5 times faster than usual.
      time1.addTime(dTime * 5);
      //Then we check to see if the game is over i.e. Is it already
      if (time1.getHour() > 16) {
          isGameOver = true;
      }

    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          Exit();
          break;
        default:
          break;
      }
    }
    std::string welcome[9]={"Canteen","CIT","Library","Robotics Club","ATM","LOCUS","WASHROOM","ICTC","Lecture hall"};
      std::string greet[15]={"Are you guys planning my Birthday?","May I join you Guys?","Hi!Whatsup?","Lets go out!!!","Hello!\nHow are you?","May I join you Guys?","Hi!Whatsup?","Hey!Lets go out.","Hi Guys!!!","Hello Uncle!!!","Why are you alone\nHow was your\nAssessment?","Hello Guys!!!","May I join You?","Hello Guys!!!","Are You in Hurry?"};
      sf::Text text[15],enter[9],exit,over;
      sf::Font font;
      if (!font.loadFromFile("../res/font/arial.ttf")) {
          // handle error
      }
      //Getting the text for hello when colliding with the other avatar
      for (int i=0;i<15;i++)
      {
          text[i].setString(greet[i]);
          text[i].setCharacterSize(20);
          text[i].setFillColor(sf::Color::Black);
          text[i].setFont(font);
          text[i].setPosition(p1.getSprite().getPosition());
      }

      //Properties of Text to be displayed when entering any building
      for (int i=0;i<9;i++)
      {
          enter[i].setString(welcome[i]);
          enter[i].setCharacterSize(20);
          enter[i].setFillColor(sf::Color::White);
          enter[i].setFont(font);
          enter[i].setPosition(p1.getSprite().getPosition().x-40,p1.getSprite().getPosition().y-20);
      }

      //Text to be displayed when exiting from any building
      exit.setString("Lets Exit!!!");
      exit.setCharacterSize(20);
      exit.setFillColor(sf::Color::White);
      exit.setFont(font);
      exit.setPosition(p1.getSprite().getPosition().x-30,p1.getSprite().getPosition().y-20);

      //GameOver
      over.setString("    The Day is Over!!!\n  Loading your Profile...");
      over.setCharacterSize(35);
      over.setFillColor(sf::Color::White);
      over.setFont(font);
      over.setPosition(p1.getSprite().getPosition().x-150,p1.getSprite().getPosition().y-60);

      for (int i=0;i<9;i++) {
      // check to see if the player is on any one of the allowed tiles (9 tiles)
      // also check to see if the player has pressed the 'Z' button
      // if both conditions are fulfilled, set isInside to true and display the splashScreen
      // also, store the allowedTiles which fulfilled the condition value in buildingNumberEntered
      if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) &&
          (static_cast<int>(p1.getSprite().getPosition().x) > (building.getAllowedTiles()[i].x * 20)) &&
          (static_cast<int>(p1.getSprite().getPosition().x) < (building.getAllowedTiles()[i].x * 20 + 20)) &&
          (static_cast<int>(p1.getSprite().getPosition().y) > (building.getAllowedTiles()[i].y * 20)) &&
          (static_cast<int>(p1.getSprite().getPosition().y) < (building.getAllowedTiles()[i].y * 20 + 20))) {

          isInside = true;
          p1.setActivity(building.getBuildingActivity(i));
          insideTimeAdder = dTime;
          clock_2.restart();

           splashScreen(dTime,enter[i]);
           buildingNumberEntered = i;
           p1.getSprite().setPosition(170.0f,360.0f);
      }

      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        // if escape key is pressed, go outside (set isInside to 'false')
        // wherever the player is, set it's position outside to where it entered from
        isInside = false;

          //insideTime = clock_2.getElapsedTime().asSeconds();
          p1.updateScore(insideTime);
          insideTimeAdder = 0.0f;
          //clock_2.restart()

          p1.getSprite().setPosition((static_cast<float>(building.getAllowedTiles()[buildingNumberEntered].x) + 0.5f) * 20,
                                   (static_cast<float>(building.getAllowedTiles()[buildingNumberEntered].y + 0.5f) * 20));
          splashScreen(dTime,exit);

        // display the exterior once so that the slight time lag/glitch is avoided
        // mostly to update the player position to the door position from where it entered
        // not sure how this works, but it works!
        window.draw(map1);
        p1.update(dTime, view);
          for(int i=0;i<building.getSpriteVector().size();i++){
              //This is the part of collision detection of player and buildings
              areColliding[i]=Colliding(p1.getSprite(),building.getSpriteVector()[i]);
          }
          for(int i=0;i<tree.getSpriteVector().size();i++){
              //This is the part of collision detection of player and trees
              areColliding[i+14]=Colliding(p1.getSprite(),tree.getSpriteVector()[i]);
          }
          for(int i=0;i<avatar.getSpriteVector().size();i++){
              //This is the part of collision detection of player and trees
              areColliding[i+39]=Colliding(p1.getSprite(),avatar.getSpriteVector()[i]);
          }

        window.draw(p1);

        for (int i = 0; i < building.getSpriteVector().size(); i++) {
          window.draw(building.getSpriteVector()[i]);
        }
        for (int i = 0; i < tree.getSpriteVector().size(); i++) {
          window.draw(tree.getSpriteVector()[i]);
        }
          for(int i=0;i<avatar.getSpriteVector().size();i++){
              window.draw(avatar.getSpriteVector()[i]);
          }
        window.setView(view);
        window.display();
      }

    }
      if (isGameOver) {
          WriteFile();
          splashScreen(dTime,over);
          window.close();
          showGameOver();
      }

    else if (isInside){
      // if is inside, draw the contents of the interior of the corresponding buildingNumberEntered
      window.clear(sf::Color::Black);
      window.draw(building.returnMap()[buildingNumberEntered]);
      for (int i=0;i<building.getInteriorEnvironment()[buildingNumberEntered].getSpriteVector().size();i++) {
        window.draw(building.getInteriorEnvironment()[buildingNumberEntered].getSpriteVector()[i]); // code to draw the sprites

        // you can get the vector using building.getIngetInteriorEnvironment()[buildingNumber].getSpriteVector()
      }
      p1.update(dTime, view); // update the player position and view
        for (int i=0;i<building.getInteriorEnvironment()[buildingNumberEntered].getSpriteVector().size();i++) {
            //Checks the collision between the player and interior of classroom
            areColliding[i+54]=Colliding(p1.getSprite(),building.getInteriorEnvironment()[buildingNumberEntered].getSpriteVector()[i]);
        }

        window.draw(p1);
        updateTimebar();
        window.draw(time_board);
        window.setView(view);
        window.display();
        insideTime += insideTimeAdder;
    }
    else {
      window.clear();
      window.draw(map1); // the draw function is overloaded so you don't have to add the texture along with draw
      p1.update(dTime, view); // update the player position and view

        for(int i=0;i<building.getSpriteVector().size();i++){
            //This is the part of collision detection of player and buildings
            areColliding[i]=Colliding(p1.getSprite(),building.getSpriteVector()[i]);
        }
        for(int i=0;i<tree.getSpriteVector().size();i++){
            //This is the part of collision detection of player and trees
            areColliding[i+14]=Colliding(p1.getSprite(),tree.getSpriteVector()[i]);
        }
        for(int i=0;i<avatar.getSpriteVector().size();i++){
            //This is the part of collision detection of player and characters
            areColliding[i+39]=Colliding(p1.getSprite(),avatar.getSpriteVector()[i]);
        }
        window.draw(p1);
        for (int i = 0; i < building.getSpriteVector().size(); i++) {
            window.draw(building.getSpriteVector()[i]);
        }
        for (int i = 0; i < tree.getSpriteVector().size(); i++) {
            window.draw(tree.getSpriteVector()[i]);
        }
        for(int i=0;i<avatar.getSpriteVector().size();i++){
            window.draw(avatar.getSpriteVector()[i]);
        }
        updateScoreboardScore();
        updateScoreboardPosition();
        updateTimebar();

        for(int i=0; i<7; i++) {
            window.draw(scoreboard[i]);
        }
        window.draw(time_board);

        // since the player position has changed, set the view as per the new player coordinates
        window.setView(view);

        for(int i=39;i<54;i++){
            //Checks if the player collided with any other characters
            //If collided display the hello message
            if(areColliding[i]) {window.draw(text[i-39]);social+=1;}
        }
        window.display();
    }
  }
}

void Game::splashScreen(float dt,const sf::Text& welcome) {
    // a black screen to be shown on the screen while the textures are loaded/drawn
    // change time of display by modifying the 2.0f parameter
    while (splashTime < 2.0f){
        window.clear(sf::Color::Black);
        window.draw(welcome);
        window.display();
        splashTime += dTime;
    }
    splashTime -= 2.0f; // decrement the splashTime so that it will work the next time
    // whoever has free time, please make this a loading screen. Use sf::Text and display the text loading screen
}
//Checking the collision of the passed sprite
bool Game::Colliding(const sf::Sprite& player, const sf::Sprite& object) {
    return player.getGlobalBounds().intersects(object.getGlobalBounds());
}

//This sets the position of our scoreboard..
void Game::updateScoreboardPosition() {
    scoreboard[0].setPosition(p1.getSprite().getPosition().x - 150, p1.getSprite().getPosition().y - 150);
    scoreboard[1].setPosition(p1.getSprite().getPosition().x -80, p1.getSprite().getPosition().y - 150);
    scoreboard[2].setPosition(p1.getSprite().getPosition().x - 10, p1.getSprite().getPosition().y - 150);
    scoreboard[3].setPosition(p1.getSprite().getPosition().x + 70, p1.getSprite().getPosition().y - 150);
    scoreboard[4].setPosition(p1.getSprite().getPosition().x - 80, p1.getSprite().getPosition().y - 140);
    scoreboard[5].setPosition(p1.getSprite().getPosition().x - 10, p1.getSprite().getPosition().y - 140);
    scoreboard[6].setPosition(p1.getSprite().getPosition().x + 70, p1.getSprite().getPosition().y - 140);
    for(int i=0;i<7;i++)
    {
        scoreboard[i].setFillColor(sf::Color::White);
    }
}

//This is used to assign a player its different scores at the beginning of the game.
void Game::initialilze_Player_Stats(Player &instance) {
    instance.setAcademics(40);
    instance.setFun(50);
    instance.setMoney(50);
    instance.setMaterials(45);
    instance.setSocial(50);
    instance.setEnergy(50);
}

//We need to keep updating the scoreboard's scores as well..
void Game::updateScoreboardScore() {
    scoreboard[0].setString("SCOREBOARD::");
    scoreboard[1].setString("ENERGY :" + std::to_string(p1.getEnergy()));
    scoreboard[2].setString("ACADEMICS :" + std::to_string(p1.getAcademics()));
    scoreboard[3].setString("SOCIAL          :" + std::to_string(p1.getSocial()));
    scoreboard[4].setString("FUN       :" + std::to_string(p1.getFun()));
    scoreboard[5].setString("MONEY          :" + std::to_string(p1.getMoney()));
    scoreboard[6].setString("MATERIALS  :"+ std::to_string(p1.getMaterials()));
}

//Updating the timebar position as per player and string as per current time.
void Game::updateTimebar() {
    time_board.setString("Time " + std::to_string(static_cast<int>(time1.getHour())) + " : "  + std::to_string(static_cast<int>(time1.getMinutes())));
    time_board.setPosition(p1.getSprite().getPosition().x - 150, p1.getSprite().getPosition().y - 140);
}

//This function sets the time bar font and size
void Game::setTimebar() {
    time_board.setFont(font);
    time_board.setCharacterSize(12);
    time_board.setFillColor(sf::Color::White);
}

//After the game is over , we render game over screen
void Game::showGameOver() {

    sf::RenderWindow overwindow(sf::VideoMode(800, 600), "PULCHOWK",sf::Style::Close);
    sf::Text text;
    font.loadFromFile("../res/font/arial.ttf");
    text.setString("Here is your Profile!!!\n____________________________");
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setPosition(10,10);

    Button exit;
    exit.setButton("Exit", {100 , 40 }, 40, sf::Color::Black, sf::Color::White);
    exit.setFont(font);
    exit.setPosition({ 650, 500 });

    Button restart;
    restart.setButton("Restart", {120 , 40 }, 40, sf::Color::Black, sf::Color::White);
    restart.setFont(font);
    restart.setPosition({ 50, 500 });

    while (overwindow.isOpen())
    {
        sf::Event event;
        while (overwindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                overwindow.close();
            if(event.type== sf::Event::MouseButtonPressed) {
                if (exit.isMouseOver(overwindow)) {
                    overwindow.close();
                    window.close();
                }
                if (restart.isMouseOver(overwindow)) {
                    isGameOver = 0;
                    overwindow.close();
                    Game game("PULCHOWK");
                }
            }
        }
            sf::Text game_over, highest_score, lowest_score, restart_game;

    //game_over.setPosition(p1.getSprite().getPosition().x - 55, p1.getSprite().getPosition().y - 40);
    highest_score.setPosition(100,200);
    lowest_score.setPosition(100,350);

        score[0].setString("SCOREBOARD::");
        score[1].setString("ENERGY :" + std::to_string(p1.getEnergy()));
        score[2].setString("ACADEMICS :" + std::to_string(p1.getAcademics()));
        score[3].setString("SOCIAL          :" + std::to_string(p1.getSocial()));
        score[4].setString("FUN       :" + std::to_string(p1.getFun()));
        score[5].setString("MONEY          :" + std::to_string(p1.getMoney()));
        score[6].setString("MATERIALS  :"+ std::to_string(p1.getMaterials()));
    for(int i=0;i<7;i++){
        score[i].setPosition(10,50*(i+1));
        score[i].setCharacterSize(20);
        score[i].setFont(font);
    }


    highest_score.setString(p1.getHighestScore());
    lowest_score.setString(p1.getLowestScore());

    highest_score.setFillColor(sf::Color::Green);
    lowest_score.setFillColor(sf::Color::Green);

    highest_score.setFont(font);
    lowest_score.setFont(font);

    highest_score.setCharacterSize(40);
    lowest_score.setCharacterSize(40);

    overwindow.clear(sf::Color::White);
        for(int i=0;i<7;i++){
           overwindow.draw(scoreboard[i]);
        }

    overwindow.draw(highest_score);
    overwindow.draw(lowest_score);

        overwindow.draw(text);
        restart.drawTo(overwindow);
        exit.drawTo(overwindow);
        overwindow.display();
    }
}

void Game::Exit() {
    sf::RenderWindow exitwindow(sf::VideoMode(250, 100), "PULCHOWK",sf::Style::Close);
    sf::Text text;
    font.loadFromFile("../res/font/arial.ttf");
    text.setString("Are you sure to exit?");
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setPosition(10,0);

    Button exit;
    exit.setButton("Exit", { 70, 30 }, 30, sf::Color::Black, sf::Color::White);
    exit.setFont(font);
    exit.setPosition({ 90, 60 });
    while (exitwindow.isOpen())
    {
        sf::Event event;
        while (exitwindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                exitwindow.close();
            if(event.type== sf::Event::MouseButtonPressed)
                if (exit.isMouseOver(exitwindow)) {
                    exitwindow.close();
                    window.close();
                }
        }

        exitwindow.clear(sf::Color::White);
        exitwindow.draw(text);
        exit.drawTo(exitwindow);
        exitwindow.display();
    }

}

void Game::WriteFile() {
    extern bool isMale;
    std::ofstream file;
    //open file in write mode
    file.open("Profile.txt",std::ios::app);

    file<<"\nPlayer:"<<nam;
    file<<"\nGender:"<<(isMale ? "Male\n\n" : "Female\n\n");
    file<<p1.getHighestScore()<<"\n"<<p1.getLowestScore()<<std::endl;
    file.close();

}
