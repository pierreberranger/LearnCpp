#include <iostream>

void megaphone(char** message_begin) {
    for (char* arg = *message_begin; arg; arg=*++message_begin) {
        for (char c = *arg; c != '\0'; c=*++arg) {
            if (c != '"'){
                std::cout << (char) toupper(c);
            }
        }
        std::cout << " ";
    }
    std::cout << std::endl;
    
}

int main(int argc, char *argv[]) {
    char default_answer[] = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    if (argc < 2) {
        std::cout << default_answer << std::endl;
    } else {
        megaphone((char **) argv + 1);
    }
    return 0;
}