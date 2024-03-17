#pragma once
#include <string>
#include "Weapon.hpp"

class HumanB {
    // Using reference becaus attribute not declared in constructor.
    Weapon* _weapon;
    std::string _name;

    public:
    HumanB(std::string name);
    ~HumanB();
    void attack();
    void setWeapon(Weapon& weapon);
};