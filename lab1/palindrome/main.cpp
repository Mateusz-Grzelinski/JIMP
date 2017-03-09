//
// Created by mat on 04.03.17.
//

#include "Palindrome.h"
#include <iostream>

int main(){
    int rozkaz;
    std::string tekst;
    while (1) {
        std::cout << "---1) Sprawdź palindrom" << std::endl << "---2) Wyjście\n (wpisz 1 lub 2)" << std::endl;
        std::cin >> rozkaz;
        if (rozkaz==2) break;
        if (rozkaz==1) {
            std::cin >> tekst;
            std::cout<<is_palindrome(tekst)<<std::endl;
        }
    }
    return 0;
}