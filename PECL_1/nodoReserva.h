#ifndef NODORESERVA_H_INCLUDED
#define NODORESERVA_H_INCLUDED

#include <iostream>
#include "reserva.h"


    using namespace std;

    class NodoR{
        public:
            NodoR(Reserva v, NodoR* sig = nullptr)
            {
                valor = v;
                siguiente = sig;
            }



            ~NodoR(){
           }

            Reserva getValor() {
                return valor;
            }

            NodoR* getSiguiente() {
                return siguiente;
            }

            void setSiguiente(NodoR* nodo) {
                siguiente = nodo;
            }

        private:
            Reserva valor;
            NodoR* siguiente;
    };

#endif // NODORESERVA_H_INCLUDED
