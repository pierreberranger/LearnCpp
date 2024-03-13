#include "ZombieEvent.hpp"

int main(){
    ZombieEvent zombie_event;
    zombie_event.setZombieType("darwin");
    Zombie * zombie = zombie_event.newZombie("Melvin");
    zombie->announce();
    delete zombie;
    zombie_event.randomChump();

    return 0;
}