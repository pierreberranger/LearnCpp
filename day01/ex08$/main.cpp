#include "Human.hpp"

int main() {
    Human human;
    const std::string target = "Bob";
    human.action("meleeAttack", target);
    human.action("rangedAttack", target);
    human.action("intimidatingShout", target);
}