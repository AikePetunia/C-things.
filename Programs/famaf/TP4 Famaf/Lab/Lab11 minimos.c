#include <stdio.h>
#include <limits.h>

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
    assert(tam > 0 || tam > 10 && "Error: El tamaño debe ser entre 1 y 10.");

    printf("Ingrese un elemento por cada linea\n");
    for(int k = 0; k < tam; k++) {
        printf("elemento %d: ", k);
        scanf("%d", &a[k]);
    }   

    printf("el minimo par del arreglo es: %d\n", minimo_pares(tam, a));
    printf("el minimo impar del arreglo es: %d\n", minimo_impares(tam, a));

}