#include "PhoneBook.hpp"
#include <stdexcept>
#include <iostream>
#include <iomanip>


PhoneBook::PhoneBook(){
    size = 0;
}

PhoneBook::~PhoneBook(){
}

void PhoneBook::add_phone_number(std::string new_name, std::string new_phone_number){
    if (size >= MAX_SIZE){
        throw std::length_error("You cannot add more than 10 numbers");
    } else {
        phone_numbers[size++] = PhoneNumber(new_name, new_phone_number);
    }
};
PhoneNumber PhoneBook::search_phone_number(std::string name){
    for (int i = 0; i < size; i++) {
        PhoneNumber phone_number = phone_numbers[i];
        if (phone_number.get_name() == name){
            return phone_number;
        }
    }
    throw std::invalid_argument("Name not found in phonebook");

};

PhoneNumber PhoneBook::get_contact(int i){
    if (i >= size){
        throw std::invalid_argument("Contact id is not in the phonebook");
    }
    return phone_numbers[i];
}
int PhoneBook::get_size() {
    return size;
}
void PhoneBook::display(){
    std::cout << "Current PhoneBook: \n\n";
    std::cout << std::setw(10) << "id" << "|" << std::setw(10) << 
        "name" << "|" << std::setw(10) << "phone n." << std::endl;
    std::cout << std::setfill ('-') << std::setw(10) << "" << "-" << std::setw(10) << 
        "" << "-" << std::setw(10) << "" <<std::endl;
    std::cout << std::setfill (' ');
    for (int i = 0; i < size; i++) {
        std::cout << std::setw(10) << i << "|" << std::setw(10) << 
        crop_string(phone_numbers[i].get_name()) << "|" << std::setw(10) << 
        crop_string(phone_numbers[i].get_number()) << std::endl;
    }
    std::cout << std::endl;
}

std::string crop_string(std::string string, int size){
    if ((int) string.length() <= size){
        return string;
    } else {
        std::string cropped_string = string.substr(0, size);
        cropped_string[size-1] = '.';
        return cropped_string;
    }
}