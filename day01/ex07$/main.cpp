#include <iostream>
#include <fstream>
#include <exception>
#include <string>

std::string replaceAll(std::string str, const std::string str1, const std::string str2) {
    size_t pos = str.find(str1);
    while (pos != std::string::npos) {
        str.replace(pos, str1.length(), str2);
        pos = str.find(str1, pos + str2.length());
    }
    return str;
}

void replace_string(std::string filename, std::string str1, std::string str2){
    std::ifstream myfile (filename);
    std::ofstream replaced_file (filename + ".replaced");
    std::string line;
    if (!myfile.is_open()) {
        std::cout << "Error: failed to open file " << filename << std::endl;
        throw std::exception();
    } else if (!replaced_file.is_open()){
        std::cout << "Error: failed to create output file :  " << filename + ".replaced" << std::endl;
        throw std::exception();
    } else {
        while ( getline (myfile,line) ){
            replaced_file << replaceAll(line, str1, str2) << std::endl;
        }
    myfile.close();
    replaced_file.close();
    }
}

int main(int argc, char** argv){

    if (argc != 4){
        std::cout << "Usage: ./replace <filename> <string1> <string2>" << std::endl;
        std::cout << "If you have no idea, try this funny example : `./replace test.txt o etta`" << std::endl;
        return 1;
    } else if (*argv[2] == '\0' || *argv[3] == '\0'){
        std::cout << "One string among str1 or str2 is empty, which is not allowed." << std::endl;
        std::cout << "Usage: ./replace <filename> <string1> <string2>" << std::endl;
        std::cout << "If you have no idea, try this funny example : `./replace test.txt o etta`" << std::endl;
        return 1;
    }

    replace_string(argv[1], argv[2], argv[3]);

    return 0;
}