### A DAY IN PULCHOWK

It is a top-down 2D simulation RPG game using C++ and SFML as library. As the name suggests, the game is a one-day simulation in Pulchowk Campus,
where the player can interact with different avatars in-game and visit buildings inside the campus.\
Scores are awarded as points in 6 sections: health, education, energy, money, social and fun based on the amount of time you spend inside a building.
The objective is to accrue as many points as possible within the given time frame.\
The game is developed for the academic project of Object Oriented Programming.

#### Dependencies
-  SFML 2.0
 
#### Building Instructions
Compiling is simple in itself, simply compile all the executables within the
/src folder and the main.cpp in the root directory and link the following 
sfml flags with the compiler:\
`-lsfml-graphics -lsfml-window -lsfml-system`

##### 1) Windows
You can use CMake if you are on Windows to build the executable through the
CMakeLists file included in the root directory.

##### 2) Linux
If on Linux, use the Makefile to compile and run the program\
`$ make` - to build the program\
`$ make run` - to run the executable\

Additionally, you can refer to the official [SFML documentation](https://www.sfml-dev.org/tutorials/2.5/) for building files on other platforms.

##### 3) Using CLion IDE (JetBrains)
Open this folder from CLion IDE and run the program. 
The CMakeLists file should be sufficient to build the program.

#### Developers:
**1.Nishan Poudel 075BCT057 ([@nsn39](https://github.com/nsn39))**\
**2.Pranjal Pokharel 075BCT061 ([@pranjalpokharel7](https://github.com/pranjalpokharel7))**\
**3.Ranju G.C. 075BCT064 ([@Itshyphen](https://github.com/Itshyphen))**

#### Screenshots:
##### Main Menu
![Main Menu](https://raw.githubusercontent.com/Itshyphen/Pulchowk/master/screenshots/Main-Menu.png)

##### Game Start
![Game Start](https://raw.githubusercontent.com/Itshyphen/Pulchowk/master/screenshots/Game-Start.png)

##### Department (Interior)
![Department](https://raw.githubusercontent.com/Itshyphen/Pulchowk/master/screenshots/Department.png)

##### Social Conversation
![Social Conversation](https://raw.githubusercontent.com/Itshyphen/Pulchowk/master/screenshots/Conversation.png)

##### Robotics Club
![Robotics Club](https://raw.githubusercontent.com/Itshyphen/Pulchowk/master/screenshots/Robotics-Club.png)

##### Game Over
![Game Over](https://raw.githubusercontent.com/Itshyphen/Pulchowk/master/screenshots/Game-Over-Scores.png)
