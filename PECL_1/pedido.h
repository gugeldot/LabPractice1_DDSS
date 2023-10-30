#ifndef PEDIDO_H_INCLUDED
#define PEDIDO_H_INCLUDED

//Importes
#include <iostream>
#include "mesa.h"
#include "reserva.h"

//Declaracion Importes
using namespace std;

class Pedido
{
    public:
        Pedido(int _numMesa, string _nombreReserva, int _numPersonas, string _preferenciaMenu, string _situacion, bool _finalizado,Mesa* _mesadeReserva);
        Pedido();
        ~Pedido(){}

        string toString();
        string toStringMINI();
        int getNumMesa (){return numMesa;}
        Mesa* getMesadeReserva () {return mesadeReserva;}
        void setFinalizado(bool _finalizado){finalizado = _finalizado;}
        bool getFinalizado (){return finalizado;}
        Reserva* getReserva(){return reserva;}
    private:
        int numMesa;
        string nombreReserva;
        int numPersonas;
        string preferenciaMenu;
        string situacion;

        Mesa* mesadeReserva;
        Reserva* reserva;
        bool finalizado;

};

#endif // PEDIDO_H_INCLUDED
