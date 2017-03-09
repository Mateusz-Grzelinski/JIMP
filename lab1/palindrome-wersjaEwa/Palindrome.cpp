//
// Created by hushmans on 04.03.17.
//

#include "Palindrome.h"

bool is_palindrome(string str) {
    int i,j;
    int dl;
    dl=str.length();
    if (dl==0) {
        std::cout<<"Dlugosc 0"<<std::endl;
        return true;
    }
    for (i=0, j=dl-1; i<j; i++, j--) {
        if (str[i] != str[j]) break;
    }
    if (i < j) {
        std::cout<<"Slowo nie jest palindromem"<<std::endl;
        return false;
        }
    else {
        std::cout<<"Slowo jest palindromem"<<std::endl;
        return true;
        }
    }