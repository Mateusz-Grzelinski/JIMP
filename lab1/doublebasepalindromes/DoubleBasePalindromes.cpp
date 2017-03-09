//
// Created by mat on 05.03.17.
//

#include "DoubleBasePalindromes.h"
#include "ConvertToBase2.h"


uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    uint64_t wynik=0;
    long int i;
    std::string BaseTenString;

    for(i=1; i<max_vaule_exculsive; i++){
        //konwertuj liczbę do stringa
        BaseTenString = std::to_string(i);
        //sprawdź czy liczba jest jest palindromem w dwóch systemach
        if ( is_palindrome(BaseTenString) && is_palindrome(ConvertToBase2(i)) )
            wynik+=i;
    }
    return wynik;
}


bool is_palindrome(std::string str){
    if (str.length()==1) return true;
    int i,j;
    for (i=0, j=str.length()-1; i<j; i++, j--)
        if (str[i]!=str[j]) break;
    if (i<j) return false;
    else return true;
}
