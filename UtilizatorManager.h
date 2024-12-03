#pragma once
#ifndef UTILIZATORMANAGER_H
#define UTILIZATORMANAGER_H

#include <string>
#include <unordered_map>
#include "Utilizator.h"

class UtilizatorManager {
private:
    std::unordered_map<std::string, Utilizator> utilizatori;

public:
    // Adaugă un utilizator nou
    bool adaugaUtilizator(const std::string& nume, const std::string& username, const std::string& parola);

    // Verifică logarea unui utilizator existent
    bool logareUtilizator(const std::string& username, const std::string& parola) const;

    // Obține un utilizator după username
    Utilizator getUtilizator(const std::string& username) const;
};

#endif
