#pragma once
#include <string>

class Logger {
    std::string _filename;

    void logToConsole(std::string const & message);
    void logToFile(std::string const & message);
    std::string makeLogEntry(std::string const & message);

    public:
    Logger(std::string const & filename);
    ~Logger();
    void log(std::string const & dest, std::string const & message);
};