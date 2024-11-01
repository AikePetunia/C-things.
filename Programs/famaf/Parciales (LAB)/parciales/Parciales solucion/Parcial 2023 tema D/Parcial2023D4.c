#include <stdio.h>
#include <stdbool.h>
#define N 5

struct coordenada {
    float ordenada;
    float abscisa;
    float error;
};

struct coordenadas_superpuestas {
    bool coincide;
    bool contiene;
    bool es_contenida;
};

struct coordenadas_superpuestas verificar_superposicion(struct coordenada original, struct coordenada nueva) {
    struct coordenadas_superpuestas res;
    res.coincide = false;
    res.contiene = false;
    res.es_contenida = false;
    nueva.error = 0.0;

    if(nueva.ordenada == nueva.ordenada && original.abscisa == nueva.abscisa && original.error == nueva.error) {
        res.coincide = true;
    }   else if (original.ordenada == nueva.ordenada && original.abscisa == nueva.abscisa && original.error > nueva.error) {
        res.contiene = true;
    }   else if (original.ordenada == nueva.ordenada && original.abscisa == nueva.abscisa  && original.error < nueva.error) {
        res.es_contenida = true;
    }

    return res;
    
}

int main (void) {
    struct coordenada a[N];
    int i = 0;

    while (i < N) {
        printf("Ingrese la ordenada de la cordenada");
        scanf("%f", &a[i].ordenada);
        printf("Ingrese una abscisa de coordenada");
        scanf("%f", &a[i].abscisa);
        printf("Ingrese el error (?)");
        scnaf("%f", &a[i].error);
        i = i + 1;
    }

    struct coordenadas_superpuestas respuesta = verificar_superposicion(a, a); //falta terminar esto, m tuve q ir
    return 0;
}