#include <string>
#include <iostream>


void memoryLeak(){
    std::string* panthere = new std::string("String panthere");
    std::cout << *panthere << std::endl;
    delete panthere;
}


int main(){
    // -g -fsanitize=address in makefile to check for memory leaks
    memoryLeak();
    return 0;

}
