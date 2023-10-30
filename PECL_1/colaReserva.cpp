#include "colaReserva.h"
#include "variables.h"

bool ColaR::estaVacia() {
            return principio == nullptr;
}

void ColaR::insertar(Reserva v) {
        NodoR* nuevo = new NodoR(v);
        if (fin){
          fin -> setSiguiente(nuevo);
        }

        fin = nuevo;
        if (!principio)
          principio = nuevo;

    }

void ColaR::eliminar() {
    if (!estaVacia()) {
        NodoR* nodoAEliminar = principio;
        principio = principio->getSiguiente();
        delete nodoAEliminar;
    }
}

void ColaR::mostrar() {
    if (!estaVacia()) {
        NodoR* actual = principio;
        cout << "Contenidos de cola: " << endl;
        int i = 1;
        while (actual != NULL) {

            cout << i << ". {" <<actual->getValor().toStringMINI() << "}\n";
            actual = actual->getSiguiente();
            i++;
        }
    }
    else {
        cout << "VACIO" << endl;
    }
}

void ColaR::reservasNuevasRandom(int n){
    for (int i=0; i<n ; i++){
        insertar(reservaRand());
    }
}

void ColaR::reservaRandPg2P1 (){
    int indexHora = 0;

    while (indexHora < nHora){
        // Indices random
        for (int i=0; i<4;i++)
            {
                int indexNombre = rand()%nNombres;
                int indexSitu = rand()%nSituaciones;

                int indexPref = rand()%nPreferencias;

                // Num personas random
                int personas = rand()%(MAX_MESA)+1; // Sin +1 dominio = {1..7}

                // Creacion reserva
                Reserva res(nombres[indexNombre],situaciones[indexSitu],personas,horas[indexHora],preferencias[indexPref]);
                insertar(res);
            }
            indexHora++;
    }
}

int ColaR::tamannoCola()
{
    //Contador para contar el numero de elementos
    int contador = 0;

    //Hago una copia para iterar sin tocar la cola original
    NodoR* ultimoAux = principio;

    //Itero
    while(ultimoAux != nullptr)
        {

            ultimoAux = ultimoAux->getSiguiente();
            contador++;

        }

    return contador;

}
