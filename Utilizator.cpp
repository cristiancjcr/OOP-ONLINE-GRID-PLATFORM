#include <iostream>
#include "Utilizator.h"

Utilizator::Utilizator(const std::string& nume) : nume(nume), scor(0) {}

void Utilizator::setScor(int scor) {
    this->scor = scor;
}

int Utilizator::getScor() const {
    return scor;
}

std::string Utilizator::getNume() const {
    return nume;
}

void Utilizator::afiseazaDetalii() const {
    std::cout << "Utilizator: " << nume << std::endl;
    std::cout << "Scorul final: " << scor << std::endl;
}
