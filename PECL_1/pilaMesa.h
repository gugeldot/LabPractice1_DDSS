#ifndef PILAMESA_H_INCLUDED
#define PILAMESA_H_INCLUDED
#include "nodoMesa.h"
#include "metodos.h"
#include "variables.h"

    class PilaM{
        public:
            PilaM();
            ~PilaM();
            void insertar(Mesa v);
            Mesa extraer();
            void mostrar();
            void mesasNuevasRandom(int n);
            void inicializar();
            bool estaVacia();
            void reservaRandPg2P4 ();
            NodoM* getUltimo(){return ultimo;}

        private:
            NodoM* ultimo;

    };


#endif // PILAMESA_H_INCLUDED
