#include <iostream>
#include "Menu.h"
#include "User.h"
#include <fstream>
#include <string>
#include "Test.h"


// Meniu de intampinare
void Menu::welcomeMenu() {
    std::cout << "Bine ai venit!" << std::endl;
    std::cout << "1. Start" << std::endl;
    std::cout << "2. Iesire program" << std::endl;

    int choice;
    std::cin >> choice;
    std::cin.ignore(); // Curăță buffer-ul de intrare

    switch (choice) {
    case 1:
        mainMenu(); // Apelăm meniul principal
        break;
    case 2:
        std::cout << "La revedere!" << std::endl;
        exit(0); // Iesire din program
        break;
    default:
        std::cout << "Optiune invalida!" << std::endl;
        welcomeMenu(); // Reapelați meniul de întâmpinare dacă alegerea este invalidă
    }
}

// Funcție pentru a verifica dacă un username este deja folosit
bool Menu::isUsernameTaken(const std::string& username) {
    std::ifstream file("users.txt");
    std::string fileUsername, filePassword, fileName;

    if (!file.is_open()) {
        std::cerr << "Eroare la deschiderea fișierului pentru citire." << std::endl;
        return false;
    }

    // Citește fiecare linie din fișier și verifică username-ul
    while (file >> fileUsername >> filePassword >> fileName) {
        if (fileUsername == username) {
            file.close();
            return true;  // Username-ul există deja
        }
    }

    file.close();
    return false;  // Username-ul nu există
}

// Funcție pentru a crea un cont nou
void Menu::createAccount() {
    std::string name, username, password;

    // Introducerea numelui
    std::cout << "Introduceti numele complet: ";
    std::getline(std::cin, name);

    // Introducerea username-ului
    bool usernameValid = false;
    while (!usernameValid) {
        std::cout << "Introduceti un username (minim 4 litere si 2 cifre): ";
        std::getline(std::cin, username);

        // Verificăm dacă username-ul este deja folosit
        if (!isUsernameTaken(username)) {
            User newUser(name, username, ""); // Creăm obiectul User doar după validare
            if (newUser.isUsernameValid()) {
                usernameValid = true;
            }
            else {
                std::cout << "Username-ul nu este valid. Incercati din nou.\n";
            }
        }
        else {
            std::cout << "Username-ul este deja folosit. Incercati altul.\n";
        }
    }

    // Introducerea parolei
    bool passwordValid = false;
    while (!passwordValid) {
        std::cout << "Introduceti o parola (minim 4 litere si 4 cifre): ";
        std::getline(std::cin, password);

        User newUser(name, username, password); // Creăm obiectul User cu datele complete
        if (newUser.isPasswordValid()) {
            passwordValid = true;
        }
        else {
            std::cout << "Parola nu este valida. Incercati din nou.\n";
        }
    }

    // Creăm obiectul User cu toate datele corect introduse
    User newUser(name, username, password);

    // Salvăm contul în fișier doar dacă toate condițiile sunt îndeplinite
    newUser.saveToFile();

    std::cout << "Contul a fost creat cu succes!" << std::endl;

    // După crearea contului, revenim la meniul principal
    mainMenu(); // Apelăm din nou meniul principal
}

// Funcție de ștergere a unui cont din fișier
void Menu::deleteAccount(const std::string& username) {
    std::ifstream file("users.txt");
    std::ofstream tempFile("temp.txt");

    if (file.is_open() && tempFile.is_open()) {
        std::string fileUsername, filePassword, fileName;
        bool accountFound = false;

        // Citește fișierul și scrie în fișierul temporar, ignorând contul pe care vrem să-l ștergem
        while (file >> fileUsername >> filePassword >> fileName) {
            if (fileUsername == username) {
                accountFound = true;
                std::cout << "Contul cu username-ul '" << username << "' a fost sters!" << std::endl;
                continue;  // Omită contul de șters
            }
            // Scriem întreaga linie pentru celelalte conturi
            tempFile << fileUsername << " " << filePassword << " " << fileName << "\n";
        }

        if (!accountFound) {
            std::cout << "Nu am găsit niciun cont cu acest username!" << std::endl;
        }

        file.close();
        tempFile.close();

        // Șterge fișierul original și redenumește fișierul temporar pentru a păstra doar conturile valabile
        remove("users.txt");
        rename("temp.txt", "users.txt");
    }
    else {
        std::cerr << "Eroare la deschiderea fișierului pentru ștergere." << std::endl;
    }
}

// Funcție de logare
void Menu::login() {
    std::string username, password;

    std::cout << "Introduceti username: ";
    std::getline(std::cin, username);

    std::cout << "Introduceti parola: ";
    std::getline(std::cin, password);

    if (User::authenticate(username, password)) {
        setLoggedInUser(username);  // Setăm utilizatorul logat
        std::cout << "Logare cu succes!\n";
        secondaryMenu();  // Apelăm meniul secundar după logare
    }
    else {
        std::cout << "Username sau parola invalide!\n";
        mainMenu(); // Revenim la meniul principal dacă logarea eșuează
    }
}


// Meniu principal
void Menu::mainMenu() {
    std::cout << "Meniu Principal" << std::endl;
    std::cout << "1. Creare cont nou" << std::endl;
    std::cout << "2. Logare cont existent" << std::endl;
    std::cout << "3. Stergere cont" << std::endl; // Opțiunea de ștergere a unui cont
    std::cout << "4. Iesire program" << std::endl;

    int choice;
    std::cin >> choice;
    std::cin.ignore(); // Curăță buffer-ul

    switch (choice) {
    case 1:
        createAccount(); // Crearea contului
        break;
    case 2:
        login(); // Logarea
        break;
    case 3: {
        std::string username;
        std::cout << "Introduceti username-ul contului de sters: ";
        std::getline(std::cin, username);
        deleteAccount(username); // Apelăm funcția de ștergere
        break;
    }
    case 4:
        std::cout << "La revedere!" << std::endl;
        exit(0); // Iesire din program
        break;
    default:
        std::cout << "Optiune invalida!" << std::endl;
        break;
    }
}

void Menu::secondaryMenu() {
    int choice;
    do {
        std::cout << "Meniu Secundar\n";
        std::cout << "1. Meniu optiuni test \n";
        std::cout << "2. Inapoi la meniul principal\n";
        std::cout << "3. Iesire din program\n";
        std::cout << "Alege o optiune: ";
        std::cin >> choice;
        std::cin.ignore(); // Curăță buffer-ul de intrare

        switch (choice) {
        case 1:
            testOptionsMenu();
            break;
        case 2:
            mainMenu(); // Revin la meniul principal
            return;     // Ies din meniul secundar
        case 3:
            std::cout << "La revedere!\n";
            exit(0);     // Închide programul
        default:
            std::cout << "Optiune invalida! Incercati din nou.\n";
        }
    } while (choice != 3);
}

// Meniu de opțiuni pentru test
// Meniu de opțiuni pentru test
void Menu::testOptionsMenu() {
    int choice;

    do {
        std::cout << "Meniu Optiuni Test\n";
        std::cout << "1. Nivel de dificultate intrebari (Se alege la inceputul testului dupa selectarea case-ului 5)\n";
        std::cout << "2. Domeniul intrebarilor din test (Se alege la inceputul testului dupa selectarea case-ului 5)\n";
        std::cout << "3. Selectarea numarului de intrebari (Se alege la inceputul testului dupa selectarea case-ului 5)\n";
        std::cout << "4. Intrebari cu raspunsuri multiple (//TO DO)\n";
        std::cout << "5. Incepe testul\n";  // Noua opțiune pentru a începe testul
        std::cout << "6. Inapoi la meniul secundar\n";
        std::cout << "Alege o optiune: ";
        std::cin >> choice;
        std::cin.ignore(); // Curăță buffer-ul

        switch (choice) {
        case 1:
            std::cout << "Setarea nivelului de dificultate (Se alege la inceputul testului dupa selectarea case-ului 5)\n";
            break;
        case 2:
            std::cout << "Setarea domeniului intrebarilor (Se alege la inceputul testului dupa selectarea case-ului 5)\n";
            break;
        case 3:
            std::cout << "Setarea numarului de intrebari (Se alege la inceputul testului dupa selectarea case-ului 5)\n";
            break;
        case 4:
            std::cout << "Configurarea intrebarilor cu raspunsuri multiple (//TO DO)\n";
            break;
        case 5:
            startTest();  // Apelăm funcția care începe testul
            break;
        case 6:
            std::cout << "Revenire la meniul secundar.\n";
            break;
        default:
            std::cout << "Optiune invalida. Incercati din nou.\n";
            break;
        }
    } while (choice != 6);

}


// Funcție pentru a începe testul
void Menu::startTest() {
    // Afișează opțiunile pentru utilizator
    int difficultyChoice, domainChoice, numQuestions;

    // Selecția nivelului de dificultate
    std::cout << "Alege nivelul de dificultate (1: Easy, 2: Medium, 3: Hard): ";
    std::cin >> difficultyChoice;

    std::string difficulty;
    if (difficultyChoice == 1) {
        difficulty = "Easy";
    }
    else if (difficultyChoice == 2) {
        difficulty = "Medium";
    }
    else if (difficultyChoice == 3) {
        difficulty = "Hard";
    }
    else {
        std::cout << "Alegere invalida, setăm la 'Easy'.\n";
        difficulty = "Easy";
    }

    // Selecția domeniului întrebărilor
    std::cout << "Alege domeniul (1: Istorie, 2: Geografie, 3: Stiinte naturale, 4: Literatura, 5: Matematica, 6: Tehnologie, 7: Arta si cultura, 8: Sport, 9: Economie, 10: Medicina): ";
    std::cin >> domainChoice;

    std::string domain;
    switch (domainChoice) {
    case 1: domain = "Istorie"; break;
    case 2: domain = "Geografie"; break;
    case 3: domain = "Stiinte naturale"; break;
    case 4: domain = "Literatura"; break;
    case 5: domain = "Matematica"; break;
    case 6: domain = "Tehnologie"; break;
    case 7: domain = "Arta si cultura"; break;
    case 8: domain = "Sport"; break;
    case 9: domain = "Economie"; break;
    case 10: domain = "Medicina"; break;
    default: domain = "Istorie"; break;
    }

    // Selecția numărului de întrebări
    std::cout << "Alege numarul de intrebari: ";
    std::cin >> numQuestions;

    // Crearea unui test pe baza selecțiilor utilizatorului
    Test test;
    test.setDifficulty(difficulty);
    test.setDomain(domain);
    test.loadQuestions("intrebari.txt");

    int availableQuestions = test.getQuestions().size();
    if (numQuestions > availableQuestions) {
        numQuestions = availableQuestions;
    }

    test.setNumQuestions(numQuestions);
    test.startTest(); // Începe testul

    // Afișează rezultatul final al utilizatorului logat
    std::cout << "Rezultatul final al utilizatorului " << getLoggedInUser() << " este: "
        << test.getScore() << "/" << numQuestions << std::endl;
}