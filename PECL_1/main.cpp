
//Importes
#include <iostream>
#include <stdlib.h>
#include <ctime>

//Importes de proyecto
#include "metodos.h"
#include "variables.h"
#include "reserva.h"
#include "colaReserva.h"
#include "pilaMesa.h"
#include "pedido.h"
#include "menu.h"


//Declaracion Importes
using namespace std;

int main()
{
    // Seed random
    srand(time(NULL));


    abrirMenu();




    //TESTEO DE UN CORRECTO FUNCIONAMIENTO DE LOS TAD´s
    // Testeo de pilas (LIFO)
    /*
    PilaM pMesas;
    pMesas.insertar(mesaRand());
    pMesas.mostrar();
    pMesas.insertar(mesaRand());
    pMesas.mostrar();
    pMesas.insertar(mesaRand());
    pMesas.mostrar();
    pMesas.insertar(mesaRand());
    pMesas.mostrar();

    pMesas.extraer();
    pMesas.mostrar();


    // Testeo de colas (FIFO)
    cReservas.insertar(reservaRand());
    cReservas.reservasNuevasRandom(2);
    cReservas.mostrar();

    cReservas.eliminar();
    cReservas.mostrar();
    */


    return 0;
}

