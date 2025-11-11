//
// Created by Maria-Camila on 3/11/2025.
//

#ifndef PROY_CENTELLAS_H
#define PROY_CENTELLAS_H
#include "Criatura.h"
#include <cstdlib>
#include "json.hpp"
#include <iostream>
using namespace std;
using json = nlohmann::json;

class Centella : public virtual Criatura {
public:
 Centella() = default;
 Centella(char s, int v , int x, int y);
 void movimiento(int ciclos, char (&mapa)[6][6]) override ;

};


#endif //PROY_CENTELLAS_H