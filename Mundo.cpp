#include "Mundo.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

Mundo::Mundo(string n, string ar) : nombre(n), archivo(ar) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            mapa[i][j] = '_';
            mapaBiomas[i][j] = BIOMA_LLANO;

            if (i < 2 && j < 2)
                mapaBiomas[i][j] = BIOMA_BOSQUE_ETERNO;
            else if (i < 2 && j >= 4)
                mapaBiomas[i][j] = BIOMA_LUMINOS0;
            else if (i >= 4 && j < 2)
                mapaBiomas[i][j] = BIOMA_ROCOSO;
            else if (i >= 4 && j >= 4)
                mapaBiomas[i][j] = BIOMA_VENENOSO;
        }
    }
}

Mundo::~Mundo() {
    for (auto c : criaturas) delete c;
}

char Mundo::getSimbolo(int b) const {
    switch (b) {
        case BIOMA_BOSQUE_ETERNO: return 'B';
        case BIOMA_LUMINOS0: return 'L';
        case BIOMA_ROCOSO: return 'R';
        case BIOMA_VENENOSO: return 'V';
        default: return 'P';
    }
}

void Mundo::agregarCriatura(Criatura *c) {
    criaturas.push_back(c);
}

void Mundo::interacciones() {
    for (auto it = criaturas.begin(); it != criaturas.end();) {
        Criatura* c = *it;
        int fil = c->getY();
        int col = c->getX();
        int biomaActual = mapaBiomas[fil][col];
        char simbolo = c->getSimbolo();

        switch (biomaActual) {
            case BIOMA_VENENOSO: {
                int danoBase = 10;
                if (simbolo == 'A' || simbolo == 'M')
                    c->recibirDaño(danoBase / 2);
                else
                    c->recibirDaño(danoBase);
                break;
            }
            case BIOMA_BOSQUE_ETERNO:
                if (simbolo == 'R')
                    c->aumentarVida(5);
                break;
            case BIOMA_LUMINOS0:
                if (simbolo == 'A' || simbolo == 'C') {
                    c->aumentarVida(15);
                    cout << simbolo << " Ha aumentado su vida ahora tiene: " << c->getVida() << endl;
                } else {
                    c->recibirDaño(8);
                }
                break;
            case BIOMA_ROCOSO:
                if (simbolo == 'C')
                    c->recibirDaño(9);
                else if (simbolo == 'A' || simbolo == 'M')
                    c->recibirDaño(7);
                else
                    c->aumentarVida(5);
                break;
        }

        if (c->getVida() <= 0) {
            mapa[fil][col] = '_';
            cout << c->getSimbolo() << " Ha muerto." << endl;
            delete c;
            it = criaturas.erase(it);
        } else {
            ++it;
        }
    }
}

void Mundo::actualizarMapa(int ciclo) {

        for (auto &c : criaturas)
            c->movimiento(ciclo, mapa);

    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j)
            mapa[i][j] = '_';

        char temp[6][6];
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 6; ++j)
                temp[i][j] = '_';

        for (auto &c : criaturas) {
            int nx = c->getNx();
            int ny = c->getNy();


            if (!c->dentroDelimites(ny, nx) || temp[ny][nx] != '_') {
                nx = c->getX();
                ny = c->getY();
            } else {
                temp[ny][nx] = c->getSimbolo(); // marca la casilla como usada
            }

            c->setNx(nx);
            c->setNy(ny);
        }

        for (auto &c : criaturas) {
            c->setX(c->getNx());
            c->setY(c->getNy());
            mapa[c->getY()][c->getX()] = c->getSimbolo();
        }

        interacciones();
    }




void Mundo::mostrar(int ciclo) {
    json historial = json::array();

    ifstream fileIn(archivo);
    if (fileIn.is_open()) {
        try { fileIn >> historial; }
        catch (...) {
            cout << "Archivo vacío o corrupto." << endl;
            historial = json::array();
        }
        fileIn.close();
    }

    json simulacion;
    simulacion["simulacion"] = historial.size() + 1;
    simulacion["ciclos"] = json::array();

    for (int m = 1; m <= ciclo; ++m) {
        cout << "Ciclo " << m << endl;
        actualizarMapa(m);

        json cicloJson;
        cicloJson["ciclo"] = m;
        cicloJson["mapa"] = json::array();

        for (int i = 0; i < 6; ++i) {
            json fila = json::array();
            for (int j = 0; j < 6; ++j)
                fila.push_back(string(1, mapa[i][j]));
            cicloJson["mapa"].push_back(fila);
        }

        cicloJson["criaturas"] = json::array();
        for (auto &c: criaturas) {
            json jc;
            jc["simbolo"] = string(1, c->getSimbolo());
            jc["vida"] = c->getVida();
            jc["x"] = c->getX();
            jc["y"] = c->getY();
            cicloJson["criaturas"].push_back(jc);
        }

        simulacion["ciclos"].push_back(cicloJson);

        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                cout << "[" << getSimbolo(mapaBiomas[i][j]) << "] " << mapa[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
        for (auto &c : criaturas) {
            cout << c->getSimbolo() << " (" << c->getVida() << " vida) en ("
                 << c->getY() << ", " << c->getX() << ")" << endl;
        }
        cout << endl;
    }

    historial.push_back(simulacion);
    ofstream fOut(archivo);
    fOut << historial.dump(4);
    fOut.close();
    cout << "Simulacion " << simulacion["simulacion"] << " guardada" << endl;
}


void Mundo::cargar() {
    ifstream file(archivo);
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo: " << archivo << endl;
        return;
    }
    json historialJ;
    file >> historialJ;
    file.close();
    if (historialJ.empty()) {
        cerr << "Archivo vacio." << endl;
        return;
    }
    cout << "Hay " << historialJ.size() << " simulaciones guardadas." << endl;
    int simSeleccionada;
    cout << "Ingrese simulacion a cargar: ";
    cin >> simSeleccionada;
    if (simSeleccionada < 1 || simSeleccionada > historialJ.size()) {
        cerr << "Simulacion no valida." << endl;
        return;
    }
    json simulacionJ = historialJ[simSeleccionada - 1];
    json ciclosJ = simulacionJ["ciclos"];
    cout << "La simulacion tiene " << ciclosJ.size() << " ciclos guardados." << endl;
    int c;
    cout << "Ingrese ciclo a cargar: ";
    cin >> c;
    if (c < 1 || c > ciclosJ.size()) {
        cerr << "Ciclo no valido." << endl;
        return;
    }
    json cicloJ = ciclosJ[c - 1];
    cout << "Cargando ciclo " << c << " de simulacion " << simSeleccionada << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) { this->mapa[i][j] = cicloJ["mapa"][i][j].get<string>()[0]; }
    }
    this->criaturas.clear();
    for (auto &cri: cicloJ["criaturas"]) {
        char simbolo = cri["simbolo"].get<string>()[0];
        int vida = cri["vida"];
        int x = cri["x"];
        int y = cri["y"];
        switch (simbolo) {
            case 'A': this->agregarCriatura(new Albo(simbolo, vida, x, y));
                break;
            case 'C': this->agregarCriatura(new Centella(simbolo, vida, x, y));
                break;
            case 'R': this->agregarCriatura(new Raiz(simbolo, vida, x, y));
                break;
            case 'M': this->agregarCriatura(new Metamorfita(simbolo, vida, x, y));
                break;
        }
    }
    cout << "Mapa cargado del ciclo " << c << ":" << endl;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) { cout << this->mapa[i][j] << " "; }
        cout << endl;
    }
    cout << "Criaturas cargadas:" << endl;
    for (auto &cri: this->criaturas) {
        cout << cri->getSimbolo() << " (" << cri->getVida() << " vida) en (" << cri->getY() << ", " << cri->getX() <<
                ")" << endl;
    }
}
