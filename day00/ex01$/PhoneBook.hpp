#include <vector>
#include "PhoneNumber.hpp"

const int MAX_SIZE = 8;
std::string crop_string(std::string string, int size=10);

class PhoneBook

{
private:
    int size;
    PhoneNumber phone_numbers[MAX_SIZE];
public:
    PhoneBook();
    ~PhoneBook();
    void add_phone_number(std::string new_name, std::string new_phone_number);
    PhoneNumber search_phone_number(std::string name);
    PhoneNumber get_contact(int i);
    int get_size();
    void display();

};