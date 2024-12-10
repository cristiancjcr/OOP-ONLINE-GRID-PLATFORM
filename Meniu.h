#pragma once
#ifndef MENIU_H
#define MENIU_H

#include "UtilizatorManager.h"

class Meniu {
public:
    static void afiseazaMeniu();
    static void procesareComanda(int alegere, UtilizatorManager& manager);
    static void afiseazaMeniuSecundar();
    static void procesareComandaSecundar(int alegere, UtilizatorManager& manager);
};

#endif
