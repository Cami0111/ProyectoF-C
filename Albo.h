#ifndef PROY_ALBO_H
#define PROY_ALBO_H
#include "json.hpp"
#include "Metamorfita.h"
#include "Centella.h"
#include "Criatura.h"

using namespace std;
using json = nlohmann::json;


class Albo : public Metamorfita, public  Centella {
public:

    Albo(char s,int v , int x,int y);
    char getSimbolo() const override;
    void movimiento(int ciclos, char (&mapa)[6][6]) override;

};


#endif //PROY_ALBO_H