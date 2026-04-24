#include "Asistent.h"
#include <iostream>

Asistent::Asistent(int id, std::string nume, std::string prenume,
                   double salariu, std::string sectie, int nivel)
    : Angajat(id, nume, prenume, salariu) {
    this->sectie = sectie;
    this->nivel = nivel;
}

Asistent::~Asistent() {}

std::string Asistent::getSectie() const {
    return sectie;
}

int Asistent::getNivel() const {
    return nivel;
}

// Costul asistentului depinde de nivel
double Asistent::calcul_cost() const {
    return salariu + (nivel * 200.0);
}

void Asistent::afiseaza() const {
    Angajat::afiseaza();
    std::cout << "Sectie: " << sectie << "\n";
    std::cout << "Nivel: " << nivel << "\n";
    std::cout << "Cost: " << calcul_cost() << " RON\n";
}