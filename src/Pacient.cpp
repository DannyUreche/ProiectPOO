#include "Pacient.h"
#include <iostream>

Pacient::Pacient(int id, std::string nume, std::string prenume,
                 std::string cnp, std::string diagnostic, int varsta) {
    this->id = id;
    this->nume = nume;
    this->prenume = prenume;
    this->cnp = cnp;
    this->diagnostic = diagnostic;
    this->varsta = varsta;
}

int Pacient::getId() const { return id; }
std::string Pacient::getNume() const { return nume; }
std::string Pacient::getPrenume() const { return prenume; }
std::string Pacient::getCnp() const { return cnp; }
std::string Pacient::getDiagnostic() const { return diagnostic; }
int Pacient::getVarsta() const { return varsta; }

void Pacient::setDiagnostic(std::string d) {
    this->diagnostic = d;
}

void Pacient::afiseaza() const {
    std::cout << "ID: " << id << "\n";
    std::cout << "Nume: " << nume << " " << prenume << "\n";
    std::cout << "CNP: " << cnp << "\n";
    std::cout << "Diagnostic: " << diagnostic << "\n";
    std::cout << "Varsta: " << varsta << " ani\n";
}