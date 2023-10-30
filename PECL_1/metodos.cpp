
//Importes
#include <iostream>
#include <string.h>

#include "metodos.h"
#include "reserva.h"
#include "mesa.h"
#include "pedido.h"
#include "pilaMesa.h"
#include "nodoMesa.h"
#include "nodoPedido.h"
#include "nodoReserva.h"

using namespace std;

//Definicion de metodos

bool inLista(string& elemento,string* lista, int n) {
    bool encontrado = false;
    int i = 0;
    while (i < n) {
        if (lista[i] == elemento) {
            encontrado = true;
            break;  // Salir del bucle al encontrar el elemento
        }
        i++;
    }
    return encontrado;
}

Reserva reservaRand (){

    // Indices random
    int indexNombre = rand()%nNombres;
    int indexSitu = rand()%nSituaciones;
    int indexHora = rand()%nHora;
    int indexPref = rand()%nPreferencias;

    // Num personas random
    int personas = rand()%(MAX_MESA) + 1; // Sin +1 dominio = {1..7}

    // Creacion reserva
    Reserva res(nombres[indexNombre],situaciones[indexSitu],personas,horas[indexHora],preferencias[indexPref]);

    return res;
}

Mesa mesaRand(){

    int numeroMesa = rand() % 20 + 1; // del 1 al 20
    int capacidad = ((rand() % 2)*4) + 4;  // 4 o 8
    int indexSitu = rand()%nSituaciones;

    Mesa mesa(numeroMesa,capacidad,situaciones[indexSitu]);

    return mesa;
}


bool asignacionMesa(Reserva &res, PilaM &pilaMesas)
{

    string situcionReserva = res.getSituacion();
    int numPersonasReserva = (res.getNumPersonas() <= 4)? 4: 8;

    //Genero dos varible de busqueda
    bool encontrado = false;


    //Busco el primer elemento de la pila
    NodoM ultimo = *pilaMesas.getUltimo();

    while (!encontrado && ultimo.getSiguiente() != nullptr ) // Si no se ha encontrado o no ha llegado al final de pila
    {
            Mesa mesa = ultimo.getValor(); // saco mesa
            string situacionMesa = mesa.getSituacion(); // caracteristicas mesa
            int numPersonasMesa = mesa.getCapacidad();

            bool situacionCheck = situcionReserva==situacionMesa;
            bool numPersonasCheck = numPersonasReserva == numPersonasMesa;

            /*
            // Verbose
            string a,b,c;
            if (situacionCheck ) { a = "si";} else {a = "no"; }
            if (numPersonasCheck ) { b = "si";}else {b = "no"; }
            if (numPersonasCheck && situacionCheck ) { c = "si";}else {c = "no"; }
            cout << "N: " << mesa.getNumeroMesas() << "\n Datos reserva a asginar: \n\t" <<  situcionReserva << "\n\t" << numPersonasReserva << "\nDatos mesa " << mesa.getNumeroMesas() << ":\n\t" << situacionMesa << "\n\t" << numPersonasMesa << "\nFuncionan?: \n\t"<<  a  << "\n\t"<< b <<"\n\tConculsion: " << c << "\n-------------------------------\n"  <<  endl;
            */

            if (situacionCheck && numPersonasCheck){
                mesa.setReserva(&res);              // Asigna
                encontrado = true;
            }
            else{
                ultimo = *ultimo.getSiguiente();
            }


    }

    return encontrado; //&& esta

}
bool reservaCorrespondeMesa(Reserva res, PilaM pilaMesas)
{
    string situcionReserva = res.getSituacion();
    int numPersonasReserva = res.getNumPersonas();

    //Busco el primer elemento de la pila
    NodoM* ultimo = pilaMesas.getUltimo(); //cima

    Mesa mesa = ultimo->getValor(); // saco mesa

    string situacionMesa = mesa.getSituacion(); // caracteristicas mesa
    int numPersonasMesa = mesa.getCapacidad();

    bool situacionCheck = situcionReserva==situacionMesa;
    bool numPersonasCheck = numPersonasReserva==numPersonasMesa;


    return situacionCheck && numPersonasCheck; //&& esta


}
Mesa mesadeReserva(Reserva &res, PilaM &pilaMesas)
{
    string situcionReserva = res.getSituacion();
    int numPersonasReserva = (res.getNumPersonas() <= 4)? 4: 8;

    //Genero dos varible de busqueda
    bool encontrado = false;


    //Busco el primer elemento de la pila
    NodoM* ultimo = pilaMesas.getUltimo(); //cima

    while (!encontrado && ultimo->getSiguiente() != nullptr ) // Si no se ha encontrado o no ha llegado al final de pila
    {
        //Sacamos los datos del la Mesa del Nodo para compararlos
            Mesa mesa = ultimo->getValor(); // saco mesa

            string situacionMesa = mesa.getSituacion(); // caracteristicas mesa
            int numPersonasMesa = mesa.getCapacidad();

            bool situacionCheck = situcionReserva==situacionMesa;
            bool numPersonasCheck = numPersonasReserva==numPersonasMesa;

            if( situacionCheck && numPersonasCheck )
            {
                    encontrado = true;
            }
            else{
               ultimo = ultimo->getSiguiente();
            }

    }
    return ultimo ->getValor();

}

void extraerMesaDePila(Mesa &mesa, PilaM &pilaM)
{
    int numMesa = mesa.getNumeroMesas();
    bool extraido = false;
    NodoM* copiaUltimo = pilaM.getUltimo();
    PilaM pilaAUX;

    while (copiaUltimo && !extraido){
        // Volcado valores a pila aux
        Mesa mesaComparada = copiaUltimo->getValor();
        int numMesaComparada = mesaComparada.getNumeroMesas();

        if (numMesa == numMesaComparada){
            extraido = true;
            pilaM.extraer();
        }
        else{
            Mesa m = pilaM.extraer();
            pilaAUX.insertar(m);
        }
        copiaUltimo = pilaM.getUltimo();
    }

    // Restaurar pilaM desde pilaAUX (en orden invertido)
    while (!pilaAUX.estaVacia())
    {
        Mesa m = pilaAUX.extraer();
        pilaM.insertar(m);
    }
}

bool estaMesa(Mesa mesa, PilaM pilaMesas) {
    NodoM* actual = pilaMesas.getUltimo();

    while (actual != nullptr) {
        if (actual->getValor().getNumeroMesas() == mesa.getNumeroMesas()) {
            return true;
        }
        actual = actual->getSiguiente();
    }

    return false;

}
