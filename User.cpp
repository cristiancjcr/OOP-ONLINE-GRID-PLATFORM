#include "User.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Funcția trim care elimină spațiile suplimentare
std::string trim(const std::string& str) {
    const std::string WHITESPACE = " \t\n\r\f\v";
    size_t first = str.find_first_not_of(WHITESPACE);
    size_t last = str.find_last_not_of(WHITESPACE);
    return (first == std::string::npos) ? "" : str.substr(first, (last - first + 1));
}

// Salvează un utilizator într-un fișier
void User::saveToFile() const {
    std::ofstream file("users.txt", std::ios::app);  // Deschidem fișierul în modul append
    if (file.is_open()) {
        file << username << " " << password << " " << name << std::endl;
        file.close();
    }
    else {
        std::cerr << "Eroare la deschiderea fișierului pentru salvare." << std::endl;
    }
}

// Verifică dacă username-ul și parola corespund unui cont existent
bool User::authenticate(const std::string& username, const std::string& password) {
    std::ifstream file("users.txt");
    std::string fileUsername, filePassword, fileName;

    if (file.is_open()) {
        while (file >> fileUsername >> filePassword >> fileName) {
            // Curățăm username-ul și parola citite din fișier și le comparăm cu cele introduse
            if (trim(fileUsername) == trim(username) && trim(filePassword) == trim(password)) {
                file.close();
                return true;  // Contul a fost găsit
            }
        }
        file.close();
    }
    return false;  // Nu am găsit niciun cont cu aceste date
}

// Funcții de validare pentru username și parolă
bool User::isUsernameValid() const {
    int letterCount = 0, digitCount = 0;
    for (char c : username) {
        if (isalpha(c)) letterCount++;
        if (isdigit(c)) digitCount++;
    }
    return letterCount >= 4 && digitCount >= 2;
}

bool User::isPasswordValid() const {
    int letterCount = 0, digitCount = 0;
    for (char c : password) {
        if (isalpha(c)) letterCount++;
        if (isdigit(c)) digitCount++;
    }
    return letterCount >= 4 && digitCount >= 4;
}
