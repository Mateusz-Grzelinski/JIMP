//
// Created by mat on 21.03.17.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include "../point/Point.h"

//namespace geometry {

    class Square {
    public:
        Square(Point, Point, Point, Point);

//        ~Square(); //nie potrzebny?

        double Circumference();

        double Area();

//    private:
        Point one;
        Point two;
        Point three;
        Point four;

    void InsertSort(Point *tmpx[4]) ;
};

#endif //JIMP_EXERCISES_SQUARE_H
