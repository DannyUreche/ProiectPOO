#include "Angajat.h"
#include <iostream>

// Constructor - initializam toate campurile
Angajat::Angajat(int id, std::string nume, std::string prenume, double salariu) {
    this->id = id;
    this->nume = nume;
    this->prenume = prenume;
    this->salariu = salariu;
}

// Destructor
Angajat::~Angajat() {
    // nimic de eliberat deocamdata
}

// Getteri
int Angajat::getId() const {
    return id;
}

std::string Angajat::getNume() const {
    return nume;
}

std::string Angajat::getPrenume() const {
    return prenume;
}

double Angajat::getSalariu() const {
    return salariu;
}

// Afisare informatii de baza
void Angajat::afiseaza() const {
    std::cout << "ID: " << id << "\n";
    std::cout << "Nume: " << nume << " " << prenume << "\n";
    std::cout << "Salariu: " << salariu << " RON\n";
}