#include <string>

const std::string number_charset = "0123456789";

class PhoneNumber {
    std::string name;
    std::string number;

    public:
    PhoneNumber(std::string new_name="", std::string new_number=""):
        name(new_name), number(check_phone_number(new_number)) {};
    // PhoneNumber& operator=(const PhoneNumber& other);
    std::string check_phone_number(std::string phone_number);
    std::string get_name();
    std::string get_number();
    void display();
};