#ifndef NODOMESA_H_INCLUDED
#define NODOMESA_H_INCLUDED
#include <iostream>
#include "mesa.h"

    using namespace std;

    class NodoM{
        public:
            NodoM(Mesa v, NodoM* sig = nullptr)
            {
                valor = v;
                siguiente = sig;
            }

            ~NodoM(){
           }

            Mesa getValor() {
                return valor;
            }

            NodoM* getSiguiente() {
                return siguiente;
            }

            void setSiguiente(NodoM* nodo) {
                siguiente = nodo;
            }

        private:
            Mesa valor;
            NodoM* siguiente;
            friend class PilaM;

    };

#endif // NODOMESA_H_INCLUDED
