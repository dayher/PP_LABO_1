#ifndef INFORME_H_
#define INFORME_H_

#endif /* INFORME_H_ */

#include "pedido.h"
int imprimirClientes(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes);
int imprimirPendientes(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes);
int imprimirProcesados(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes);
int imprimirPendientesPorLocalidad(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes);
int promediarPropileno(ePedido listaPedidos[], int nPedidos, int nClientes);
int imprimirPendientesPorCliente(ePedido list[], int len, int cliente);
int imprimirProcesadosPorCliente(ePedido list[], int len, int cliente);
int contarPendientesPorCliente(ePedido list[], int len, int cliente);