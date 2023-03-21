#include <Windows.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int lista[100], n = sizeof(lista) / sizeof(int), i = 0;

    srand(time(NULL));
    int valor = rand();

    lista[i] = valor;
    i = (++i) % n;

    printf("Lista: [");
    for (size_t i = 0; i < n; i++) {
        printf("%d,", lista[i]);
    }
    printf("]\n");

    while (!_kbhit) {
    }

    return 0;
}
