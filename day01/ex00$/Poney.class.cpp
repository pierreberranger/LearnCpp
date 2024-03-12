#include <iostream>
#include "Poney.class.hpp"

Poney::Poney(std::string name, int age, std::string owner) {
    _name = name;
    _age = age;
    _owner = owner;
    std::cout << _name << " just entered on the pitch ! " 
    << _owner << " is so proud of him and his " << _age << " years old !"
    << std::endl;
}

Poney::~Poney() {
    if (_age < 5) {
        std::cout << "Oh no ! " << _name << " died ;(" << std::endl;
    } else{
        std::cout << "As expected by the law of nature " << _name << " died..." << std::endl;
    }
};

void ponyOnTheStack(std::string name, int age, std::string owner){
    Poney myponey(name, age, owner);
    myponey.jump();
}
void ponyOnTheHeap(std::string name, int age, std::string owner){
    Poney * myponey = new Poney(name, age, owner);
    myponey->jump();
    delete myponey; // delete always calls destructor.
}
void Poney::jump(){
    if (_age < 5) {
        std::cout << _name << " jumps and jumps and jumps to the sky ! "
    << _owner << " is so happy to see you!" << std::endl;
    } else {
        std::cout << _name << " cannot jump to the sky because his legs are to old. "
    << _owner << " is crying." << std::endl;
    }
}
