#ifndef COLARESERVA_H_INCLUDED
#define COLARESERVA_H_INCLUDED
#include <iostream>
#include "reserva.h"
#include "nodoReserva.h"
#include "metodos.h"
class ColaR {
    public:
        ColaR(){
               principio = fin = nullptr;
        }

        ~ColaR() {
            while (!estaVacia()) {
                eliminar();
            }
        }

        bool estaVacia();

        void insertar(Reserva v);

        void eliminar();

        void mostrar();

        void reservasNuevasRandom(int n);

        void reservaRandPg2P1();

        NodoR* getPrincipio(){return principio;}

        int tamannoCola();

    private:
        NodoR* principio;
        NodoR* fin;
};

#endif // COLARESERVA_H_INCLUDED
