#include "PhoneNumber.hpp"
#include <stdexcept>
#include <iostream>

std::string PhoneNumber::check_phone_number(std::string phone_number) {
    for (int i = 0; i < (int) phone_number.length(); i++) {
        std::size_t found = number_charset.find(phone_number[i]);
        if (found == std::string::npos && (phone_number[i] != '+' || i != 0)) {
            throw std::invalid_argument("Accepted phone numbers only contain numbers and + as first character");
        }
        
    }
    return phone_number;
}
// PhoneNumber& PhoneNumber::operator=(const PhoneNumber& other){
//     this->number = other.number;
//     this->name = other.name;
//     return *this;
//     };
std::string PhoneNumber::get_name(){
    return name;
}
std::string PhoneNumber::get_number(){
    return number;
}
void PhoneNumber::display(){
    std::cout << "Contact : \n" << name << " : " << number << std::endl;
}