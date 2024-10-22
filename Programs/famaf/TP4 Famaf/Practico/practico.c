/*
1)
 { P } S { Q }

    a)
        Pre             Pos
    { P = x = X ∧ y = Y } S { Q = x v y }

    Var x, y, res: Int;
    { x = X ∧ y = Y }
      if 
        x <= y ->  
            res := x;
        x > y ->  
            res := y;
      fi ; 
    { res = min.x.y }

    Derivacion:

        wp.s.q
    ={Defincion de wp}
        wp.(if..fi).(res = min.x.y)
    ={Por digesto de condicional}
        (x <= y ^ x > y) ^
        (x <= y -> wp.(res := x).(res = min.x.y) ^
        (x > y -> wp.(res := y).(res = min.x.y))
    ={Logica, abs. Def de secuenciacion}
        (x <= y -> (res = min.x.y) (x <- res) ^
        (x > y -> (res = min.x.y) (y <- res)
    ={Asignacion}
        (x <= y -> (x = min.x.y) ^          1)
        (x > y -> (y = min.x.y)             2)
    ={Supongamos que vale 1)}
        (x = min.x.y) ^ ( x > y -> ( y = min.x.y))
    ={Como es una suposicion de x <= y, entonces min.x.y = x. Vale una o la otra}
        True ^ ( y = min.x.y)
    ={Por suposicion de x >y, entonces min.x.y = y}
        True ^ True
    ={Logica}
        True 

    b)      
    Var x: Int;
    { x = X }
        if
            x >= 0 -> 
                skip;
            x < 0 -> 
                x := -x;
        fi;
    { x = |X|}

    Derivacion:

        wp.s.q
    ={Definicon por asignacion}
        wp.(if..fi).(x = |X|)
    ={Por digesto de if}
        (x >= 0 ^ x < 0) ^
        (x >= 0 -> wp.skip.(x = |X|) ^
        (x < 0 -> wp.(x := -x).(x = |X|)
    ={Logica}
        (True) ^
        (x >= 0 -> x = |X|) ^
        (x < 0 -> wp.(x := -x).(x = |X|)
    ={Def de digesto de asignacion. Abs de true}
        (x >= 0 -> x = |X|) ^
        (x < 0 -> (x = |X|).(x <- -x)
    ={Asignacion}
        (x >= 0 -> x = |X|) ^
        (x < 0 -> -x = |X|)
    ={Supongo x >= 0 }
        (x = |X|) ^
        (x < 0 -> -x = |X|)
    ={Por suposicion y aritmetica}
        True ^ (x < 0 -> -x = |X|)
    ={Supongo ewl antescedente y demuestro el consecuente}
        True ^ (-x = |X|)
    ={Por suposicion como x < 0 ^ x = X }
        True ^ True
    ={Logica}
        True
        
2)

    apunte del profe luque:

    Ejemplo: Factorial de un número N: Dado N ≥ 0 quiero calcular el factorial de N.

    Const N : Int;
    Var res : Int;
    { P: N ≥ 0 }
    S
    { Q:  res = N!  }

    ¿Nos saldrá este programa a ojo? Queremos calcular: 
                                1 * 2 * 3 * 4 * …. * (N-1) * N
    La idea es hacer un ciclo que recorra los números desde 1 hasta el N (en una variable n), e ir multiplicando en res esos números.

    Const N : Int;
    Var res , n : Int;
    { P: N ≥ 0 }
    res , n  :=  1 , 1  ;
    do n ≤ N → 
            res , n := res * n , n + 1
    od
    { Q:  res = N!  }

    La otra forma a ojo, recorriendo al revés:

    Const N : Int;
    Var res , n : Int;
    { P: N ≥ 0 }
    res , n  :=  1 , N  ;
    do n ≥ 1 → 
            res , n := res * n , n - 1
    od
    { Q:  res = N!  }

    Ahora probemos derivando:
    Usando la técnica de reemplazo de constante por variable, creamos una nueva variable n : Int, y proponemos:
        INV ≡  res = n!  ∧  0 ≤ n ≤ N
        B    ≡   n ≠ N     (también andaría n < N)

    Replanteamos el programa:
    Const N : Int;
    Var res : Int;
    { P: N ≥ 0 }
    S1 ;
    { INV }
    do n ≠ N → 
            { INV ∧ B }
            S2
            { INV }
    od
    { Q:  res = N!  }

    Inicialización:
    { P: N ≥ 0 }
    S1 ; 
    { INV: res = n !  ∧  0 ≤ E ≤ N }

    S1 debe ser de la forma: res, n := E , F
    ( F no puede ser 1 porque no puedo saber 1 ≤ N )
    Elijo F = 0, E = 1 y sale todo bien (ejercicio: verificarlo con la wp)

    Cuerpo del ciclo:
            { INV ∧ B:  res = n !  ∧  0 ≤ n ≤ N  ∧  n ≠ N }
            S2
            { INV:  res = n !  ∧  0 ≤ n ≤ N }

    S2 debe ser de la forma:   res, n := E , n + 1.

    Derivemos: Supongamos como hipótesis INV ∧ B, y veamos la wp:

    wp.(res, n := E , n + 1).INV
    ≡ { def. wp para :=  }
    E = (n+1) !  ∧  0 ≤ n+1 ≤ N
    ≡ { algebra (prop !) }
    E = n! * (n + 1)     ∧      0 ≤ n+1 ≤ N
    ≡ { hip. INV }   ← FUNDAMENTAL A LA HORA DE DERIVAR UN CUERPO DE CICLO
    E = res * (n + 1)     ∧      0 ≤ n+1 ≤ N
    ≡ { elijo E = res * (n+1) }
    res * (n+1) = res * (n + 1)     ∧     0 ≤ n+1 ≤ N
    ≡ { lógica }
    0 ≤ n+1 ≤ N
    ≡ { 0 ≤ n+1 vale por hip. 0 ≤ n,    n+1 ≤ N vale por hip   n ≤ N  ∧ n ≠ N  } 
    True

    Listo! Resultado final:
    Const N : Int;
    Var res : Int;
    { P: N ≥ 0 }
    res, n := 1, 0 ;
    do n ≠ N → 
            res,  n := res * (n+1) , n + 1
    od
    { Q:  res = N!  }

    Es muy parecido pero no igual al que hicimos a ojo. Ambos andan bien igual.


3)

    Dado N >= 0

    Var n, sum : Int;
    { P: N > 0 }
        sum := 0;
        do 
            sum = sum + n;
        od 
    { Q <Sum i : 0 <= i < n: n>}

    
*/