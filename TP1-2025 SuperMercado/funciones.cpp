#include "funciones.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

int VolcarArchivos() {
    FILE *archivo = fopen("Articulos.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    } else {
        printf("Archivo abierto correctamente.\n");
    }

    char linea[100];

    while (fgets(linea, sizeof(linea), archivo)) {
        printf("%s", linea);
    }

    fclose(archivo);
    return 0;
}
