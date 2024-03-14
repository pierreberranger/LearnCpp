#include "Human.hpp"

std::string Human::identify(){
    return _brain.identify();
}

Human::Human(int brain_size, std::string name):
    _brain(Brain(brain_size)), _name(name) {};

Human::~Human(){
    std::cout << "You died" << std::endl;
}

//  Return reference and not copy to get same address when calling identify on it.
const Brain& Human::getBrain(){
    return _brain;
}