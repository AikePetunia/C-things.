#include <stdio.h>
#include <float.h>

struct datos_t {
    float min;
    float max;
    double promedio;
};

struct datos_t stats(int tam, float a[]) {
    struct datos_t resultado;
    resultado.min = FLT_MAX;
    resultado.max = FLT_MIN;
    float sum = 0.0;
    
    for (int i = 0; i < tam; ++i) {
       if (a[i] < resultado.min) {
           resultado.min = a[i];
       }
        if (a[i] > resultado.max) {
             resultado.max = a[i];
        }
       sum += a[i];
    }

    resultado.promedio = sum / tam;
    return resultado;

}

int main (void) {
    int tam;
    float a[10];
    
    printf("Ingrese el tamaño del arreglo: \n");
    
    if(scanf("%d", &tam) != 1) {
        printf("Debe ingresarse un numero");
        return 1;
    }

    if (tam > 10 || tam < 1) {
        printf("Debe ingresar un tamaño no mayor a 10 y mayor a 1");
        return 1;
    }

    printf("Ingrese los numeros del arreglo: \n");
    for (int k = 0; k < tam ; k++) {
        printf("Elemento %d: ", k);
        if(scanf("%f", &a[k])!= 1) {
            printf("Debe ingresar un numero");
            return 1;
        }
    }

    struct datos_t resultado = stats(tam, a);
    printf("El valor minimo es: %f\n", resultado.min);
    printf("El valor maximo es: %f\n", resultado.max);
    printf("El promedio es: %f\n", resultado.promedio);
    return 0;
}
