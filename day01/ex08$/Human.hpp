#pragma once
#include <string>

class Human
{
private:
static const std::string _action_names[3];
void meleeAttack(std::string const & target);
void rangedAttack(std::string const & target);
void intimidatingShout(std::string const & target);

public:
void action(std::string const & action_name, std::string const & target);
};