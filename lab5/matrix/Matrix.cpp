//
// Created by mat on 01.04.17.
//
#include<iostream>
#include "Matrix.h"

namespace algebra {
    Matrix::Matrix(unsigned int x, unsigned int y) : x_(x), y_(y) {
        if (x_>0 && y_>0) {
            matrix_.reserve(x_);
            for (auto &item : matrix_) {
                item.reserve(y_);
            }
        }
    }

    Matrix::Matrix(std::vector<std::vector<std::complex<double>>> in) {
        matrix_=in;
    }

    Matrix::Matrix(std::initializer_list<std::initializer_list<std::complex<double>>> in):
    x_(in.size()), y_((*in.begin()).size()) {
        int i=0;
        matrix_.reserve(x_);
        for ( const std::initializer_list<std::complex<double>> &l : in )
        {
            matrix_[i].assign( l );
            ++i;
        }
    }

    void Matrix::set(unsigned int x, unsigned int y, std::complex<double> &in) {
        this->matrix_[x][y] = in;
    }

    std::complex<double> Matrix::get(unsigned int x, unsigned int y) {
        if (x < x_ && y < y_)
            return this->matrix_[x][y];
    }

    unsigned int Matrix::Size() {
        return x_*y_;
    }

    const Matrix& Matrix::Add(const Matrix &mm) {
        if (this->x_ == mm.x_ && this->y_ == mm.y_)
            for (int i = 0; i < x_; ++i)
                for (int j = 0; j < y_ ; ++j)
                this->matrix_[i][j] += mm.matrix_[i][j];
        return *this;
    }

    Matrix &Matrix::operator+(Matrix &mm) {
        this->Add(mm);
    }

    Matrix Matrix::sub(Matrix &mm) {
        if (this->x_ == mm.x_ && this->y_ == mm.y_)
            for (int i = 0; i < x_; ++i)
                for (int j = 0; j < y_ ; ++j)
                    this->matrix_[i][j] += mm.matrix_[i][j];
        return *this;
    }

    Matrix &Matrix::operator-(Matrix &mm) {
        this->sub(mm);
    }

    std::string Matrix::Print() const {
        std::stringstream result;
        result<<"[";
        for (int i = 0; i < x_; ++i) {
            for (int j = 0; j < y_; ++j) {
                result<<this->matrix_[i][j].real();
//                if(this->matrix_[i][j].imag()!=0)
                result<<"i"<<this->matrix_[i][j].imag();
                if (j < y_ - 1)
                    result<<", ";
            }
            if (i<x_-1)
                result<<"; ";
        }
        result<<"]";
        return result.str();
    }

}