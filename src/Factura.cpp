#include "Factura.h"
#include <iostream>

Factura::Factura(int nr, std::string data, std::string nume_pacient) {
    this->nr_factura = nr;
    this->data_emitere = data;
    this->nume_pacient = nume_pacient;
    this->total = 0;
}

void Factura::adauga_serviciu(std::string serviciu, double cost) {
    servicii.push_back(serviciu);
    costuri.push_back(cost);
}

double Factura::calcul_total() {
    total = 0;
    for (double c : costuri)
        total += c;
    return total;
}

void Factura::emite() {
    calcul_total();
    std::cout << "\n=============================\n";
    std::cout << "FACTURA #" << nr_factura << "\n";
    std::cout << "Data: " << data_emitere << "\n";
    std::cout << "Pacient: " << nume_pacient << "\n";
    std::cout << "-----------------------------\n";
    for (int i = 0; i < servicii.size(); i++) {
        std::cout << servicii[i] << ": " 
                  << costuri[i] << " RON\n";
    }
    std::cout << "-----------------------------\n";
    std::cout << "TOTAL: " << total << " RON\n";
    std::cout << "=============================\n";
}

int Factura::getNrFactura() const { return nr_factura; }
double Factura::getTotal() const { return total; }

void Factura::afiseaza() const {
    std::cout << "Factura #" << nr_factura 
              << " | Pacient: " << nume_pacient 
              << " | Total: " << total << " RON\n";
}
