#include <stdio.h>

int pedir_entero (char name) {
	int x;
	
	printf("Ingrese un valor \n");
	scanf("%c \n", &name);
	printf("Ingrese un numero \n");
	scanf("%d \n", &x);
	return x;
}

void imprimir_entero (int x, char name) {
	printf("Su variable '%c' tiene", name);
	printf(" el numero entero: %d", x);
}

int main () {
	int n;
	
	n = pedir_entero('n');
	imprimir_entero( n, 'n');
	
	return 0;	
}
