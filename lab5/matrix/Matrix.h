//
// Created by mat on 01.04.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <initializer_list>
#include<iostream>
#include <complex>
#include <vector>

namespace algebra {

    class Matrix {
    public:
        Matrix(unsigned int x, unsigned int y); //niepotrzebne
        Matrix(std::initializer_list<std::initializer_list<std::complex<double>>> in);

        Matrix(std::vector<std::vector<std::complex<double>>> in);

        //set, get i size
        void set(unsigned int x, unsigned int y, std::complex<double> &in);
        std::complex<double> get(unsigned int x, unsigned int y);
        unsigned int Size();

        const Matrix &Add(const Matrix &mm);
        Matrix &operator+(Matrix &mm); //niepotrzebne, ale fajne :)

        Matrix sub(Matrix &mm);
        Matrix &operator-(Matrix &mm); //niepotrzebne, ale fajne :)

//        Matrix Pow(Matrix &mm);
//
//        Matrix Mul(Matrix &mm);
//
//        Matrix Div(Matrix &mm);

        std::string Print() const;

    private:
        //macierz implementowana w jednowymiarowej tablice, do której odnoszę się w taki sposób:
        // matrix_[x_*zadane_y +zadane_x]
        std::vector<std::vector<std::complex<double>>>  matrix_;
        unsigned int x_, y_;
    };

}
#endif //JIMP_EXERCISES_MATRIX_H
