#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
bool todos_pares(int tam, int a[]) { 
    for (int i = 0; i < tam; i++) {
        if (a[i] % 2 != 0) {
            printf("No todos los elementos del arreglo son pares\n");
            return false;
        }
    }
    printf("Todos los elementos del arreglo son pares\n");
    return true; 
}

bool existe_multiplo(int m, int tam, int a[]) {
    printf("Ingrese el multiplo que desea buscar: ");
    scanf("%d", &m);
    for (int i = 0; i < tam; i++) {
        if (a[i] % m == 0) {
            printf("El multiplo %d existe en el arreglo\n", m);
            return true;
        }
    }
    printf("El multiplo %d no existe en el arreglo\n", m);
    return false;
}

int main(void) {
    int tam;
    int a[10];
    int m;
    printf("ingrese la cantidad de elementos del arreglo:\n ");
    scanf("%d", &tam);
    assert(tam > 0 || tam > 10 && "Error: El tamaño debe ser entre 1 y 10.\n");
    printf("Ingrese un elemento por cada linea\n");
    for(int k = 0; k < tam; k++) {
        printf("elemento %d: ", k); //bueno, misma. no puedo con el assert checkear que son numeros los ingresados?
        scanf("%d", &a[k]);
    }

    existe_multiplo(m, tam, a);
    todos_pares(tam, a);

}
