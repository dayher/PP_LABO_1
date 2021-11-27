#ifndef E_PEDIDO_
#define E_PEDIDO_
#define MAX_TIPO 3
#define MAX_CANTIDAD 500
#define HDPE 0
#define LDPE 1
#define PP 2
#define PENDIENTE 1
#define COMPLETADO 0

typedef struct {
    int id; //private key
    int cliente; //foreign key
    float cantidad;
    float tipo[MAX_TIPO];
    int estado;
    int isEmpty;
} ePedido;

#endif /*E_PEDIDO_*/


#ifndef PEDIDO_H_
#define PEDIDO_H_

#include "cliente.h"
#include "factura.h"


int inicializarListaPedidos(ePedido lista[], int longitud);
int guardarPedido(ePedido lista[], int longitud, int id, int cliente, float cantidad);
int crearPedido(ePedido listaPedidos[], int nPedidos, int id, eCliente listaClientes[], int nClientes);
int buscarPedidoPorId(ePedido lista[], int longitud, int id);
int procesarPedido(ePedido lista[], int longitud, int idFactura, eFactura listaFacturas[], int nFacturas);

#endif /* PEDIDO_H_ */

