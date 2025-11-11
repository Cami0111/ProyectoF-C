#include <iostream>
#include <cstdlib>
#include <ctime>
#include "json.hpp"
#include "Mundo.h"
#include "Criatura.h"
#include "Centella.h"
#include "Metamorfita.h"
#include "Raiz.h"
#include "Albo.h"

using namespace std;
using json = nlohmann::json;
int main() {

    int ciclos;
    char op;
    srand(time(nullptr)); // Inicializa la semilla
    Mundo valle("Valle","../HistorialSimulaciones.json");
    do {
        cout << "Ingrese la cantidad de ciclos : " ;
        cin >> ciclos;
    }while (ciclos < 0 );

    valle.agregarCriatura(new Raiz('R',15,rand()%6,rand()%6));
    valle.agregarCriatura(new Centella('C',12,rand()%6,rand()%6));
    valle.agregarCriatura(new Albo('A',30,rand()%6,rand()%6));
    valle.agregarCriatura(new Metamorfita('M',20,rand()%6,rand()%6));
    valle.mostrar(ciclos);

    do {
        cout << "Cargar simulaciones anteriores?(s/n) ";
        cin >> op;
        if (op == 's' or op == 'S' ) {
            valle.cargar();
        }
        else {
            cout << "Adioss";
        }
    }while(op != 's' and op != 'n');

    return 0;

}