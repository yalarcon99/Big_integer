#include "IntGrande.h"

/*constructor predeterminado
 *convierte un entero largo en un objeto IntGrande*/
IntGrande::IntGrande(long valor)
{
    for(int i = 0; i <= 29; i++)
        entero[i] = 0;

    /*coloca los digitos del argumento dentro del arreglo*/
    for(int j = 29; valor != 0 && j >= 0; j--){
        entero[j] = valor % 10;
        valor /= 10;
    }
}

/*constructor de conversion que convierte una cadena de caracteres
 * que representan un entero grande en un objeto IntGrande*/
IntGrande::IntGrande(const char *cadena)
{
    for(int i = 0; i <= 29; i++)
        entero[i] = 0;

    /*coloca los digitos del argumento dentro del arreglo*/
    int longitud = strlen(cadena);
    for(int j = 30 - longitud, k = 0; j <= 29; j++, k++)
        if (isdigit(cadena[k]))
            entero[j] = cadena[k] - '0';
}

IntGrande::IntGrande(const IntGrande& orig)
{
    for(int i = 0; i <= 29; i++)
        entero[i] = 0;
    
    for(int j = 29; j >= 0; j--){
        entero[j] = orig.entero[j];
    }
}

IntGrande::~IntGrande()
{
}

IntGrande IntGrande::operator+(const IntGrande &op2)
{
    IntGrande temp;
    int acarreo = 0;

    for(int i = 29; i >= 0; i--){
        temp.entero[i] = entero[i] + op2.entero[i] + acarreo;
        if(temp.entero[i] > 9){
            temp.entero[i] %= 10; //reduce a 0-9
            acarreo = 1;
        }
        else
            acarreo = 0;
    }
    return temp;
}

/*operador de suma IntGrande + int
 * convierte op2 en un IntGrande e invoca a operator+*/
IntGrande IntGrande::operator+(int op2)
{
    return *this + IntGrande(op2);
}

/*operador de suma; IntGrande + cadena que representa
 * un valor IntGrande*/
IntGrande IntGrande::operator+(const char *op2)
{
    return *this + IntGrande(op2);
}
/*Operador resta*/
IntGrande IntGrande::operator-(const IntGrande &op2)
{
    IntGrande temp;
    int acarreo = 10;
    int aux[30], aux3[30];
    bool opt, aux2;
    for(int i = 29; i >= 0; i--){
        aux[i] = entero[i];
        aux3[i] = op2.entero[i];
    }
    for(int i = 0; i < 30; i++){
        if(aux[i] > op2.entero[i]){
            opt = 1; i = 30;
        }
        else if(aux[i] < op2.entero[i]){
            opt = 0; i = 30;
        }    
    }
    if(opt == 1){
        for(int i = 29; i >= 0; i--){
            if(aux[i] < op2.entero[i]){
                temp.entero[i] = (acarreo + aux[i]) - op2.entero[i];
                aux[i-1] -= 1;   
            }
            else if(aux[i] >= op2.entero[i])
                temp.entero[i] = aux[i] - op2.entero[i];
        }
    }else if(opt == 0){  
        for(int i = 29; i >= 0; i--){
            if(aux3[i] < entero[i]){
                temp.entero[i] = (acarreo + aux3[i]) - entero[i];
                aux3[i-1] -= 1;   
            }
            else if(aux3[i] >= entero[i])
                temp.entero[i] = aux3[i] - entero[i];
        }
        for(int i = 0; i < 30; i++){
            if(temp.entero[i] > 0){
                temp.entero[i] = -temp.entero[i]; 
                i = 30;
            }
        }
    }
    return temp;
}

IntGrande IntGrande::operator-(int op2)
{
    return *this - IntGrande(op2);
}

IntGrande IntGrande::operator-(const char *op2)
{
    return *this - IntGrande(op2);
}
IntGrande IntGrande::operator*(const IntGrande &op2)
{
    IntGrande temp;
    int marc1, marc2, res; bool ex;
    ex = 1; bool conf1 = 1; bool conf2 = 1;
    for(int i = 0; i < 29; i++){
        if(entero[i+1] > 0 && conf1 == 1){
            marc1 = i; conf1 = 0;
        }
        if(op2.entero[i+1] > 0 && conf2 == 1){
            marc2 = i; conf2 = 0;
        }
    }
    int acarreo2 = 0; int acarreo = 0;int factor = 0; int ite;
    //Se implementó la multiplicación por sumas sucesivas, sin embargo,
    //el método involucra un gasto computacional muy amplio
    for(int i = 29; i >= marc2; i--){
        ite = 29 - i;
        factor += op2.entero[i] * pow(10,ite);
    }
    for(int j = 0; j < factor; j++){
        for(int i = 29; i >= 0; i--){
            temp.entero[i] = temp.entero[i] + entero[i] + acarreo;
            if(temp.entero[i] > 9){
                temp.entero[i] %= 10; //reduce a 0-9
                acarreo = 1;
            }
            else
                acarreo = 0;
        }
    }
    /*
    //if(((29-marc1)+(29-marc2)) > 30)
    //    ex = 0;
    for(int j = 0; j < 29; j++){
        acarreo = 0;
        for(int i = 29; i >= 0; i--){
            res = entero[i] * op2.entero[29-j];
            temp.entero[i-j] += (res % 10) + acarreo + acarreo2 ;
            acarreo = res/10;
            if(temp.entero[i-j] > 9 && j > 0){
                temp.entero[i-j] %= 10;
                acarreo2 = temp.entero[i-j]/10;
            }else
                acarreo2 = 0;
        }
    }*/
    return temp;
}

/*operador de multiplicacion IntGrande * int
 * convierte op2 en un IntGrande e invoca a operator* */
IntGrande IntGrande::operator*(int op2)
{
    return *this * IntGrande(op2);
}

IntGrande IntGrande::operator*(const char *op2)
{
    return *this * IntGrande(op2);
}
//Para la división efectuamos el método de división por restas sucesivas
IntGrande IntGrande::operator/(const IntGrande &op2)
{
    IntGrande temp; int iter;
    bool conf = 1; int marc1,marc2;
    int acarreo = 10;
    int aux[30], aux3[30];
    bool opt, aux2;
    for(int i = 29; i >= 0; i--){
        temp.entero[i] = entero[i];
    }
    bool conf1 = 1; bool conf2 = 1;int ite, factor1, factor2;
    iter = 0;
    while(conf == 1){
        //Proceso de resta
        for(int i = 29; i >= 0; i--){
            aux[i] = temp.entero[i];
            aux3[i] = op2.entero[i];
        }
        for(int i = 0; i < 30; i++){
            if(aux[i] > op2.entero[i]){
                opt = 1; i = 30;
            }
            else if(aux[i] < op2.entero[i]){
                opt = 0; i = 30;
            }    
        }
        if(opt == 1){
            for(int i = 29; i >= 0; i--){
                if(aux[i] < op2.entero[i]){
                    temp.entero[i] = (acarreo + aux[i]) - op2.entero[i];
                    aux[i-1] -= 1;   
                }
                else if(aux[i] >= op2.entero[i])
                    temp.entero[i] = aux[i] - op2.entero[i];
            }
        }else if(opt == 0){  
            for(int i = 29; i >= 0; i--){
                if(aux3[i] < temp.entero[i]){
                    temp.entero[i] = (acarreo + aux3[i]) - temp.entero[i];
                    aux3[i-1] -= 1;   
                }
                else if(aux3[i] >= entero[i])
                    temp.entero[i] = aux3[i] - temp.entero[i];
            }
            for(int i = 0; i < 30; i++){
                if(temp.entero[i] > 0){
                    temp.entero[i] = -temp.entero[i]; 
                    i = 30;
                }
            }
        }
        //Parte 2
        factor1 = 0;factor2 = 0;
        for(int i = 29; i >= marc2; i--){
            ite = 29 - i;
            factor1 += op2.entero[i] * pow(10,ite);
            factor2 += temp.entero[i] * pow(10,ite);
        }
        if(factor2 >= factor1)
            conf = 1;
        else if(factor2 < factor1)
            conf = 0;
        iter += 1;
    }
    for(int i = 29; i >= 0; i--){
        temp.entero[i] = iter % 10;
        iter /= 10;
    }
    return temp;
}

IntGrande IntGrande::operator/(int op2)
{
    return *this / IntGrande(op2);
}

IntGrande IntGrande::operator/(const char *op2)
{
    return *this / IntGrande(op2);
}
/*operador de salida sobrecargado*/
ostream& operator<<(ostream &salida, const IntGrande &num)
{
    int i;
    for(i = 0; (num.entero[i] == 0) && (i <= 29); i++);
    /*ignora ceros a la izquierda*/

    if(i == 30)
        salida << 0;
    else
        for( ; i <=29; i++)
            salida << num.entero[i];
    return salida;
}