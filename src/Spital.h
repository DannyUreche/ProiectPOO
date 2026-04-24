#ifndef SPITAL_H
#define SPITAL_H

#include "Pacient.h"
#include "Medic.h"
#include "Asistent.h"
#include "Programare.h"
#include "Factura.h"
#include "Logger.h"
#include <vector>
#include <string>

class Spital {
private:
    std::string nume;
    std::vector<Pacient> pacienti;
    std::vector<Angajat*> angajati;
    std::vector<Programare> programari;
    std::vector<Factura> facturi;

public:
    Spital(std::string nume);
    ~Spital();

    // Pacienti
    void adauga_pacient(Pacient p);
    void afiseaza_pacienti() const;
    std::vector<Pacient> filtrare_diagnostic(std::string diagnostic) const;
    Pacient* cauta_pacient(int id);

    // Angajati
    void adauga_angajat(Angajat* a);
    void afiseaza_angajati() const;
    Medic* cauta_medic(int id);

    // Programari
    void adauga_programare(Programare p);
    void afiseaza_programari() const;

    // Facturi
    void adauga_factura(Factura f);
    void afiseaza_facturi() const;

    // Salvare JSON
    void salveaza_JSON() const;
    void incarca_JSON();
};

#endif