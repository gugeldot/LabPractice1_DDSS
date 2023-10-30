#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <iostream>
#include "nodo.h"


class Cola {
    public:
        Cola(){
               principio = fin = NULL;
        }

        ~Cola() {
            while (!estaVacia()) {
                eliminar();
            }
        }

        bool estaVacia();

        void insertar(int v);

        void eliminar();

        void mostrar();

    private:
        Nodo* principio;
        Nodo* fin;
};

#endif // COLA_H_INCLUDED
