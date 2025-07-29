#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "funciones.h"

using namespace std;

int main() {
    IndiceDescripcion tablaInd[MAX_IND];
    int cantidad = VolcarIndiceDescripcion(tablaInd, "IndDescripArt.txt");

    // Mostrar lo cargado
    for (int i = 0; i < cantidad; i++) {
        printf("%-30s %5d %d\n", tablaInd[i].descripcionArt, tablaInd[i].posicionArt, tablaInd[i].estado);
    }
    Compra volcarCompras[MAX_IND];
    int cant = VolcarListaCompras(volcarCompras, "ListaCompras.txt");

    // Mostrar lo cargado
    for (int i = 0; i < cant; i++) {
        printf("%-30s    %d\n", volcarCompras[i].descripcionArt, volcarCompras[i].cantidad);
    }

    return 0;
}
