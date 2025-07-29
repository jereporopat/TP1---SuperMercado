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
int VolcarIndiceDescripcion(IndiceDescripcion tablaInd[], const char* rutaArchivo) {
    FILE *archivo = fopen(rutaArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 0;
    }

    printf("Archivo abierto correctamente.\n");

    int cantidad = 0;
    char descripcion[31];
    int pos;
    int estado;

    while (fscanf(archivo, "%30[^\t\n]%d %d\n", descripcion, &pos, &estado) == 3 && cantidad < MAX_IND) {
        // Eliminar espacios al final de la descripción
        int len = strlen(descripcion);
        while (len > 0 && descripcion[len - 1] == ' ') {
            descripcion[--len] = '\0';
        }

        strcpy(tablaInd[cantidad].descripcionArt, descripcion);
        tablaInd[cantidad].posicionArt = pos;
        tablaInd[cantidad].estado = estado;
        cantidad++;
    }

    fclose(archivo);
    return cantidad;
}
