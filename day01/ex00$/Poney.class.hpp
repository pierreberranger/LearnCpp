#pragma once

#include <string>

void ponyOnTheHeap(std::string name, int age, std::string owner);
void ponyOnTheStack(std::string name, int age, std::string owner);

class Poney {
    std::string _name;
    int _age;
    std::string _owner;
    
    public:

    Poney(std::string name, int age, std::string owner);
    ~Poney();
    void jump();

};