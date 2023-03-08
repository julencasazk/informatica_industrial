#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void* cargaDatos(int* dim);

typedef struct pack
{
    long v1 : 4;    // Entra en el 1. long; 4/32
    unsigned long v2 : 16; // Entra en el 1. long; 20/32
    long v3 : 16;   // No entra en el 2. long; 1->20/32,  2-> 16/32
    // Salto de 12 bits
    long v4 : 2;    // Entra en el 2. long; 1->20/32,  2-> 18/32
    unsigned long v5 : 32; // No entra en el 2. long; 1->20/32,  2-> 18/32, 3-> 32/32
    // Salto de 14 bits
    long v6 : 32;   // No entra en el 3. long; 1->20/32,  2-> 18/32, 3-> 32/32, 4->32/32
    // Salto de 0 bits
    unsigned long v7 : 1;   // No entra en el 4. long; 1->20/32,  2-> 18/32, 3-> 32/32, 4->32/32, 5->1/32
    // Salto de 0 bits
    unsigned long v8 : 16;  // Entra en el 5. long; 1->20/32,  2-> 18/32, 3-> 32/32, 4->32/32, 5->17/32
    long v9 : 9;    // Entra en el 5. long; 1->20/32,  2-> 18/32, 3-> 32/32, 4->32/32, 5->26/32

    // [ v1 v2 (12 bits) | v3 v4 (14 bits) | v5 | v6 | v7 v8 v9 (8 bits)]

} pack;




int main()
{

    FILE* fichero = fopen("datos.txt", "a"); // Abro el fichero en modo append

    int dim;
    long* loquedevuelve = (long*)malloc(4 * sizeof(long)); // Reservo hueco en memoria para los 4 bytes que devuelve pero empaquetados
    loquedevuelve = (long*)cargaDatos(&dim);

    pack datos;

    datos.v1 = loquedevuelve[0] & 0xf;
    datos.v2 = (loquedevuelve[0] >> 4 ) & 0xFFFF;
    datos.v3 = (loquedevuelve[0] >> 20) & 0x7ff & ((loquedevuelve[1] & 0xf) << 0x7ff );
    datos.v4 = (loquedevuelve[1] >> 4) & 0x3;
    datos.v5 = (loquedevuelve[1] >> 6) & 0x3FFFFFF & ((loquedevuelve[2] & 0x3f) << 26);

    return 0;
}
