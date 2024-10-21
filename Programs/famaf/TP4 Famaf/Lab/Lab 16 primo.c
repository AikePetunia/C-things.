#include <stdio.h>
#include <stdbool.h>

bool es_primo(int n) {
    if (n <= 1) return false;
    if (n == 2) return true; 
    if (n % 2 == 0) return false; 
    for (int i = 3; i * i <= n; i += 2) {  
        if (n % i == 0) return false;
    }
    return true;
}

int nesimo_primo(int N) {
    int contador = 0;
    int numero = 1;

    while (contador < N) {
        numero++;
        if (es_primo(numero)) {
            contador++;
        }
    }
    return numero;
}

int main(void) {
    int N;
    int control = 0;
    
    do {
        printf("Ingrese un numero entero positivo: ");
        
        if (scanf("%d", &N) != 1) {  
            printf("Debe ingresar un numero entero.\n");
            control = 0;
            while (getchar() != '\n'); // Limpiar el buffer de entrada
        } else if (N <= 0) { 
            printf("Debe ingresar un numero entero positivo.\n");
            control = 0;
        } else {
            control = 1;  
        }

    } while (control == 0);

    int primo = nesimo_primo(N);
    printf("El %d-ésimo número primo es: %d\n", N, primo);

    return 0;
}
