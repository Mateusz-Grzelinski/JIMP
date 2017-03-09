//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorial(int value){
    /*if (value<=-13 || value>=13) return 0;
    int wynik=1;
    if( value>=0)
        for(int i=1;i<=value;i++)
            wynik*=i;
    else
        for(int i=1;i<=-value;i++)
            wynik*=-i;
    return wynik;*/


    if (value<=-13 || value>=13) return 0;
    if (value>2)
        return value*factorial(value-1);
    if (value <2 && value >-1)
        return 1;
    if (value <0)
        return factorial(value+1)*value;


}
