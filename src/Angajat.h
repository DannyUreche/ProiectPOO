#ifndef ANGAJAT_H
#define ANGAJAT_H

#include <string>

// Clasa de baza pentru toti angajatii spitalului
class Angajat {
protected:
    int id;
    std::string nume;
    std::string prenume;
    double salariu;

public:
    // Constructor
    Angajat(int id, std::string nume, std::string prenume, double salariu);

    // Destructor virtual - important pentru mostenire!
    virtual ~Angajat();

    // Getteri
    int getId() const;
    std::string getNume() const;
    std::string getPrenume() const;
    double getSalariu() const;

    // Metoda virtuala pura - fiecare angajat calculeaza costul diferit
    virtual double calcul_cost() const = 0;

    // Afisare informatii
    virtual void afiseaza() const;
};

#endif