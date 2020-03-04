//
// Created by admin on 3/3/2020.
//

#include "../headers/Time.h"

DisplayTime::DisplayTime() {
    hours = 8.0f;
    minutes = 0.0f;
}

float DisplayTime::getHour() {
    return hours;
}

float DisplayTime::getMinutes() {
    return minutes;
}

void DisplayTime::addTime(float deltaTime) {
    minutes += deltaTime;
    if (minutes > 60.0f) {
        hours++;
        minutes = 0.0f;
    }
}

void DisplayTime::restart() {
    hours = 8.0f;
    minutes = 0.0f;
}
