#ifndef RESERVA_H_INCLUDED
#define RESERVA_H_INCLUDED

//Importes
#include <string>


//Declaracion Importes
using namespace std;


class Reserva{
    public:
        Reserva(string nombre, string situ, int num, string hora,string pref);
        Reserva();
        string toString();
        string toStringMINI();
        string getSituacion();
        int getNumPersonas();
        string getNombre(){return Nombre;}
        string getPrefMenu(){return prefMenu;}
        void setSituacion(string _situacion);
        void setNumPersonas(int _numPersonas);
        string getHoraReserva(){return horaReserva;}

    private:
        string Nombre;
        string situacionM;
        int numPersonas;
        string horaReserva;
        string prefMenu;



};

#endif // RESERVA_H_INCLUDED
