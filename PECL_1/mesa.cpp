//Importes
#include <iostream>
#include "mesa.h"
#include "reserva.h"

//Declaracion de Importes
using namespace std;


//Declaracion de metodos para la clase Mesa
Mesa::Mesa(int nMesas, int capac, string situ)
{
    numeroMesas = nMesas;
    capacidad = capac;
    situacion = situ;
}
Mesa::Mesa()
{
    numeroMesas = 0;
    capacidad = 0;
    situacion = situaciones[0];
}
string Mesa::toString()
{
    string result = "Numero de Mesas: " + to_string(numeroMesas) + "\n";
    result += "Capacidad: " + to_string(capacidad) + "\n";
    result += "Situacion: " + situacion + "\n";
    return result;
}
string Mesa::toStringMINI()
{
    string result = "Numero de Mesas: " + to_string(numeroMesas) + ", Capacidad: " + to_string(capacidad) + ", Situacion: " + situacion;
    return result;
}

Reserva* Mesa::getReservaMesa(){return reservaMesa;}
void Mesa::setReservaMesa(Reserva* _reservaMesa){reservaMesa = _reservaMesa;}
