#ifndef FACTURA_H_
#define FACTURA_H_
#include "pedido.h"

#define PRECIOXKG 0.6

typedef struct {
    int id; // private key
    int pedido; // foreign key
    float importe;
    int isEmpty;
} eFactura;

int inicializarListaFacturas(eFactura lista[], int longitud);
int guardarFactura(eFactura lista[], int longitud, int id, int pedido, float cantidad);
int crearFactura(eFactura listaFacturas[], int nFacturas, int id, ePedido listaClientes[], int nPedidos);
int buscarFacturaPorId(eFactura lista[], int longitud, int id);

#endif /* FACTURA_H_ */
