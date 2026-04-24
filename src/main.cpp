/*

#include "Spital.h"
#include "FacturaFactory.h"
#include "Exceptii.h"
#include <iostream>

int main() {
    std::cout << "=== SISTEM GESTIUNE SPITAL ===\n\n";

    // Cream spitalul
    Spital spital("Spitalul Municipal Cluj");

    // Adaugam medici
    Medic* m1 = new Medic(1, "Ionescu", "Alexandru", 
                           8000, "Cardiologie", 300.0, 10);
    Medic* m2 = new Medic(2, "Popescu", "Maria", 
                           7500, "Pediatrie", 250.0, 5);
    spital.adauga_angajat(m1);
    spital.adauga_angajat(m2);

    // Adaugam asistenti
    Asistent* a1 = new Asistent(3, "Gheorghe", "Ion", 
                                 4000, "Cardiologie", 2);
    spital.adauga_angajat(a1);

    // Adaugam pacienti
    spital.adauga_pacient(Pacient(1, "Popa", "Andrei", 
                          "1234567890123", "Hipertensiune", 45));
    spital.adauga_pacient(Pacient(2, "Stan", "Elena", 
                          "2345678901234", "Diabet", 60));
    spital.adauga_pacient(Pacient(3, "Marin", "George", 
                          "3456789012345", "Hipertensiune", 35));

    // Afisam pacienti
    spital.afiseaza_pacienti();

    // Afisam angajati
    spital.afiseaza_angajati();

    // Cream o programare
    Programare p1(1, "2026-04-01 10:00", 
                  spital.cauta_pacient(1), m1);
    spital.adauga_programare(p1);
    spital.afiseaza_programari();

    // Filtram pacienti dupa diagnostic
    std::cout << "\n=== PACIENTI CU HIPERTENSIUNE ===\n";
    auto rezultat = spital.filtrare_diagnostic("Hipertensiune");
    for (Pacient& p : rezultat)
        p.afiseaza();

    // Cream facturi cu Factory
    Factura f1 = FacturaFactory::creeaza_consultatie(
        1, "2026-04-01", "Popa Andrei", 300.0);
    f1.emite();

    Factura f2 = FacturaFactory::creeaza_internare(
        2, "2026-04-01", "Stan Elena", 500.0, 3);
    f2.emite();

    Factura f3 = FacturaFactory::creeaza_operatie(
        3, "2026-04-01", "Marin George", 2000.0);
    f3.emite();

    spital.adauga_factura(f1);
    spital.adauga_factura(f2);
    spital.adauga_factura(f3);
    spital.afiseaza_facturi();

    // Salvam datele in JSON
    spital.salveaza_JSON();

    // Test exceptii
    std::cout << "\n=== TEST EXCEPTII ===\n";
    try {
        spital.cauta_pacient(999);
    } catch (ExceptieSpital& e) {
        std::cout << "Exceptie prinsa: " << e.what() << "\n";
    }

    std::cout << "\nProgram finalizat cu succes!\n";
    return 0;
}

*/

#include "Spital.h"
#include "FacturaFactory.h"
#include "Exceptii.h"
#include <iostream>
#include <limits>

// Culori ANSI pentru consola
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void afiseaza_meniu() {
    std::cout << CYAN << BOLD;
    std::cout << "\n+==================================+\n";
    std::cout << "|    SISTEM GESTIUNE SPITAL        |\n";
    std::cout << "+==================================+\n";
    std::cout << RESET;
    std::cout << GREEN << "  1. Adauga pacient\n";
    std::cout << "  2. Afiseaza pacienti\n";
    std::cout << "  3. Adauga medic\n";
    std::cout << "  4. Afiseaza angajati\n";
    std::cout << "  5. Adauga programare\n";
    std::cout << "  6. Afiseaza programari\n";
    std::cout << "  7. Emite factura\n";
    std::cout << "  8. Afiseaza facturi\n";
    std::cout << "  9. Filtrare pacienti dupa diagnostic\n";
    std::cout << "  10. Salveaza date in JSON\n";
    std::cout << RED << "  0. Iesire\n";
    std::cout << RESET;
    std::cout << YELLOW << "\n  Alegere: " << RESET;
}

int main() {
    Spital spital("Spitalul Municipal Cluj");

    // Date initiale
    spital.adauga_angajat(new Medic(1, "Ionescu", "Alexandru",
                           8000, "Cardiologie", 300.0, 10));
    spital.adauga_angajat(new Medic(2, "Popescu", "Maria",
                           7500, "Pediatrie", 250.0, 5));
    spital.adauga_angajat(new Asistent(3, "Gheorghe", "Ion",
                           4000, "Cardiologie", 2));
    spital.adauga_pacient(Pacient(1, "Popa", "Andrei",
                          "1234567890123", "Hipertensiune", 45));
    spital.adauga_pacient(Pacient(2, "Stan", "Elena",
                          "2345678901234", "Diabet", 60));

    int optiune;
    int id_counter_p = 3;
    int id_counter_m = 4;
    int id_counter_prog = 1;
    int id_counter_fact = 1;

    do {
        afiseaza_meniu();
        std::cin >> optiune;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(optiune) {

            case 1: {
                std::cout << BLUE << "\n--- Adauga Pacient ---\n" << RESET;
                std::string nume, prenume, cnp, diagnostic;
                int varsta;
                std::cout << "Nume: "; std::getline(std::cin, nume);
                std::cout << "Prenume: "; std::getline(std::cin, prenume);
                std::cout << "CNP: "; std::getline(std::cin, cnp);
                std::cout << "Diagnostic: "; std::getline(std::cin, diagnostic);
                std::cout << "Varsta: "; std::cin >> varsta;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                spital.adauga_pacient(Pacient(id_counter_p++, nume, prenume,
                                              cnp, diagnostic, varsta));
                std::cout << GREEN << "Pacient adaugat cu succes!\n" << RESET;
                break;
            }

            case 2: {
                spital.afiseaza_pacienti();
                break;
            }

            case 3: {
                std::cout << BLUE << "\n--- Adauga Medic ---\n" << RESET;
                std::string nume, prenume, spec;
                double salariu, tarif;
                int exp;
                std::cout << "Nume: "; std::getline(std::cin, nume);
                std::cout << "Prenume: "; std::getline(std::cin, prenume);
                std::cout << "Specializare: "; std::getline(std::cin, spec);
                std::cout << "Salariu: "; std::cin >> salariu;
                std::cout << "Tarif ora: "; std::cin >> tarif;
                std::cout << "Ani experienta: "; std::cin >> exp;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                spital.adauga_angajat(new Medic(id_counter_m++, nume, prenume,
                                                salariu, spec, tarif, exp));
                std::cout << GREEN << "Medic adaugat cu succes!\n" << RESET;
                break;
            }

            case 4: {
                spital.afiseaza_angajati();
                break;
            }

            case 5: {
                std::cout << BLUE << "\n--- Adauga Programare ---\n" << RESET;
                int id_p, id_m;
                std::string data_ora;
                std::cout << "ID Pacient: "; std::cin >> id_p;
                std::cout << "ID Medic: "; std::cin >> id_m;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Data si ora (ex: 2026-04-01 10:00): ";
                std::getline(std::cin, data_ora);
                try {
                    Programare prog(id_counter_prog++, data_ora,
                                    spital.cauta_pacient(id_p),
                                    spital.cauta_medic(id_m));
                    spital.adauga_programare(prog);
                    std::cout << GREEN << "Programare adaugata!\n" << RESET;
                } catch (ExceptieSpital& e) {
                    std::cout << RED << "Eroare: " << e.what() << "\n" << RESET;
                }
                break;
            }

            case 6: {
                spital.afiseaza_programari();
                break;
            }

            case 7: {
                std::cout << BLUE << "\n--- Emite Factura ---\n" << RESET;
                std::cout << "Tip factura:\n";
                std::cout << "  1. Consultatie\n";
                std::cout << "  2. Internare\n";
                std::cout << "  3. Operatie\n";
                std::cout << "Alegere: ";
                int tip; std::cin >> tip;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string pacient, data;
                double cost;
                std::cout << "Nume pacient: "; std::getline(std::cin, pacient);
                std::cout << "Data (ex: 2026-04-01): "; std::getline(std::cin, data);
                std::cout << "Cost serviciu: "; std::cin >> cost;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                Factura f(id_counter_fact, data, pacient);
                if (tip == 1)
                    f = FacturaFactory::creeaza_consultatie(
                        id_counter_fact, data, pacient, cost);
                else if (tip == 2) {
                    int zile;
                    std::cout << "Zile internare: "; std::cin >> zile;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    f = FacturaFactory::creeaza_internare(
                        id_counter_fact, data, pacient, cost, zile);
                } else
                    f = FacturaFactory::creeaza_operatie(
                        id_counter_fact, data, pacient, cost);

                id_counter_fact++;
                f.emite();
                spital.adauga_factura(f);
                break;
            }

            case 8: {
                spital.afiseaza_facturi();
                break;
            }

            case 9: {
                std::cout << BLUE << "\n--- Filtrare dupa diagnostic ---\n" << RESET;
                std::string diag;
                std::cout << "Diagnostic: "; std::getline(std::cin, diag);
                auto rezultat = spital.filtrare_diagnostic(diag);
                if (rezultat.empty())
                    std::cout << RED << "Niciun pacient gasit!\n" << RESET;
                else {
                    std::cout << GREEN << "Pacienti cu " << diag << ":\n" << RESET;
                    for (Pacient& p : rezultat)
                        p.afiseaza();
                }
                break;
            }

            case 10: {
                spital.salveaza_JSON();
                std::cout << GREEN << "Date salvate in spital_data.json!\n" << RESET;
                break;
            }

            case 0: {
                std::cout << YELLOW << "\nLa revedere!\n" << RESET;
                break;
            }

            default: {
                std::cout << RED << "Optiune invalida!\n" << RESET;
            }
        }

    } while (optiune != 0);

    return 0;
}