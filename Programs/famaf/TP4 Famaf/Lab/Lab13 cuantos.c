#include <stdio.h>  

struct comp_t {
int menores;
int iguales;
int mayores;
};

struct comp_t cuantos(int tam, int a[], int elem) {
    struct comp_t resultado;
    resultado.menores = 0;
    resultado.iguales = 0;
    resultado.mayores = 0;

    // Recorre el arreglo y actualiza el contador
    for (int i = 0; i < tam; i++) {
        if (a[i] < elem) {
            resultado.menores++;
        } else if (a[i] == elem) {
            resultado.iguales++;
        } else {
            resultado.mayores++;
        }
    }
    return resultado;
}

int main(void) {
    int tam;
    int a[10];
    int elem; 

    printf("Ingrese el tamaño del arreglo: ");
    if (scanf("%d", &tam) != 1) {
        printf("Error: el tamaño debe ser un número entero\n");
        return 1;
    }
    if (tam > 10 || tam < 1) {
        printf("El tamaño debe ser un número entre 1 y 10\n");
        return 1;
    }

    printf("ingrese los elementos del arreglo");
    for (int k; k < tam; k++) {
        printf("elemento %d: ", k);
        if (scanf("%d", &a[k]) == 0) {
            printf("Debe ingresar un número en el arreglo\n");
        return 1;
    }

    printf("Ingrese el numero que quiere saber cuantas veces se repite en el arreglo: ");
    if (scanf("%d", &elem) != 1) {
        printf("Error: el elemento debe ser un número entero\n");
        return 1;
    }


    struct comp_t resultado = cuantos(tam, a, elem);

    printf("Menores: %d\n", resultado.menores);
    printf("Iguales: %d\n", resultado.iguales);
    printf("Mayores: %d\n", resultado.mayores);

    return 0;
}
