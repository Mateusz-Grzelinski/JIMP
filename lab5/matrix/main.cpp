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
    Matrix m3{2,2};
    const Matrix m1{{7.0, 2.2i, 0.9i}, {0., 1.0, 0.}, {0., 0., 1.0}};
    const Matrix m2{{5.0, 2., 0.9i}, {0., 1.0, 0.}, {0., 0., 1.0}};

    cout << "Macierz pierwsza: " << m1.Print() << endl;
    cout << "Macierz druga:    " << m2.Print() << endl;
    cout << "Macierz 3:    " << m3.Print() << endl;

    cout << "Dodawanie" << m1.Add(m2).Print() << endl;
    cout << "Odejmowanie" << (m1.Sub(m2)).Print() << endl;
    cout << "Mnożenie" << (m1.Mul(m2)).Print() << endl;
//    cout << "Dzielenie" << (m1.Div(m2)).Print() << endl;
    cout << "Potęgowanie" << (m1.Pow(2)).Print() << endl;
}