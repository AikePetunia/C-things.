#include <stdio.h>

int sumatoria (int tam, int a[]) {
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += a[i];
    }
    printf("la sumatoria de los elementos del arreglo es: %d\n", suma);
}

int main() {
    int tam;
    int a[10];

    printf("Ingrese la cantidad de elementos que tendrá el arreglo: \n");
    scanf("%d", &tam);

    if(tam > 10 || tam <= 0) {
        printf("el tamaño debe ser entre 1 y 10\n");
        return 1;
    }

    printf("Introduzca los valores de los elementos \n");

    for (int k = 0; k < tam; k++) {
        printf("elemento %d: ", k);
        scanf("%d", &a[k]);
    }

    sumatoria(tam, a);
    
    return 0;
}