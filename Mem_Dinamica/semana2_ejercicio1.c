#include <stdio.h>
#include <stdlib.h>

typedef struct dispositivo {
    short id;
    char ip[15+1];  // cada grupo de 4 bits de la dir ip.
} Device;

typedef struct mes {  
    char mesIp[15 + 1]; // 15 + 1 por el char de fin de cadena \0 
    short numeroDispositivos;
    Device listaDispositivos[20];
} MES;

MES leeFichero(char* nomFichero) {
    int count = 15; // Variable para loop de los dispositivos, i = n. de dispositivos, por defecto 15
    FILE *fichero = fopen(nomFichero, "r");
    assert(fichero != NULL && "Error al abrir fichero");

    MES mes;
    Device *dispositivos;

    char primero[6 + 1];
    char segundo[15 + 1];

    int escaneo = fscanf(fichero, "%s: %s", primero, segundo);
    assert(escaneo != 2 && "Error al usar fscanf");

        // Siempre sigue el mismo patrón: ALGO: ALGO\n
    // Lo que hago es ir comparando la primera parte con strings concretos, y dependiendo de lo que sea, meter el segundo donde toque

    if (strcmp(primero, "IP_MES")) {
        strcpy(mes.mesIp, segundo);

    } else if (strcmp(primero, "N")) {
        char *endptr; // Necesario para strtol
        count = strtol(segundo, &endptr, 10);
        //
        printf("Numero de dispositivos: %d\n", count);
        //
        mes.numeroDispositivos = count;

        dispositivos = (Device *)malloc(count * sizeof(Device));
        assert(dispositivos != NULL &&
           "Error al reservar memoria");  // Si no se cumple la condición sale
                                          // del programa

    } else {
    }

    for (size_t i = 0; i < count; i++)
    {
        int escaneo = fscanf(fichero, "%s: %s", primero, segundo);
        assert(escaneo != EOF && "Fin de fichero");
        *(dispositivos + i)->ip = segundo; 
        
    }

    return mes; 
    
}


int main() { 

    MES mes;
    mes = leeFichero("DatosConfig.txt");

    printf("Ordenador donde se sitúa el programa MES: %s\n\n", mes.mesIp);

    for (int i = 0; i < mes.numeroDispositivos; i++){
        printf("Codigo del PLC(%d): %d, direccion IP: %s\n", i, mes.listaDispositivos[i].id, mes.listaDispositivos[i].ip);
    }
    
    
    return 0; 
}

