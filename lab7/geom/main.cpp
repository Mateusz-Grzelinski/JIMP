//
// Created by mat on 18.04.17.
//

#include <iostream>
#include "Kula.h"

int main() {
    Kula kl(0, 0, 0, 10);
    std::cout << "pole kuli: " << kl.Pole()<<std::endl;
    std::cout << "pole przekroju: " << kl.Kolo::Pole();


    return 0;
}