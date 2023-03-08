#include <stdio.h>

int main()
{
    long *a, b;
    long c;

    a, b = &c;

    c += *a + *b;

    return 0;
}


// Esto da error por que b no se ha declarado como un puntero a long, si no directamente como un long. El asterisco solo se aplica a 'a'.

