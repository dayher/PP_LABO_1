#ifndef CLIENTE_H_
#define CLIENTE_H_

#endif /* CLIENTE_H_ */

#include "input.h"
#include <stdlib.h>
#include <string.h>
#define MAX_CADENA 51
#define MAX_CUIT 12
#define MAX_ID 1000000

typedef struct {
    int id; //private key
    char nombre[MAX_CADENA];
    char cuit[MAX_CADENA];
    char direccion[MAX_CADENA];
    char localidad[MAX_CADENA];
    int isEmpty;
} eCliente;

int inicializarListaClientes(eCliente lista[], int longitud);
int guardarCliente(eCliente lista[], int longitud, int id, char nombre[], char cuit[], char direccion[], char localidad[] );
int ingresarCliente(eCliente lista[], int longitud, int id);
int buscarClientePorId(eCliente lista[], int longitud, int id);
int eliminarCliente(eCliente lista[], int longitud);
int modificarCliente(eCliente lista[], int longitud);
