#include <stdio.h>

void pedir_arreglo(int n_max, int a[]) {
    while (n_max > 10 || n_max <= 0) {
        printf("el tamaño debe ser entre 1 y 10\n");
        printf("Ingrese nuevamente la cantidad de elementos que tendrá el arreglo: \n");
        scanf("%d", &n_max);
    }

    printf("ingrese elementos al arreglo a:  \n");

    for (int k = 0; k < n_max; k++) {
        printf("elemento %d: ", k);
        scanf("%d", &a[k]);
    }
}

void imprimir_arreglo(int n, int a[]) {
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
    scanf("%d", &n_max);

    pedir_arreglo(n_max, a);
    imprimir_arreglo(n_max, a);

    return 0;
}
