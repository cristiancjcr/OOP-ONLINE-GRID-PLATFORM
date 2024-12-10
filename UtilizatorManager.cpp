#include "UtilizatorManager.h"
#include <iostream>

bool UtilizatorManager::adaugaUtilizator(const std::string& nume, const std::string& username, const std::string& parola) {
    if (utilizatori.find(username) != utilizatori.end()) {
        std::cout << "Username-ul este deja utilizat!\n";
        return false;
    }
    utilizatori[username] = Utilizator(nume, username, parola);
    return true;
}

bool UtilizatorManager::logareUtilizator(const std::string& username, const std::string& parola) const {
    auto it = utilizatori.find(username);
    if (it != utilizatori.end() && it->second.getParola() == parola) {
        return true;
    }
    return false;
}

Utilizator UtilizatorManager::getUtilizator(const std::string& username) const {
    return utilizatori.at(username);
}
