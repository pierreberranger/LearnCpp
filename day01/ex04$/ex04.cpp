#include <iostream>
#include <string>

int main(){
    std::string brain = "HI THIS IS BRAIN";
    std::string* brain_pointer = &brain;
    std::string& brain_reference = brain;
    std::cout << "String : " << brain << " stored at : " << &brain << std::endl;
    std::cout << "Pointer : " << *brain_pointer << " stored at : " << brain_pointer << std::endl;
    std::cout << "Reference : " << brain_reference << " stored at : " << *(&brain_pointer) << std::endl;

    return 0;
}