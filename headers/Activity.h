//
// Created by admin on 3/2/2020.
//

#ifndef PULCHOWK_ACTIVITY_H
#define PULCHOWK_ACTIVITY_H

#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <utility>

class Activity {
private:
    std::string activity_name;
    std::vector<std::pair<std::string,int>> threshold;
    std::vector<std::pair<std::string,int>> deducements;
    std::vector<std::pair<std::string,int>> perks;

public:
    Activity(std::string);

    Activity();

    void add_threshold(std::string, int);
    void add_deducements(std::string, int);
    void add_perks(std::string, int);

    std::vector<std::pair<std::string,int>> get_threshold() {
        return threshold;
    }

    std::vector<std::pair<std::string,int>> get_deducements() {
        return deducements;
    }

    std::vector<std::pair<std::string,int>> get_perks() {
        return perks;
    }
};


#endif //PULCHOWK_ACTIVITY_H
