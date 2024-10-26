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

    Programa:

    Var n, sum : Int;
    { P: N > 0 }
        sum := 0;
        do 
            sum = sum + n;
        od 
    { Q <Sum i : 0 <= i < n: n>}

    Con las invariantes:

    Con estructura de ciclo:

    Var n, sum : Int;
    { P }
        S1 ; // Inicializacion
        do
            {INV ^ B} 
            S2              // Cuerpo del ciclo
            {INV}
        od 
    { Q }

    Var n, sum : Int;
    { P: N > 0 }
        sum := 0;
        {INV ^ B}
        do 
            sum = sum + n;
            {INV}
        od 
        {Inv ^ -b}
    { Q <Sum i : 0 <= i < n: n>}

    Primero calculo la wp de la asignacion:

        p -> I
    ={Definicion de wp por asignacion}
        N > 0 -> wp.(sum := 0).(I)

    { P } -> { Inv } //Alternativamente, el es { P } skip { Inv } no se pone skip opr cuestiones de logica 
    {Inv ^ B } S { Inv }        
    { Inv ^ -B } skip { Q } //Termina el bucle ya que no cumple b
 
    
    4)
    Ejemplo: Suma de los elementos de un arreglo. 

    Const N : Int, A : Array[0, N) of Int;
    Var pos, res : Int;
    { P: N ≥ 0 }
    res, pos := 0, 0 ;
    { R: res = 0 ∧ pos = 0 }
    do pos < N → 
        { hasta acá ya sumé todas las posiciones desde 0 hasta pos no inclusive }
        res, pos := res + A.pos, pos + 1
    od
    { Q: res = 〈∑ i : 0 ≤ i < N : A.i 〉}

    Invariante:  Recordemos que expresa el “resultado intermedio”:

    INV ≡     res = 〈 ∑ i : 0 ≤ i < pos : A.i 〉  ∧   0 ≤ pos ≤ N

    Lo sacamos “de la galera”. Ahora vamos a demostrar que es correcto:

    i) R ⇒ INV

    Suponemos R como hip: res = 0 ∧ pos = 0.
    Vemos INV:
    INV
    ≡ {  ?????  (ejercicio) }
    True

    ii) El invariante se preserva en el cuerpo del ciclo:
    { INV ∧ B } S { INV }
    donde S es el cuerpo del ciclo: res, pos := res + A.pos, pos + 1

    Demostración: Usamos wp: Probamos que INV ∧ B ⇒ wp.S.INV.

    Suponemos INV ∧ B como hipótesis:
    INV ≡         res = 〈 ∑ i : 0 ≤ i < pos : A.i 〉     
                        ∧ 0 ≤ pos ≤ N 
                res = A.0 + …. + A.(pos-1)
    B    ≡      pos < N

    Veamos la wp:
    wp.(res, pos := res + A.pos, pos + 1).INV
    ≡ { def. wp para := }
    res + A.pos  = 〈 ∑ i : 0 ≤ i < pos + 1 : A.i 〉  ∧   0 ≤ pos + 1 ≤ N
            ///               A.0 + …. + A.(pos-1) + A.pos
    ≡ { lógica y partición de rango }
    res + A.pos  = 〈 ∑ i : 0 ≤ i < pos : A.i 〉   + 〈 ∑ i : i = pos : A.i 〉      ∧   0 ≤ pos + 1 ≤ N
    ≡ { rango unitario }
    res + A.pos  = 〈 ∑ i : 0 ≤ i < pos : A.i 〉 +   A.pos                               ∧   0 ≤ pos + 1 ≤ N
    ≡ {  hip. me dice que esa sumatoria es res }
    res + A.pos  = res +   A.pos                                                                 ∧      0 ≤ pos + 1 ≤ N
    ≡ { reflexividad }
    True ∧       0 ≤ pos + 1 ≤ N
    ≡ {  neutro, y lógica  }
    0 ≤ pos + 1   ∧   pos + 1 ≤ N
    ≡ { 0 ≤ pos + 1 vale por hip pos ≥ 0. }
    pos + 1 ≤ N
    ≡ { pos + 1 ≤ N vale por hip B: pos < N }
    True

*/