#include "UtilizatorManager.h"
#include <iostream>  // Asigură-te că ai inclus acest fișier pentru std::cout
#include <unordered_map>  // Pentru std::unordered_map

// Definirea tipului de mapă pentru utilizatori
std::unordered_map<std::string, Utilizator> utilizatori;

bool UtilizatorManager::adaugaUtilizator(const std::string& nume, const std::string& username, const std::string& parola) {
    // Verifică dacă username-ul este deja folosit
    if (utilizatori.find(username) != utilizatori.end()) {
        std::cout << "Username-ul este deja utilizat!\n";
        return false;
    }

    // Adăugăm utilizatorul în mapă
    utilizatori[username] = Utilizator(nume);  // Crează un utilizator cu numele dat
    std::cout << "Contul a fost creat cu succes!\n";

    return true;  // Returnează succesul operației
}