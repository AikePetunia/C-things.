#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

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

int minimo_pares(int tam, int a[]) {
    int min_value = INT_MAX;
    for (int i = 0; i < tam; ++i) {
       if (a[i] % 2 == 0 && a[i] < min_value) {
           min_value = a[i];
       }
    }
    return min_value;

}   //devuelve el elemento par mas chico del arreglo

int minimo_impares(int tam, int a[]) {
    int min_value = INT_MAX;
    for (int i = 0; i < tam; ++i) {
       if (a[i] % 2 != 0 && a[i] < min_value) {
           min_value = a[i];
       }
    }
    return min_value;
}   //devuelve el elemento impar mas chico del arreglo

int main(void) {
    int tam; 
    int a[10];
    
    printf("Ingrese la cantidad de elementos que tendrá el arreglo: \n");
    scanf("%d", &tam);
    if (tam > 10 ) {
        printf("el tamaño debe ser menor o igual a 10\n");
        return 1;
    }

    printf("Ingrese un elemento por cada linea\n");
    for(int k = 0; k < tam; k++) {
        printf("elemento %d: ", k);
        scanf("%d", &a[k]);
    }   

    if (todos_pares(tam, a)) {
        printf("El mínimo par del arreglo es: %d\n", minimo_pares(tam, a));
    } else {
        printf("No hay elementos pares en el arreglo\n");
    }
    
    if (!todos_pares(tam, a)) {
        printf("El mínimo impar del arreglo es: %d\n", minimo_impares(tam, a));
    } else {
        printf("No hay elementos impares en el arreglo\n");
    }


}