#include <stdio.h>
#include <stdbool.h>

int main() {
    int x = 5;
    bool res = true;  // Inicializamos como true, asumiendo que x es primo
    int i = 2; 

    while (i < x && res == true) {
        if (x % i == 0) {
            res = false;  // Si x es divisible por i, no es primo
        }
        i = i + 1;
    }
    
    printf("El resultado de la division entera es i = %d\nx = %d\n res = %d\n", i, x, res);
    return 0;
}

//por que no anda? no se.
