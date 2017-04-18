//
// Created by mat on 18.04.17.
//

#ifndef JIMP_EXERCISES_KOLO_H
#define JIMP_EXERCISES_KOLO_H


class Kolo {
public:
    Kolo(double X, double Y, double R): x(X), y(Y), r(R) {};
    virtual double Pole() const;

protected:
    double r;
    double x, y;
};


#endif //JIMP_EXERCISES_KOLO_H
