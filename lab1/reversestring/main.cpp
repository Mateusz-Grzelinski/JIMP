//
// Created by mat on 04.03.17.
//
#include <iostream>
#include "ReverseString.h"

int main (void){
    std::string napis;
    std::cout<<"Podaj napis do odwrocenia:"<< std::endl;
    std::cin>>napis;
    std::cout<< napis << " odwrócony: " << reverse(napis) << std::endl;
    return 0;
}