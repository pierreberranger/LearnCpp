#pragma once

#include <string>
#include "Zombie.hpp"

const int N_NAMES = 5;

class ZombieEvent {
    std::string _type;
    static const std::string _available_zombie_names[N_NAMES];

    public:
    void setZombieType(std::string type);
    Zombie * newZombie(std::string name);
    void randomChump();
};