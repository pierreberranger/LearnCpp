#include <random>
#include <ctime>
#include <iostream>
#include "ZombieHorde.hpp"

const std::string ZombieHorde::_available_zombie_names[N_NAMES] = {"Blurk", "Mary", "Ronald", "Hemo", "Theon"};

ZombieHorde::ZombieHorde(int N){
    _N = N;
    _horde = new Zombie[N];

    std::srand(std::time(nullptr));
    std::uniform_int_distribution<int> distribution(0, N_NAMES-1);
    std::mt19937 generator(std::rand());
    for (int i = 0; i < N; i++){
        _horde[i].setName(_available_zombie_names[distribution(generator)]);
    }
}

ZombieHorde::~ZombieHorde(){
    delete[] _horde;
}

void ZombieHorde::announce(){
    for (int i = 0; i < _N; i++){
        _horde[i].announce();
    }
}