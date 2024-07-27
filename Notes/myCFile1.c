#include <stdio.h>
#include <stdbool.h>

int main() {

            // Así se comenta en una línea
            /*
            Múltiples
            comentarios
            */

            /*
            \n = nueva línea en un print u otros
            \t = espacios tipo tab en los textos
            */
            printf("ESTO ES UN GRID DE NUMEROS \n");
            printf("1\t2\t3\n4\t5\t6\n7\t8\t9\n");
            printf("ESTO ES UN GRID DE NUMEROS\n");

            /*
            Para imprimir comillas, se debe usar la barra invertida (\)
            */
            printf("yo comi una \"hamburguesa\" ayer\n");

            // Variables

            int number1; // Declaración
            number1 = 5; // Inicialización

            // Alternativamente

            // Números 
            int number = 5;                        // 4 Bytes (-2b to 2b+)                                  %d
            unsigned int number8 = 4294967295;     // 4 bytes (0 to 4b) %u
            long long int number9 = 3123333333;    // 8 bytes (-9q to 9q) %lld
            unsigned long long int number10 = 414; // 8 bytes (0 to 18q) %llu
            short int number5 = 32767;             // 2 bytes (-32,768 a +32,767)                             %d
            unsigned short int number6 = 65535;    // 2 bytes (0 a +65,535)                                   %d
            short number7 = 32767;                 // 2 bytes (-32,768 a +32,767) (no necesario declarar int) %d
            unsigned short number123 = 65535;        // 2 bytes (0 a +65,535) (no es necesario declarar int)    %d

            float number4 = 2.3123123514512;       // Decimal, 4 bytes (32 bits de precisión) 6-7 dígitos     %f
            float number2 = 2.04;                  // Decimal, 4 bytes (32 bits de precisión) 6-7 dígitos     %f
            double number3 = 2.3123123514512;      // Decimal, 8 bytes (64 bits de precisión) 15-16 dígitos   %lf

            printf("%0.15f FLOAT NORMAL CON MUCHOS NUMEROS, se pierde precisión con muchos dígitos\n", number4);
            printf("%0.15lf LONG FLOAT CON capacidad de manejar más dígitos\n", number3);
            printf("%f float normal\n", number2);

            // Booleans
            // Se necesita declarar al inicio (antes de usarse) #include <stdbool.h>

            bool t = true;   // 1 Byte, trabajan en binario 1 = True, 0 = False    %d
            bool f = false;  // 1 Byte, trabajan en binario 1 = True, 0 = False    %d    
            printf("%d, %d,\n1 = True, 0 = False\n\n", t, f); 

            // Caracteres o strings

            char grades = 'F';             // Char, un caracter                                              %c
            char name[] = "Aike";          // Strings o lista de caracteres                                  %s
            char numerito1 = 100;          // 1 byte (-128 a +127)                                           %d o %c
            signed char numerito2 = 100;   // 1 byte (-128 a +127) (realmente innecesario, ya están todos signed)
            unsigned char numerito3 = 255; // 1 byte (0 a +255)                                              %d o %c

            printf("Char con números según el ASCII, si uso \"%c\" se usa un caracter según ASCII, y \"%d\" será un número\n\n");
            printf("Esto es un caracter \n%c\nArte ASCII según tabla\n%d\nNúmero normal\n\n", numerito1, numerito1);

            printf("Tengo %d años, me llamo %s, la nota que tengo es %c, y sin redondeo es %.2f\n\n\n\n\n", number, name, grades, number2); 
            
            /* El %d es para enteros
            (se especifica el tipo, y después las variables que van en el print serán en orden)
            No hay espacios para unir los strings con +
            Para los strings, no es necesario poner el [], pero sí el %s de String
            */

            /* Otros format specifier (%)
            %.1 = Decimal pecision              <- Cantidad de decimales que apareceran de un float
            %1 = minimum field width            <- espacio en blaco despues de algo )? $    1.00
            %- = Left align                     <-
            */

            // constantes <- variable no alterable

            const float pi = 3.14159;

            //ARITMETICA

            /*
            + Adicion
            - Resta
            * Multiplicacion
            % Modulo
            / Division
            ++ Incremento
            -- Decrement 
            */

            int sum = 5; 
            sum++;
            int min = 2;
            min++;
            int operation = 5 - 2; 
            int division = 5 / (float) 2;   //Se puede hacer asi. No se guarda el resto ni habra display de un decimal si no es FLOAT, es con modulo
            float  division1 = 5 / 2;       //Se puede hacer asi

            printf("%d\n", operation);

            // el "atajo artimentico" funca con todos los operadores
            
            int x = x + 1;
            //insteed 
            x+=1;

            int z = z + 2;
            //insteed 
            z-=2;

            return 0;




}
