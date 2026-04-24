#ifndef EXCEPTII_H
#define EXCEPTII_H

#include <stdexcept>
#include <string>

class ExceptieSpital : public std::runtime_error {
public:
    ExceptieSpital(std::string mesaj) 
        : std::runtime_error(mesaj) {}
};

class ExceptiePacientInexistent : public ExceptieSpital {
public:
    ExceptiePacientInexistent() 
        : ExceptieSpital("Pacientul nu exista in sistem!") {}
};

class ExceptieProgramareInvalida : public ExceptieSpital {
public:
    ExceptieProgramareInvalida() 
        : ExceptieSpital("Programarea este invalida!") {}
};

#endif