#include <sstream>
#include "Brain.hpp"


Brain::Brain(int size) :
    _size(size) {};

std::string Brain::identify() const{
    std::ostringstream oss;
    oss << this;
    return oss.str();
}

Brain::~Brain(){
    std::cout << "You lost your brain" << std::endl;
}

int Brain::getSize(){
    return _size;
}