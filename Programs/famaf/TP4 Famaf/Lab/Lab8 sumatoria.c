#include <stdio.h>
#include <assert.h>

int sumatoria (int tam, int a[]) {
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += a[i]; //esta expresion es legal bajo lo que nos enseñaron en la clase?
    }
    printf("la sumatoria de los elementos del arreglo es: %d\n", suma);
}

int main() {
    int tam;
    int a[10];

    printf("Ingrese la cantidad de elementos que tendrá el arreglo: \n");
    scanf("%d", &tam);
    assert(tam <= 0 && tam > 10 && "\n Error: El tamaño debe ser entre 1 y 10.\n");

    printf("Introduzca los valores de los elementos \n");
    for (int k = 0; k < tam; k++) {
        printf("elemento %d: ", k); //bueno, misma. no puedo con el assert checkear que son numeros los ingresados?
        scanf("%d", &a[k]);
    }

    sumatoria(tam, a);
    
    return 0;
}