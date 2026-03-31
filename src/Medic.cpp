#include "Medic.h"
#include <iostream>

// Constructor
Medic::Medic(int id, std::string nume, std::string prenume,
             double salariu, std::string specializare,
             double tarif_ora, int ani_experienta)
    : Angajat(id, nume, prenume, salariu) {
    this->specializare = specializare;
    this->tarif_ora = tarif_ora;
    this->ani_experienta = ani_experienta;
}

// Destructor
Medic::~Medic() {}

// Getteri
std::string Medic::getSpecializare() const {
    return specializare;
}

double Medic::getTarifOra() const {
    return tarif_ora;
}

int Medic::getAniExperienta() const {
    return ani_experienta;
}

// Calculul costului - tarif pe ora + bonus experienta
double Medic::calcul_cost() const {
    double bonus = ani_experienta * 50.0;
    return tarif_ora * 8 + bonus;
}

// Afisare informatii medic
void Medic::afiseaza() const {
    Angajat::afiseaza(); // apelam afisarea din clasa de baza
    std::cout << "Specializare: " << specializare << "\n";
    std::cout << "Tarif ora: " << tarif_ora << " RON\n";
    std::cout << "Ani experienta: " << ani_experienta << "\n";
    std::cout << "Cost servicii: " << calcul_cost() << " RON\n";
}