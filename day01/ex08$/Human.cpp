#include <iostream>
#include "Human.hpp"

const std::string Human::_action_names[3] = {"meleeAttack", "rangedAttack", "intimidatingShout"};


void Human::meleeAttack(std::string const & target){
    std::cout << "You will taste my sword " << target << std::endl;
}
void Human::rangedAttack(std::string const & target){
    std::cout << "You will taste my arrows " << target << std::endl;
}
void Human::intimidatingShout(std::string const & target){
    std::cout << "Raaaaaaaaaaaaaah, don't hide you coward !!!! " << target 
    << " is a coward !" << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target){
    void (Human::*action_methods[3])(std::string const &) = {
        &Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout
        };
    // instead of using std::find we do it on our own;
    // because rules about using external libraries are not clear enough.
    for (int i = 0; i < 3; i++){
        if (_action_names[i] == action_name){
            (*this.*(action_methods[i]))(target);
            break;
        }
    }
}