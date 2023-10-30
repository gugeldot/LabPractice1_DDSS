#include <iostream>
#include "reserva.h"
#include "metodos.h"

using namespace std;
Reserva::Reserva(string nombre, string situ, int num, string hora,string pref){
            Nombre = nombre;
            situacionM = situ;
            numPersonas = num;
            horaReserva = hora;
            prefMenu = pref;
}

Reserva::Reserva() {
    Nombre = "";
    situacionM = "";
    numPersonas = 0;
    horaReserva = "";
    prefMenu = "";
}

string Reserva::getSituacion(){return situacionM;}
int Reserva::getNumPersonas(){return numPersonas;}
void Reserva::setSituacion(string _situacion){situacionM = _situacion;}
void Reserva::setNumPersonas(int _numPersonas){numPersonas = _numPersonas;}


string Reserva::toString() {
    string result = "Nombre: " + Nombre + "\n";
    result += "Situacion: " + situacionM + "\n";
    result += "Numero de Personas: " + to_string(numPersonas) + "\n";
    result += "Hora de Reserva: " + horaReserva + "\n";
    result += "Preferencia de Menu: " + prefMenu + "\n";
    return result;
}
string Reserva::toStringMINI() {
    string result = "Nombre: " + Nombre + ", Situacion: " + situacionM + ", Personas: " + to_string(numPersonas) + ", Hora: " + horaReserva + ", Menu: " + prefMenu;
    return result;
}
