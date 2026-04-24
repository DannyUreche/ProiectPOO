#ifndef FACTURAFACTORY_H
#define FACTURAFACTORY_H

#include "Factura.h"
#include <string>

// Factory Pattern - creeaza facturi de tipuri diferite
class FacturaFactory {
public:
    // Tipuri de factura
    static Factura creeaza_consultatie(int nr, std::string data,
                                       std::string pacient, double cost);

    static Factura creeaza_internare(int nr, std::string data,
                                     std::string pacient, double cost,
                                     int zile);

    static Factura creeaza_operatie(int nr, std::string data,
                                    std::string pacient, double cost);
};

#endif