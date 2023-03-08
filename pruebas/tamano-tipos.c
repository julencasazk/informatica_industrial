#include <stdio.h>
#include <conio.h>

int main()
{

    printf("Entero: %d\n", sizeof(int)); //4
    printf("Caracter: %d\n", sizeof(char)); //1
    printf("Short: %d\n", sizeof(short)); //2
    printf("long: %d\n", sizeof(long)); //4
    printf("Long long: %d\n", sizeof(long long)); //8
    printf("Float: %d\n", sizeof(float)); //4
    printf("Double: %d\n", sizeof(double)); //8
    printf("Puntero: %d\n", sizeof(void*)); //4??

    while (!_kbhit())
    {
        /* code */
    }
    

    return 0; 
}
