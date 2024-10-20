#include <stdio.h>
#include <stdbool.h>

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
    if (tam > 10) {
        printf("el tamaño debe ser menor o igual a 10\n");
        return 1;
    }  
    printf("Ingrese un elemento por cada linea\n");
    for(int k = 0; k < tam; k++) {
        printf("elemento %d: ", k);
        scanf("%d", &a[k]);
    }

    existe_multiplo(m, tam, a);
    todos_pares(tam, a);

}
