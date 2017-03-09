//
// Created by hushmans on 04.03.17.
//

#include <iostream>
#include <string>
#include "Palindrome.h"

using namespace std;

int main(){
    int check;
    std::cout<<"(1) Wyjdz"<<std::endl;
    std::cout<<"(2) Sprawdz palindrom"<<std::endl;
    std::cin>>check;
    if (check==1) return 0;
    if (check==2) {
        std::cout<<"Podaj slowo do sprawdzenia:"<<std::endl;
        string word;
        std::cin>>word;
        is_palindrome(word);
    }
}