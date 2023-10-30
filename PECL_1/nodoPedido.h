//Importes
#include <iostream>
#include "pedido.h"

//Declaracion Importes
using namespace std;

class NodoPedido
{
    public:
        NodoPedido(Pedido pedido, NodoPedido* sig=nullptr)
        {
            valor = pedido;
            siguiente = sig;
        }
        ~NodoPedido(){}

        Pedido getValor(){return valor;}
        NodoPedido* getSiguiente(){return siguiente;}
        void setSiguiente(NodoPedido* _siguiente){siguiente = _siguiente;}
        void setValor(Pedido _valor) {valor=_valor; }
    private:
        Pedido valor;
        NodoPedido* siguiente;
};
