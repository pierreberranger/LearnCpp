#include <iostream>
#include "HumanB.hpp"

void HumanB::attack(){
    std::cout<< _name << " attacks with his " << (*_weapon).getType() << std::endl;
}

HumanB::HumanB(std::string name):
    _weapon(nullptr), _name(name) {};

HumanB::~HumanB(){};

void HumanB::setWeapon(Weapon& weapon){
    _weapon = &weapon;
}