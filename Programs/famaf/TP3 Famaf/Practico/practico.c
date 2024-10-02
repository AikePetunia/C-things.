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
*/