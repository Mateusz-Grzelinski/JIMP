//
// Created by mat on 18.04.17.
//

#ifndef JIMP_EXERCISES_KULA_H
#define JIMP_EXERCISES_KULA_H
#include "Kolo.h"

class Kula : public Kolo{
public:
    void Draw() override ;
    Kula(double X=0, double Y=0, double Z=0, double R=0): Kolo(X,Y,R), z(Z) {}
    virtual double Pole() const override; 
private:
    double z;
};


#endif //JIMP_EXERCISES_KULA_H
