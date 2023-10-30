#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED
using namespace std;

        // Variables de entorno
        const int MAX_MESA = 8;
        const int MAX_NUM_MESA = 20;

        const string nombres[15] = {"Manuel", "Jose", "Rosa", "Galinda", "Josefina", "Maria", "Carlos", "Luis", "Ana", "Sofia", "Pedro", "Laura", "Antonio", "Isabel", "Fernando"};
        const int nNombres = sizeof(nombres)/sizeof(nombres[0]);

        const string situaciones[2] = {"Terraza", "Interior"};
        const int nSituaciones = sizeof(situaciones) / sizeof(situaciones[0]);

        const string horas[3] = {"13:00","14:00","15:00"};
        const int nHora = sizeof(horas) / sizeof(horas[0]);

        const string preferencias[3] = {"Vegano","Sin gluten","Completo"};
        const int nPreferencias = sizeof(preferencias) / sizeof(preferencias[0]);





#endif // VARIABLES_H_INCLUDED
