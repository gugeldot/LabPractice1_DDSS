#ifndef COLAPEDIDO_H_INCLUDED
#define COLAPEDIDO_H_INCLUDED

//Importes
#include <iostream>
#include "nodoPedido.h"
#include "pedido.h"

//Declaracion de importes
using namespace std;

class ColaP
{
    public:
        ColaP()
        {
            primero = nullptr;
            ultimo = nullptr;
        }
        ~ColaP()
        {
            while(!estaVacia())
                {
                    eliminar();
                }
        }
        bool estaVacia();
        void eliminar();
        void insertar(Pedido pedido);
        void mostrar();
        NodoPedido* getPrimero() { return primero;}
        NodoPedido* getUltimo () {return ultimo;}
        int tamannoCola();



    private:
        NodoPedido* primero;
        NodoPedido* ultimo;
};





#endif // COLAPEDIDO_H_INCLUDED
