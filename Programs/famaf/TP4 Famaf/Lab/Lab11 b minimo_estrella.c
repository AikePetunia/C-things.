#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

bool existe_multiplo(int m, int tam, int a[]) {     //devuelve bool
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

bool todos_pares(int tam, int a[]) {    //devuelve bool
    for (int i = 0; i < tam; i++) {
        if (a[i] % 2 != 0) {
            return false;
        } //hay impares
    }
    return true; //todos son pares
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
    int m;
    printf("Este programa no admite decimales. \n");
    printf("Ingrese la cantidad de elementos que tendrá el arreglo: \n");
    scanf("%d", &tam);
    assert(tam > 0 || tam > 10 && "Error: El tamaño debe ser entre 1 y 10.");

    printf("Ingrese un elemento por cada linea\n");
    for(int k = 0; k < tam; k++) {
        printf("elemento %d: ", k); //bueno, misma. no puedo con el assert checkear que son numeros los ingresados?
        scanf("%d", &a[k]);
    }   

    if (todos_pares(tam, a) == false) {
        printf("No todos los elementos del arreglo son pares\n");
        printf("El minimo impar es: %d\n", minimo_impares(tam, a));
        printf("El minimo par es: %d\n", minimo_pares(tam, a));
    } else {
        printf("Todos los elementos del arreglo son pares\n");
        printf("El minimo par es: %d\n", minimo_pares(tam, a));
    }

    existe_multiplo(m, tam, a);


}