#ifndef INFORME_H_
#define INFORME_H_

#include "pedido.h"
#include "factura.h"

int imprimirClientes(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes, eLocalidad listaLocalidades[], int nLocalidades);
int imprimirPendientes(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes);
int imprimirProcesados(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes);
int imprimirPendientesPorLocalidad(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes, eLocalidad listaLocalidades[], int nLocalidades);
int promediarPropileno(ePedido listaPedidos[], int nPedidos, int nClientes);
int imprimirPendientesPorCliente(ePedido list[], int len, int cliente);
int imprimirProcesadosPorCliente(ePedido list[], int len, int cliente);
int contarPendientesPorCliente(ePedido list[], int len, int cliente);
int imprimirClienteConMasPendientes(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes);
int imprimirClienteConMasProcesados(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes);
int contarPendientesPorCliente(ePedido list[], int len, int cliente);
int contarProcesadosPorCliente(ePedido list[], int len, int cliente);
int imprimirClienteConMasPedidos(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes);
int imprimirLocalidadConMayorImporte(ePedido listaPedidos[], int nPedidos, eCliente listaClientes[], int nClientes, eLocalidad listaLocalidades[], int nLocalidades, eFactura listaFacturas[], int nFacturas);

#endif /* INFORME_H_ */
