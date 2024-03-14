#pragma once
#include <string>
#include "Zombie.hpp"

const int N_NAMES = 5;

class ZombieHorde {

    static const std::string _available_zombie_names[N_NAMES];
    
    int _N;
    Zombie* _horde;

    public:

    ZombieHorde(int N);
    ~ZombieHorde();
    void announce(); 
};