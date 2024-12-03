#ifndef UTILIZATOR_H
#define UTILIZATOR_H

#include <string>
#include <iostream>

class Utilizator {
private:
    std::string nume;
    std::string username;
    std::string parola;
    int scor;

public:
    // Constructori
    Utilizator(); // Constructor implicit
    Utilizator(const std::string& nume, const std::string& username, const std::string& parola);
    Utilizator(const std::string& nume);  // Constructor cu un singur parametru

    // Metode
    std::string getNume() const;
    std::string getUsername() const;
    std::string getParola() const;
    int getScor() const;
    void afiseazaDetalii() const;
};

#endif // UTILIZATOR_H
