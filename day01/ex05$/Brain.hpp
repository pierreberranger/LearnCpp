#pragma once
#include <iostream>
#include <string>


class Brain {

    int _size; //size doesn't matter but who knows

    public:
    Brain(int size=1);
    ~Brain();
    std::string identify() const;
    int getSize();
};