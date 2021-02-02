cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME PULCHOWK)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp src/Animation.cpp src/Interior.cpp src/Activity.cpp headers/Activity.h headers/Time.h src/Time.cpp headers/Interior.h src/Players.cpp headers/Players.h src/MainMenu.cpp headers/MainMenu.h src/Avatar.cpp headers/Avatar.h headers/TextField.h headers/Button.h headers/Object.h src/Player.cpp src/Rect.cpp src/Game.cpp headers/Animation.h headers/Game.h headers/Player.h headers/Rect.h  headers/Trees.h src/Trees.cpp headers/Building.h src/Building.cpp headers/Profile.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

# add absolute path to where SFML is installed in your computer within set()
set(SFML_ROOT C:/SFML)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2 REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(PULCHOWK headers)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()
