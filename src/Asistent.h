#ifndef ASISTENT_H
#define ASISTENT_H

#include "Angajat.h"
#include <string>

class Asistent : public Angajat {
private:
    std::string sectie;
    int nivel; // 1, 2 sau 3

public:
    Asistent(int id, std::string nume, std::string prenume,
             double salariu, std::string sectie, int nivel);
    ~Asistent();

    std::string getSectie() const;
    int getNivel() const;

    double calcul_cost() const override;
    void afiseaza() const override;
};

#endif