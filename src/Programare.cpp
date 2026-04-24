#include "Programare.h"
#include "Exceptii.h"
#include <iostream>

Programare::Programare(int id, std::string data_ora,
                       Pacient* pacient, Medic* medic) {
    this->id = id;
    this->data_ora = data_ora;
    this->pacient = pacient;
    this->medic = medic;
    this->confirmata = false;
}

int Programare::getId() const { return id; }
std::string Programare::getDataOra() const { return data_ora; }
Pacient* Programare::getPacient() const { return pacient; }
Medic* Programare::getMedic() const { return medic; }
bool Programare::esteConfirmata() const { return confirmata; }

void Programare::confirma() {
    confirmata = true;
}

void Programare::valideaza() {
    if (pacient == nullptr)
        throw ExceptieSpital("Programare invalida: pacient inexistent!");
    if (medic == nullptr)
        throw ExceptieSpital("Programare invalida: medic inexistent!");
    if (data_ora.empty())
        throw ExceptieSpital("Programare invalida: data/ora lipsa!");
}

double Programare::calcul_cost() const {
    return medic->calcul_cost();
}

void Programare::afiseaza() const {
    std::cout << "Programare #" << id << "\n";
    std::cout << "Data/Ora: " << data_ora << "\n";
    std::cout << "Pacient: " << pacient->getNume() 
              << " " << pacient->getPrenume() << "\n";
    std::cout << "Medic: " << medic->getNume() 
              << " " << medic->getPrenume() << "\n";
    std::cout << "Confirmata: " << (confirmata ? "Da" : "Nu") << "\n";
    std::cout << "Cost: " << calcul_cost() << " RON\n";
}