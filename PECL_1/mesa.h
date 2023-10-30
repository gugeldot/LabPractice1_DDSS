#ifndef MESA_H_INCLUDED
#define MESA_H_INCLUDED

#include <string>
#include "variables.h"
#include "reserva.h"

using namespace std;

class  Mesa {
    public:
        Mesa(int nMesas, int capac, string situ);
        Mesa(int _nMesas, int _capac, string _situ,Reserva* _reservaMesa){
            numeroMesas = _nMesas;
            capacidad = _capac;
            situacion = _situ;
            reservaMesa = _reservaMesa;
        }
        Mesa();
        string toString();
        string toStringMINI();
        Reserva* getReservaMesa();
        void setReservaMesa(Reserva* _reservaMesa);
        string getSituacion(){return situacion;}
        void setSituacion(string _situacion){situacion = _situacion;}
        int getCapacidad(){return capacidad;}
        void setCapacidad(int _capacidad){capacidad = _capacidad;}
        void setReserva(Reserva* _reservaMesa){reservaMesa = _reservaMesa;}
        Reserva* getReserva(){return reservaMesa;}
        int getNumeroMesas() {return numeroMesas;}

    private:
        int numeroMesas;
        int capacidad;
        string situacion;
        Reserva* reservaMesa;



};


#endif // MESA_H_INCLUDED
