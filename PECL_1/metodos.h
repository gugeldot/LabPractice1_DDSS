//Importes
#include <string>
#include "reserva.h"
#include <stdlib.h>
#include <ctime>
#include "variables.h"
#include "mesa.h"
#include "pilaMesa.h"

//Declaracion Importes
#ifndef METODOS_H_INCLUDED
#define METODOS_H_INCLUDED

class PilaM;
using namespace std;

bool inLista(string& elemento,string* lista, int n);
Reserva reservaRand ();
Mesa mesaRand();
bool asignacionMesa(Reserva &res,PilaM &pilaMesas);
Mesa mesadeReserva(Reserva &res, PilaM &pilaMesas);
void extraerMesaDePila(Mesa &mesa, PilaM &pilaM);
bool estaMesa (Mesa mesa, PilaM pilaMesas);


#endif // METODOS_H_INCLUDED
