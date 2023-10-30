#include "pilaMesa.h"

PilaM::PilaM(){
    ultimo = nullptr;
}

PilaM::~PilaM(){
    while (ultimo != nullptr) {
        NodoM* nodoAEliminar = ultimo;
        ultimo = ultimo->getSiguiente();
    }
}


void PilaM::insertar(Mesa v) {
    NodoM* nuevo = new NodoM(v);

    if (ultimo) {
        nuevo->setSiguiente(ultimo);
    }
    ultimo = nuevo;

}



Mesa PilaM::extraer() {
    if (ultimo) {
        NodoM* nodo = ultimo;
        ultimo = nodo->getSiguiente();
        Mesa v = nodo->getValor();

        delete nodo;
        return v;
    }
}

void PilaM::mostrar() {
    if (!estaVacia()){
        NodoM* aux = ultimo;
        int i = 1;

        if (aux) {
            cout << "Pila:\n";
            while (aux) {
                cout << i << ". {" << aux->getValor().toStringMINI() << "}\n";
                aux = aux->getSiguiente();
                i++;
            }
        } else {
            cout << "La pila esta vacia.\n";
        }
    }
    else{
        cout << "VACIO" << endl;
    }
}

bool PilaM::estaVacia()
{
    return ultimo == nullptr;
}

void PilaM::mesasNuevasRandom(int n){
    for (int i=0; i<n ; i++){
        Mesa m = mesaRand();
        insertar(m);
    }
}

void PilaM::inicializar(){
    /*
    Realmente tiene poco sentido generar mesas aleatorias, teninedo en cuenta que no se puede reservar una mesa varias veces y que esta tenga diferentes caracteristicas
    Por eso, hemos decidido que el restaurante inicializara por defecto con sus 20 mesas, con sus atributos aleatorios excepto el numero de mesa.
    De esta forma, al extraer e insertar mesas en uso, nunca se perderan las caracteristicas de cada una.
    */
     for (int i = 1; i < MAX_NUM_MESA + 1; i++){
        int capacidad = ((rand() % 2)*4) + 4;  // 4 o 8
        int indexSitu = rand()%nSituaciones;

        Mesa mesa(i,capacidad,situaciones[indexSitu]);
        insertar(mesa);

     }
}

void PilaM::reservaRandPg2P4 ()
{
    int indexSitu = 0;
    for (int i=1; i<9;i++) // Son 8
        {

            int capacidad = ((rand() % 2)*4) + 4;  // 4 o 8
            Mesa mesa(i,capacidad,situaciones[indexSitu]);
            insertar(mesa);
        }
    for(int cont=9; cont < 21; cont++)
    {
        int capacidad = ((rand() % 2)*4) + 4;  // 4 o 8
        int indexSitu = rand()%nSituaciones;

        Mesa mesa(cont,capacidad,situaciones[indexSitu]);
        insertar(mesa);
    }

}

