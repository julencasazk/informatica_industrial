
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.1416f


typedef enum bruh {INICIO, ENCENDIDO, PROCESADO, APAGADO} ESTADO;

typedef enum diaDeSemana {lunes=7, martes=2} DIA;
ESTADO estado = INICIO;

int main() {
    while (1) {
        // Factor comun anterior, cosas que hay que realizar en todos los
        // estados, se sacan del switch
        switch (estado) {
            case INICIO:  // Estado de inicialización
                // Acciones dentro del estado
                // Transiciones
                estado = ENCENDIDO;
                break;
            case ENCENDIDO:
                break;
            case PROCESADO:
                break;
            case APAGADO:
                break;
            default:
                break;
        }
        // Factor comun posterior
        Sleep(1000);
    }

    return 0;
}
