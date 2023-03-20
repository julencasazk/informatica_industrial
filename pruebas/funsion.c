#include <stdio.h>
#include <stdlib.h>

void desplazarBitsIzquierda(char* bloqueActual, int tamanyoBloque, char* bloqueNuevo, int bitsADesplazar){


    for (size_t i = 0; i < tamanyoBloque; i++) {
        
        if (i != (tamanyoBloque - 1)) {
        bloqueNuevo[i] = (bloqueActual[i] >>  bitsADesplazar) | (bloqueActual[i+1] << (8 - bitsADesplazar));           
        } else {
            bloqueNuevo[i] = bloqueActual[i] >> bitsADesplazar;
        }
        
    }
    // Acordarze de asignar memoria a bloqueNuevo con malloc, y liberarla cuando no la necesitas.

}

int main()
{

    FILE *fichero = fopen("codigoBarras.txt", "a"); // Hacer esto al principio de cada lectura
    // Convertir 
    unsigned long ms = 7200000;

    unsigned long seg;
    unsigned long min;
    unsigned long hora;
    unsigned long dia;

    seg = ms / 1000;
    ms %= 1000;
    min = seg / 60;
    seg %= 60;
    hora = min / 60;
    min %= 60;
    dia = hora / 24;
    hora %= 24;

    printf("[%d;%d:%d:%d,%d]\n", dia, hora, min, seg, ms);


    fclose(fichero);

    return 0;
}
