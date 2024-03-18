#include "Logger.hpp"

int main(){
    Logger logger("logger_output.txt");
    const std::string message1 = "Hey you, have a great day!";
    const std::string message2 = "May the force be with you !";
    logger.log("logToFile", message1);
    logger.log("logToConsole", message1);
    logger.log("logToFile", message2);
    logger.log("logToConsole", message2);
    return 0;
}