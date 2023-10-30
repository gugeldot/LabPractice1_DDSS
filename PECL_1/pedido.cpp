//Importes
#include "pedido.h"
#include <iostream>

//Declaracion de importes
using namespace std;

Pedido::Pedido(int _numMesa, string _nombreReserva, int _numPersonas, string _preferenciaMenu, string _situacion, bool _finalizado,Mesa* _mesadeReserva)
{
                numMesa = _numMesa;
                nombreReserva = _nombreReserva;
                numPersonas = _numPersonas;
                preferenciaMenu = _preferenciaMenu;
                situacion = _situacion;
                finalizado = _finalizado;
                mesadeReserva = _mesadeReserva;
                reserva = _mesadeReserva ->getReserva();
}

Pedido::Pedido()
{
                numMesa = 0;
                nombreReserva = "";
                numPersonas = 0;
                preferenciaMenu = "";
                situacion = "";
                finalizado = false;
}


string Pedido::toString()
{
    //Genero el string de True o False
    string stringBool = "False";
    if (finalizado){stringBool = "True";}

    //Genero el String
    string result = "Numero de Mesa: " + to_string(numMesa) + "\n";
    result += "Nombre de la Reserva: " + nombreReserva + "\n";
    result += "Numero de Personas: " + to_string(numPersonas) + "\n";
    result += "Situacion: " + situacion + "\n";
    result += "Finalizado: " + stringBool + "\n";
    return result;
}

string Pedido::toStringMINI() {
    string result = "Nombre Reserva: " + nombreReserva + ", Situacion: " + situacion + ", Personas: " + to_string(numPersonas) + ", Menu: " + preferenciaMenu;
    return result;
}
