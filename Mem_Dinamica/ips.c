#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Dispositivo
{
    unsigned short id;
    unsigned char ip[15+1];
} Dispositivo;

typedef struct MES
{
    unsigned char mesIp[15+1];
    unsigned short numDisp;
    Dispositivo *devices;
} MES;

MES leeFichero(char *nombreFichero){

    FILE *fichero = fopen(nombreFichero, "r");
    assert(fichero != NULL && "Error al abrir fichero");

    MES mes;
    //fscanf(fichero, "%s%*s%s",,)
    int scan = fscanf(fichero, " IP_MES: %s N: %hd", mes.mesIp, &mes.numDisp);
    mes.devices = (Dispositivo*)malloc(mes.numDisp * sizeof(Dispositivo));

    for (size_t i = 0; i < mes.numDisp; i++)
    {
        scan = fscanf(fichero, "%hd: %s", &mes.devices[i].id, mes.devices[i].ip);
    }
    
    return mes;
}


int main()
{
    MES mes;
    mes = leeFichero("DatosConfig.txt");

    printf("Ordenador donde se sitúa el programa MES: %s\n\n", mes.mesIp);

    for (int i = 0; i < mes.numDisp; i++){
        printf("Codigo del PLC(%d): %d, direccion IP: %s\n", i, mes.devices[i].id, mes.devices[i].ip);
    }

    return 0;
}


