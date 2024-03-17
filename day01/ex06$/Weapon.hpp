#pragma once
#include <string>


class Weapon {
    std::string _type;

    public:
    Weapon(std::string type);
    ~Weapon();
    const std::string& getType();
    void setType(std::string type);
};