#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type):
    _name(name), _type(type) {};
Zombie::~Zombie() {
    std::cout << _name << " was destroyed ! \n";
};
void Zombie::announce(){
    std::cout << "<" + _name + "(" + _type + ")" + " Braiiiiiiinnnssss..." << std::endl;
}