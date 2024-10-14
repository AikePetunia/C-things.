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
    σ0 : (x →2,y →5)
y,x := y + y,x + y
    σ1 : 10, 7

//Chekiado

-2)

a) El orden de ejecucion. En el caso de la a) se ejecuta primero la asignacion de x = 5 y luego se imprime el valor de x.
Las variables, son asignadas de manera diferente.

b) el d lo hace. 

-3)

a) 
x = 3, y = 1

    si x >= y entonces x = 0. <- EL UNICO que se cumple.

    si x <= y entonces x = 2.  **NO SE CUMPLE**

    si x = y entonces toma el primero valor

b) 
x = 100, y = 1 

    si x>= y entonces x = 0. <- EL UNICO que se cumple. 

    si x <= y entonces x = 2. **NO SE CUMPLE**

    si x = y entonces toma el primero valor **NO SE CUMPLE**
c)

x = 1, y = 1

si x>= y entonces x = 0.

si x<= y entonces x = 2. 

si x = y entonces toma el primero valor, o sea x := 0. <- se cumple.

-4) queseyo, se rompe todo.
Segun c, da el ultimo valor. No da un error del tipo "no exhaustive patterns"

-5)

a)
i = 4
  i /= 0
    i = 4 - 1 = 3, 
    i == 3 - 1 = 2,
    i == 2 - 1 = 1, 
    i == 1 - 1 = 0

b)
i = 400
    i == 0
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

    i == 0 -1 = -1

i = 0

e)

r == 3 

    r < 0 
        skip <- No toma la guarda
    r > 0 
        r = 3 -1 = 2 
    r > 0 
        r = 2 - 1 = 1 
    r > 0 
        r = 1 - 1 = 0 
    // al ser 0, se rompe ??? 

r = 0 

6)

No, no existe un predicado que pueda hacer que `i < 0`, `i = 0` y `i > 0` al mismo tiempo. Estos son estados mutuamente excluyentes para la variable [`i`](command:_github.copilot.openSymbolFromReferences?%5B%22%22%2C%5B%7B%22uri%22%3A%7B%22scheme%22%3A%22file%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2Fhome%2Fusuario%2FDevelopment%2FCe-cosas.--main%2FPrograms%2Ffamaf%2FTP3%20Famaf%2FPractico%2Fpractico.c%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%2C%22pos%22%3A%7B%22line%22%3A79%2C%22character%22%3A4%7D%7D%5D%2C%22bba19c6c-1d34-4ee0-b4d2-3ad6a107d539%22%5D "Go to definition"). En cualquier momento dado, [`i`](command:_github.copilot.openSymbolFromReferences?%5B%22%22%2C%5B%7B%22uri%22%3A%7B%22scheme%22%3A%22file%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2Fhome%2Fusuario%2FDevelopment%2FCe-cosas.--main%2FPrograms%2Ffamaf%2FTP3%20Famaf%2FPractico%2Fpractico.c%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%2C%22pos%22%3A%7B%22line%22%3A79%2C%22character%22%3A4%7D%7D%5D%2C%22bba19c6c-1d34-4ee0-b4d2-3ad6a107d539%22%5D "Go to definition") solo puede satisfacer una de estas condiciones:

7)

a)
    Var I, res : Int;
    do i >= 0
        if
            i := 0;
            [          ]
        fi 
        if i = 1 
            [          ]
            i = 1;
        fi 
        if i > 1  
            [          ]
            res, n ≔ res * n, n-1; 
        fi
    od

b) 

    const N : Int;
    Var n, res : Int;
    do i >= 0
        if
            i := 0;
            [          ]
        fi 
        if i = 1 
            [          ]
            i = 1;
        fi 
        if i <= N   
            [          ]
            res, n ≔ res * n, n+1; 
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

--8)
i = -3, s = 5, a = [2,10,10,-1]

    i, s == 0, 0

    do 
        i < 4 ->
            s, i == s + a.i, i + 1<- Suma s a el elemento de a, y incrementa en uno.

σ0	-3	5	[2, 10, 10, -1]
σ′0	0	0	[2, 10, 10, -1]
σ01	1	2	[2, 10, 10, -1]
σ02	2	12	[2, 10, 10, -1]
σ11	3	22	[2, 10, 10, -1]
σ12	4	21	[2, 10, 10, -1]
σ3	4	21	[2, 10, 10, -1]

--b)

i == 3, c == 12, a == [12, -9, 10, -1]

    i, c == 0, 0

    do 
        i < 4 ->
            if a.i > 0 ->
                c = c + 1
            fi
            if a.i <= 0 ->
                skip
            fi
            i = i + 1


    i    c          a

<--o0--> 
σ0 : i = 3, c = 12, A = [12, -9, 10, -1] 

<--o1--> con los indicies de c== c + 1

σ0',   	0	0	[12, -9, 10, -1]

σ′1 0,	0	0	[12, -9, 10, -1]

σ′1 1,	0	0	[12, -9, 10, -1]

σ′1 2,	0	0	[12, -9, 10, -1]

σ′1 3,	0	0	[12, -9, 10, -1]

<--o2-->

σ′2 0,	0	1	[12, -9, 10, -1]

σ′2 1,	0	1	[12, -9, 10, -1]

σ′2 2,	0	2	[12, -9, 10, -1]

σ′2 3,	0	2	[12, -9, 10, -1]

<--o3-->

σ′3 0,	1	2	[12, -9, 10, -1]

σ′3 1,	2	2	[12, -9, 10, -1]

σ′3 2,	3	2	[12, -9, 10, -1]

σ′3 3,	4	2	[12, -9, 10, -1]

<--o4-->

σ′4,	4	2	[12, -9, 10, -1]

no se si este bien

--9)

Const A : array[0,4) ofInt;
Var i,s : Int;
Jσ0 : (i →−3,s →5,A → [2 10 10 −1 )
i,s := 0,0;
σ′0
do i < 4 →
σ01,··· ,σ31
s,i := s + A.i,i + 1
σ02,··· ,σ32
od
sum A.i % lenght A
σ3

-b)
if (i % 2 == 0) {
            printf("%d ", arr[i]); 
        }
agrego eso de arriba

--10)
--a)
    Const A : array[0,n) of Int;
        a.i >= 0
            [o01 o02 o03 o04]
            sumi += a[i]
        a.i mod 3 == 0
            [o12 o12 o13 o14]
            sum3 += a[i]
    [o2]
--b)
    Const A : array[12, -9, 10, 0, -1) of Int;
        a.i >= 0
            [o00o01 o02 o03 o04]
            sumi += a[i]
        a.i mod 3 == 0
            [o10 o11 o12 o13 o14]
            sum3 += a[i]
    [o2]

o00,
o01, 12
o02,  12 
o03,  12 + 10
o04, 12 + 10 + 0
o05, 12 + 10 + 0 = 22

o10, 12
o11, 12 - 9
o12, 12 - 9 
o13, 12 - 9
o14, 12 - 9 = 3

o2, 22, 3
    
--11)
--a)
Const A : array[0,n) of Int;
Const B : array[0,m) of Int;

    if a.i == b.i 
        [o01 o02 o03 o04]
        conteo += 1 
    fi 
     
--b) q flojera, no se si hice bien. consultarlo.

--12) Ternas de Hoare y Weakest precondition.

hecho aca: 

https://r9.whiteboardfox.com/93872386-7680-8941

--13)

a)
si se refiere a el x := x * x si, por que se esta multiplicando el valor de x por si mismo para dar positivo y q de true.
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

    si valida, es una sumatoria de elementos hasta llegar al elemento N de la lista A


  ¡En lenguaje C, no existe la asignación múltiple!
Debemos tener cuidado cómo traducimos para que se respete la semántica del programa,. Es decir, tengan estados equivalentes (el valor de las variables sean los mismos).
OJO, ASIGNACION, NO DE VALOR.  

b)

SUmatoria de k elementos hasta el N de la lista tal que el ultimo elemento sea k.

c)

    Si i no es el ultimo elemento de la lista, que siga buscando serlos mientras se suma un s a la lista del indice i.
d)
Si existe un elemento (Ak) del arreglo que sea igual a E entonces el elemento (Ai) es igual a E.

Ej extra

--17) 
a) {P} x := 8 {x = 8}

    wp.S.Q
={Definicion de WP por asignacion}
    wp.(x := 8).(x = 8)
={Asignacion}
    8 = 8
={Logica}
    True 

b)
{P} x := 8 {x ̸= 8}

    wp.S.Q
={Definicion de WP por asignacion}
    wp.(x := 8).(x ̸= 8)
={Asginacion}
    8 ̸= 8
={Logica}
    False

c)

{P} x := 9 {x = 7}

    wp.S.Q
={Definicion de WP por asignacion}
    wp.(x := 9).(x = 7)
={Asignacion}
    9 = 7
={Logiac}
    False +

d)
{P} x := x + 1; y := y −2 {x + y = 0} => Queda:

{P} x := x + 1 {x + y = 0} ^
{P} y := y −2 {x + y = 0} 

entonces
{P} x := x + 1 {x + y = 0} ≡ {P} y := y −2 {x + y = 0} 

    wp.S.Q
={Definicion por asignacion}
   wp.S.(wp.T.Q)
={Secuenciacion}
    wp.(x := x + 1).(wp.(y := y −2).(x + y = 0))
={Asignacion}
    wp.(x := x + 1).(y − 2 + x = 0)
={Asignacion}
    (x + 1) + y − 2 = 0

e)
{P} x := x + 1; y := y −1 {x ∗y = 0} => Queda:

wp.(S ; T).Q ≡ wp.S.(wp.T.Q)

{P} x := x + 1 {x ∗ y = 0} ^
{P} y := y −1 {x ∗ y = 0}

    wp.S.Q
={definicion por asignacion}
    wp.S.(wp.T.Q)
={secuenciacion}
    wp.(x := x + 1).(wp.(y := y −1).(x ∗ y = 0))
={Asignacion}
    wp.(x := x + 1).(y − 1 = 0)
={Asignacion}
    (x + 1) ∗ (y − 1) = 0 ?????


f)
{P} x := x + 1; y := y −1 {x + y + 10 = 0} => Queda

wp.(S ; T).Q ≡ wp.S.(wp.T.Q)

{P} x := x + 1 {x + y + 10 = 0} ^
{P} y := y −1 {x + y + 10 = 0}

    wp.S.Q
={definicion por asignacion}
    wp.S.(wp.T.Q)
={secuenciacion}
    wp.(x := x + 1).(wp.(y := y −1).(x + y + 10 = 0))
={Asignacion}
    wp.(x := x + 1).(y − 1 + x + 10 = 0)
={Asignacion}
    (x + 1) + y − 1 + x + 10 = 0
={Aritmetica}
    2x + y + 10 = 0


g)

{P} z := z ∗y; x := x −1 {z ∗y^x = C} => Queda

wp.(S ; T).Q ≡ wp.S.(wp.T.Q)

{P} z := z ∗y {z ∗y^x = C}  ^
{P} x := x −1 {z ∗yx = C}

    wp.S.Q
={Secuenciacion}
    wp.S.(wp.T.Q)
={definicion por asignacion}
    wp.(z := z ∗y).(wp.(x := x −1).(z ∗y^x = C))
={Asignacion}
    wp.(z := z ∗y).(z * y^(x − 1) = C)
={Asignacion}
    z * y^(x − 1) = C   

h)
{P} x,y,z := 1,d,c {x ∗x^y = c^d} 

    wp.S.Q
={definicion por asignacion }
    wp.(x,y,z := 1,d,c).(x ∗x^y = c^d)
={Asignacion}
    (x,y,z := 1,d,c).(x ∗x^y = c^d)
={Asignacion}
    (x,y,z := 1,d,c).(1 ∗1^d = c^d)
={Aritmetica}
    (1^(d+1) = c^d)

Bool, depende de q valor tenga c y d 

i)

{P} i,j := i + i,j; j := j + i {i = j} => Queda

{P} i,j := i + i,j {i = j} ^
{P} j := j + i {i = j} 

wp.(S ; T).Q ≡ wp.S.(wp.T.Q)

    wp.S.Q
={definicion por asignacion}
    wp.S.(wp.T.Q)
={secuenciacion}
    wp.(i,j := i + i,j).(wp.(j := j + i).(i = j))
={Asignacion}    
    wp.(i,j := i + i,j).(i = j + i)
={Asignacion}
    (i + i = j + i)


j)

{P} x := (x −y) ∗(x + y) {x + y^2 = 0} 
        
    wp.S.Q
={ASignacion}
    wp.(x := (x − y) ∗(x + y)).(x + y^2 = 0)
={Asignacion}
    ((x - y) * (x + y)) + y^2 = 0


k)
{P} q,r := q + 1,r −y {q ∗y + r = x}

    wp.S.Q
={Asignacion}
    wp.(q,r := q + 1,r −y).(q ∗y + r = x)
={Asignacion}
    (q + 1) * y + (r - y) = x

l)

{P} a := a ≡b; b := a ≡b; a := a ≡b {(a ≡ B) ∧ (b ≡ A)} => Queda

{P} a := a ≡ b {a ≡ B) ∧ (b ≡ A)} ^
{P} b := a ≡ b {a ≡ B) ∧ (b ≡ A)} ^
{P} a := a ≡ b {a ≡ B) ∧ (b ≡ A)}

wp.(S ; T ; R).Q ≡ wp.S.(wp.T.(wp.R.Q))

    wp.S.Q
={Secuenciacion}
    wp.S.(wp.R.(wp.T.Q))
={Asignacion}
    wp.(a := a ≡ b).(wp.(b := a ≡ b).(wp.(a := a ≡ b).((a ≡ B) ∧ (b ≡ A)))
={Asignacion}
    wp.(a := a ≡ b).(wp.(b := a ≡ b).((a ≡ b) ≡ B) ∧ (b ≡ A))
={Asignacion}
    wp.((a := a ≡ b).(a ≡ b) ≡ B)^  ((a ≡ b) ≡ A))
={asignacion}
    ((a ≡ b) ≡ b) ≡ B) ∧ (((a ≡ b) ≡ b) ≡ A))

(Dudo que este bien)

18) no entiendo como verificar ternas de hoare, en todo caso:

Tenemos en a):

if
    Guarda 0) B0 -> S0  // Que si B0 es verdadero, implica que S0 es verdadero
    Guarda 1) B1 -> S1  // Que si B1 es verdadero, implica que S1 es verdadero
fi
Que para que la terna funcione, se debe dar la preocondicion P, tiene que terminar verdadero en alguno de los dos casos.

Y en b):

if
    Guarda 0) B0 -> S0  // Que si B0 es verdadero, implica que S0 es verdadero
    Guarda 1) -B0 -> S1  // Que si B1 es verdadero, implica que S1 es verdadero
fi

es de suponer que todo lo que no es en universo 0, es en universo 1. Por lo tanto implicaria que -b0 == b1
por lo tanto, el programa deberia de dar true, ya que o bien se da algo que sea b0 implicara s0, y lo que no sea b0 implicara s1.

notemos que en ambas ternas, existe la guarda:
        Guarda 0) B0 -> S0  // Que si B0 es verdadero, implica que S0 es verdadero

Entonces el comportamiento es equivalente. 

Quiza la utilidad que tenga en c es para ahorrar tiempo en hacer casos para cada lo que no es b0.

19)


*/