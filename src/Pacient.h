#ifndef PACIENT_H
#define PACIENT_H

#include <string>

class Pacient {
private:
    int id;
    std::string nume;
    std::string prenume;
    std::string cnp;
    std::string diagnostic;
    int varsta;

public:
    Pacient(int id, std::string nume, std::string prenume,
            std::string cnp, std::string diagnostic, int varsta);

    int getId() const;
    std::string getNume() const;
    std::string getPrenume() const;
    std::string getCnp() const;
    std::string getDiagnostic() const;
    int getVarsta() const;

    void setDiagnostic(std::string diagnostic);

    void afiseaza() const;
};

#endif