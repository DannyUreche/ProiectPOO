#include "Spital.h"
#include "Exceptii.h"
#include <iostream>
#include <fstream>

Spital::Spital(std::string nume) {
    this->nume = nume;
    Logger::getInstance()->log("Spital initializat: " + nume);
}

Spital::~Spital() {
    for (Angajat* a : angajati)
        delete a;
}

// ---- PACIENTI ----
void Spital::adauga_pacient(Pacient p) {
    pacienti.push_back(p);
    Logger::getInstance()->log("Pacient adaugat: " + 
        p.getNume() + " " + p.getPrenume());
}

void Spital::afiseaza_pacienti() const {
    std::cout << "\n=== PACIENTI ===\n";
    if (pacienti.empty()) {
        std::cout << "Nu exista pacienti!\n";
        return;
    }
    for (const Pacient& p : pacienti)
        p.afiseaza();
}

std::vector<Pacient> Spital::filtrare_diagnostic(std::string diagnostic) const {
    std::vector<Pacient> rezultat;
    for (const Pacient& p : pacienti)
        if (p.getDiagnostic() == diagnostic)
            rezultat.push_back(p);
    return rezultat;
}

Pacient* Spital::cauta_pacient(int id) {
    for (Pacient& p : pacienti)
        if (p.getId() == id)
            return &p;
    throw ExceptiePacientInexistent();
}

// ---- ANGAJATI ----
void Spital::adauga_angajat(Angajat* a) {
    angajati.push_back(a);
    Logger::getInstance()->log("Angajat adaugat: " + 
        a->getNume() + " " + a->getPrenume());
}

void Spital::afiseaza_angajati() const {
    std::cout << "\n=== ANGAJATI ===\n";
    if (angajati.empty()) {
        std::cout << "Nu exista angajati!\n";
        return;
    }
    for (Angajat* a : angajati)
        a->afiseaza();
}

Medic* Spital::cauta_medic(int id) {
    for (Angajat* a : angajati) {
        Medic* m = dynamic_cast<Medic*>(a);
        if (m && m->getId() == id)
            return m;
    }
    throw ExceptieSpital("Medicul nu a fost gasit!");
}

// ---- PROGRAMARI ----
void Spital::adauga_programare(Programare p) {
    try {
        p.valideaza();
        programari.push_back(p);
        Logger::getInstance()->log("Programare adaugata #" + 
            std::to_string(p.getId()));
    } catch (ExceptieSpital& e) {
        std::cout << "Eroare: " << e.what() << "\n";
    }
}

void Spital::afiseaza_programari() const {
    std::cout << "\n=== PROGRAMARI ===\n";
    if (programari.empty()) {
        std::cout << "Nu exista programari!\n";
        return;
    }
    for (const Programare& p : programari)
        p.afiseaza();
}

// ---- FACTURI ----
void Spital::adauga_factura(Factura f) {
    facturi.push_back(f);
    Logger::getInstance()->log("Factura emisa #" + 
        std::to_string(f.getNrFactura()));
}

void Spital::afiseaza_facturi() const {
    std::cout << "\n=== FACTURI ===\n";
    if (facturi.empty()) {
        std::cout << "Nu exista facturi!\n";
        return;
    }
    for (const Factura& f : facturi)
        f.afiseaza();
}

// ---- JSON ----
void Spital::salveaza_JSON() const {
    std::ofstream f("spital_data.json");
    f << "{\n";
    f << "  \"spital\": \"" << nume << "\",\n";
    f << "  \"pacienti\": [\n";
    for (int i = 0; i < pacienti.size(); i++) {
        f << "    {\n";
        f << "      \"id\": " << pacienti[i].getId() << ",\n";
        f << "      \"nume\": \"" << pacienti[i].getNume() << "\",\n";
        f << "      \"prenume\": \"" << pacienti[i].getPrenume() << "\",\n";
        f << "      \"diagnostic\": \"" << pacienti[i].getDiagnostic() << "\"\n";
        f << "    }";
        if (i < pacienti.size() - 1) f << ",";
        f << "\n";
    }
    f << "  ]\n";
    f << "}\n";
    f.close();
    Logger::getInstance()->log("Date salvate in spital_data.json");
}