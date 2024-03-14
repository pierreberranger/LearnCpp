#pragma once
#include <iostream>
#include <string>
#include "Brain.hpp"


class Human{
    const Brain _brain;
    std::string _name;

    public:
    std::string identify();
    Human(int brain_size=1, std::string name="Bertolt");
    ~Human();
    const Brain& getBrain();
};