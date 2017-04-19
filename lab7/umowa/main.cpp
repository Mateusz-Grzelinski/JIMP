//
// Created by mat on 19.04.17.
//

#include <iostream>
#include "Umowa.h"

using namespace std;

int main(){
    UmowaPraca pracaUmowa(1000);
    Pracownik pracus("mat", "grz", "1234", &pracaUmowa);


    cout<<pracus;

    return 0;
}