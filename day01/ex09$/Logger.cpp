#include <iostream>
#include <fstream>
#include <ctime>
#include "Logger.hpp"

void Logger::logToConsole(std::string const & message){
    std::cout << message << std::endl;
}
void Logger::logToFile(std::string const & message){
    std::ofstream file (_filename, std::ios_base::app);
    file << message <<std::endl;
    file.close();
}

Logger::Logger(std::string const & filename):
    _filename(filename) {};

Logger::~Logger() {};

std::string Logger::makeLogEntry(std::string const & message){
    char buffer[80];
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    std::strftime(buffer,80,"[%Y/%m/%d %H:%M:%S] ",now);
    return buffer + message;
}
void Logger::log(std::string const & dest, std::string const & message){
    const std::string log_entry = makeLogEntry(message);
    std::string log_methods_names[2] = {"logToConsole", "logToFile"};
    void (Logger::*lookup_table[2])(std::string const &) = {&Logger::logToConsole, &Logger::logToFile};
    for (int i =0; i < 2; i++){
        if (log_methods_names[i] == dest){
            (*this.*(lookup_table[i]))(log_entry);
            break;
        }
    }
}