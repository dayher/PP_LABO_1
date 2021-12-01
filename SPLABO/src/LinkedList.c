#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList *) malloc(sizeof(LinkedList));

    if(this){
    	this->size = 0;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL){
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node * pNode = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){

		pNode = this->pFirstNode;

		while(nodeIndex--){
			pNode = pNode->pNextNode;
		}
	}
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int returnAux = -1;
    Node * pNode, * newNode;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if (!(nodeIndex<0 || nodeIndex>len))
    	{
    		newNode = (Node *) malloc(sizeof(Node));

			if (newNode != NULL)
			{
					newNode->pElement = pElement;

					if(nodeIndex == 0)
					{
						newNode->pNextNode = this->pFirstNode;
						this->pFirstNode = newNode;
					} else
					{
						pNode = getNode(this, nodeIndex-1);
						newNode->pNextNode = pNode->pNextNode;
						pNode->pNextNode = newNode;
					}
					this->size = len+1;
					returnAux = 0;
			}
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL){
    	if(addNode(this, ll_len(this), pElement)==0){
    		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node * pNode;

    if(this != NULL && index >= 0 && index < ll_len(this)){
    	if((pNode = getNode(this, index)) != NULL) {
    		returnAux = pNode->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node * pNode;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	if((pNode = getNode(this, index)) != NULL)
    	{
    		pNode->pElement = pElement;
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node * pNode, *pAux;
    int len = ll_len(this);

    if(this != NULL && index >= 0 && index < len)
    {
    		if(index == 0)
    		{
    			pNode = this->pFirstNode;
    			pAux = pNode->pNextNode;
    			this->pFirstNode = pAux;
    		} else
    		{
    			if((pAux = getNode(this, index-1)) != NULL){
    				pNode = pAux->pNextNode;
    				pAux->pNextNode = pNode->pNextNode;
    			}
    		}
    		free(pNode);
    		this->size = len -1;
    		returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL){
    	while(ll_len(this)){
    		ll_remove(this, 0);
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
    	ll_clear(this);
    	free(this);
    	this=NULL;
    	returnAux=0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i = 0;

    if(this != NULL){
        while(i<ll_len(this)){

        	if(ll_get(this, i) == pElement){
        		returnAux=i;
        		break;
        	}
        	i++;
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(!ll_len(this))
    	{
    		returnAux = 1;
    	} else {
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL){
    	if((addNode(this, index, pElement))==0){
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL){
    	if((returnAux = ll_get(this, index))!= NULL){
    		ll_remove(this, index);
    	}
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL){
    	if(ll_indexOf(this, pElement) >=0){
    		returnAux=1;
    	} else {
    		returnAux=0;
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i=0;
    int len1;
    int len2;

    if(this!=NULL && this2!=NULL){

        len1 = ll_len(this);
        len2 = ll_len(this2);

    	if(len1>=len2){
    		while(i<len2){
				if(!ll_contains(this, ll_get(this2, i++))){
					break;
				}
			}
			if(i==len2){
				returnAux = 1;
			}else{
				returnAux = 0;
			}
    	} else {
    		returnAux = 0;
    	}

    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL && from>=0 )
    {
    	if( to>from && to<=ll_len(this))
    	{
			if((cloneArray = ll_newLinkedList()) != NULL)
			{
				while(from<to)
				{
					if(ll_add(cloneArray, ll_get(this, from))) {
						break;
					}
					from++;
				}
				if(from<to)
				{
					ll_deleteLinkedList(cloneArray);
				}
			}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if( this != NULL){
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    void * pElement1, *pElement2;
    int i,j, len;

    if (this!=NULL && pFunc!=NULL && (order==0 || order==1))
    {
    	if (order==0) order=-1;

    	if((len=ll_len(this))>0)
    	{
    		for(i=0; i<len-1 ; i++)
    		{
    			for(j=i+1; j<len; j++)
    			{
					pElement1= ll_get(this, i);
    				pElement2= ll_get(this, j);

    				if((order*(pFunc(pElement1, pElement2)))>0)
    				{
    					ll_set(this, i, pElement2);
    					ll_set(this, j, pElement1);
    				}
    			}
    		}
    		returnAux=0;
    	}
    }

    return returnAux;

}

/** \brief Generará la nueva lista resultado, agregará a la misma los ítems correspondientes y la devolverá.
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*fn) Puntero a la funcion criterio
 * \return LinkedList* Puntero a la nueva lista lista o NULL en caso de error.
 */
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
{
	int len = ll_len(this);
	void * aux;
	LinkedList * newLinkedList = NULL;

	if(this!=NULL && fn!=NULL)
	{
		if((newLinkedList = ll_newLinkedList())!=NULL)
		{
			for (int i=0; i<len ; i++)
			{
				aux = ll_get(this,i);

				if(aux!=NULL && fn(aux)==1)
				{
					ll_add(newLinkedList, aux);
				}
			}
		}
	}
	return newLinkedList;
}

//brief ejecutará la función recibida como parámetro por cada ítem de la lista
//return 0 en caso de exito o 1 en caso de error

int ll_map(LinkedList* this, int (*fn)(void* element))
{
	int retorno=1;
	int len = ll_len(this);
	void * aux;

	if(this!=NULL && fn!=NULL)
	{
		for (int i=0; i<len ; i++)
		{
			aux = ll_get(this,i);

			if(aux!=NULL)
			{
				fn(aux);
			}
		}
		retorno=0;
	}
	return retorno;
}
int ll_count(LinkedList* this, int (*fn)(void* element))
{
	int count=-1;
	int len = ll_len(this);
	void * aux;

	if(this!=NULL && fn!=NULL)
	{
		count=0;
		for (int i=0; i<len ; i++)
		{
			aux = ll_get(this,i);

			if(aux!=NULL && fn(aux)==1)
			{
				count++;
			}
		}

	}
	return count;
}
