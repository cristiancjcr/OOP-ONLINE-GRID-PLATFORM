#include <iostream>
#include <vector>
#include <string>
#include "UtilizatorManager.h"
#include "Test.h"
#include "Question.h"
#include <fstream>
#include <regex>

// Functia care citeste intrebari din fisier
std::vector<Question> citesteIntrebariDinFisier(const std::string& fisier) {
    std::vector<Question> intrebari;
    std::ifstream inFile(fisier);

    if (!inFile) {
        std::cout << "Nu am putut deschide fisierul de intrebari.\n";
        return intrebari;  // Returnează un vector gol
    }

    std::string textIntrebare;
    std::vector<std::string> optiuni;
    std::string optiune;
    int raspunsCorect;

    while (getline(inFile, textIntrebare)) {
        // Citim intrebarea
        if (textIntrebare.empty()) continue;
        optiuni.clear();

        // Citim opțiunile
        for (int i = 0; i < 4; ++i) {
            getline(inFile, optiune);
            optiuni.push_back(optiune);
        }

        // Citim răspunsul corect
        inFile >> raspunsCorect;
        inFile.ignore();  // Ignore '\n' la finalul ultimei linii de intrare
        intrebari.push_back(Question(textIntrebare, optiuni, raspunsCorect - 1));  // Ajustăm la index bazat pe 0
    }

    return intrebari;
}

// Validare username
bool validareUsername(const std::string& username) {
    return username.length() >= 4;  // Username-ul trebuie să aibă minim 4 caractere
}

// Validare parola
bool validareParola(const std::string& parola) {
    if (parola.length() < 4) return false;

    // Verificăm dacă parola conține cel puțin 2 cifre
    int cifraCount = 0;
    for (char c : parola) {
        if (isdigit(c)) cifraCount++;
    }

    return cifraCount >= 2;
}

int main() {
    UtilizatorManager manager;
    std::vector<Question> intrebari = citesteIntrebariDinFisier("intrebari.txt");

    int optiune;
    std::cout << "1. Creaza un cont nou\n2. Logheaza-te\n3. Iesire\nAlege optiunea: ";
    std::cin >> optiune;

    if (optiune == 1) {
        // Creare cont
        std::string nume, username, parola;
        std::cout << "Introdu numele: ";
        std::cin.ignore();  // Pentru a ignora eventuale caractere ramase in buffer
        getline(std::cin, nume);

        // Validare username
        do {
            std::cout << "Introdu username-ul (minim 4 caractere): ";
            getline(std::cin, username);
        } while (!validareUsername(username));

        // Validare parola
        do {
            std::cout << "Introdu parola (minim 4 caractere si minim 2 cifre): ";
            getline(std::cin, parola);
        } while (!validareParola(parola));

        if (manager.adaugaUtilizator(nume, username, parola)) {
            std::cout << "Contul a fost creat cu succes!\n";
        }
        else {
            std::cout << "Contul nu a putut fi creat. Username-ul este deja utilizat.\n";
            return 0;
        }

        // Meniu secundar după crearea contului
        int meniuSecundar;
        do {
            std::cout << "\nMeniu secundar:\n";
            std::cout << "1. Logheaza-te cu un cont existent\n";
            std::cout << "2. Inapoi la meniul principal\n";
            std::cout << "3. Inchide programul\n";
            std::cout << "Alege optiunea: ";
            std::cin >> meniuSecundar;

            if (meniuSecundar == 1) {
                // Logare utilizator
                std::string username, parola;
                std::cout << "Introdu username-ul: ";
                std::cin >> username;
                std::cout << "Introdu parola: ";
                std::cin >> parola;

                if (manager.logareUtilizator(username, parola)) {
                    std::cout << "Logare reusita!\n";

                    // După logare, utilizatorul poate susține testul
                    Test test(intrebari);
                    test.shuffleQuestions();
                    test.shuffleAnswers();
                    test.displayTest();

                    int scor = test.evaluateAnswers();
                    std::cout << "Scorul tau este: " << scor << " din " << intrebari.size() << std::endl;
                    break; // Iesim din bucla meniu secundar
                }
                else {
                    std::cout << "Username sau parola gresite!\n";
                }
            }
            else if (meniuSecundar == 2) {
                std::cout << "Inapoi la meniul principal.\n";
                break; // Iesim din bucla meniu secundar
            }
            else if (meniuSecundar == 3) {
                std::cout << "Inchidere program...\n";
                return 0; // Inchide programul
            }
            else {
                std::cout << "Optiune invalida. Te rog alege din nou.\n";
            }
        } while (meniuSecundar != 2);  // Continuă până când alegi opțiunea 2 (înapoi la meniul principal)
    }
    else if (optiune == 2) {
        // Logare utilizator
        std::string username, parola;
        std::cout << "Introdu username-ul: ";
        std::cin >> username;
        std::cout << "Introdu parola: ";
        std::cin >> parola;

        if (manager.logareUtilizator(username, parola)) {
            std::cout << "Logare reusita!\n";
        }
        else {
            std::cout << "Username sau parola gresite!\n";
            return 0;
        }

        // După logare, utilizatorul poate susține testul
        Test test(intrebari);
        test.shuffleQuestions();
        test.shuffleAnswers();
        test.displayTest();

        int scor = test.evaluateAnswers();
        std::cout << "Scorul tau este: " << scor << " din " << intrebari.size() << std::endl;
    }
    else if (optiune == 3) {
        std::cout << "Iesire din program.\n";
        return 0;
    }
    else {
        std::cout << "Optiune invalida.\n";
        return 0;
    }

    return 0;
}
