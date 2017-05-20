//
// Created by mat on 18.05.17.
//

#include "AddTemplate.h"

#include <iostream>
#include <complex>

int main() {
    int i = 5;
    double d = 5.5;
    std::complex<double> c = {1, 2};
    std::cout << "wynik: " << Add<int>(i, i);

    std::unique_ptr<int> ptr = std::make_unique<int>();
    Value(move(ptr));

    std::vector<double> meanvec = {2.0, 5.0};
    std::cout<<"\nsrednia: "<<Mean(meanvec);

}