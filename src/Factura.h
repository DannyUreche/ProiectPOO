#ifndef FACTURA_H
#define FACTURA_H

#include <string>
#include <vector>

class Factura {
private:
    int nr_factura;
    std::string data_emitere;
    std::string nume_pacient;
    std::vector<std::string> servicii;
    std::vector<double> costuri;
    double total;

public:
    Factura(int nr, std::string data, std::string nume_pacient);

    void adauga_serviciu(std::string serviciu, double cost);
    double calcul_total();
    void emite();
    void afiseaza() const;

    int getNrFactura() const;
    double getTotal() const;
};

#endif
