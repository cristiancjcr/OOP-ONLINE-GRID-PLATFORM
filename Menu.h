#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
private:
    std::string loggedInUser;  // Adăugăm un atribut pentru utilizatorul logat

public:
    // Meniu de întâmpinare
    void welcomeMenu();

    // Meniu principal
    void mainMenu();

    // Crearea unui cont nou
    void createAccount();

    // Logarea unui cont existent
    void login();

    // Funcție pentru a verifica dacă username-ul este deja folosit
    bool isUsernameTaken(const std::string& username);

    // Funcție pentru a șterge un cont
    void deleteAccount(const std::string& username);

    // Meniu secundar
    void secondaryMenu();

    // Meniu de test
    void testOptionsMenu();

    // Funcție pentru a începe testul
    void startTest();

    // Setăm utilizatorul logat
    void setLoggedInUser(const std::string& username) {
        loggedInUser = username;
    }

    // Obținem utilizatorul logat
    std::string getLoggedInUser() const {
        return loggedInUser;
    }
};


#endif // MENU_H
