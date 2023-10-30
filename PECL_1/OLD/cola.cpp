#include "cola.h"

bool Cola::estaVacia() {
            return principio == nullptr;
}

void Cola::insertar(int v) {
        Nodo* nuevo = new Nodo(v);
        if (fin){
          fin -> setSiguiente(nuevo);
        }

        fin = nuevo;
        if (!principio)
          principio = nuevo;

    }

void Cola::eliminar() {
    if (!estaVacia()) {
        Nodo* nodoAEliminar = principio;
        principio = principio->getSiguiente();
        delete nodoAEliminar;
    }
}

void Cola::mostrar() {
    Nodo* actual = principio;
    while (actual != NULL) {
        std::cout << actual->getValor() << " ";
        actual = actual->getSiguiente();
    }
    std::cout << std::endl;
}
