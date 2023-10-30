#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <iostream>
    using namespace std;

    class Nodo{
        public:
            Nodo(int v, Nodo* sig = nullptr)
            {
                valor = v;
                siguiente = sig;
            }




           ~Nodo(){
           }

            int getValor() {
                return valor;
            }

            Nodo* getSiguiente() {
                return siguiente;
            }

            void setSiguiente(Nodo* nodo) {
                siguiente = nodo;
            }

        private:
            int valor;
            Nodo* siguiente;

    };


#endif // NODO_H_INCLUDED
