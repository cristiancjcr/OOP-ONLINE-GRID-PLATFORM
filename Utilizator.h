#pragma once
#ifndef UTILIZATOR_H
#define UTILIZATOR_H

#include <string>

class Utilizator {
private:
    std::string nume;
    int scor;

public:
    Utilizator(const std::string& nume);
    void setScor(int scor);
    int getScor() const;
    std::string getNume() const;
    void afiseazaDetalii() const;
};

#endif
