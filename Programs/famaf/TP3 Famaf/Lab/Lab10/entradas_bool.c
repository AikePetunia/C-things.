#include <stdio.h>
#include <stdbool.h>

bool pedir_booleano(char name) {
    bool x;
    printf("ingrese un caracter para la caribale");
    scanf(" %c", &name);
    printf("Ingrese un valor para la variable %c (1 para verdadero, 0 para falso): ", name);
    scanf("%d", &x);  

    if (x != 0 && x != 1) {
        printf("El valor ingresado no es valido. Por favor ingrese 1 o 0\n");
        scanf("%d", &x);
    }

    return x;
}

void imprimir_booleano(bool x, char name) {
    printf("La variable %c tiene el valor ", name);
    if (x == 0) {
        printf("falso\n");
    } else {
        printf("verdadero\n");
    }
}

int main() {
    bool x;
    char name = 'n';  
    x = pedir_booleano(name);
    imprimir_booleano(x, name);
    return 0;
}


//da un segmentaion fault raro?