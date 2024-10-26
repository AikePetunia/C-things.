#include <stdio.h>
#include <assert.h>
void pedir_arreglo(int n_max, int a[]) {    //no debe retornar nada, ni true ni false.
    assert(n_max >= 0 && n_max <= 10 && "\n Error: El tamaño debe ser entre 1 y 10.\n");

    printf("ingrese elementos al arreglo a:  \n");

    for (int k = 0; k < n_max; k++) {
        printf("Elemento %d: ", k);
        
        if (scanf("%d", &a[k]) != 1) {
            printf("Error: Debe ingresar un número.\n");
            break;
        }
    }
}

void imprimir_arreglo(int n, int a[]) {     //no debe retornar nada, ni true ni false.
    for (int i = 0; i < n; i++) { 
        if (i == n) { 
            printf("%d ", a[i]); 
        } else {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

int main(void) {
    int n_max;
    int a[10];

    printf("Ingrese la cantidad de elementos que tendrá el arreglo: \n");
    if (scanf("%d", &n_max) != 1) {
            printf("Error: Debe ingresar un número.\n");
    } else {
        pedir_arreglo(n_max, a);
        imprimir_arreglo(n_max, a);
    }
    return 0;
}

//Como hago que assert pueda ver si se ingresaron numeros, y no, caracteres?
//Como hago para que aca, si se printea un a, haga un break? (Mas en la parte de imprimir arreglo, pq me lo printea igual)