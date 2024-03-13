#pragma once
#include <string>

class Zombie {
    std::string _name;
    std::string _type;

    public:
    void announce();
    Zombie(std::string name, std::string type);
    ~Zombie();
};