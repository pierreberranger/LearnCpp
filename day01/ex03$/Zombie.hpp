#pragma once
#include <string>

class Zombie {


    std::string _name;
    std::string _type;

    public:
    void announce();
    void setName(std::string name);
    Zombie(std::string name="Unamed Zombie", std::string type="basic zombie");
    ~Zombie();
};