//
// Created by mat on 01.04.17.
//
#include<iostream>
#include "Matrix.h"

namespace algebra {
    Matrix::Matrix(unsigned int x, unsigned int y) : x_(x), y_(y) {
        int i = 0;
        matrix_.resize(x_);
        for (std::vector<std::complex<double>> &l : matrix_) {
            l.assign(y_, {0, 0});
            ++i;
        }
    }


    Matrix::Matrix(std::initializer_list<std::initializer_list<std::complex<double>>> in) :
            x_(in.size()), y_((*in.begin()).size()) {
        int i = 0;
        matrix_.reserve(x_);
        for (const std::initializer_list<std::complex<double>> &l : in) {
            matrix_[i].assign(l);
            ++i;
        }
    }

    void Matrix::set(unsigned long x, unsigned long y, std::complex<double> in) {
        this->matrix_[x][y] = in;
    }

    std::complex<double> Matrix::get(unsigned int x, unsigned int y) const {
        if (x < x_ && y < y_)
            return matrix_[x][y];
        else return {0, 0};
    }

    unsigned int Matrix::getx() const { return this->x_; }

    unsigned int Matrix::gety() const { return this->y_; }

    unsigned long Matrix::Size() const { return x_ * y_; }

    Matrix Matrix::Add(const Matrix &mm) const {
        Matrix resultmx{x_, y_};
        if (this->x_ == mm.getx() && this->y_ == mm.gety())
            for (int i = 0; i < x_; ++i)
                for (int j = 0; j < y_; ++j) {
                    std::complex<double> tmpcomplex = this->get(i, j) + mm.get(i, j);
                    resultmx.set(i, j, tmpcomplex);
                }
        return resultmx;
    }

    Matrix Matrix::Sub(const Matrix &mm) const {
        Matrix resultmx{x_, y_};
        if (this->x_ == mm.getx() && this->y_ == mm.gety())
            for (int i = 0; i < x_; ++i)
                for (int j = 0; j < y_; ++j) {
                    std::complex<double> tmpcomplex = this->get(i, j) - mm.get(i, j);
                    resultmx.set(i, j, tmpcomplex);
                }
        return resultmx;
    }

    Matrix Matrix::Mul(const Matrix &in) const {
        Matrix res(x_, y_);
        if (this->x_ == in.getx() && this->y_ == in.gety()) {
            for (unsigned long m = 0; m < this->x_; m++) {
                for (unsigned long i = 0; i < in.y_; ++i) {
                    for (unsigned long j = 0; j < this->x_; j++) {
                        res.matrix_[m][i] += this->matrix_[m][j] * in.matrix_[j][i];
                    }
                }
            }
        }
        return res;
    }

    Matrix Matrix::Pow(int n) const {
        Matrix out(x_, y_);
        if (this->x_ == this->y_)
            if (n != 0) {
                Matrix tmp(x_, y_);
                tmp.matrix_ = this->matrix_;
                out.matrix_ = this->matrix_;
                for (int i = 1; i <= n; i++) {
                    out = out.Mul(tmp);
                }
            } else if (n == 0) {
                for (unsigned long i = 0; i < this->x_; ++i)
                    out.matrix_[i][i] = 1.;
            }
        return out;
    }


    std::string Matrix::Print() const {
        std::stringstream result;
        result << "[";
        for (int i = 0; i < x_; ++i) {
            for (int j = 0; j < y_; ++j) {
                result << this->matrix_[i][j].real();
                result << "i" << this->matrix_[i][j].imag();
                if (j < y_ - 1)
                    result << ", ";
            }
            if (i < x_ - 1)
                result << "; ";
        }
        result << "]";
        return result.str();
    }

}