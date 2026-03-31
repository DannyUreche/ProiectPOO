#ifndef MEDIC_H
#define MEDIC_H

#include "Angajat.h"
#include <string>

// Medic mosteneste din Angajat
class Medic : public Angajat {
private:
    std::string specializare;
    double tarif_ora;
    int ani_experienta;

public:
    // Constructor
    Medic(int id, std::string nume, std::string prenume, 
          double salariu, std::string specializare, 
          double tarif_ora, int ani_experienta);

    // Destructor
    ~Medic();

    // Getteri
    std::string getSpecializare() const;
    double getTarifOra() const;
    int getAniExperienta() const;

    // Implementam metoda virtuala pura din Angajat
    double calcul_cost() const override;

    // Suprascriem afisarea
    void afiseaza() const override;
};

#endif