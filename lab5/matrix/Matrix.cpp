//
// Created by mat on 01.04.17.
//
#include<iostream>
#include "Matrix.h"

namespace algebra {
    Matrix::Matrix(unsigned int x, unsigned int y) : x_(x), y_(y) {
        if (x_>0 && y_>0) {
            matrix_.reserve(y_);
            for (auto &&item : matrix_) {
                item.reserve(x_);
            }
        }
    }

    Matrix::Matrix(std::vector<std::vector<std::complex<double>>> in) {
        matrix_=in;
    }
    Matrix::Matrix(std::initializer_list<std::initializer_list<std::complex<double>>> in) {
//        std::string tmp;
//        tmp.insert(tmp.begin, in.begin(), in.end());
//        for (auto item : in) {
//            matrix_.insert(matrix_.end(), item.begin(), item.end());
//        }
    }

    void Matrix::set(unsigned int x, unsigned int y, std::complex<double> &in) {
        this->matrix_[x][y] = in;
    }

    std::complex<double> Matrix::get(unsigned int x, unsigned int y) {
        if (x < x_ && y < y_)
            return this->matrix_[x][y];
    }

    Matrix & Matrix::add(Matrix &mm) {
        if (this->x_ == mm.x_ && this->y_ == mm.y_)
            for (int i = 0; i < x_; ++i)
                for (int j = 0; j < y_ ; ++j)
                this->matrix_[i][j] += mm.matrix_[i][j];
        return *this;
    }

    Matrix &Matrix::operator+(Matrix &mm) {
        this->add(mm);
    }

    Matrix Matrix::sub(Matrix &mm) {
        if (this->x_ == mm.x_ && this->y_ == mm.y_)
            for (int i = 0; i < x_; ++i)
                for (int j = 0; j < y_ ; ++j)
                    this->matrix_[i][j] += mm.matrix_[i][j];
        return *this;
    }

    std::string Matrix::Print() {
        std::stringstream result;
        result<<"[";
        for (int i = 0; i < x_; ++i) {
            for (int j = 0; j < y_; ++j) {
                result<<this->matrix_[i][j];
                if (j < y_ - 1)
                    result<<", ";
            }
            result<<"; ";
        }
        result<<"]";
    }

}