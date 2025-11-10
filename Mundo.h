//
// Created by Maria-Camila on 7/11/2025.
//

#ifndef PROY_MUNDO_H
#define PROY_MUNDO_H
#include <Vector>
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "Criatura.h"
#include "Albo.h"
#include "Raiz.h"


using namespace std;
using json = nlohmann::json;

using namespace std;
const int BIOMA_BOSQUE_ETERNO = 1;
const int BIOMA_LUMINOS0 = 2;
const int BIOMA_ROCOSO = 3;
const int BIOMA_VENENOSO = 4;
const int BIOMA_LLANO = 0;
class Mundo {
private:
    string nombre, archivo;
    char mapa[6][6];
    int mapaBiomas[6][6];
    vector <Criatura*> criaturas;
public:
    Mundo(string n, string ar);

    ~Mundo();

    char getSimbolo(int b) const;

    void agregarCriatura(Criatura *c);

    void interacciones();

    void actualizarMapa(int ciclos);

    void mostrar(int ciclo);

    void cargar();
};


#endif //PROY_MUNDO_H