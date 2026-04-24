#include "Logger.h"
#include <iostream>
#include <ctime>
#include <cstring>

Logger* Logger::instanta = nullptr;

Logger::Logger() {
    fisier.open("spital.log", std::ios::app);
}

Logger::~Logger() {
    if (fisier.is_open())
        fisier.close();
}

Logger* Logger::getInstance() {
    if (instanta == nullptr)
        instanta = new Logger();
    return instanta;
}

void Logger::log(std::string mesaj) {
    // obtinem timpul curent
    time_t now = time(0);
    char* dt = ctime(&now);
    dt[strlen(dt)-1] = '\0'; // eliminam \n de la ctime

    std::string linie = "[" + std::string(dt) + "] " + mesaj;
    
    // scriem in fisier
    if (fisier.is_open())
        fisier << linie << "\n";
    
    // afisam si in consola
    std::cout << linie << "\n";
}