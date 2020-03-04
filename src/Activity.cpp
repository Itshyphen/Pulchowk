//
// Created by admin on 3/2/2020.
//

#include "../headers/Activity.h"

#include <utility>

Activity::Activity (std::string name) {
    activity_name = name;
};

void Activity::add_threshold(std::string param, int val) {
    threshold.push_back(std::make_pair(param, val));
}

void Activity::add_perks(std::string param, int val) {
    perks.push_back(std::make_pair(param, val));
}

void Activity::add_deducements(std::string param, int val) {
    deducements.push_back(std::make_pair(param, val));
}

Activity::Activity() {}