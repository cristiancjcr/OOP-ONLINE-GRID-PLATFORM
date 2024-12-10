#include "Utilizator.h"

// Constructor implicit
Utilizator::Utilizator() : nume(""), username(""), parola(""), scor(0) {}

// Constructor cu 3 parametri
Utilizator::Utilizator(const std::string& nume, const std::string& username, const std::string& parola)
    : nume(nume), username(username), parola(parola), scor(0) {
}

// Constructor cu un singur parametru (nume)
Utilizator::Utilizator(const std::string& nume) : nume(nume), username(""), parola(""), scor(0) {}

// Getters
std::string Utilizator::getNume() const {
    return nume;
}

std::string Utilizator::getUsername() const {
    return username;
}

std::string Utilizator::getParola() const {
    return parola;
}

int Utilizator::getScor() const {
    return scor;
}

// Metoda pentru afisarea detaliilor
void Utilizator::afiseazaDetalii() const {
    std::cout << "Nume: " << nume << ", Username: " << username << ", Parola: " << parola << ", Scor: " << scor << std::endl;
}
