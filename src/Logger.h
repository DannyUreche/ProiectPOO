#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

// Singleton - o singura instanta de logger in toata aplicatia
class Logger {
private:
    static Logger* instanta;
    std::ofstream fisier;

    Logger(); // constructor privat

public:
    static Logger* getInstance();
    void log(std::string mesaj);
    ~Logger();
};

#endif