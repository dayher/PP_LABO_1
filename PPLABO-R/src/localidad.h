#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

#endif /* LOCALIDAD_H_ */

#include "input.h"
#define PRUEBA 10

typedef struct {
    int id;
    char nombre[51];
    int isEmpty;
} eLocalidad;

int mostarLocalidades(eLocalidad lista [], int longitud);
int ingresarLocalidad(eLocalidad lista [], int longitud);
int buscarLocalidadPorId(eLocalidad list[], int len, int id);
int inicializarListaLocalidades(eLocalidad list[], int len);
