#include "Meniu.h"
#include "UtilizatorManager.h"
#include <iostream>
#include <string>
#include <cctype> // pentru isalpha() si isdigit()

// Funcția pentru validarea numelui (doar litere și spații)
bool esteValidNume(const std::string& nume) {
    for (char c : nume) {
        if (!(std::isalpha(c) || c == ' ')) { // Permite doar litere și spații
            return false; // Dacă găsește un caracter care nu este literă sau spațiu, returnează false
        }
    }
    return true; // Dacă toate caracterele sunt litere sau spații, returnează true
}

// Funcția pentru validarea username-ului (minim 4 litere)
bool esteValidUsername(const std::string& username) {
    int numarLitere = 0;

    for (char c : username) {
        if (std::isalpha(c)) {
            numarLitere++;
        }
    }

    return numarLitere >= 4; // Minimum 4 litere
}

// Funcția pentru validarea parolei (minim 4 caractere, minim 2 cifre)
bool esteValidParola(const std::string& parola) {
    int numarLitere = 0;
    int numarCifre = 0;

    for (char c : parola) {
        if (std::isalpha(c)) {
            numarLitere++;
        } else if (std::isdigit(c)) {
            numarCifre++;
        }
    }

    return numarLitere >= 4 && numarCifre >= 2; // Minimum 4 litere și 2 cifre
}

void Meniu::afiseazaMeniu() {
    std::cout << "Meniu Principal:\n";
    std::cout << "1. Add user\n";
    std::cout << "2. Log in - existing user\n";
    std::cout << "3. Shut Down program\n";
    std::cout << "Alege o optiune (1-3): ";
}

void Meniu::procesareComanda(int alegere, UtilizatorManager& manager) {
    switch (alegere) {
    case 1:
        std::cout << "Creare cont nou:\n";
        {
            std::string nume, username, parola;
            std::cin.ignore(); // Eliminăm caracterul '\n' rămas de la citirea anterioară
            std::cout << "Introduceti numele: ";
            std::getline(std::cin, nume); // Permitem nume cu spații

            // Validare nume (doar litere și spații)
            bool numeValabil = false;
            while (!numeValabil) {
                if (!esteValidNume(nume)) {
                    std::cout << "Numele trebuie sa contina doar litere si spatii! Te rog sa incerci din nou.\n";
                    std::cout << "Introduceti numele: ";
                    std::getline(std::cin, nume); // Permitem din nou nume cu spații
                } else {
                    numeValabil = true;
                }
            }

            // Validare username cu minim 4 litere
            bool usernameValabil = false;
            while (!usernameValabil) {
                std::cout << "Introduceti username (minim 4 litere): ";
                std::cin >> username;

                if (!esteValidUsername(username)) {
                    std::cout << "Username-ul trebuie sa contina cel putin 4 litere! Te rog sa incerci din nou.\n";
                } else {
                    usernameValabil = true;
                }
            }

            // Validare parola cu minim 4 caractere si minim 2 cifre
            bool parolaValabila = false;
            while (!parolaValabila) {
                std::cout << "Introduceti parola (minim 4 caractere si minim 2 cifre): ";
                std::cin >> parola;

                if (!esteValidParola(parola)) {
                    std::cout << "Parola trebuie sa contina cel putin 4 caractere si 2 cifre! Te rog sa incerci din nou.\n";
                } else {
                    parolaValabila = true;
                }
            }

            if (manager.adaugaUtilizator(nume, username, parola)) {
                afiseazaMeniuSecundar();
                int alegereSecundara;
                std::cin >> alegereSecundara;
                procesareComandaSecundar(alegereSecundara, manager);
            }
        }
        break;
    case 2:
        std::cout << "Logare utilizator existent (inca nu implementat).\n";
        break;
    case 3:
        std::cout << "Programul se opreste...\n";
        exit(0);
        break;
    default:
        std::cout << "Optiune invalida! Alege intre 1 si 3.\n";
        break;
    }
}

void Meniu::afiseazaMeniuSecundar() {
    std::cout << "Meniu secundar:\n";
    std::cout << "1. Log in\n";
    std::cout << "2. Shut Down the program\n";
    std::cout << "Alege o optiune (1-2): ";
}

void Meniu::procesareComandaSecundar(int alegere, UtilizatorManager& manager) {
    switch (alegere) {
    case 1:
        std::cout << "Logare (inca nu implementat).\n";
        break;
    case 2:
        std::cout << "Programul se opreste...\n";
        exit(0);
        break;
    default:
        std::cout << "Optiune invalida! Alege intre 1 si 2.\n";
        break;
    }
}
