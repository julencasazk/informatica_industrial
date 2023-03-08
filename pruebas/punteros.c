#include <stdio.h>

int main()
{

    int a, *b; // a es una variable de tipo int, y b es un puntero a entero. Por defecto b tiene "basura".
    printf("\nVariable b: %x\n", b);
    printf("Dirección de a: %x\nValor de a: %d\n\n", &a, a);
    a = 17;
    b = &a;
    printf("\nVariable b: %x\n", b);
    printf("Dirección de a: %x\nValor de a: %d\n\n", &a, a);
    return 0;
}
