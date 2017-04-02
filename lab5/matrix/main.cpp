//
// Created by mat on 01.04.17.
//

#include <iostream>
#include "Matrix.h"

using namespace std;
using ::algebra::Matrix;
using ::std::move;
using ::std::fill;
using ::std::swap;
using ::std::pair;

int main(int argc, char *argv[]) {
    Matrix m3{};
    Matrix m1{{1.0, 2., 0.9i}, {0., 1.0, 0.}, {0., 0., 1.0}};
    Matrix m2{{1.0i, 0.,}, {0., 1.0i} };

    cout << "Macierz pierwsza: " << m1.Print() << endl;
    cout << "Macierz druga: " << m2.Print() << endl;

    cout << "Dodawanie" << (m1.Add(m2)).Print() << endl;
    cout << "Odejmowanie" << (m1.sub(m2)).Print() << endl;
//    cout << "Mnożenie" << (m1.mul(m2)).Print() << endl;
//    cout << "Dzielenie" << (m1.div(m2)).Print() << endl;
//    cout << "Potęgowanie" << (m1.pow(2)).Print() << endl;
//    cout << "Potęgowanie" << (m2.pow(2)).Print() << endl;
}