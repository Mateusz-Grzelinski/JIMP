//
// Created by mat on 04.03.17.
//
#include <string>
#include <iostream>

bool is_palindrome(std::string str){
    if (str.length()==1) return true;
    int i,j;
    for (i=0, j=str.length()-1; i<j; i++, j--)
        if (str[i]!=str[j]) break;
    if (i<j) return false;
    else return true;
}