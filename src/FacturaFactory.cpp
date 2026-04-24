#include "FacturaFactory.h"

Factura FacturaFactory::creeaza_consultatie(int nr, std::string data,
                                             std::string pacient, double cost) {
    Factura f(nr, data, pacient);
    f.adauga_serviciu("Consultatie medicala", cost);
    f.adauga_serviciu("Taxa cabinet", 50.0);
    f.calcul_total();
    return f;
}

Factura FacturaFactory::creeaza_internare(int nr, std::string data,
                                           std::string pacient, double cost,
                                           int zile) {
    Factura f(nr, data, pacient);
    f.adauga_serviciu("Internare spital", cost);
    f.adauga_serviciu("Cazare (" + std::to_string(zile) + " zile)", 
                       zile * 150.0);
    f.adauga_serviciu("Masa zilnica", zile * 50.0);
    f.calcul_total();
    return f;
}

Factura FacturaFactory::creeaza_operatie(int nr, std::string data,
                                          std::string pacient, double cost) {
    Factura f(nr, data, pacient);
    f.adauga_serviciu("Operatie chirurgicala", cost);
    f.adauga_serviciu("Anestezie", 800.0);
    f.adauga_serviciu("Sala operatie", 500.0);
    f.adauga_serviciu("Recuperare post-operatorie", 300.0);
    f.calcul_total();
    return f;
}