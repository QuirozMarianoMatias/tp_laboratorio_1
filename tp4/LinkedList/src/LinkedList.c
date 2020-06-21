#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

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
    LinkedList* This;

    This = (LinkedList*) malloc(sizeof(LinkedList));
    if(This!=NULL)
    {
        This->size = 0;
        This->pFirstNode = NULL;
    }

    return This;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* This)
{
    int returnAux = -1;
    if(This!=NULL)
    {
        returnAux = This->size ;//this->size;
    }


    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* This, int nodeIndex)
{
    Node* pNode =NULL;
    int i;



    if (This != NULL && nodeIndex >=0 && nodeIndex < ll_len(This))
    {
        pNode = This ->pFirstNode;
        if (nodeIndex >0)
        {
            for (i=0; i<nodeIndex; i++)
            {


                pNode = pNode->pNextNode;

            }
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
static int addNode(LinkedList* This, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* prev;
// Node* next;
    Node* nuevoNodo;

    nuevoNodo = (Node*)malloc(sizeof(Node));


    if (This != NULL && nodeIndex >= 0  && nuevoNodo != NULL && nodeIndex <= ll_len(This))
    {
        if (ll_len(This) == 0)
        {

            This ->pFirstNode = nuevoNodo;
            This->size++;
            nuevoNodo->pNextNode = NULL;
            nuevoNodo->pElement = pElement;
            returnAux = 0;
        }
        else if (nodeIndex == (ll_len(This)) )
        {
            prev = getNode(This,nodeIndex-1);
            prev->pNextNode= nuevoNodo;
            nuevoNodo->pElement = pElement;
            nuevoNodo->pNextNode = NULL;
            This->size++;
            returnAux = 0;
        }
        else
        {
            prev = getNode(This,nodeIndex-1); // 2 bagon 3 bagon
            nuevoNodo->pNextNode = prev->pNextNode;
            prev->pNextNode = nuevoNodo;
            nuevoNodo->pElement = pElement;
            This->size++;
            returnAux = 0;
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
int ll_add(LinkedList* This, void* pElement)
{
    int returnAux = -1;
    int indice = 0;
    // Node* actual;



    if(This!= NULL)
    {
        indice = ll_len(This);
        addNode(This,indice,pElement);
        returnAux =0;

    }




    return returnAux;
}
//  ******* OJO CORREGIR *******************
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* This, int index)
{
    void* returnAux = NULL;
    Node * auxNode;

    if (This != NULL && index >=0 && index < ll_len(This))
    {
        auxNode = getNode(This,index);
        returnAux = auxNode ->pElement;
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
int ll_set(LinkedList* This, int index,void* pElement)
{
    int returnAux = -1;
    Node* actual;
    // int cantidad; no la uso

    if (This != NULL && index >=0 && index < ll_len(This))
    {
        actual = getNode(This,index);
        actual->pElement = pElement;
        returnAux =0;


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
int ll_remove(LinkedList* This,int index)
{
    int returnAux = -1;
    Node* actual;
    Node* prev;
    Node* next;
    // int indice = 0;

    if (This != NULL && index >=0 && index < ll_len(This))
    {
        if (index == 0)
        {
            actual = getNode(This,index);
            free(actual);
            This->size--;
            returnAux=0;
        }
        else
        {
            actual = getNode(This,index);
            prev = getNode(This,index-1);
            next = getNode(This,index+1);
            This->size--;
            prev->pNextNode = next;
            free(actual);
            actual ->pElement = NULL;
            returnAux=0;
        }

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
int ll_clear(LinkedList* This)
{
    int returnAux = -1;
//   Node* nodo; no lo uso
    int i;


    if(This!=NULL)
    {
        for (i=0; i<ll_len(This); i++)
        {


            if(ll_remove(This,i)==0)
            {
                returnAux = 0;
            }


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
int ll_deleteLinkedList(LinkedList* This)
{
    int returnAux = -1;

    if (This!=NULL)
    {
        ll_clear(This);
        free(This);
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
int ll_indexOf(LinkedList* This, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* nodo;
    if (This!=NULL)
    {
        for(i=0; i<ll_len(This); i++)
        {
            nodo=getNode(This,i);

            if (nodo->pElement==pElement)
            {
                returnAux =i;
            }
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
        if( ll_len(this))
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
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
int ll_push(LinkedList* This, int index, void* pElement)
{
    int returnAux = -1;

    if (This!=NULL && index>=0 && index <= ll_len(This))
    {
        addNode(This,index,pElement);
        returnAux=0;


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
void* ll_pop(LinkedList* This,int index)
{
    void* returnAux = NULL;
    Node* nodo;

    if (This!=NULL && index>=0 && index < ll_len(This))
    {
        nodo = getNode(This,index);
        returnAux = nodo->pElement;
        ll_remove(This,index);
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
int ll_contains(LinkedList* This, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* nodo;
    if (This!=NULL)
    {
        returnAux =0;
        for(i=0; i<ll_len(This); i++)
        {
            nodo=getNode(This,i);

            if (nodo->pElement==pElement)
            {
                returnAux =1;
                break;
            }

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
int ll_containsAll(LinkedList* This,LinkedList* This2)
{
    int returnAux = -1;
    int i;
    Node* nodo;

    if (This != NULL && This2!=NULL)
    {
        returnAux = 1;
          for(i=0;i<ll_len(This2);i++)
          {
             nodo = getNode(This2,i);
              if(ll_contains(This,nodo->pElement)==0)
              {
                  returnAux =0;
                  break;
              }

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
LinkedList* ll_subList(LinkedList* This,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* pElement;

    if (This!=NULL && from >=0 && from<=ll_len(This)&& to >=from && to<=ll_len(This))
    {
        cloneArray = ll_newLinkedList();
        if (This!=NULL)
        {
            for(i=from; i<=to; i++)
            {
                pElement = ll_get(This,i);
                ll_add(cloneArray,pElement);


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
LinkedList* ll_clone(LinkedList* This)
{
    LinkedList* cloneArray = NULL;

    if(This!= NULL )
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray!= NULL )
        {
            cloneArray = ll_subList(This,0,ll_len(This));
        }

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
int ll_sort(LinkedList* This, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    void* pAux;
    int i;
    int j;
    Node * auxNode1;
    Node * auxNode2;



    if(This!=NULL && (order == 1 || order ==0 )&& pFunc!=NULL)
    {
        for(i=0; i<ll_len(This)-1; i++)
        {
            auxNode1 = getNode(This,i);
            for(j=i+1; j<ll_len(This); j++)
            {
                auxNode2 = getNode(This,j);
                if (order == 1)
                {
                    if(pFunc(auxNode1->pElement,auxNode2->pElement)== 1)
                    {
                        pAux = auxNode1->pElement;
                        auxNode1->pElement = auxNode2->pElement;
                        auxNode2->pElement= pAux;
                        returnAux=0;
                    }
                }
                else
                {
                    if(pFunc(auxNode1->pElement,auxNode2->pElement)== -1)
                    {
                        pAux = auxNode1->pElement;
                        auxNode1->pElement = auxNode2->pElement;
                        auxNode2->pElement= pAux;
                        returnAux=0;
                    }
                }





            }
        }
    }




    return returnAux;
}

