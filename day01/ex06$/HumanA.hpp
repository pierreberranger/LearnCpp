#pragma once
#include <string>
#include "Weapon.hpp"

class HumanA {
    //  Using reference because Weapon delclared at construction, and using a reference is easier.
    std::string _name;
    Weapon& _weapon;

    public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();
    void attack();
};