#include "factura.h"
#include "pedido.h"
#include "input.h"
#include <stdio.h>
#include <string.h>

int inicializarListaFacturas(eFactura list[], int len)
{
	int retorno = -1;

    if(list!=NULL && len>0 )
    {
		for(int i=0; i<len; i++){
			list[i].isEmpty=1;
		}
		retorno = 0;
    }
	return retorno;
}

int guardarFactura(eFactura list[], int len, int id, int pedido, float importe, char descripcion[])
{
	int retorno = -1;

    if(list!=NULL && len>0 )
    {
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty){
				list[i].id= id;
				list[i].pedido=pedido;
				list[i].importe=importe;
				list[i].isEmpty=0;
				strcpy(list[i].descripcion,descripcion);
				retorno = 0;
				break;
			}
		}
    }
    return retorno;
}

int crearFactura(eFactura listaFacturas[], int nFacturas, int idFactura, ePedido listaPedidos[], int nPedidos, int idPedido)
{
    float importe;
    int index;
    int retorno = -1;
    char descripcion[MAX_DETALLE];

	if(listaPedidos!=NULL && nPedidos>0 && listaFacturas!=NULL && nFacturas>0 )
	{

		index = buscarPedidoPorId(listaPedidos, nPedidos , idPedido);

		if(index>=0)
		{
			getString("Ingrese descripción: ", descripcion);
			importe = (listaPedidos[index].cantidad)*PRECIOXKG;
			retorno = guardarFactura(listaFacturas, nFacturas, idFactura, idPedido ,importe, descripcion);
		}
	}
	return retorno;
}

int buscarFacturaPorId(eFactura list[], int len, int id)
{
	int retorno = -1;

    if(list!=NULL && len>0 )
    {
		for(int i=0; i<len; i++)
		{
			if(list[i].id==id && list[i].isEmpty==0) {
				retorno=i;
				break;
			}
		}
    }
    return retorno;
}
