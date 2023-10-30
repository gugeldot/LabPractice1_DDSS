//Importes
#include <iostream>
#include "colaPedido.h"

//Declaracion Importes
using namespace std;

bool ColaP::estaVacia()
{
    return primero == nullptr;
}

void ColaP::eliminar()
{
    if(!estaVacia())
        {
            NodoPedido* nodoAELiminar = primero;
            primero = primero -> getSiguiente();
            delete nodoAELiminar ;
        }
}


void ColaP::insertar(Pedido pedido)
{
    //Creamos el nodo
    NodoPedido* nuevo = new NodoPedido(pedido);

    if(ultimo)
        {
            ultimo -> setSiguiente(nuevo);
        }

    ultimo = nuevo;

    //Comprobamos si habia principio
    if(!primero)
        {   //Como no hay primero, este tambien apuntara al nuevo nodo.
            primero = nuevo;
        }

}


void ColaP::mostrar() {
    if (!estaVacia()){
        NodoPedido* actual = primero;
        cout << "Contenidos de pedidos: " << endl;
        int i = 1;
        while (actual != NULL) {
            Pedido pedido = actual->getValor();
            int numMesaReserva = pedido.getNumMesa();
            string estado = (pedido.getFinalizado())? "FINALIZADO" : "PENDIENTE";
            cout << i << ". {" <<pedido.toStringMINI()<< "}\t["<<estado << "]\n";
            cout << "\t->Mesa reservada: " << pedido.getMesadeReserva() ->toStringMINI() <<  endl;
            actual = actual->getSiguiente();
            i++;
        }
    }
    else {
        cout << "VACIO" << endl;
    }
}

int ColaP::tamannoCola()
{
    //Contador para contar el numero de elementos
    int contador = 0;

    //Hago una copia para iterar sin tocar la cola original
    NodoPedido* ultimoAux = primero;

    //Itero
    while(ultimoAux != nullptr)
        {
            ultimoAux = ultimoAux->getSiguiente();
            contador++;
        }
    return contador;
}



