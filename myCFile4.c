#include <stdio.h>
#include <string.h>

int main () {
    // ARRAYS
    // Un array puede almacenar varios valores del mismo tipo.

    double prices[] = {5.0, 3.1, 10.23, 20.0};

    printf("%lf\n", prices[0]);  // Las posiciones de los arrays empiezan en 0. Uso de [] para seleccionar un item.
    
    double prices1[5];  // Se puede definir un array sin inicializar valores, indicando el tamaño.
    
    prices1[2] = 3.2;
    prices1[4] = 1.2;  // Corrección del índice. Los índices van de 0 a 4 en este caso.
    prices1[1] = 3.4;

    // Cómo hacer printf de todos los items de un array.

    int precios[] = {2, 3, 45, 14, 4, 25, 66, 31, 45, 24, 4};

    // Corrección del bucle: el índice debe empezar en 0 y usar < en lugar de <=.
    for (int i = 0; i < sizeof(precios)/sizeof(precios[0]); i++) {
        printf("$%d\n", precios[i]);
    }

    // ARRAYS 2D: cada elemento es un array, útil para tablas o matrices.
    
    int numbers2[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // El 3 (columnas) es la cantidad de elementos de cada array, el 2 (filas) es la cantidad de arrays.
    
    int number3[2][3];
    int rows = sizeof(number3)/sizeof(number3[0]);      // Número de filas.
    int columns = sizeof(number3[0])/sizeof(number3[0][0]);  // Número de columnas.

    number3[0][0] = 1;   // Primera fila, primera columna.
    number3[0][1] = 2;   // Primera fila, segunda columna.
    number3[0][2] = 3;   // Primera fila, tercera columna.
    number3[1][0] = 4;   // Segunda fila, primera columna.
    number3[1][1] = 5;   // Segunda fila, segunda columna.
    number3[1][2] = 4;   // Segunda fila, tercera columna.

    // Imprimir los elementos del array 2D.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", number3[i][j]);
        }
        printf("\n");
    }

    // lista de strings

    char cars[][10] = {"Mustang", "corvette", "Camaro"};        //los segundos [], son la cantidad de caracteres
   // char cars[0] = "Tesla";         // no puedo a no ser... que importe #include <string.h>

    strcpy(cars[0], "tesla");

    for (int i = 0; i < sizeof(cars)/sizeof(cars[0]); i++)      //3 dividido en 1
    {
        printf("%s\n", cars[i]);
    }

    //cambio de variable

    char x[15] = "limon";
    char y[15] = "lima";
    char temp[15];

    strcpy(temp, x);                    //LO PASO DE TEMP a X
    strcpy(x, y);                    //LO PASO DE X a Y     necesario de [15] para que x no quede vacio
    strcpy (y, temp);                    //LO PASO DE Y a TEMP

    //es como la propiedad de transitividad de cualq cosa de Matematica discreta



    return 0;
}
