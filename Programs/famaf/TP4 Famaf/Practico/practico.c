/*
1)
 { P } S { Q }

    a)
        Pre             Pos
    { P = True } S { Q = x v y }

    Var x, y, res: Int;
    { x /=0 }
    res := 0;
      if 
        x > y ->  
            res := y;
        x < y ->  
            res := x;
      fi ; 
    { res = x v y }

    Derivacion:

        wp.s.q
    ={Definicon por asignacion}
        wp.s.(res = x v y)
        hago dos casos:
            Caso 1: x > y
                wp.(res := y).(res = y v x)
            ={Asignacion}
                wp.(y = y v x)
            ={Logica}
                True

            Caso 2: x < y
                wp.(res := x).(res = x v y)
            ={Asignacion}
                wp.(x = x v y)
            ={Logica}
                True

    b)      
    Var x, res: Int;
    { True }
    res := 0;
        if
            x > 0 -> 
                res := x;
            x < 0 -> 
                res := -x;
        fi;
    { res = x }

    Derivacion:

        wp.s.q
    ={Definicon por asignacion}
        wp.s.(res = x)
        hago dos casos:
            Caso 1: x > 0
                wp.(res := x).(res = x)
            ={Asignacion}
                wp.(x = x)
            ={Logica}
                True

            Caso 2: x < 0
                wp.(res := -x).(res = x)
            ={Asignacion}
                wp.(-x = x)
            ={Logica}
                True 
*/