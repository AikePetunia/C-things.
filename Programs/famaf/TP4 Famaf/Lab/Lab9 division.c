#include <stdio.h>
#include <assert.h>
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
/*
El struct div_t que has creado en tu código es una estructura que sirve para agrupar dos valores enteros: el cociente y el resto de una división. 
Esta estructura te permite devolver ambos valores juntos desde la función division. 
En C, una función solo puede devolver un valor, y al usar un struct, puedes "empaquetar" múltiples valores y devolverlos como un solo objeto.
*/

int main(void) {
    int x, y;

    printf("ingrese el dividendo: ");
    scanf("%d", &x);
    assert(x > 0 && "El dividendo debe ser positivo\n");

    printf("ingrese el divisor: ");
    scanf("%d", &y);
    assert(y > 0 && "El divisor debe ser positivo\n");

    struct div_t resultado = division(x, y); //defino una variable nueva que es resultado del tipo struct div_t que actua como:
    /*
    struct div_t resultado; //Crear la variable 
    resultado.cociente = x / y; // Asignación a resultado
    resultado.resto = x % y;    // Asignación a resultado
    return resultado;   //Devolución de resultado
    */
    printf("Cociente: %d\n", resultado.cociente);
    printf("Resto: %d\n", resultado.resto);
    printf("Quedando el algoritmo de division como: %d = %d * %d + %d\n", x, y, resultado.cociente, resultado.resto);

    return 0;
}

// El algoritmo de divison es:
// a = b * q + r
// donde a es el dividendo, b es el divisor, q es el cociente y r es el resto.

//deberia de poner floats?