#include <stdio.h>

void intercambiar(int tam, int a[], int i, int j) { //Las funciones void no retornan nada
    // tam es el tamaño maximo del arreglo.
    // las dos posiciones que es j e i, cuales se intercambiaran.
    // a es el arreglo.
    if (i < tam && j < tam && i >= 0 && j >= 0) {
        int aux = a[i];
        a[i] = a[j];
        a[j] = aux;
    }
    else {
        printf("i o j deben ser mayores a 0\n");
    }

}

int main (void) {
    int a[10]; //no puedo dejar [] ? Por que? 10 elementos? no puede ser arbitrario?
    int i, j, tam;

    printf("Ingrese la cantidad de elementos que tendrá el arreglo: \n");
    scanf("%d", &tam);

    if (tam > 10 || tam <= 0) {
        printf("Error: El tamaño debe ser entre 1 y 10.\n");
        return 1;  // sale del coso
    }

    printf("Ingrese elementos al arreglo a:  \n");

    for (int k = 0; k < tam; k++) {
        printf("Elemento %d: ", k);
        scanf("%d", &a[k]);     //este trozo de codigo me lo dio chat gpt pq ni idea como seria, pero otra manera no lo se.
    }
    printf("Ingrese la posicion i para ver \n");
    scanf("%d", &i);
    printf("Ingrese la posicion j para ver \n");
    scanf("%d", &j);

    intercambiar(tam, a, i, j); // Pasa los elementos a la funcion intercambiar

    printf("Arreglo después del intercambio: \n");
    for (int k = 0; k < tam; k++) {
        printf("%d ", a[k]);
    }
    printf("\n");
    return 0;
}
