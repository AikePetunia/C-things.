/*

-1)

a) Var x : Int;
    σ0 : (x →1)
x := 5
    σ1 : 5

b)Var x,y : Int;
    σ0 : (x →2,y →5)
x := x + y;
    σ1 : 7
y := y + y
    σ2 : 14

c)
Var x,y : Int;
    σ0 : (x →2,y →5)
y := y + y;
    σ1 : 10
x := x + y
    σ2 : 12


d)

Var x,y : Int;
    σ0 : (x 7→2,y 7→5)
y,x := y + y,x + y
    σ1 : 17


-2)

a) El orden de ejecucion. En el caso de la a) se ejecuta primero la asignacion de x = 5 y luego se imprime el valor de x.
Las variables. 

b) el d lo hace. 


-3)

a) 
x= 3, y = 1
si x>= y entonces x = 0. <- EL UNICO que se cumple.

si x <= y entonces x = 2.

si x = y entonces se romperia? 

b) 
x = 100, y = 1 

si x>= y entonces x = 0. <- EL UNICO que se cumple. 

si x <= y entonces x = 2. 

c)

x = 1, y = 1

si x>= y entonces x = 0.<- se cumple.
si x<= y entonces x = 2. <- se cumple.

-4) que seyo, se rompe todo.

-5)

a)
i = 4
  i /= 0
    i = 4, i = 4 - 1 = 3, 
    i = 3 - 1 = 2,
    i = 2 - 1 = 1, 
    i = 1 - 1 = 0

b)
i = 400
    i = 0
i = 0

c)
i = 4
    4 < 0, i = 4 - 1 = 3, 
    3 < 0,  3- 1 = 2,
    2 < 0,  2 - 1 = 1, 
    1 < 0,  1 - 1 = 0

    i = 0

d)

i = 0 

i = 0


e)

r = 3 

     r < 0 
        skip 
    r > 0 
        r = 3 - 1   = 2
    r > 0 
        r = 2 - 1 = 1 
    r > 0 
        r = 1 - 1 = 0 
    // al ser 0, se rompe 

r = 0 

6)

No, no existe un predicado que pueda hacer que `i < 0`, `i = 0` y `i > 0` al mismo tiempo. Estos son estados mutuamente excluyentes para la variable [`i`](command:_github.copilot.openSymbolFromReferences?%5B%22%22%2C%5B%7B%22uri%22%3A%7B%22scheme%22%3A%22file%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2Fhome%2Fusuario%2FDevelopment%2FCe-cosas.--main%2FPrograms%2Ffamaf%2FTP3%20Famaf%2FPractico%2Fpractico.c%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%2C%22pos%22%3A%7B%22line%22%3A79%2C%22character%22%3A4%7D%7D%5D%2C%22bba19c6c-1d34-4ee0-b4d2-3ad6a107d539%22%5D "Go to definition"). En cualquier momento dado, [`i`](command:_github.copilot.openSymbolFromReferences?%5B%22%22%2C%5B%7B%22uri%22%3A%7B%22scheme%22%3A%22file%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2Fhome%2Fusuario%2FDevelopment%2FCe-cosas.--main%2FPrograms%2Ffamaf%2FTP3%20Famaf%2FPractico%2Fpractico.c%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%2C%22pos%22%3A%7B%22line%22%3A79%2C%22character%22%3A4%7D%7D%5D%2C%22bba19c6c-1d34-4ee0-b4d2-3ad6a107d539%22%5D "Go to definition") solo puede satisfacer una de estas condiciones:

7)

a)
    var i: Int; 
    O0 : (i →1) 
    do i >= 0
        [          ]
        if i = 0 
            [          ]
                i = 1 
        fi 
        if i = 1 
            [          ]
                i = 1 
        fi 
        if i > 1  
            [          ]
                i * i - 1  
        fi
    od

b) ? 

    var i: Int; 
    O0 : (i →1) 
    do i >= 0
        if i > 1  
            [          ]
                i * i - 1  
        fi
        [          ]
        if i = 0 
            [          ]
                i = 1 
        fi 
        if i = 1 
            [          ]
                i = 1 
        fi 
        
    od

c)  i = 5

    O0 : (i →5) 
    do i >= 0                   --1
        if i > 1                     --2 
            [          ]
                i * i - 1  
        fi
        [          ]    
        if i = 0                      --3
            [          ]
                i = 1 
        fi 
        if i = 1                    --4
            [          ]
                i = 1 
        fi 
        
    od

    i = 5
={Asignacion}
    5 >= 0 
={Entra en bucle de do guarda 1}
    5 * 4 
={Aritmetica de 5 * 4 y caso 2}
    20 + 4 * 3 
={Arimetica de 4 * 3 y caso 2}
    20 + 12  + 3 * 2 
={Arimetica de 3* 2 y caso 2}
    32 + 6 + 2 * 1
={Arimetica de 2 * 1 y caso 2}
    38 + 2
={Arimetica de 1 y caso 4}
    40


Alt (me lo robe de los chikis)

a) 
Var N : Int
(N >= 0) que calcule N!

Var n, res : Int;
n, res ≔ N, 1;
do n>1 →
     res, n ≔ res * n; n -1
od 
7b)
const N : Int;
Var n, res : Int;
n, res ≔ 1, 1;
do n<N →
     res ≔ res * n * (n+1);
     n ≔ n+2;
od

7c) -> N=5
Var N : Int
i- (N >= 0) que calcule N!

Var n, res : Int;
n, res ≔ N, 1;
n, res ≔ 5, 1;
do n>1 →
res, n ≔ res * n; (n - 1)
res, n ≔ 1 * 5; (5 - 1)
	res, n ≔ (1 * 5) * (4 * 1); (4-1)

	res, n ≔ (1 * 5) * (4 * 1) * (3 * 1);(3 - 1)

	res, n ≔ (1 * 5) * (4 * 1) * (3 * 1) * (2 * 1); (2-1)





ii- 
const N : Int;
Var n, res : Int;
n, res ≔ 1, 1;
do n<= N →
     res ≔ res * n;
     n ≔ n+1;
od
N = 5;
primera iteración:
do 1 <= 5 →
     res ≔ 1 * 1;
     n ≔ 1+1;
od
resultado: res = 1; n = 2
segunda iteración:
do 2 <= 5 →
     res ≔ 1 * 2;
     n ≔ 2+1;
od
resultado: res = 2; n = 3
tercera iteración:
do 3 <= 5 →
     res ≔ 2 * 3;
     n ≔ 3+1;
od
resultado: res = 6; n = 4
cuarta iteración:
do 4 <= 5 →
     res ≔ 6 * 4;
     n ≔ 4+1;
od
resultado: res = 24; n = 5
quinta iteración:
do 5 <= 5 →
     res ≔ 24 * 5;
     n ≔ 5+1;
od
resultado: res = 120; n = 6
estado final: res = 120


--8, 9, 10, 11)

PASS, NO ENTENDI.

https://chatgpt.com/share/66fd5eb5-e2a0-8009-8057-5681a0ce3637

--12) Ternas de Hoare y Weakest precondition.

https://r9.whiteboardfox.com/93872386-7680-8941

--13)

a)
si se refiere a el x := x * x si, por que se esta multiplicando el valor de x por si mismo para dar positivo.

b)

1)

        wp.S.Q
    ={ Definicion de wp por asignacion }
        wp.(x := x * x).(True)
    ={Def. de true}
        True.

El true es mas debil. Ya que solo requiere que la condicion sea verdadera, y nada mas.
2)

    wp.S.Q
={ Definicion de wp por asignacion }
    wp.(x := x * x).(x >= 0)
={ Aplico la asginacion}
    (x * x) >= 0
={ Aritmetica}
    x >= 0 

la Q es la mas fuerte, ya que pide que sea mayor o igual que 0 (o sea, toma numeros del 0 al inf)

3)

    wp.S.Q
={ Definicion de wp por asignacion }
    wp.(x := x * x ).(x > 0 ^ x < 100) 
={Asignacion}
    (x * x) > 0 ^ (x * x) < 100
={Aritmetica}
    |x| > 0 ^ |x| < 10 
={Funca}

La wp es la p, ya que pide que sea mayor a 0 y menor a 100 (restrigue solo un rango), en cambio el otro pide del 0, al inf, intervalo abierto.

c) con una restriccion menos "existente o molesta"

d)

Ejemplo 4 (práctico 5, ejercicio 4a): 

{ x > 0 }   x := x * x   { True }

¿Vale? Sí vale, ya que siempre terminamos en un estado final que satisface True.

Ejemplo 7: Cálculo del máximo mal especificado:
     Var  r, x, y : Int;
     { P: True }
     S
     { Q: r = x max y }

¿Cuál es el programa más simple que podemos dar que satisface esta especificación?

¿Vale la siguiente terna?:
     Var  r, x, y : Int;
     { True }
     r, x, y := 0, 0, 0
     { r = x max y }
¡Vale!

¿Es correcta esta especificación para el cálculo del máximo entre x e y? No, porque admite programas que no reflejan el problema que yo quiero solucionar.

La especificación funciona como contrato entre la persona que quiere resolver el problema y la persona que lo va a solucionar. 

Especificación correcta para max:
     Var  r, x, y : Int;
     { x = A ∧ y = B }
     S
     { r = A max B }
(usando variables de especificación A y B)


--14)

    wp.S.Q
={ Definicion de wp por asignacion }
    wp.(x := x * x ).(x > 0 ^ x < 100) 
={Asignacion}
    (x * x) > 0 ^ (x * x) < 100
={Aritmetica}
    |x| > 0 ^ |x| < 10 
={Funca}

    wp.S.Q
={ Definicion de wp por asignacion }
    wp.(x := x + y).(x = 6 ^ y = 5)
={Asignacion}
    x + y = 6 ^ y x + y = 5

b)
    
        wp.S.Q
    ={Definicion de wp por asignacion}
        wp.(x:=8).(x = 8)
    ={Asignacion}
        8 = 8
    ={logica}
        True

c)

        wp.S.Q
    ={Definicion de wp por asignacion}
        wp.(x:=8).(x = 7)
    ={Asignacion}
        8 = 7
    ={Logica}+
        False 

d)
    
            wp.S.Q
        ={Definicion de wp por asignacion}
            wp.(x, y = y, x).(x = B ^ y = A)
        ={Asignacion}
            x, y = B, ^ y, x = A
        ={Logica}
            

Es de este estilo:

Ejemplo 1: “Swap” (intercambio de valores):

      { x = A  ∧  y = B } 
        x, y := y , x 
      { x = B ∧ y = A }

(A y B son variables de especificación)

¿Vale esta terna?
Si empezamos en un estado que satisface P, ¿al ejecutar S terminamos en un estado que satisface Q? ¡Si! Siempre.

e)

        wp.S.Q
    ={Definicion de wp por asignacion}
        wp.(a,x := x, y).(x = B ^ y = A)
    ={Asignacion}
        x, y
    ={Logica}
        False

f)

        wp.S.Q
    ={Definicion de wp por asignacion}
        wp.(x >= y v x <= y).((x = 0 v x = 2) ^ y = 1)
    ={Distributividad de v con ^}
        wp.(x >= y v x <= y).((x = 0 ^ y = 1 )v (x = 2 ^ y = 1))
    ={Hago dos casos, uno para x >= y (1), otro para x <= y (2)}
        
    (1)
        wp.(x := 0).((0 = 0 ^ y = 1 )v (0 = 2 ^ y = 1))
    ={Asignacion}
        (true ^ 1 = 1 )v (False ^ 1 = 1)
    ={Logica}
        true v false
    ={logica}
        True 
    
    (2)
        wp.(x := 2).((x = 0 ^ y = 1 )v (x = 2 ^ y = 1))
    ={Asignacion}
        ((2 = 0 ^ y = 1 )v (2 = 2 ^ y = 1))
    ={Logica}
        (False ^ 1 = 1 )v (True ^ 1 = 1)
    ={Logica}
        False v True
    ={Logica}
        True


--15)

a)

    Es true, pues la precondicion dice que es verdadero, pero la post condicion no se cumpliria para x =  1 si toma x - 1

b)
    Es true, pues por swap se cumplira la primera guarda si es q no se cumplio

c)

    si el s nos condicion a q sera valido. notemos que duplica el valor de x, teniendo que ser siempre mayor a un negativo.
    ademas, se asegura que el mas grande sea restado por el mas pequeño, manteineod siempre una resta de un positivo por un negativo, cumpliendo.
    pero, tienen que cumoplirse ambos al mism otiempo

d)

    Es por tabla de la verdad de v. 
    El unico que no se cumpliria seria para no b y no a.

e) 

    Es un cconteno desde el 0 hasta que alcance el valro de n. sera true cuando se alcance x = n

f)

    no funciona, pues n no aparece en la postcondicion.


--16)

a)

    si valida, es una sumatira de elementos hasta llegar al elemento N de la lista A
    
*/