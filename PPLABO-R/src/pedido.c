#include "pedido.h"
#include <stdio.h>

/**
 * \brief Inicializa lista de pedidos con valor 1 en el campo isEmpty
 * \param lista de pedidos
 * \param longitud de la lista
 * \return 0 en caso de exito -1 en caso de error
 *
 */
int inicializarListaPedidos(ePedido list[], int len)
{
	int retorno=-1;

     if(list!=NULL &&len>0 )
     {
		for(int i=0; i<len; i++){
			list[i].isEmpty=1;
		}
    	retorno=0;
     }
    return retorno;
}

/**
 * \brief Guarda una estructura pedido en la lista recibida y setea los datos de dicha estructura con el resto de parametros
 * \param lista de pedidos
 * \param longitud de la lista
 * \param id pedido
 * \param id cliente
 * \param cantidad de kilos
 * \return 0 en caso de exito -1 en caso de error
 *
 */
int guardarPedido(ePedido list[], int len, int id, int cliente, float cantidad)
{
	int retorno =-1;

    if(list!=NULL && len>0 )
    {
		for(int i=0;i<len;i++){
			if(list[i].isEmpty){
				list[i].id= id;
				list[i].cliente=cliente;
				list[i].estado=PENDIENTE;
				list[i].cantidad=cantidad;
				list[i].isEmpty=0;
				return 0;
			}
		}
    	retorno=0;
    }
    return retorno;
}

/**
 * \brief Crear pedido de recolección: Se imprimirán los clientes por pantalla y se pedirá que se ingrese el ID de un cliente existente y la cantidad de kilos totales que se recolectarán del cliente.
 * Se generará un ID para el pedido y el mismo quedará en estado “Pendiente” hasta que se obtengan los residuos del cliente y se trasladen a la empresa.
 * \param lista de pedidos
 * \param longitud de la lista de pedidos
 * \param lista de Clientes
 * \param longitud de la lista de clientes
 * \return 0 en caso de exito -1 en caso de error
 *
 */
int crearPedido(ePedido listaPedidos[], int nPedidos, int id, eCliente listaClientes[], int nClientes)
{
    float cantidad;
    int index;
    int cliente;
    int retorno=-1;

	if(listaClientes!=NULL && nClientes>0 && listaPedidos!=NULL && nPedidos>0 )
	{
		cliente = getInt("Ingrese id del cliente: ",0,MAX_ID);
		index = buscarClientePorId(listaClientes, nClientes , cliente);

		if(index>=0)
		{
			cantidad= getFloat("Ingrese cantidad de kilos a recolectar: ",0,MAX_CANTIDAD);

			retorno = guardarPedido(listaPedidos, nPedidos, id, cliente ,cantidad);
		}
	}
	 return retorno;
}

/**
 * \brief Busca la posicion de un pedido dentro de la lista.
 * \param lista de pedidos
 * \param longitud de la lista de pedidos
 * \param id del pedido a buscar
 * \return índice de la lista en caso de exito -1 en caso de error
 *
 */
int buscarPedidoPorId(ePedido list[], int len, int id)
{
	int retorno = -1;

    if(list!=NULL && len>0 )
    {
		for(int i=0; i<len; i++){
			if(list[i].id==id && list[i].isEmpty==0) {
				retorno=i;
				break;
			}
		}
    }
	return retorno;
}

/**
 * \brief Procesar residuos: Se elegirá esta opción cuando los residuos que volvieron a la empresa se hayan procesado y separado en los diferentes tipos de plástico que la empresa puede reciclar.
 * Se imprimirán los pedidos por pantalla y se pedirá seleccionar el ID de uno de ellos.
 * Luego deberán ingresarse la cantidad de kilos de plástico de cada uno de los 3 tipos que la empresa puede procesar que se obtuvieron de los kilos totales que se recolectaron.
 * Por último, se marcará al pedido como “Completado”.
 * \param lista de pedidos
 * \param longitud de la lista de pedidos
 * \param id para la nueva factura
 * \param lista de facturas
 * \param longitud de la lista de facturas
 * \return 0 en caso de exito -1 en caso de error
 *
 */
int procesarPedido(ePedido list[], int len, int idFactura, eFactura listaFacturas[], int nFacturas)
{
	int index, id;
	int retorno=-1;

	if(list!=NULL && len>0 )
	{
		id = getInt("Ingrese id del pedido: ",0,MAX_ID);
		index = buscarPedidoPorId(list, len , id);
		if(index<0) return -1;
		list[index].tipo[HDPE] = getFloat("Ingrese kilos de HDPE: ",0,MAX_CANTIDAD);
		list[index].tipo[LDPE] = getFloat("Ingrese kilos de LDPE: ",0,MAX_CANTIDAD);
		list[index].tipo[PP] = getFloat("Ingrese kilos de PP: ",0,MAX_CANTIDAD);
		list[index].estado=COMPLETADO;
		retorno=crearFactura(listaFacturas, nFacturas, idFactura, list, len, id);
	}

	return retorno;
}
