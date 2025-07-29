#ifndef FUNCIONES_H
#define FUNCIONES_H

const int MAX_ART = 10000;
const int MAX_IND = 10000;
const int MAX_COMPRAS = 100;
const int MAX_RUBROS = 15;

struct Articulo {
    int codArt;
    short codRubro;
    char descripcionArt[31];
    unsigned short stockActual;
    float precioUnitario;
    char uniMedida[11];
    short porcOfertas;
};

struct IndiceDescripcion {
    char descripcionArt[31];
    int posicionArt;
    bool estado;
};

struct Compra {
    char descripcionArt[31];
    short cantidad;
};

struct Rubro {
    short codRubro;
    char descripcion[21];
};

int VolcarArchivos();

#endif
