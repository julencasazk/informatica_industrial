#include <stdio.h>

#define TIPO short // Cambiar el tipo del registro

const int iteraciones = 250; // Numero de iteraciones que se van a imprimir
// const int longitud = sizeof(char);

int main(){
   
    unsigned TIPO registro = 0; // Registro de 16 bits
    const int longitud = sizeof(registro) * 8; // Numero de bits del registro
    registro = ((1 << (longitud - 1)) | (1)); // 1000000000000001 -> Valor inicial del registro

    int contador = 0; // Contador que irá de 0 a 7 y vuelta
    int subiendo = 1;

    for (size_t i = 0; i < iteraciones; i++)
    {
        registro = (1 << ((longitud-1) - contador)) | (1 << contador);

        if ((registro & 1) && ((registro >> (longitud-1)) & 1)){
            subiendo = 1;
        } else if ((registro >> ((longitud/2)-1) & 3)){
            subiendo  = 0;
        }

        if (subiendo){
            ++contador;
        } else {
            --contador;
        }

      
    
        char caracterAscii = 0;
        for (size_t i = 0; i < longitud; i++)
        {
            if ((registro >> i) & 1)
            {
                caracterAscii = '0';
            } else {
                caracterAscii = '-';
            }
            
            printf("%c", caracterAscii);
        }
        printf("\n");
           
    }
    

    return 0;
}



