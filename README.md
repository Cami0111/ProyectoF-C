## 🏆 Proyecto Final - Programación Orientada a Objetos
![Version](https://img.shields.io/badge/version-1.4-blue)
[![License: CC BY-NC-ND 4.0](https://img-url-por-ejemplo)](https://creativecommons.org/licenses/by-nc-nd/4.0/)

---

## 🌱 Descripción 
**El Valle Iridiano** es un ecosistema vivo y hogar de múltiples criaturas, que habitan en un mundo dividido en núcleos.  
Allí se mueven, viven y mueren, dando forma a un ciclo constante de cambio y equilibrio.

El proyecto es una **simulación de los ciclos de este mundo**, desarrollada en **C++**, aplicando diversos conceptos de **Programación Orientada a Objetos** como herencia, polimorfismo y abstracción.

---
## 🏞️ Modelo y Habitantes del Valle Iridiano
El **Valle Iridiano** esta compuesto por un mundo que cobra vida gracias a la interacción entre sus nodos(biomas) y las criaturas que lo habitan.  
Cada especie tiene su propio comportamiento y forma de adaptarse a los ciclos del valle.

🌍 **El Mundo**:
es el ecenario principal donde ocurre todo, guarda el mapa, los biomas y todas las criaturas que viven dentro de el.
Cada cierto tiempo, el mundo avanza un ciclo, donde:
  - Las criaturas se mueven.
  - Interactuan con los nodos.
  - recuperan vida o mueren.


  el mundo tambien tiene biomas, ubicados en cada esquina de su espacio, hay 5 biomas:

  - Bioma Llano[P] - Bioma neutral ocupa los espacios donde no hay bioma en espacifico, no afecta a las criaturas.


  - Bioma Bosque eterno[B] - Ubicado en la esquina superior izquierda del mapa, no es agresivo con las criaturas.


  - Bioma Venenoso[V] - Ubicado en la esquina inferior derecha del mapa, es un bioma lleno de lodo y gas venenoso extremadamender agresivo con las criaturas.


  - Bioma Rocoso [R] - Ubicado en la esquina inferior derecha del mapa, lastima a las criaturas con las rocas mayormente a las que son agiles. 


  - Bioma Luminoso [L] - Ubicado en la esquina superior derecha del mapa, Recupera la vida de las criaturas agiles.


- 🧬 **Las Criaturas**:
todas las criaturas comparten un mismo origen, un solo lazo que las relaciona a todas, pero cada una de ellas tiene su manera unica de moverse por el mundo, 
sobrevivir e interactuar con los nucleos, hay 4 criaturas distintas en el mapa:
    - Raiz(R) - El equilibrio de este mundo, mantiene estatica durante los pulsos, recupera vida si aparece en ciertos biomas y pierde vida con cada ciclo. 
    - Metamorfita(M) - Se adapta facilmente a los nucleos recibiendo poco daño de estos, se mueve cada ciclo par si encuentra un lugar disponible en el mundo.
    - Centella(C) - Rapida con poca vida, Se mueve dos veces por ciclo dirijida por el mundo se recupera facilemente en el nucleo luminoso. Tambien si las nubes la dejan puede volar hasta un extremo del mundo,
    tiene poca vida y muere facilmente.
    - Albo(A) - Mezcla agilidad con adaptacion, es la combinacion de una Centella y una Metamorfita, recibe los movimientos de ambos y los combina de una manera unica.
---
## 🚀 Cómo ejecutar el proyecto 
El proyecto contiene un .gitignore() y usa CMake para gestionar las diversas clases y archivos que se usan en el programa.

---
### 🧩 Requisitos
Antes de empezar, asegurate de tener:
- **CLion** instalado(o cualquier IDE con soporte para C++).
- **CMake** (ya incluido con CLion).
- **Compilador C++17 o superior** (`g++`, `clang` o `MinGW`).

### 1️⃣ Clonar el repositorio
Abre la terminal(Git Bash,PowerShell o inclusive en Clion ) y escribe en una carpeta donde quieras tener este proyecto:
```bash
git clone https://github.com/tu-usuario/ProyectoF-C.git
---
```
## 2️⃣ Abrir el proyecto en Clion
1. Abre Clion
2. Selecciona New proyect
3. Elige la carpeta del repositorio.
4. Dale a create.
5. Oprime ok si te pregunta por create from existing sources.
6. Oprime this window en la segunda ventana que aparezca.
---

## 3️⃣ Ejecutar el programa
Una vez ya tengas abierto el repositorio en Clion:
1. verifica que el archivo principal este seleccionado  como **Run Configuration**.
2. Presiona el botón ▶️ Run.

---
## ✅ Resultado
Si todo está correcto, el programa se compilará y ejecutará iniciando la simulación del valle iridiano.

## Ejemplo de uso 
Al ejecutar el programa lo primero que te aparecera es lo siguiente:
```text
Ingrese la cantidad de ciclos : 
```
El programa admite cualquier cantidad de ciclos, sin embargo se recomienda poner maximo 20, ya que esa es la cantidad suficiente para ver la mayoria los sucesos.

La simulación se guarda automaticamente en el archivo, el cual ya esta configurado sin embargo se puede cambiar en el main.cpp:
```text
Mundo valle("Valle","../HistorialSimulaciones.json")
```
este es el constructor del valle el primer parametro es el nombre que se le da al mundo y el segundo el archivo .json donde se guarda todo. si quieres modificar ese archvo,
modifica esa parte: "../nombre.json" asegurate de que sea .json ya que este proyecto solo trabaja con este tipo de archivos.

## Salida de la consola 
Despues de poner el numero de ciclos este sera el formato como se mostrar el mapa visualmente en cada ciclo

```text
Ciclo 2
C Ha aumentado su vida ahora tiene: 42
R Ha muerto.
[B] _ [B] _ [P] _ [P] _ [L] _ [L] C
[B] _ [B] _ [P] _ [P] _ [L] _ [L] _
[P] _ [P] _ [P] _ [P] _ [P] _ [P] _
[P] _ [P] _ [P] _ [P] _ [P] _ [P] _
[R] _ [R] M [P] _ [P] A [V] _ [V] _
[R] _ [R] _ [P] _ [P] _ [V] _ [V] _

C (42 vida) en (0, 5)
A (30 vida) en (4, 3)
M (13 vida) en (4, 1)
```
- Sucesos que han pasado en el ciclo(Muerte o recuperacíon de vida).


- [B] , [P] , [L] , [V] , [R] - Biomas del mapa.


- M, A , C , R - Criaturas en el mapa.


- Ciclo N - el numero de ciclo.


- Informacíon sobre las criaturas su posicion actual y la vida que tienen.


Cada vez que se acabe una simulación, el programa le preguntara si quiere ver una simulación, si es asi, le preguntara cual simulacion y cual ciclo en especifico quiere ver. Ya que el formato
del archivo json es el siguiente:
```text
[
    {
        "ciclos": [
            {
                "ciclo": 1,
                "criaturas": [...],
                "mapa": [...]
            },
            {
                "ciclo": 2,
                "criaturas": [...],
                "mapa": [...]
            },
              {
                "ciclo": 3,
                "criaturas": [...],
                "mapa": [...]
            },
              {
                "ciclo": 4,
                "criaturas": [...],
                "mapa": [...]
            },  ]
            }
        ],
        "simulacion": 1
    },
   
```
Despues de haber ingresado el numero de la simulación y el ciclo, esta sera la salida del cargar simulación en la pantalla:
```text
Cargando ciclo N de simulacion M
Mapa cargado del ciclo N:
_ _ _ _ _ C
_ _ _ _ _ _
_ _ _ _ _ _
_ _ _ _ _ _
_ M _ A _ _
_ _ _ _ _ _
Criaturas cargadas:
C (42 vida) en (0, 5)
A (30 vida) en (4, 3)
M (13 vida) en (4, 1)
```
La informacion cargada se muestra en un formato mas secillo con las posiciones de las criaturas y sus vidas en ese ciclo.
Solo se puede cargar un ciclo de una simulación a la vez.

---

## 🗂️ Estructura del código fuente

| Carpeta / Archivo | Descripción breve                                                  |  Relación / Principio aplicado           |
|-------------------|--------------------------------------------------------------------|-------------------------
| main.cpp          | Punto de entrada. Controla el flujo general.                       |    
| Mundo.h/cpp       | Implementa el escenario e interacciones de las ciriaturas.         |  Agregación y Persistencia
| Criatura.h/cpp    | Clase abstracta y Base de las criaturas.                           |  Herencia 
| Raiz.h/cpp        | Define el comportamiente de la criatura Raiz.                      |  Herencia
| Centella.h/cpp    | Define el comportamiento de la criatura Centella.                  |  Herencia virtual
| Metamorfita.h/cpp | Define el comportamiento de la criatura Metamorfita.               |  Herencia virtual
| Albo.h/cpp        | Extiende a otras criaturas con habilidades únicas.                 |  Herencia Multiple
| HistorialSimulaciones.json | Archivo donde se guardan las simulaciones(ciclos, criaturas, mapa) |  persistencia

Autor: Maria Camila Gaitan

:]
