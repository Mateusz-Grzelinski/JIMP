//
// Created by mat on 18.04.17.
//

#ifndef JIMP_EXERCISES_KOLO_H
#define JIMP_EXERCISES_KOLO_H


#include "Shape.h"

class Kolo: public Shape {
public:
    Kolo(double X=0, double Y=0, double R=0): x(X), y(Y), r(R) {};
    virtual double Pole() const;
    void Draw() override ;

protected:
    double r;
    double x, y;
};


#endif //JIMP_EXERCISES_KOLO_H
