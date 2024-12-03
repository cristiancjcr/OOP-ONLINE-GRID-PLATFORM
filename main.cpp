#include <iostream>
#include "Test.h"
#include "Meniu.h"
#include "UtilizatorManager.h"
#include <fstream>
#include <vector>

int main() {
    int alegere;
    UtilizatorManager manager;  // Instanțiem managerul de utilizatori

    // Afișăm meniul principal
    Meniu::afiseazaMeniu();
    std::cin >> alegere;

    // Procesăm comanda din meniul principal
    Meniu::procesareComanda(alegere, manager);

    // Loop pentru continuarea meniului principal
    while (true) {
        Meniu::afiseazaMeniu();
        std::cin >> alegere;
        Meniu::procesareComanda(alegere, manager);
    }

    return 0;
}
