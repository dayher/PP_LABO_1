#ifndef E_FACTURA_
#define E_FACTURA_
#define MAX_DETALLE 140
typedef struct {
    int id; // private key
    int pedido; // foreign key
    float importe;
    char descripcion[MAX_DETALLE];
    int isEmpty;
} eFactura;
#endif /*E_FACTURA_*/

#ifndef FACTURA_H_
#define FACTURA_H_

#include "pedido.h"
#define PRECIOXKG 0.6

int inicializarListaFacturas(eFactura lista[], int longitud);
int guardarFactura(eFactura lista[], int longitud, int id, int pedido, float cantidad, char descripcion[]);
int crearFactura(eFactura listaFacturas[], int nFacturas, int id, ePedido listaPedidos[], int nPedidos, int idPedido);
int buscarFacturaPorId(eFactura lista[], int longitud, int id);

#endif /* FACTURA_H_ */
