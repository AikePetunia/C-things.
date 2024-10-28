#include <stdio.h>
#include <assert.h>
#define N 5

int sumatoria (int tam, int a[]) {
    int suma = 0;
    int i = 0;
    while (i < N) {
        suma += a[i]; //esta expresion es legal bajo lo que nos enseñaron en la clase?
        i = i + 1;
    }
    printf("la sumatoria de los elementos del arreglo es: %d\n", suma);
}

int main() {
    int a[10];
    int i = 0;
    printf("Introduzca los valores de los elementos \n");
    while (i < N) {
        printf("elemento %d: ", i); //bueno, misma. no puedo con el assert checkear que son numeros los ingresados?
        scanf("%d", &a[i]);
        i = i + 1;
    }

    sumatoria(N, a);
    
    return 0;
}