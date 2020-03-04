//
// Created by admin on 3/3/2020.
//

#ifndef PULCHOWK_TIME_H
#define PULCHOWK_TIME_H


class DisplayTime {
public:
    DisplayTime();
    void addTime(float);
    void restart();
    float getHour();
    float getMinutes();

private:
    float hours, minutes;

};


#endif //PULCHOWK_TIME_H
