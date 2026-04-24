#ifndef PROGRAMARE_H
#define PROGRAMARE_H

#include "Pacient.h"
#include "Medic.h"
#include <string>

class Programare {
private:
    int id;
    std::string data_ora;
    Pacient* pacient;
    Medic* medic;
    bool confirmata;

public:
    Programare(int id, std::string data_ora, 
               Pacient* pacient, Medic* medic);

    int getId() const;
    std::string getDataOra() const;
    Pacient* getPacient() const;
    Medic* getMedic() const;
    bool esteConfirmata() const;

    void confirma();
    void valideaza(); // arunca exceptie daca e invalida
    double calcul_cost() const;
    void afiseaza() const;
};

#endif