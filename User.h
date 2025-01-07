#ifndef USER_H
#define USER_H

#include <string>
#include <fstream>

class User {
private:
    std::string name;
    std::string username;
    std::string password;

public:
    // Constructor
    User(std::string name, std::string username, std::string password)
        : name(name), username(username), password(password) {
    }

    // Getter pentru nume
    std::string getName() const { return name; }

    // Getter pentru username
    std::string getUsername() const { return username; }

    // Salvează utilizatorul într-un fișier
    void saveToFile() const;

    // Verifică dacă username-ul și parola corespund unui cont existent
    static bool authenticate(const std::string& username, const std::string& password);

    // Funcții de validare
    bool isUsernameValid() const;
    bool isPasswordValid() const;
};

#endif // USER_H
