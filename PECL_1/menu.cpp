// Importes
#include "menu.h"
#include "reserva.h"
#include "colaReserva.h"
#include "colaPedido.h"
#include "pilaMesa.h"
#include "metodos.h"
#include "pedido.h"
//Declaracion Importes
using namespace std;


//Definicion de metodos

//Creo variables que voy a necesitar para que pueda ejecutarse el menu correctamente
int opcionUser;
string horaReservasGestionar;
int opcionGestionHoraReserva;
int contadorPedidosAnexados = 0;
ColaR colaAuxReservas;

//Creo todo lo necesario para inicializar el "restaurante"

// Colas de reserva
ColaR cReservas;        // Reservas hechas por clientes
ColaR cPendientes;      // Reservas almacenadas pendientes de gestion


// Pila de mesas
PilaM pMesas;

// Cola de pedidos
ColaP cPedidos;

void gestionDeUnaReserva (NodoR* nodoPrimeraReserva, Reserva resTemp)
{
    if(asignacionMesa(resTemp,pMesas)) // Esta asignada y por tanto existe
    {
        cout << "\tSe ha encontrado mesa satisfacotriamente!" << endl;
        //Creo el pedido
        Mesa mesaReserva = mesadeReserva(resTemp,pMesas);
        int numMesa = mesaReserva.getNumeroMesas();     // Genera atributos pasa generar clase nueva
        int capac = mesaReserva.getCapacidad();
        string situ = mesaReserva.getSituacion();
        Reserva* reservaMesa = mesaReserva.getReserva();

        Mesa* mesa = new Mesa(numMesa,capac,situ,reservaMesa);
        string nombreReserva = resTemp.getNombre();
        int numPersonas = resTemp.getNumPersonas();
        string preferenciaMenu = resTemp.getPrefMenu();
        string situacion = resTemp.getSituacion();
        bool finalizado = false;
        Pedido nuevoPedido = Pedido(numMesa,nombreReserva,numPersonas,preferenciaMenu,situacion,finalizado,mesa);
        cPedidos.insertar(nuevoPedido);
        cout << "\tPedido generado e insertado" << endl;
        cReservas.eliminar();
        cout << "\tReserva eliminada de la cola" << endl;
        extraerMesaDePila(mesaReserva,pMesas);
        cout << "\tMesa extraida de la pila" << endl;
    }
    else {
        cout << "\tVaya...no se ha encontrado mesa \nPasando reserva a Pendientes" << endl;
        cPendientes.insertar(resTemp);
        cReservas.eliminar();
        }
}

void gestionDeUnaReservaSILENT (NodoR* nodoPrimeraReserva, Reserva resTemp)
{
    if(asignacionMesa(resTemp,pMesas)) // Esta asignada y por tanto existe
    {

        //Creo el pedido
        Mesa mesaReserva = mesadeReserva(resTemp,pMesas);
        int numMesa = mesaReserva.getNumeroMesas();     // Genera atributos pasa generar clase nueva
        int capac = mesaReserva.getCapacidad();
        string situ = mesaReserva.getSituacion();
        Reserva* reservaMesa = mesaReserva.getReserva();

        Mesa* mesa = new Mesa(numMesa,capac,situ,reservaMesa);
        string nombreReserva = resTemp.getNombre();
        int numPersonas = resTemp.getNumPersonas();
        string preferenciaMenu = resTemp.getPrefMenu();
        string situacion = resTemp.getSituacion();
        bool finalizado = false;
        Pedido nuevoPedido = Pedido(numMesa,nombreReserva,numPersonas,preferenciaMenu,situacion,finalizado,mesa);
        cPedidos.insertar(nuevoPedido);

        cReservas.eliminar();

        extraerMesaDePila(mesaReserva,pMesas);
        cout << "\t[+]Pedido de " << resTemp.getNombre() << " gestionado [Mesa "<< mesa->getNumeroMesas() << "]"<< endl;
        contadorPedidosAnexados++;
    }
    else {
        cout << "\t[-]Pedido de " << resTemp.getNombre() << " no ha podido ser gestionado -> Anexado a cola de pendientes"<< endl;
        cPendientes.insertar(resTemp);
        cReservas.eliminar();
        }
}

void gestionPendiente(NodoR* nodoPrimeraReserva, Reserva resTemp) // Identica excepto parte del else
{
    if(asignacionMesa(resTemp,pMesas)) // Esta asignada y por tanto existe
    {
        cout << "\tSe ha encontrado mesa satisfacotriamente para gestionarla de cPendientes!" << endl;
        //Creo el pedido
        Mesa mesaReserva = mesadeReserva(resTemp,pMesas);

        int numMesa = mesaReserva.getNumeroMesas();     // Genera atributos pasa generar clase nueva
        int capac = mesaReserva.getCapacidad();
        string situ = mesaReserva.getSituacion();
        Reserva* reservaMesa = mesaReserva.getReserva();
        Mesa* mesa = new Mesa(numMesa,capac,situ,reservaMesa);
        string nombreReserva = resTemp.getNombre();
        int numPersonas = resTemp.getNumPersonas();
        string preferenciaMenu = resTemp.getPrefMenu();
        string situacion = resTemp.getSituacion();

        bool finalizado = false;
        Pedido nuevoPedido = Pedido(numMesa,nombreReserva,numPersonas,preferenciaMenu,situacion,finalizado,mesa);
        cPedidos.insertar(nuevoPedido);
        cout << "\tPedido generado e insertado" << endl;
        cReservas.eliminar();
        cout << "\tReserva eliminada de la colaPendientes" << endl;


        extraerMesaDePila(mesaReserva,pMesas);
        cout << "\tMesa extraida de la pila" << endl;
    }
    else{
        cout << "\tVaya...no se ha encontrado mesa \nPasando reserva al final de  cPendientes" << endl;
        cPendientes.eliminar();
        cPendientes.insertar(resTemp);
    }

}

void gestionPendienteSILENT(NodoR* nodoPrimeraReserva, Reserva resTemp) // Identica excepto parte del else
{
    if(asignacionMesa(resTemp,pMesas)) // Esta asignada y por tanto existe
    {
        //Creo el pedido
        Mesa mesaReserva = mesadeReserva(resTemp,pMesas);

        int numMesa = mesaReserva.getNumeroMesas();     // Genera atributos pasa generar clase nueva
        int capac = mesaReserva.getCapacidad();
        string situ = mesaReserva.getSituacion();
        Reserva* reservaMesa = mesaReserva.getReserva();
        Mesa* mesa = new Mesa(numMesa,capac,situ,reservaMesa);
        string nombreReserva = resTemp.getNombre();
        int numPersonas = resTemp.getNumPersonas();
        string preferenciaMenu = resTemp.getPrefMenu();
        string situacion = resTemp.getSituacion();

        bool finalizado = false;
        Pedido nuevoPedido = Pedido(numMesa,nombreReserva,numPersonas,preferenciaMenu,situacion,finalizado,mesa);
        cPedidos.insertar(nuevoPedido);
        cReservas.eliminar();


        extraerMesaDePila(mesaReserva,pMesas);
        cout << "\t[++]PENDIENTE RECUPERADO: Pedido de " << resTemp.getNombre() << " gestionado [Mesa "<< mesa->getNumeroMesas() << "]"<< endl;
        cPendientes.eliminar();
        contadorPedidosAnexados++;

    }
    else{
        cout << "\t[--]Pedido de " << resTemp.getNombre() << " no ha podido ser gestionado -> Anexado a cola de pendientes"<< endl;

        cPendientes.eliminar();
        cPendientes.insertar(resTemp);
    }

}


void mostrarTodo(){
    cout << "\n-------" << endl;
    cout << "Cola reservas" << endl;
    cReservas.mostrar();
    cout << "\n-------" << endl;
    cout << "Cola de reservas pendientes" << endl;
    cPendientes.mostrar();
    cout << "\n-------" << endl;
    cout << "Pila de mesas" << endl;
    pMesas.mostrar();
    cout << "\n-------" << endl;
    cout << "Cola de pedidos" << endl;
    cPedidos.mostrar();
    cout << "\n-------" << endl;

}


void abrirMenu()
{

    do{
            //Muestro el menu
            cout << "\n\n\n\tBienvenido a PastasEstructuradas\n";
            cout << "\t======================================\n";
            cout << "\n\nMENU DE OPCIONES:\n";
            cout << "\n1.Generar 12 reservas";
            cout << "\n2.Mostrar todas las reservas";
            cout << "\n3.Borrar todas las reservas ";
            cout << "\n4.Generar 20 mesas";
            cout << "\n5.Mostrar mesas";
            cout << "\n6.Borrar mesas";
            cout << "\n7.Gestion Completa de 1 reserva";
            cout << "\n8.Gestion Completa de reservas a una determinada hora.";
            cout << "\n9.Gestion de todas las reservas del restaurante";
            cout << "\n0.Salir del programa";

            //Almaceno la opcion del usuario
            cout << "\n\nElija la opcion deseada escribiendo un numero del 1 al 9 --> ", cin >> opcionUser, cout << endl;


            //En funcion de la opcion del usuario vemos si hacemos una cosa o otra
            switch (opcionUser)
            {
                case 0:
                    cout << "\nCERRANDO PROGRAMA...";
                    break;
                case 1:
                    if(cReservas.estaVacia())
                    {
                        cReservas.reservaRandPg2P1();
                    }
                    else
                        {
                            //Sino esta vacia, primero la limpio, y luego creo las reservas
                            while(!cReservas.estaVacia())
                                {
                                    cReservas.eliminar();
                                }
                            cReservas.reservaRandPg2P1();

                        }
                    break;
                case 2:
                    cReservas.mostrar();
                    break;
                case 3:
                    if(cReservas.estaVacia())
                    {
                        cout << "No hay nada que borrar" << endl;
                    }
                    else
                        {
                            //Sino esta vacia, primero la limpio, y luego creo las reservas
                            while(!cReservas.estaVacia())
                                {
                                    cReservas.eliminar();
                                }
                            cout << "Reservas eliminadas correctamente" << endl;
                        }
                    break;
                case 4:
                    if(pMesas.estaVacia())
                    {
                        pMesas.reservaRandPg2P4();
                    }
                    else
                        {
                            //Sino esta vacia, primero la limpio, y luego creo las reservas
                            while(!pMesas.estaVacia())
                                {
                                    pMesas.extraer();
                                }
                            pMesas.reservaRandPg2P4();

                        }
                    break;
                case 5:
                    pMesas.mostrar();
                    break;
                case 6:
                    if(pMesas.estaVacia())
                    {
                        cout << "No hay nada que borrar" << endl;
                    }
                    else
                        {
                            //Sino esta vacia, primero la limpio, y luego creo las reservas
                            while(!pMesas.estaVacia())
                                {
                                    pMesas.extraer();
                                }
                            cout << "Mesas eliminadas correctamente" << endl;

                        }
                    break;
                case 7:
                    {
                        bool ningunaVacia = true;
                        if (pMesas.estaVacia()){
                             cout << "\tPila Mesas vacia, no hay nada que gestionar" << endl;
                             ningunaVacia = false;

                        }
                        if (cReservas.estaVacia()){
                            cout << "\tCola reservas vacia, no hay nada que gestionar" << endl;
                            ningunaVacia = false;
                        }


                        if(ningunaVacia)
                            {
                                NodoR* nodoPrimeraReserva =  cReservas.getPrincipio(); // una reserva
                                Reserva resTemp = nodoPrimeraReserva->getValor();

                                gestionDeUnaReserva(nodoPrimeraReserva,resTemp);
                            }


                        mostrarTodo();

                    }
                    break;
                case 8:
                    {

                    cout << "\n\nGestionar Reservas para la hora:\n";
                    cout << "\n1.13:00";
                    cout << "\n2.14:00";
                    cout << "\n3.15:00";
                    cout << "\n\nEscriba que hora desea gestionar 1 al 3 --> ", cin >> opcionGestionHoraReserva, cout << endl;

                    //Compruebo que haya metido una opcion valida
                    if (opcionGestionHoraReserva == 1 || opcionGestionHoraReserva == 2 || opcionGestionHoraReserva == 3)
                        {
                            if(opcionGestionHoraReserva == 1)
                                {horaReservasGestionar = "13:00";}
                            else if (opcionGestionHoraReserva == 2)
                                {horaReservasGestionar = "14:00";}
                            else
                                {horaReservasGestionar = "15:00";}



                            //Gestiono las reservas
                            if(!cReservas.estaVacia() && !pMesas.estaVacia())
                                {
                                    while (!cReservas.estaVacia())
                                        {
                                            //Creo la reserva a gestionar
                                            NodoR* nodoPrimeraReserva =  cReservas.getPrincipio(); // una reserva
                                            Reserva resTemp = nodoPrimeraReserva->getValor();

                                            if (cReservas.getPrincipio()->getValor().getHoraReserva() == horaReservasGestionar)
                                                {
                                                    gestionDeUnaReservaSILENT(nodoPrimeraReserva,resTemp);
                                                }
                                            else
                                                {
                                                    //Lo que no se debe de gestionar
                                                    colaAuxReservas.insertar(resTemp);
                                                    cReservas.eliminar();
                                                }
                                        }
                                        //Devuelvo las reservas a su cola original
                                        while(!colaAuxReservas.estaVacia())
                                            {
                                                //Creo la reserva a gestionar
                                                Reserva resTemp = colaAuxReservas.getPrincipio()->getValor();
                                                cReservas.insertar(resTemp);
                                                colaAuxReservas.eliminar();
                                            }
                                }
                            if(cReservas.estaVacia()){cout << "La cola de reservas esta vacia, no hay nada que gestionar" << endl;}
                            if(pMesas.estaVacia()){cout << "La pila de mesas esta vacia, no hay nada que gestionar" << endl;}
                            }
                    else
                        {cout << "Opcion introducida no valida." << endl;}

                        mostrarTodo();
                    }
                    break;
                case 9:
                    {
                        int contadorPendientes = 0;
                        int contadorHoras = 0;
                        NodoPedido* puntoDePartida = nullptr;


                        if (pMesas.estaVacia())
                            {cout << "\tPila Mesas vacia, no hay nada que gestionar" << endl;}
                        if (cReservas.estaVacia())
                            {cout << "\tCola reservas vacia, no hay nada que gestionar" << endl;}

                        // Gestion de reservas (8 + funcionalidades)
                        while(!pMesas.estaVacia() && !cReservas.estaVacia())
                            {

                                NodoR* nodoPrimeraReserva =  cReservas.getPrincipio(); // una reserva
                                Reserva resTemp = nodoPrimeraReserva->getValor();

                                // Tratamiento de pendientes
                                if (contadorPendientes == 2)
                                    {
                                        cout << "------- Checkeo rutinario de pedidos pendientes -------" << endl;

                                        if(!cPendientes.estaVacia())
                                        {
                                            NodoR* nodoPrimeraReserva =  cPendientes.getPrincipio(); // una reserva
                                            Reserva resTemp = nodoPrimeraReserva->getValor();
                                            gestionPendienteSILENT(nodoPrimeraReserva,resTemp);

                                        }
                                        else
                                        {cout << "\t->La cola de reservas pendientes esta vacia" << endl;}

                                        //Reinciamos el contadorPendientes
                                        contadorPendientes = 0;
                                    }
                                else{
                                    gestionDeUnaReservaSILENT(nodoPrimeraReserva,resTemp);
                                    contadorPendientes++; // Se tiene en cuenta que el gestionar una reserva como pendiente cuenta como gestionada
                                    //cout <<"\t" << resTemp.getNombre() << " : " << resTemp.getHoraReserva() << " : " << contadorHoras << endl;
                                    contadorHoras++;
                                }
                                // Finalizacion de pedidos
                                if(contadorHoras > 3)
                                {
                                    //contadorPedidosAnexados variable de cuantos hay q avanzar
                                    int n = contadorPedidosAnexados /2;
                                    cout << "!------ Pedidos finalizados ------!" << endl;
                                    if (puntoDePartida == nullptr)
                                        puntoDePartida = cPedidos.getPrimero();

                                    //Getionas la cola de pedidos, poniendo a true el atributo finalizado de la mitad de la cola
                                    for (int i =0; i < n ; i++)
                                        {
                                            Pedido pedido = puntoDePartida->getValor();
                                            pedido.setFinalizado(true);
                                            puntoDePartida->setValor(pedido);
                                            Mesa mesa = *pedido.getMesadeReserva();
                                            pMesas.insertar(mesa);

                                            cout << "\t[*]Pedido liberado" << "\n\t\t" <<mesa.toStringMINI() << endl;
                                            puntoDePartida = puntoDePartida->getSiguiente();
                                        }



                                    contadorPedidosAnexados = 0;
                                    contadorHoras = 0;
                                }


                            }


                        cout << "----------------------\nNo hay mas reservas, gestionando las pendientes" << endl;
                        //Gestion de las pendientes restantes
                        if(cReservas.estaVacia() && !cPendientes.estaVacia())
                            {
                                int tamannoPendientes = cPendientes.tamannoCola();

                                for (int i = 0; i < tamannoPendientes; i++)
                                    {
                                        NodoR* nodoPrimeraReserva =  cPendientes.getPrincipio(); // una reserva
                                        Reserva resTemp = nodoPrimeraReserva->getValor();

                                        gestionPendienteSILENT(nodoPrimeraReserva,resTemp);
                                    }

                            }
                        if (!cPendientes.estaVacia()){
                            cout << "Siguen reservas pendientes, se ha intentado volver a gestionarlas pero no ha sido posible" << endl;
                        }
                        else if (cPendientes.estaVacia()){
                            cout << "Cola pendientes vacia" << endl;
                        }




                        mostrarTodo();
                    }
                    break;
                default:
                    cout << "\nOpcion no disponible, porfavor seleccione una valida.";
                    break;
            }
        }
    while (opcionUser != 0);
}

