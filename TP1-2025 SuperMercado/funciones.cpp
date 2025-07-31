#include "funciones.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

int VolcarArchivos() {
    FILE *archivo = fopen("Articulos.txt", "rb");

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
int VolcarIndiceDescripcion(IndiceDescripcion tablaInd[], const char* rutaIndDesc) {
    FILE *archivo = fopen(rutaIndDesc, "r");
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

int VolcarListaCompras(Compra volcarCompras[], const char* rutaListaComp) {
    FILE *archivo = fopen(rutaListaComp, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 0;
    }

    printf("Archivo abierto correctamente.\n");

    int itCantidad = 0;
    char descripcionArt[31];
    short cant;

    while (fscanf(archivo, "%30[^\t\n] %hd \n", descripcionArt, &cant) == 2 && itCantidad < MAX_IND) {
        // Eliminar espacios al final de la descripción
        int len = strlen(descripcionArt);
        while (len > 0 && descripcionArt[len - 1] == ' ') {
            descripcionArt[--len] = '\0';
        }

        strcpy(volcarCompras[itCantidad].descripcionArt, descripcionArt);
        volcarCompras[itCantidad].cantidad = cant;
        itCantidad++;
    }

    fclose(archivo);
    return itCantidad;
}
int VolcarArticulos(Articulo tablaArticulos[], const char* rutaArticulos, const char* rutaIndDesc){
    FILE *archivo = fopen(rutaArticulos, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 0;
    }

    printf("Archivo abierto correctamente.\n");

    FILE *archivo = fopen(rutaIndDesc, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 0;
    }

    printf("Archivo abierto correctamente.\n");
}
