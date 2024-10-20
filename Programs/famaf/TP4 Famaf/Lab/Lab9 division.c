#include <stdio.h>

struct div_t {
    int cociente;
    int resto;
};

struct div_t division(int x, int y) {
    struct div_t resultado;  
    resultado.cociente = x / y; 
    resultado.resto = x % y;     
    return resultado;        //el resultado actua como una variable extra para poder asignas valor a un valor del struct)?
}

int main(void) {
    int x, y;

    printf("ingrese el dividendo: ");
    scanf("%d", &x);
    if (x < 0) {
        printf("el dividendo debe ser positivo\n");
        return 1;
    }

    printf("ingrese el divisor: ");
    scanf("%d", &y);
    if (y <= 0) {
        printf("el divisor debe ser positivo\n");
        return 1;
    }

    struct div_t resultado = division(x, y);
    printf("Cociente: %d\n", resultado.cociente);
    printf("Resto: %d\n", resultado.resto);
    printf("Quedando el algoritmo de division como: %d = %d * %d + %d\n", x, y, resultado.cociente, resultado.resto);

    return 0;
}

// El algoritmo de divison es:
// a = b * q + r
// donde a es el dividendo, b es el divisor, q es el cociente y r es el resto.