#ifndef BIMATH_H
#define BIMATH_H

#define SET_BIT(Var,BitPos)       Var |= (1<<BitPos)
#define CLEAR_BIT(Var,BitPos)     Var  = Var &~ (1<<BitPos)
#define GET_BIT(Var,BitPos)       ((Var>>BitPos)&1)
#define WRITE_BYTE(Var,Value)     Var = Value
#define READ_BYTE(Var)            Var 
#define TOGGLE_BIT(Var,BitPos)    Var = Var ^ (1<<BitPos)
#define TOGGLE_BYTE(Var)          Var = Var ^ 255  

#endif