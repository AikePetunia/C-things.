#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define N 5

bool todos_pares(int tam, int a[]) { 
    int i = 0;
    while (i < N) {
        if (a[i] % 2 != 0) {
            printf("No todos los elementos del arreglo son pares\n");
            return false;
        }
        i = i + 1;
    }
    printf("Todos los elementos del arreglo son pares\n");
    return true; 
}

bool existe_multiplo(int m, int tam, int a[]) {
    printf("Ingrese el multiplo que desea buscar: ");
    scanf("%d", &m);
    int i = 0;
    while (i < N) {
        if (a[i] % m == 0) {
            printf("El multiplo %d existe en el arreglo\n", m);
            return true;
        }
        i = i + 1;
    }
    printf("Hay multiplos %d no existe en el arreglo\n", m);
    return false;
}

int main(void) {
    int a[10];
    int m;
    int i = 0;
    printf("Ingrese un elemento por cada linea\n");
    while(i < N) {
        printf("elemento %d: ", i);
        scanf("%d", &a[i]);
        i = i + 1 ;
    }
    existe_multiplo(m, N, a);
    todos_pares(N, a);

}
