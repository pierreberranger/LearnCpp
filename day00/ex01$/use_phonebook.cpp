#include <iostream>
#include <string>
#include "PhoneBook.hpp"


std::string get_param(std::string param_name) {
    std::string input;
    std::cout << "Please enter " << param_name << std::endl;
    std::cin >> input;
    return input;
}

void print_welcoming_informations() {
    std::cout << "Welcome to your favorite phonebook app!" << std::endl;
    std::cout << "Use 'ADD' to add a phone number" << std::endl;
    std::cout << "Use 'SEARCH' to look for an already existing phone number" << std::endl;
    std::cout << "Use 'EXIT' to exit the app." << std::endl;
}

int main(){
    bool exit = false;
    std::string command;
    PhoneBook phonebook;
    while (!exit) {
        print_welcoming_informations();
        std::cin >> command;
        if (command == "ADD"){
            if (phonebook.get_size() >= MAX_SIZE) {
                std::cout << "Sorry, your phonebook is full, you cannot add any more number." 
                " Having " << MAX_SIZE << " friends is already good ! \n";
                continue;
            }
            bool valid_number = false;
            std::string name = get_param("the name of your new contact");
            while (!valid_number){
                std::string number = get_param("the corresponding phone number");
            try {
                phonebook.add_phone_number(name, number);
                valid_number = true;
            }
            catch (std::invalid_argument exception){
                std::cout << "The phone number you entered did not match" 
                "our criterias (only numbers except for the first character"
                " that can be '+') " << name << std::endl;
            }
            }
        } else if (command == "SEARCH"){
            phonebook.display();
            bool wrong_id = true;
            while (wrong_id){
                int id = std::stoi(get_param("the id corresponding to the phone contact you are looking for"));
                try {
                    phonebook.get_contact(id).display();
                    wrong_id = false;
                }
                catch (std::invalid_argument exception) {
                    std::cout << "Wrong id: try another one : " << id << std::endl;
                }
            }
        } else if (command == "EXIT"){
            exit = true;
            std::cout << "Thanks for using your favorite phonebook app";
        }else {
            std::cout << "Sorry, this command doesn't exist : (" << command << ")\n";
        }
        std::cout << "\n\n";
    }
    return 0;
}