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

    return 0;
}
