#include "ZombieEvent.hpp"
#include <random>
#include <ctime>

const std::string ZombieEvent::_available_zombie_names[N_NAMES] = {"Blurk", "Mary", "Ronald", "Hemo", "Theon"};

void ZombieEvent::setZombieType(std::string type){
    _type = type;
}
Zombie * ZombieEvent::newZombie(std::string name){
    //allocate on the heap because zombie will be used for specific purpose outside of the scope.
    Zombie * zombie = new Zombie(name, _type);
    return zombie;
}
void ZombieEvent::randomChump(){
    std::srand(std::time(nullptr));
    std::uniform_int_distribution<int> distribution(0, N_NAMES-1);
    std::mt19937 generator(std::rand());
    int random_number = distribution(generator);
    Zombie zombie (_available_zombie_names[random_number], _type);
    zombie.announce();
}