#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "localidad.h"
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
    int localidad; //foreign key
    int isEmpty;
} eCliente;

int inicializarListaClientes(eCliente lista[], int longitud);
int guardarCliente(eCliente lista[], int longitud, int id, char nombre[], char cuit[], char direccion[], int localidad );
int ingresarCliente(eCliente listaClientes[], int nClientes, int id, eLocalidad listaLocalidades[], int nLocalidades);
int buscarClientePorId(eCliente lista[], int longitud, int id);
int eliminarCliente(eCliente lista[], int longitud);
int modificarCliente(eCliente lista[], int longitud, eLocalidad list2[], int len2);

#endif /* CLIENTE_H_ */
