//
// Created by mat on 18.04.17.
//

#ifndef JIMP_EXERCISES_KULA_H
#define JIMP_EXERCISES_KULA_H
#include "Kolo.h"

class Kula : public Kolo{
public:
    Kula(double X, double Y, double Z, double R): Kolo(X,Y,R), z(Z) {} 
    virtual double Pole() const override; 
private:
    double z;
};


#endif //JIMP_EXERCISES_KULA_H
