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



*/